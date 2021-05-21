#include "../Main_Define.H"


void __attribute__((interrupt, no_auto_psv)) _SI2C1Interrupt(void) 
{

	if(I2C1STATbits.S)//接收傳送過程，或者啟動訊號
	{
		if(I2C1STATbits.D_A)//判斷是1=Data 0=Address
		{
			
			if(I2C_Data.R_W==Comand_read)//判斷是不是讀取川
			{
				*I2C_Buffer_index=I2C1RCV;
			}
			else
			{
				*I2C_Buffer_index=I2C1RCV;
			}		
			I2C_Buffer_index++;
			I2C_Data.RTIndex++;
			if(	I2C_Data.RTIndex==I2C_Data.Index2)//當要收的資料數與以收資料數相同
			{

				I2C_Data.Busy_IF = 0;
				
			}
			I2C1CONbits.SCLREL=1;
			
		}	
		else
		{

			I2C_Data.Statue_IF =0;//清除旗標
			
			I2C_Data.Busy_IF = 1;
			I2C_Data.Index2 = 4;//這裡設定固定，因為已知要收的數量只有4個而已
			I2C_Data.RTIndex = 0;
	//		I2C_Buffer_index = &CP_Data;
			I2C_Data.Address = I2C1RCV;
		}
	}
	else if (I2C1STATbits.P)
	{
		//清除所有狀態
	}	
	
	IFS1bits.SI2C1IF=0;	 
}	
void __attribute__((interrupt, no_auto_psv)) _MI2C1Interrupt(void) 
{
	if(!I2C1STATbits.BCL)//總線衝突
	{
		if(I2C1STATbits.S)//接收傳送過程，或者啟動訊號
		{
			if(I2C_Data.R_W==Comand_read)//判斷是不是讀取川
			{
				if(I2C_Data.Address_IF || I2C_Data.ASK_IF)//剛剛上一個動作是傳送位置資料或者ASK，如果是位置代表要開始第一個資料讀取
				{//如果是傳送完ASK訊號，則開始下一個資料接收
					if(I2C_Data.RTIndex < (I2C_Data.Index1 + I2C_Data.Index2))//接收到的資料數量是否跟需要的資料數量相同
					{	
						I2C1CONbits.RCEN = 1;
						I2C_Data.RCEN_IF = 1;//設定現在動作是接收
						I2C_Data.ASK_IF = 0;
						I2C_Data.Address_IF = 0;
					}
					else if(I2C_Data.RTIndex > (I2C_Data.Index1+I2C_Data.Index2))//有問題!
					{
						while(1);
					}
					else//接收結束
					{
							I2C1CONbits.PEN = 1;	
							I2C_Data.Address_IF = 0;
							I2C_Data.ASK_IF = 0;
							I2C_Data.Busy_IF=0;
					}						
				}
				else if(I2C_Data.RCEN_IF)//剛剛上一個動作是啟動接收功能，再來要對裝置端傳送ASK訊號或者NASK訊號
				{
					*I2C_Buffer_index=I2C1RCV;
					I2C_Buffer_index++;
					I2C_Data.RTIndex++;
					if(I2C_Data.RTIndex==I2C_Data.Index1 + I2C_Data.Index2)I2C1CONbits.ACKDT = 1;
					else I2C1CONbits.ACKDT = 0;
					I2C1CONbits.ACKEN = 1;
					I2C_Data.ASK_IF = 1;//設定現在動作是ASK或是NASK
					I2C_Data.RCEN_IF = 0;
					
				}					
				
			}	
			else
			{
				if(I2C_Data.RStart_IF==0)//剛剛的啟動訊號，是重複啟動還是一般啟動
				{
					if(I2C_Data.RTIndex==I2C_Data.Index1 && I2C_Data.Data_R_W==Comand_read)//如果是讀取 判斷是不是第三個資料傳完(對方位置1+資料位置2) 如果傳完就會重新啟動
					{
						I2C1CONbits.RSEN = 1;
						I2C_Data.RStart_IF=1;					
					}
					else if (I2C_Data.RTIndex == I2C_Data.Index1 + I2C_Data.Index2)//當如果是寫入的話 代表資料已經寫完了
					{
						I2C1CONbits.PEN = 1;	
						I2C_Data.RTIndex=0;	
						I2C_Data.Busy_IF=0;						
					}	
					else if (I2C_Data.RTIndex > (I2C_Data.Index1 + I2C_Data.Index2))//有問題!
					{
						while(1);						
					}		
					else //當如果是寫入的話 就會一直寫 可是如果是讀取 第三個資料傳完(對方位置1+資料位置2) 這邊就不會進來
					{
						if(I2C_Data.RTIndex==1 && I2C1STATbits.ACKSTAT==1)//因為EEPROM寫入需要大約5ms時間  在這期間，要測試對方是否完成
						{//只能不斷的"啟動(S)" 傳送"位置(address)"訊息，確認對方有ask或nask nask的話就要傳送"停止(P)" 之後再"啟動(S)"
							I2C_Buffer_index--;				
							I2C_Data.RTIndex--;				
							I2C_Data.Device_Busy_IF=1;
							I2C1CONbits.PEN = 1;			
						}
						else
						{
							I2C1TRN = *I2C_Buffer_index;
							I2C_Buffer_index++;//把資料位置+1
							I2C_Data.RTIndex++;//把計數器+1
							if(I2C_Data.RTIndex == I2C_Data.Index1 && I2C_Data.Data_R_W==Comand_write)
							{
								I2C_Buffer_index=(unsigned char *)I2C_Data.Data_Addr;
							}
						}
					}										
				}
				else //已經傳送完重新啟動 要再傳送一次對方Address 並且將自己設定的Address旗標設1
				{
					I2C_Data.R_W = 			Comand_read;
					I2C_Buffer_index = (unsigned char *)I2C_Data.Data_Addr;
					I2C1TRN = I2C_Data.Address;
					I2C_Data.Address_IF=1;
				}
			}			
		}
		else if (I2C1STATbits.P)
		{
			if(I2C_Data.Device_Busy_IF)
			{
				I2CStat;				// 發出啟始位元		
				I2C_Data.Device_Busy_IF=0;
			}
			else
			{
				//這裡少寫一個，發生無法偵測到對方位置時候
				if(I2C_Data.Data_R_W==Comand_read)
				{
					I2C_Data.RIF = 1;
				}
				else 
				{
					I2C_Data.TIF = 1;
				}				
			}

		}
	}
	else
	{
		I2C1CONbits.PEN = 1;
		LED_Red = LED_ON;
		LED_Green = LED_OFF;
		LED_Blue = LED_OFF;	
		while(1);	
	}

	IFS1bits.MI2C1IF=0;
} 


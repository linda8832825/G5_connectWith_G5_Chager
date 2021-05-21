#include "../Main_Define.H"
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
	unsigned int  math_a,math_b,math_c;
		
		

	
		if(IC_Data.Wait_Coulomb_Read==0)
		{
			if(Coulomb_Data.Read_Timer)
			{
				if(Coulomb_Data.Read_Timer==0)
				{
					Coulomb_Data.Read_Timer=1;
				}
				Coulomb_Data.Read_Timer--;
				if(Coulomb_Data.Read_Timer>Coulomb_Read_Data_Timer)
				{
					Coulomb_Data.Read_Timer=Coulomb_Read_Data_Timer;
				}
				
				if(Coulomb_Data.Read_Timer==0)
				{
					Coulomb_Data.Read_Timer=0;
				//	IC_Data.Wait_Coulomb_Read= Read_Data_Timer-Coulomb_Read_Data_Timer;
					Read_ALL_Coulomb_Data();	
				//	IC_Data.Coulomb_No_Reback=Coulomb_No_Reback_Time;
				}
			}				
		}
		else
		{
			IC_Data.Wait_Coulomb_Read--;
		}


			
		
		//如果沒收到面板回傳資料的話
		if(Sent_struct.NO_RESPONSE_Time)
		{
			Sent_struct.NO_RESPONSE_Time--;
			if(Sent_struct.NO_RESPONSE_Time==0)
			{
				if(Sent_struct.RTIndex>0)
				{
					//有接收到但，接收錯誤
					Sent_struct.RTIndex=0;
					Sent_struct.Index=0;
					Sent_struct.ERRIF=1;
				}
				else
				{
					Original_Data.Item3Bits.COMM = 0;
					Sent_struct.ERRIF=1;

				}
				if(Sent_struct.Count==0)
				{
					Sent_struct.Count=1;
					math_a=Sent_Data_TO_BMS_Time;
					math_b=Coulomb_Read_Data_Timer;					
					Coulomb_Data.Read_Timer=math_a-(math_b-Coulomb_Data.Read_Timer);					
				}
		//		Coulomb_Data.Read_Timer=
				Sent_struct.RTIndex=0;
				Sent_struct.Index=0;
				Sent_struct.End_Flag=0;
				
			}
		}
		
		//如果沒收到庫倫計回傳資料的話
		if(IC_Data.Coulomb_No_Reback)
		{
			IC_Data.Coulomb_No_Reback--;
			if(IC_Data.Coulomb_No_Reback==0)
			{
				ModBus_Receiver.Index=0;
				ModBus_Receiver.RTIndex=0;
				ModBus_Receiver.BusyIF=0;
				ModBus_Receiver.RIF=0;		
				ModBus_Receiver.TIF=0;
				ModBus_Receiver.ERRIF=1;
				ModBus_Sent.Index=0;
				ModBus_Sent.RTIndex=0;		
			}
		}	
		
		
		
		
		
		
		if(IC_Data.Timer0_Count)
		{
			IC_Data.Timer0_Count--;
			if(IC_Data.Timer0_Count==0)
			{
				IC_Data.Timer0_Count_IF=1;		
			}
		}		
		
		if(IC_Data.Timer1_Count)
		{
			IC_Data.Timer1_Count--;
			if(IC_Data.Timer1_Count==0)
			{
				IC_Data.Timer1_Count_IF=1;		
			}
		}				
		
		if(IC_Data.Timer2_Count)
		{
			IC_Data.Timer2_Count--;
			if(IC_Data.Timer2_Count==0)
			{
				IC_Data.Timer2_Count_IF=1;		
			}
		}	
				
		if(IC_Data.Timer3_Count)
		{
			IC_Data.Timer3_Count--;
			if(IC_Data.Timer3_Count==0)
			{
				IC_Data.Timer3_Count_IF=1;		
			}
		}							
		
		//紀錄EROM倒數計時
		if(EEPROM.Save_Count)
		{
			EEPROM.Save_Count--;	
			if(EEPROM.Save_Count==0)
			{
				EEPROM.Save_IF=1;
			}
		}
		
		//使用時間計時		
		if(IC_Data.ms==0)
		{
			IC_Data.ms=1000;				
			if(IC_Data.Second==59)
			{
				IC_Data.Second=0;
				//IC_Data_Save_IF.minute_IF=1;						
				if(IC_Data.Save_struct.minute==59)
				{
					IC_Data.Save_struct.minute=0;
					IC_Data_Save_IF.Hour_IF=1;
					EEPROM.Save_IF=1;
					if(IC_Data.Save_struct.Hour==23)
					{
						IC_Data.Save_struct.Hour=0;
						IC_Data_Save_IF.Day_IF=1;
						math_b=29;
						math_c=IC_Data.Save_struct.Month%12;
						if(math_c==0)math_a=1;
						else if(math_c==1)math_a=0;
						else if(math_c==2)math_a=1;
						else if(math_c==3)math_a=0;
						else if(math_c==4)math_a=1;						
						else if(math_c==5)math_a=0;
						else if(math_c==6)math_a=1;						
						else if(math_c==7)math_a=0;
						else if(math_c==8)math_a=1;
						else if(math_c==9)math_a=1;
						else if(math_c==10)math_a=0;
						else if(math_c==11)math_a=1;
						else if(math_c==12)math_a=0;		
						math_a = math_a + math_b;																
						if(IC_Data.Save_struct.Day == math_a)
						{
							IC_Data.Save_struct.Day=0;
							IC_Data_Save_IF.Month_IF=1;
							IC_Data.Save_struct.Month++;									
						}
						else 	IC_Data.Save_struct.Day++;			
					}	
					else 	IC_Data.Save_struct.Hour++;	 					
				}
				else 	IC_Data.Save_struct.minute++;					
			}
			else 	IC_Data.Second++;
		}
		else
		{
			IC_Data.ms--;
		}	
		
		
		
		
		
		IFS0bits.T1IF=0;
}	

void Timer1_initial(void)
{
	T1CON=0;
	IEC0bits.T1IE=1; //TIMER中斷允許位 1=允許
	IFS0bits.T1IF=0; //TIMER中斷標誌狀態位 0=未受到中斷
	T1CONbits.TCKPS=1;//1:8
	T1CONbits.TCS=0; //內部clock (FOSC/2
	T1CONbits.TON=1; //打開TIMER功能
	PR1=2000; //4秒做一次
}
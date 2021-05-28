//###########################################################//
//    日期   : 2020.09.22                                    //
//    版本   : v2.3                                          //
//  更新紀錄 : 可從moxa寫安時數進去                           //
//    作者   : 小銘、twfno 、linda                            //
//###########################################################//

#include "Main_Define.H"

_CONFIG1( WINDIS_OFF & FWDTEN_OFF & ICS_PGx1 & BKBUG_ON & GWRP_OFF & GCP_OFF & JTAGEN_OFF  )
_CONFIG2( IESO_OFF & FNOSC_FRCPLL & FCKSM_CSDCMD & OSCIOFNC_OFF   )



void __attribute__((interrupt, no_auto_psv)) _OscillatorFail(void)
{
	INTCON1bits.OSCFAIL = 0;
	while(1);     
}

void __attribute__((interrupt, no_auto_psv)) _AddressError(void)
{
	unsigned char math_a=1;
	INTCON1bits.ADDRERR = 	0;
	while(math_a);     
}

void __attribute__((interrupt, no_auto_psv))_StackError(void)
{
	INTCON1bits.STKERR = 0;
	while(1);     
}

void __attribute__((interrupt, no_auto_psv)) _MathError(void)
{
	
	INTCON1bits.MATHERR = 0;
	while(1);     
}

IC_data_Define IC_Data;
IC_Data_IF IC_Data_Save_IF;
LED_Statue_Define LED_Statue;


int main (void) 
{
	
	unsigned int math_a,math_c,math_b;

	Initial_Clock(); 	
	IC_Data.ms=1000;
	
	//IC_Data.Wait_Coulomb_Read=0;
	
	
	//一些數值的初始化設定-----------------------------------------------
	IC_Data.Wait_Coulomb_Read=1480;
	Sent_struct.W_R=1;
	IC_Data.Charge_Voltage_Avg=0;		
	IC_Data.Charge_Voltage_Avg_Count=0;	
	LED_Statue.Battery_Led.Dimmy=Battery_Led_Dimmy;
	LED_Statue.G_Flick.Freq = Flick_Fast;
	LED_Statue.R_Flick.Freq = Flick_Slow;        
	LED_Statue.B_Flick.Freq = Flick_Middle;
	 IC_Data.Return_ID=0x06;
	//--------------------------------------------------------------------


	         
	Initial_IO();
	Initial_Coulomb_UART();
	Initial_MOXA_UART();
	Timer1_initial();
	Initial_UART2();
//	I2C_Initial();
		

	
	
	
	LED_Battery0 = LED_ON;
	LED_Battery1 = LED_ON;
	LED_Battery2 = LED_ON;
	LED_Battery3 = LED_ON;
	LED_Battery4 = LED_ON;
	LED_Green 	 = LED_ON;
	LED_Blue		 = LED_ON;
	LED_Red 		 = LED_ON;	

	Bebe = Bebe_ON;
	while(IC_Data.Wait_Coulomb_Read>980);//開機逼聲
	Bebe = Bebe_OFF;		
	while(IC_Data.Wait_Coulomb_Read>480);//開機逼聲
	
	
	Bebe = Bebe_ON;		
	while(IC_Data.Wait_Coulomb_Read>400);//開機逼聲
	Bebe = Bebe_OFF;	
	while(IC_Data.Wait_Coulomb_Read>320);//開機逼聲

	
	Bebe = Bebe_ON;		
	while(IC_Data.Wait_Coulomb_Read>240);//開機逼聲
	Bebe = Bebe_OFF;	
	while(IC_Data.Wait_Coulomb_Read>160);//開機逼聲	


	Bebe = Bebe_ON;		
	while(IC_Data.Wait_Coulomb_Read>80);//開機逼聲
	Bebe = Bebe_OFF;	
	while(IC_Data.Wait_Coulomb_Read);//開機逼聲	

	
	
	do
	{	
		if(ModBus_Receiver.ERRIF)IC_MODE_LED_SET(ERRO_MODE);//如果沒有接收到庫倫計資料 會顯示錯誤
		ModBus_Receiver.IF = 0;
		Read_ALL_Coulomb_Data();
		
		Coulomb_Data.Read_Timer=500;
		while(ModBus_Receiver.IF==0); //等待庫倫計回應資料
		
	}while(ModBus_Receiver.ERRIF==1);
	
	IC_MODE_LED_SET(Normal_Statue_MODE);
	while(IC_Data.Wait_Coulomb_Read);
	Bebe = Bebe_OFF;



	
	
	
//	Read_All_EEROM_Information();
//	math_a=Read_first_information();	
//  IC_Data.Save_struct.Now_Total_Capacity=525;  	
	
	IC_Data.Save_struct.Battery_ID=44;
	IC_Data_Save_IF.Battery_ID_IF = 1;
//	EEPROM.Save_Count=5000;	
    /***************** 電池 ID ******************/  //19091211
	IC_Data.Save_struct.S_N[0] = 1;
	IC_Data.Save_struct.S_N[1] = 9;
	IC_Data.Save_struct.S_N[2] = 0;
	IC_Data.Save_struct.S_N[3] = 9;	
	IC_Data.Save_struct.S_N[4] = 1;
	IC_Data.Save_struct.S_N[5] = 2;
	IC_Data.Save_struct.S_N[6] = 1;
	IC_Data.Save_struct.S_N[7] = 5;	
    /***************** 電池 ID ******************/
	
		IC_Data.Save_struct.Capacity_To_Voltage=Get_Capacity_To_Voltage_variable();
	
        Unlock_Coulomb();
		Write_Coulomb_Data(0x0009,FULL_Battery_Capacity);//0x0009  標準電池容量 0.0~6553.5AH
		while(!ModBus_Receiver.TIF);
		ModBus_Receiver.TIF=0;		
	
	
	
	math_b=math_a;
	math_b=0;
	math_b=math_a;
	math_b=0;		
	
	if(math_a!=1)
	{	
		Write_Coulomb_Data(0x0009,FULL_Battery_Capacity);//0x0009  標準電池容量 0.0~6553.5AH
		while(!ModBus_Receiver.TIF);
		ModBus_Receiver.TIF=0;		
		
		Write_Coulomb_Data(0x0007,FULL_Battery_Capacity);//0x0007  剩下電量0.0~6553.5Ah
		while(!ModBus_Receiver.TIF);
		ModBus_Receiver.TIF=0;
		Battery_LED_SET(0);	
				
		math_a=1;
//		EEPROM_Write( 0 ,First_Use_Addr, &math_a , 1);
//		while(I2C_Data.TIF==0);
//		I2C_Data.TIF=0;			
	}	


	


					
	if (SW3_Reset==SW_Push)//重置電量或是滿電
	{
		 if (SW1_Bootloader==SW_Push)//滿電
		 {
			 
				IC_Data.Save_struct.Now_Total_Capacity = FULL_Battery_Capacity;	//將目前的電容量值存到目前的總電容量
			
				IC_Data.Save_struct.Capacity_To_Voltage=Get_Capacity_To_Voltage_variable();	
				IC_Data_Save_IF.Now_Total_Capacity_IF = 1;
				IC_Data_Save_IF.Capacity_To_Voltage_IF = 1;
//				EEPROM.Save_Count=5000;						 
			 
			 
				Write_Coulomb_Data(0x0007,FULL_Battery_Capacity);//0x0007  剩下電量0.0~6553.5Ah
				while(!ModBus_Receiver.TIF);
				ModBus_Receiver.TIF=0;
				Battery_LED_SET(5);			 
		 }
		 else //重置電量
		 {
			Write_Coulomb_Data(0x0007,0);//0x0007  剩下電量0.0~6553.5Ah
			while(!ModBus_Receiver.TIF);
			ModBus_Receiver.TIF=0;
			Battery_LED_SET(0);		 	
		 }
	}
	else if(SW1_Bootloader==SW_Push)
	{
	
	}
	else if (SW2_Factory_Test==SW_Push)
	{
		
	}	
	
/*
	math_c=525;
	IC_Data.Save_struct.Now_Total_Capacity = math_c;	//將目前的電容量值存到目前的總電容量
	IC_Data.Save_struct.Capacity_To_Voltage=Get_Capacity_To_Voltage_variable();	
	IC_Data_Save_IF.Now_Total_Capacity_IF = 1;
	IC_Data_Save_IF.Capacity_To_Voltage_IF = 1;
	EEPROM.Save_Count=5000;	
*/


	
	//第一次使用
	//math_a=1;
	//EEPROM_Write( 0 ,First_Use_Addr, &math_a , 1);
	//while(I2C_Data.TIF==0);
	//I2C_Data.TIF=0;	
	
	math_a=0;

	//math_a=6;

		
	while(1)
	{
		if(ModBus_Receiver.RIF==1)
		{
			if(T4CONbits.TON==0)Timer4_initial();
			LED_Statue.Battery_Led.Stat_IF=1;

			ModBus_Receiver.ERR_Count=0;	
			
			if(IC_Data.IC_MODE_LED_SET!=Normal_Statue_MODE)
			{
				IC_Data.IC_MODE_LED_SET=Normal_Statue_MODE;
				IC_MODE_LED_SET(Normal_Statue_MODE);
			}	
			Conversion_Data_to_BMS();				
			ModBus_Receiver.RIF=0;
			
			if(U2STAbits.OERR)
			{
				while(U2STAbits.OERR)
				{
					math_a=U2RXREG;
				}
			}					
			
			
			if(Sent_struct.ERRIF==1)//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			{			
				Coulomb_Data.Read_Timer = Sent_Data_TO_BMS_Time;
				Sent_Data_To_PLC();
			}	
			else if(Sent_struct.ERRIF==0)//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			{				
				Coulomb_Data.Read_Timer = Coulomb_Read_Data_Timer;
				Sent_Data_To_PLC();	
			}		
		}
		else if(ModBus_Receiver.ERRIF)
		{
			ModBus_Receiver.ERR_Count++;
			if(ModBus_Receiver.ERR_Count>=8)
			{
				ModBus_Receiver.ERR_Count=8;
				Coulomb_Data.Read_Timer = Sent_Data_TO_BMS_Time;
						
				if(IC_Data.IC_MODE_LED_SET!=ERRO_MODE)
				{
					IC_Data.IC_MODE_LED_SET=ERRO_MODE;
					IC_MODE_LED_SET(ERRO_MODE);
				}	
				
				
				//Sent_Data_To_PLC();	 目前考慮在想要不要恢復傳送還是乾脆就斷掉
			}
			else
			{			
				if(ModBus_Receiver.ERRIF==1)
				{
					Coulomb_Data.Read_Timer = Coulomb_Read_Data_Timer;
					Sent_Data_To_PLC();
				}	
				else if(ModBus_Receiver.ERRIF==0)
				{
					Coulomb_Data.Read_Timer = Coulomb_Read_Data_Timer;
					Sent_Data_To_PLC();	
				}					
			}
			ModBus_Receiver.ERRIF=0; 
			
		}
			
		if(Sent_struct.End_Flag==2)//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		{
			Sent_struct.End_Flag=0;
			Receive_Customer_Pannal();//將Customer_Pannal傳送過來的資料整理
		}
//		if(!I2C_Data.Busy_IF)
//		{
//			if(EEPROM.Save_IF)
//			{
//				Write_EEROM_information();
//			}
//        }	
		if(MOXA.RIF)
		{		
			MOXA_Work_Function();
		}
		
		/*
		math_c=0;
		math_c=0;
	
		if(math_a==1)
		{
			math_c=420;			
			math_a=0;
			while(ModBus_Receiver.BusyIF);
			Write_Coulomb_Data(0x0007,	math_c);//0x0007  剩下電量0.0~6553.5Ah
			while(!ModBus_Receiver.TIF);
			ModBus_Receiver.TIF=0;		
	
		}		
		else if(math_a==2)
		{
			math_c=300;
			math_a=0;			
			IC_Data.Save_struct.Now_Total_Capacity = math_c;	//將目前的電容量值存到目前的總電容量
			IC_Data.Save_struct.Capacity_To_Voltage=Get_Capacity_To_Voltage_variable();	
			IC_Data_Save_IF.Now_Total_Capacity_IF = 1;
			IC_Data_Save_IF.Capacity_To_Voltage_IF = 1;
			EEPROM.Save_Count=5000;			
		}		
		*/	
	
		if(SW1_Bootloader==SW_Push)
		{
		//	while(SW1_Bootloader==SW_Push);
		//	IC_Data.Timer3_Count=100;
		//	IC_Data.Timer3_Count_IF=0;
		//	while(!IC_Data.Timer3_Count_IF);//開機逼聲
		//	IC_Data.Timer3_Count_IF=0;	
		//	IC_Data.Save_struct.Now_Total_Capacity = FULL_Battery_Capacity;	
		}	
		else if(SW2_Factory_Test==SW_Push)
		{
			while(SW2_Factory_Test==SW_Push);
		//	ModBus_Receiver.RIF = 0;
		//	ModBus_Receiver.ERRIF = 0;
		//	Sent_struct.ERRIF = 0;
		//	Coulomb_Data.Read_Timer = 0;
		//	IC_Data.Coulomb_No_Reback = 0;	
		//	Sent_struct.NO_RESPONSE_Time = 0;
		//	goto Point1;
		}									
	}

}






		
		
	/*	
		if (SW2_Reset==SW_Push)
		{
			while(SW2_Reset==SW_Push);
			math_c=Coulomb_Data.Residual_Electricity-10;
			if(Coulomb_Data.Residual_Electricity<200)math_c=IC_Data.Save_struct.Now_Total_Capacity+50;			
			math_a=0;
			while(ModBus_Receiver.BusyIF);
			Write_Coulomb_Data(0x0007,	math_c);//0x0007  剩下電量0.0~6553.5Ah
			while(!ModBus_Receiver.TIF);
			ModBus_Receiver.TIF=0;			
		}		
		if (SW1_Bootloader==SW_Push)
		{
				while(SW1_Bootloader==SW_Push);
				math_c=500;
				IC_Data.Save_struct.Now_Total_Capacity = math_c;	//將目前的電容量值存到目前的總電容量
				IC_Data.Save_struct.Capacity_To_Voltage=Get_Capacity_To_Voltage_variable();	
				IC_Data_Save_IF.Now_Total_Capacity_IF = 1;
				IC_Data_Save_IF.Capacity_To_Voltage_IF = 1;
				EEPROM.Save_Count=5000;				
		}			
		

		if(math_a==2)//更新電容量
		{	
			IC_Data.Timer0_Count_IF=0;
			IC_Data.Timer0_Count=5000;
			math_c=500;			
			math_a=0;
			Write_Coulomb_Data(0x0007,	math_c);//0x0007  剩下電量0.0~6553.5Ah
			while(!ModBus_Receiver.TIF);
			ModBus_Receiver.TIF=0;				
		}	
				
		
		if(Original_Data.Item3Bits.CGDS)LED_Blue=LED_ON ;
		else LED_Blue=LED_OFF ;
		
		if(Original_Data.Item3Bits.CHG1)LED_Red=LED_ON ;
		else LED_Red=LED_OFF ;		
*/		
		
		
		
		
		
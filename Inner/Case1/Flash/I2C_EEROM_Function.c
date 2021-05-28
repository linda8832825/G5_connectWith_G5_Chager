//#include "../Main_Define.H"
//
//EEPROM_Information_Struct EEPROM;	
//
//
//
//void Read_All_EEROM_Information(void)
//{
//	unsigned int math_a=0,math_b=0;
//	unsigned char	*clear_index;
//	math_a=Read_first_information();
//	if(!Save_Data)math_a=Save_Data;
//	if(math_a!=1 || (SW3_Reset==SW_Push ))
//	{
//		IC_Data_Save_IF.All_IF=0xFFFF;
//		math_b=sizeof(IC_Data.Save_struct); //取得總用使用多少Byte
//		clear_index=&IC_Data.Save_struct.Now_Total_Capacity;		
//		for(math_a=0;math_a<math_b;math_a++,clear_index++)
//		{ 
//			*clear_index=0;
//		}
//		IC_Data.Save_struct.Month=0;
//		IC_Data.Save_struct.Day=0;
//		IC_Data.Save_struct.Hour=0;
//		IC_Data.Save_struct.minute=0;
//		IC_Data.Save_struct.Now_Total_Capacity=525;
//		IC_Data.Save_struct.Capacity_To_Voltage=418;
//		Write_Initial_Data_TO_EEPROM();
//	}
//	else
//	{
//		EEPROM_Read( PAGE0 ,Now_Total_Capacity_Addr,&IC_Data.Save_struct.Now_Total_Capacity	, 44);
//		while(I2C_Data.RIF==0);
//		I2C_Data.RIF=0;
//		
//		/*
//		EEPROM_Read( PAGE2 ,0,&BUFF1[0]	, IC_Data.Save_struct.Struct1_index);
//		while(I2C_Data.RIF==0);
//		I2C_Data.RIF=0;
//		
//		EEPROM_Read( PAGE3 ,0,&BUFF2[0]	, IC_Data.Save_struct.Struct2_index);
//		while(I2C_Data.RIF==0);
//		I2C_Data.RIF=0;
//		*/
//	}
//	
//}	
//
//
//void	EEPROM_Read(unsigned char Dvice_Add , unsigned int Reg_Addr  ,unsigned char *Buff_Addr , unsigned char Leng)
//{
//
//	
//	while(I2C1STATbits.BCL)
//	{
//		I2C1STATbits.BCL=0;
//		I2C1CONbits.PEN = 1	;
//	}
//	while(I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RCEN ||I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);
//
//
//	I2C_Data.Address 	=	EROMIC_I2C_Addr;	 
//	I2C_Data.R_W 			= Comand_write;
//	I2C_Data.Addr_H 	=	(Reg_Addr&0xFF);
//	if(Dvice_Add==0)
//	{
//		I2C_Data.A0=0;
//		I2C_Data.A1=0;
//				
//	}
//	else if(Dvice_Add==1)
//	{
//		I2C_Data.A0=1;
//		I2C_Data.A1=0;
//				
//	}
//	else if(Dvice_Add==2)
//	{
//		I2C_Data.A0=0;
//		I2C_Data.A1=1;
//			
//	}
//	else if(Dvice_Add==3)	
//	{
//		I2C_Data.A0=1;
//		I2C_Data.A1=1;			
//	}	
//	
//	
//	
//	/*
//	I2C_Data.Addr_H 	=	(Reg_Addr&0x0F00)>>8;
//	I2C_Data.Addr_L 	=	(Reg_Addr&0xFF);
//	*/
//	I2C_Data.ALL_IF		= 0;
//	I2C_Data.RTIndex 	= 0;
//	I2C_Data.Data_R_W = Comand_read;//要先寫入位置
//	I2C_Data.Data_Addr=(unsigned int)Buff_Addr;
//	I2C_Data.Busy_IF=1;
//	I2C_Data.Index1=2;		
//	I2C_Data.Index2=Leng;	
//			
//	I2C_Buffer_index=&I2C_Data.Address;		
//	I2CStat;				// 發出啟始位元	
//		
//}	
//void	EEPROM_Write(unsigned char Dvice_Add, unsigned char Reg_Addr  , unsigned char *Buff_Addr , unsigned char Leng)
//{
//		unsigned char DDD;
//		while(I2C1STATbits.BCL)
//		{
//			I2C1STATbits.BCL=0;
//		}
//		while(I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RCEN ||I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);
//		
//		
//		I2C_Data.Address 	=	EROMIC_I2C_Addr;	 
//		I2C_Data.R_W 			= Comand_write;
//		I2C_Data.Addr_H  	=	(Reg_Addr&0xFF);
//		
//		if(Dvice_Add==0)
//		{
//			I2C_Data.A0=0;
//			I2C_Data.A1=0;			
//		}
//		else if(Dvice_Add==1)
//		{
//			I2C_Data.A0=1;
//			I2C_Data.A1=0;
//				
//		}
//		else if(Dvice_Add==2)
//		{
//			I2C_Data.A0=0;
//			I2C_Data.A1=1;			
//		}
//		else if(Dvice_Add==3)	
//		{
//			I2C_Data.A0=1;
//			I2C_Data.A1=1;			
//		}
//		
//		I2C_Data.ALL_IF		= 0;
//		I2C_Data.RTIndex 	= 0;
//		I2C_Data.Data_R_W = Comand_write;
//		I2C_Data.Data_Addr=(unsigned int)Buff_Addr;
//		I2C_Data.Busy_IF=1;
//		I2C_Data.Index1=2;
//		I2C_Data.Index2=Leng;
//		
//		I2C_Buffer_index=&I2C_Data.Address;//把IC2結構位置放入
//
//		I2CStat;				// 發出啟始位元		
//}
//
//
//
//
//
//
//
//void Write_Initial_Data_TO_EEPROM(void)//第一次使用 將初始化資料寫入EEPROM
//{
//	unsigned int math_a=0,math_b=0,math_c=0;
//	
//
//	
//	unsigned char *index_a;
//		
//	unsigned char Buffer[16];
//
//	math_a=0;
//	EEPROM_Write( 0 ,First_Use_Addr, &math_a , 1);
//	while(I2C_Data.TIF==0);
//	I2C_Data.TIF=0;
//
//				
//	EEPROM_Write( PAGE0 ,First_Use_Addr + Now_Total_Capacity_Addr	, &IC_Data.Save_struct.Now_Total_Capacity	, 16);
//	while(I2C_Data.TIF==0);
//	I2C_Data.TIF=0;
//	
//	EEPROM_Write( PAGE0 ,First_Use_Addr + Use_Time_M_Addr	, &IC_Data.Save_struct.Month	, 16);
//	while(I2C_Data.TIF==0);
//	I2C_Data.TIF=0;
//
//
//
//	math_c=0;
//	for(math_a=0;math_a<16;math_a++)
//	{
//		Buffer[math_a] = 0;
//	}	
//	for(math_a=2;math_a<=3;math_a++)
//	{
//		for(math_b=0;math_b<16;math_b++)
//		{
//			EEPROM_Write( math_a , math_c,&Buffer[0]		, 16);
//			while(I2C_Data.TIF==0);
//			I2C_Data.TIF=0;	
//			math_c+=16;
//		}
//	}	
//	
//	EEPROM_Write( PAGE0 ,First_Use_Addr + S_N_Addr 		,&IC_Data.Save_struct.S_N[0]		, 12);
//	while(I2C_Data.TIF==0);
//	I2C_Data.TIF=0;
//	
//
//	
//}	
//
//
//char Read_first_information(void)
//{
//	unsigned char math_a;
//	EEPROM_Read( 0 , First_Use_Addr, &math_a , 1);
//	while(!I2C_Data.RIF);
//	I2C_Data.RIF=0;
//	if(math_a==1) return 1;
//	else return 0;
//	
//}
//
//void Write_EEROM_information(void)
//{
////		CHx_Save_IF *Index2 =0;
////		Channel_Data_define *Index1;
//		unsigned int math_a = 0;	
//		unsigned int ADDR = 0;	
//		unsigned char Page;			
//		
//		if(IC_Data_Save_IF.All_IF)
//		{
//			ADDR=First_Use_Addr;		
//		}
//		else
//		{
//			EEPROM.Save_IF=0;
//		}	
//		
//		if(EEPROM.Save_IF)
//		{
//			if(IC_Data_Save_IF.Struct_IF1==0x3FF)
//			{				
//				EEPROM_Write( PAGE0 ,ADDR + Now_Total_Capacity_Addr	, &IC_Data.Save_struct.Now_Total_Capacity	, 16);
//				IC_Data_Save_IF.Now_Total_Capacity_IF=0;
//				IC_Data_Save_IF.Capacity_To_Voltage_IF=0;
//				IC_Data_Save_IF.Battery_Ohm_IF=0;
//				IC_Data_Save_IF.X1_IF=0;
//				IC_Data_Save_IF.X2_IF=0;
//				IC_Data_Save_IF.X3_IF=0;
//				IC_Data_Save_IF.Struct1_index_IF=0;
//				IC_Data_Save_IF.Struct2_index_IF=0;
//				IC_Data_Save_IF.Battery_ID_IF=0;
//				IC_Data_Save_IF.X7_IF=0;					
//			}			
//			else if(IC_Data_Save_IF.Struct_IF2==0x1F)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Use_Time_M_Addr	, &IC_Data.Save_struct.Month	, 16);	
//				IC_Data_Save_IF.Month_IF=0;
//				IC_Data_Save_IF.Day_IF=0;
//				IC_Data_Save_IF.Hour_IF=0;
//				IC_Data_Save_IF.minute_IF=0;
//				IC_Data_Save_IF.X8_IF=0;								
//			}			
//			else if(IC_Data_Save_IF.Now_Total_Capacity_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Now_Total_Capacity_Addr		,&IC_Data.Save_struct.Now_Total_Capacity		, 2);
//				IC_Data_Save_IF.Now_Total_Capacity_IF=0;
//			}		
//			else if(IC_Data_Save_IF.Capacity_To_Voltage_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Capacity_To_Voltage_Addr		,&IC_Data.Save_struct.Capacity_To_Voltage		, 2);
//				IC_Data_Save_IF.Capacity_To_Voltage_IF=0;
//			}			
//			else if(IC_Data_Save_IF.Battery_Ohm_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Battery_Ohm_Addr		,&IC_Data.Save_struct.Battery_Ohm		, 2);
//				IC_Data_Save_IF.Battery_Ohm_IF=0;
//			}						
//			else if(IC_Data_Save_IF.X1_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + X1_Addr		,&IC_Data.Save_struct.X1		, 2);
//				IC_Data_Save_IF.X1_IF=0;
//			}				
//			else if(IC_Data_Save_IF.X2_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + X2_Addr		,&IC_Data.Save_struct.X2		, 2);
//				IC_Data_Save_IF.X2_IF=0;
//			}				
//			else if(IC_Data_Save_IF.X3_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + X3_Addr		,&IC_Data.Save_struct.X3		, 2);
//				IC_Data_Save_IF.X3_IF=0;
//			}	
//			else if(IC_Data_Save_IF.Struct1_index_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Struct1_index_Addr		,&IC_Data.Save_struct.Struct1_index		, 1);
//				IC_Data_Save_IF.Struct1_index_IF=0;
//			}				
//			else if(IC_Data_Save_IF.Struct2_index_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Struct2_index_Addr		,&IC_Data.Save_struct.Struct2_index		, 1);
//				IC_Data_Save_IF.Struct2_index_IF=0;
//			}					
//			else if(IC_Data_Save_IF.Battery_ID_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Battery_ID_Addr		,&IC_Data.Save_struct.Battery_ID		, 1);
//				IC_Data_Save_IF.Battery_ID_IF=0;
//			}							
//			else if(IC_Data_Save_IF.X7_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + X7_Addr		,&IC_Data.Save_struct.X7		, 1);
//				IC_Data_Save_IF.X7_IF=0;
//			}												
//			else if(IC_Data_Save_IF.Month_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Use_Time_M_Addr		,&IC_Data.Save_struct.Month		, 2);
//				IC_Data_Save_IF.Month_IF=0;
//			}							
//			else if(IC_Data_Save_IF.Day_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Use_Time_D_Addr		,&IC_Data.Save_struct.Day		, 2);
//				IC_Data_Save_IF.Day_IF=0;
//			}				
//			else if(IC_Data_Save_IF.Hour_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Use_Time_H_Addr		,&IC_Data.Save_struct.Hour		, 1);
//				IC_Data_Save_IF.Hour_IF=0;
//			}	
//			else if(IC_Data_Save_IF.minute_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + Use_Time_m_Addr		,&IC_Data.Save_struct.minute		, 1);
//				IC_Data_Save_IF.minute_IF=0;
//			}													
//			else if(IC_Data_Save_IF.S_N_IF)
//			{
//				EEPROM_Write( PAGE0 ,ADDR + S_N_Addr 		,&IC_Data.Save_struct.S_N[0]		, 12);
//				IC_Data_Save_IF.S_N_IF = 0;
//			}		
//		unsigned 	int 	Day;
//		unsigned 	char 	Hour;
//		unsigned 	char 	minute;					
//						
//		
//			
//			
//			
//			
//					
//		}			
//}	
//
//
//
//
//
//
//

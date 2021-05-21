#include "../Main_Define.H"

BMS_Return_Data_define 			BMS_Return_Data;
LCD_Data_define10 					Customer_Pannal_10; 
LCD_Data_define12 					Customer_Pannal_12; 
Sent_struct_define 					Sent_struct; 
Original_Data_define 				Original_Data;


unsigned char const Word[17]  ={0x05,0x30,0x30,0x30,0x30,0x51,0x57,0x34,0x44,0x30,0x30,0x31,0x34,0x30,0x30,0x30,0x41};//0000QW4D0014000A
unsigned char const Word2[21] ={0x05,0x30,0x30,0x30,0x30,0x51,0x52,0x34,0x44,0x30,0x30,0x31,0x34,0x32,0x30,0x30,0x35,0x36,0x37,0x0D,0x0A};//"0000QR4D0014200567" 
unsigned char const Word3[7] ={0x06,0x30,0x30,0x30,0x30,0x0D,0x0A};//面板回應有收到 
unsigned char const Word4[30] ={0x02,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x03,0x38,0x34,0x0D,0x0A};//面板回應▼0x02▼000000010000000000000000 ▼0x03▼ 84 ▼0x0D▼ ▼0x0A▼
unsigned char const Word5[7] ={0x06,0x30,0x30,0x30,0x30,0x0D,0x0A};//IC有收到資料並，回應有收到 
//unsigned char const Word[] ={"0000QW4D0014000A00010000000000F0001B00450021005C000400154E"};

	
void Get_CHeck_SUM(void)
{
	unsigned char *index1,*index6,*index3;
	unsigned int math_a,math_b,math_c;
	
	math_c = Customer_Pannal_Data_Count;
		
	if(math_c==12)//12個項目
	{
		index1 = &Customer_Pannal_12.Start;
		index3 = &Customer_Pannal_12.Check_SUM2;	
		index6 = &Customer_Pannal_12.CHAR1;
	}
	else//10個項目
	{
		index1 = &Customer_Pannal_10.Start;		
		index3 = &Customer_Pannal_10.Check_SUM2;
		index6 = &Customer_Pannal_10.CHAR1;		
	}	
		
	//-----------------------------------------------------------------------------
	//--------------------------計算出CHECK_SUM-----------------------------------
	//index1 = &Customer_Pannal_10.CHAR1;
	//math_b=0x00F6;
	//math_c=40;
	
	index1 = index6;
	math_b=0x0;
	math_c = Customer_Pannal_Data_Count*4 + 16; //重第0個開始計算
	for(math_a=0;math_a<math_c;math_a++)
	{	
		math_b+=(*index1-0x30);
		index1++;	
	}
	math_a=math_b;
	//-----------------------------------------------------------------------------	
	*index3 = ((math_a&0xF0)>>4);	
	if( (*index3 ) >= 0 && (*index3 ) <= 9)
	{
		*index3 += 0x30;
	}
	else
	{
		*index3 += 0x37;
	}
	index3++;
	
	*index3 = (math_a&0xF);	
	if( (*index3) >= 0 && (*index3) <= 9)
	{
		*index3+= 0x30;
	}
	else
	{
		*index3+= 0x37;
	}
	
	
	
}	

unsigned int  Get_Capacity_To_Voltage_variable(void)
{
	unsigned long math_a;
	unsigned int 	math_b;
	math_a=0;
	if(IC_Data.Save_struct.Now_Total_Capacity>Battery_Capacity_Low)
	{
		math_b=(IC_Data.Save_struct.Now_Total_Capacity-Battery_Capacity_Low);
	}
	else
	{
		math_b=(Battery_Capacity_Low-IC_Data.Save_struct.Now_Total_Capacity);
	}
	math_a=(Fake_FULL_Battery_Capacity_Voltage-Fake_Battery_NO_Capacity_Voltage);
	
	math_a	=	math_a*1000/math_b;
	math_b = math_a;
	return math_b;	
}


unsigned int Capacity_To_Voltage_Fuctione(unsigned int Colom)
{
	unsigned long math_a,math_c;
	unsigned int 	math_b;	
	math_a = Colom;
	if(Colom<=Battery_Capacity_Low)
	{
		math_a = (Battery_Capacity_Low-math_a)*	IC_Data.Save_struct.Capacity_To_Voltage;
		math_c = Fake_Battery_NO_Capacity_Voltage;
		math_c = math_c *1000;
		math_a = math_c - math_a;
		math_a = math_a /1000;	
		return math_a;
	}
	else
	{
		math_a = (math_a-Battery_Capacity_Low)*	IC_Data.Save_struct.Capacity_To_Voltage;
		math_c =	Fake_Battery_NO_Capacity_Voltage;
		math_c =math_c *1000;
		math_a = math_a +  math_c;
		math_a = math_a /1000;	
		return math_a;	
	}
}


void IC_Return_Pannal(void)//IC接收到面板的回傳資料，並且要回應面板說我收到了	
{
	unsigned int math_b;
	static unsigned char Count=0,math_a;
	Count++;
	Sent_struct.RIF=0;

	
	Sent_struct.Data_Address=&Word5[0];
	Sent_struct.RTIndex=0;
	Sent_struct.Index=sizeof(Word5);
	Sent_struct.TIF=0;		
	//math_a=*Sent_struct.Data_Address;
	
	math_a = IC_Data.Return_ID;
	U2TXREG = math_a;

	Sent_struct.RTIndex++;
	Sent_struct.Data_Address++;
}


void Receive_Customer_Pannal(void)
{
	unsigned char *index1,*index2,Same_IF;
	unsigned int math_a,math_b,math_c;
	Sent_struct.NO_RESPONSE_Time=0;
	
	//如果CRC錯誤，則等待1秒慢慢傳3次
	//如果資料錯誤也是3次
	//如果是ID錯誤 會立馬要重傳包含原本的算起來3次
	//如果是15 也會立馬要重傳包含原本的算起來3次
	if(BMS_Return_Data.CHAR[0]==0x15)//BMS回應資料錯誤
	{
		Sent_struct.ERRIF=1;
		if(Sent_struct.Count==0)
		{
			math_b=Coulomb_Read_Data_Timer;
			math_c=Sent_Data_TO_BMS_Time;				
			Coulomb_Data.Read_Timer=math_c-(math_b-Coulomb_Data.Read_Timer);				
			Sent_struct.Count++;
		}
		Sent_Data_To_PLC();
	}
	else
	{
		if(Sent_struct.RTIndex==7)
		{
			index1=&Word3[0];
			index2=&BMS_Return_Data.Word7_struct.Start;
			Same_IF=1;
			//確認回傳接收的資料是否吻合 ▼0x06▼0000▼0x0D▼▼0x0A▼
			for(math_a=0;math_a<Sent_struct.RTIndex;math_a++)
			{
				math_b=*index1;
				math_c=*index2;
				if(math_b != math_c) 
				{
					if (math_a==0)
					{
						IC_Data.Return_ID=math_c;
					}
					else
					{
						IC_Data.Return_ID=0x06;
						Same_IF = 0;
						Sent_struct.ERRIF=1;						
					}

				}
				index1++;
				index2++;
			}
			if(Same_IF)
			{
				
				if(Sent_struct.Count>0)
				{
					math_b=Coulomb_Read_Data_Timer;
					math_c=Sent_Data_TO_BMS_Time;				
					Coulomb_Data.Read_Timer=math_b-(math_c-Coulomb_Data.Read_Timer);					
				}				
				Sent_struct.RIF=1;
				Sent_struct.Count=0;
				Sent_struct.RTIndex=0;
				Sent_struct.Index=0;
			
			}
			else//
			{	

			//	Sent_struct.RIF=1;
			//	Sent_struct.Count=0;
				Sent_struct.RTIndex=0;
				Sent_struct.Index=0;
				Sent_struct.ERRIF=1;
				if(Sent_struct.Count==0)
				{
					Sent_struct.Count++;
					math_b=Coulomb_Read_Data_Timer;
					math_c=Sent_Data_TO_BMS_Time;					
					Coulomb_Data.Read_Timer=math_c-(math_b-Coulomb_Data.Read_Timer);					
				}				
			}
		}
		else if(Sent_struct.RTIndex==30)
		{
			index1=&Word4[0];
			index2=&BMS_Return_Data.Word31_struct.Start;
			Same_IF=1;
			for(math_a=0;math_a<Sent_struct.RTIndex;math_a++)
			{
				math_b=*index1;
				math_c=*index2;
				if(math_b != math_c)
				{
					Same_IF = 0;
					Sent_struct.ERRIF=1;
				}
				index1++;
				index2++;			
			}
			if(Same_IF)
			{
				
				if(Sent_struct.Count>0)
				{
					math_b=Coulomb_Read_Data_Timer;
					math_c=Sent_Data_TO_BMS_Time;				
					Coulomb_Data.Read_Timer=math_b-(math_c-Coulomb_Data.Read_Timer);					
				}				
		
				Sent_struct.RIF=0;
				Sent_struct.Count=0;
				Sent_struct.RTIndex=0;
				Sent_struct.Index=0;
				IC_Return_Pannal();
	
			}
			else
			{

				//Sent_struct.RIF=0;
				//Sent_struct.Count=0;
				Sent_struct.RTIndex=0;
				Sent_struct.Index=0;
				Sent_struct.ERRIF=1; 
				if(Sent_struct.Count==0)
				{
					Sent_struct.Count++;
					math_b=Coulomb_Read_Data_Timer;
					math_c=Sent_Data_TO_BMS_Time;				
					Coulomb_Data.Read_Timer=math_c-(math_b-Coulomb_Data.Read_Timer);						
				}				
			}
			
		}
		else
		{
				Sent_struct.RIF=1;
				Sent_struct.Count=0;
				Sent_struct.RTIndex=0;
				Sent_struct.Index=0;
	
		}	
	}

}
	
	
	
	
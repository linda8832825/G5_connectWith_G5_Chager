#include "../Main_Define.H"


void Conversion_Data_to_BMS(void)
{
	unsigned int math_a,math_b,math_c,*index4;
	unsigned char *index1,*index2,*index3,*index5,*index6,Sizeof_Data_Count;//Data_Count資料數量
	int math_d;
	static unsigned char math_e,Over_charge_Voltage_Count,Charge_Voltage_Count=0;

	math_c = Customer_Pannal_Data_Count;
	
	if(math_c==12)//12個項目
	{
		index1 = &Customer_Pannal_12.Start;
		index2 = &Word;
		index3 = &Customer_Pannal_12.Check_SUM2;	
		index5 = &Customer_Pannal_12.S1_1; 
		index6 = &Customer_Pannal_12.CHAR1;
		Customer_Pannal_12.CHAR16=0x43;
		Customer_Pannal_12.END_Word1=0x0D;
		Customer_Pannal_12.END_Word2=0x0A;
	}
	else//10個項目
	{
		index1 = &Customer_Pannal_10.Start;
		index2 = &Word;			
		index3 = &Customer_Pannal_10.Check_SUM2;
		index5 = &Customer_Pannal_10.S1_1; 
		index6 = &Customer_Pannal_10.CHAR1;		
		Customer_Pannal_10.CHAR16=0x41;
		Customer_Pannal_10.END_Word1=0x0D;
		Customer_Pannal_10.END_Word2=0x0A;
	}
	math_a=Coulomb_Data.Battery_Power/100; //電池容量   只要小數點第一位
	Coulomb_Data.Battery_Power=math_a;
	
	
	
	
	math_a=Coulomb_Data.Temperature1/10; 	//溫度    不要小數點
	Coulomb_Data.Temperature1=math_a;	
	if(Coulomb_Data.Temperature1>=Start_Fan_Level)Original_Data.Item3Bits.FAN=1;
	else Original_Data.Item3Bits.FAN=0;
	
	
	if(Coulomb_Data.Current_Point==4)math_a = Coulomb_Data.Current/1000;	 	//電流    只留小數點1位	
	else if(Coulomb_Data.Current_Point==3)math_a = Coulomb_Data.Current/100;	 			//電流    只留小數點1位
	else if(Coulomb_Data.Current_Point==2)math_a = Coulomb_Data.Current/10;	 	//電流    只留小數點1位
	else if(Coulomb_Data.Current_Point==1)math_a = Coulomb_Data.Current;	 		//電流    只留小數點1位
	else if(Coulomb_Data.Current_Point==0)math_a = Coulomb_Data.Current*10;	 	//電流    只留小數點1位	
    else math_a=0;
    Coulomb_Data.Current = math_a;	

	if(Coulomb_Data.Voltage_Point==4)math_a = Coulomb_Data.Voltage/1000;	 	//電壓    只留小數點1位	
	else if(Coulomb_Data.Voltage_Point==3)			math_a = Coulomb_Data.Voltage/100;	 			//電壓    只留小數點1位
	else if(Coulomb_Data.Voltage_Point==2)math_a = Coulomb_Data.Voltage/10;		//電壓    只留小數點1位
	else if(Coulomb_Data.Voltage_Point==1)math_a = Coulomb_Data.Voltage;	 		//電壓    只留小數點1位
	else if(Coulomb_Data.Voltage_Point==0)math_a = Coulomb_Data.Voltage*10 ;	//電壓    只留小數點1位	
    else math_a=0;
	 Coulomb_Data.Voltage = math_a;
	
	IC_Data.Charge_Voltage_Struct[IC_Data.Charge_Voltage_Avg_Count] = Coulomb_Data.Voltage;
	IC_Data.Charge_Voltage_Avg_Count++;	
	if(IC_Data.Charge_Voltage_Avg!=0 || IC_Data.Charge_Voltage_Avg_Count==4)
	{
		if(IC_Data.Charge_Voltage_Avg_Count==4)IC_Data.Charge_Voltage_Avg_Count=0;
		IC_Data.Charge_Voltage_Avg=0;
		for(math_a=0;math_a<4;math_a++)
		{
			IC_Data.Charge_Voltage_Avg = IC_Data.Charge_Voltage_Avg + IC_Data.Charge_Voltage_Struct[math_a];
		}
		IC_Data.Charge_Voltage_Avg = IC_Data.Charge_Voltage_Avg>>2;	
		Coulomb_Data.Voltage = IC_Data.Charge_Voltage_Avg; 
	}		



		//將電容量轉換成假的電壓值
	math_a = Capacity_To_Voltage_Fuctione(Coulomb_Data.Residual_Electricity+1);		
	IC_Data.Fake_Voltage =	math_a;
	
	if(IC_Data.Fake_Voltage>=590)IC_Data.Fake_Voltage=590;
	
	
	//	Original_Data的用意思先將資料整理準備好，放在這裡，等等比較好處理
	//需要的資料 ====>  Original_Data
	math_a = Voltage_Mode;
  if(math_a)
  {
		Original_Data.Buffer.Voltage 				=  Coulomb_Data.Voltage;  
  }
  else
  {
		Original_Data.Buffer.Voltage 				= IC_Data.Fake_Voltage;  
  }

	Original_Data.Buffer.Temperature 		= Coulomb_Data.Temperature1;
	Original_Data.Buffer.Battery_Power 	= Coulomb_Data.Battery_Power;
	Original_Data.Buffer.Mounth 				= IC_Data.Save_struct.Month;
	Original_Data.Buffer.Day 						= IC_Data.Save_struct.Day;
	Original_Data.Buffer.Current 				= Coulomb_Data.Current;
	Original_Data.Buffer.Item10 				= 0x19;
	
//	math_a=IC_Data.Save_struct.Now_Total_Capacity/100;
//	math_a=math_a<<12;	
//	math_b=(IC_Data.Save_struct.Now_Total_Capacity%100)/10;
//	math_b=math_b<<8;
//	math_a=math_a|math_b;	
//	math_b=IC_Data.Save_struct.Now_Total_Capacity%10;
//	math_b=math_b<<4;
//	math_a=math_a|math_b;	
//	math_b=0;
//	math_a=math_a|math_b;			
//	Original_Data.Buffer.S_N_2 					= math_a;//前面	
	
	
	
//	math_a=Coulomb_Data.Voltage/100;
//	math_a=math_a<<12;	
//	math_b=(Coulomb_Data.Voltage%100)/10;
//	math_b=math_b<<8;
//	math_a=math_a|math_b;	
//	math_b=Coulomb_Data.Voltage%10;
//	math_b=math_b<<4;
//	math_a=math_a|math_b;	
//	math_b=0;
//	math_a=math_a|math_b;				
//	Original_Data.Buffer.S_N_1 					= math_a;//後面	
	
	
	/***************** 電池 ID ******************/
	math_a=IC_Data.Save_struct.S_N[0];
	math_a=math_a<<12;	
	math_b=IC_Data.Save_struct.S_N[1];
	math_b=math_b<<8;
	math_a=math_a|math_b;	
	math_b=IC_Data.Save_struct.S_N[2];
	math_b=math_b<<4;
	math_a=math_a|math_b;	
	math_b=IC_Data.Save_struct.S_N[3];
	math_a=math_a|math_b;			
	Original_Data.Buffer.S_N_2 					= math_a;//前面	
	
	math_a=IC_Data.Save_struct.S_N[4];
	math_a=math_a<<12;	
	math_b=IC_Data.Save_struct.S_N[5];
	math_b=math_b<<8;
	math_a=math_a|math_b;	
	math_b=IC_Data.Save_struct.S_N[6];
	math_b=math_b<<4;
	math_a=math_a|math_b;	
	math_b=IC_Data.Save_struct.S_N[7];
	math_a=math_a|math_b;				
	Original_Data.Buffer.S_N_1 					= math_a;//後面
	/***************** 電池 ID ******************/
    
/*
	math_a=IC_Data.Save_struct.S_N[0]-0x30;
	math_a=math_a<<12;	
	math_b=IC_Data.Save_struct.S_N[1]-0x30;
	math_b=math_b<<8;
	math_a=math_a|math_b;	
	math_b=IC_Data.Save_struct.S_N[2]-0x30;
	math_b=math_b<<4;
	math_a=math_a|math_b;	
	math_b=IC_Data.Save_struct.S_N[3]-0x30;
	math_a=math_a|math_b;			
	Original_Data.Buffer.S_N_2 					= math_a;//前面	
	
	
	
	math_a=IC_Data.Save_struct.S_N[4]-0x30;
	math_a=math_a<<12;	
	math_b=IC_Data.Save_struct.S_N[5]-0x30;
	math_b=math_b<<8;
	math_a=math_a|math_b;	
	math_b=IC_Data.Save_struct.S_N[6]-0x30;
	math_b=math_b<<4;
	math_a=math_a|math_b;	
	math_b=IC_Data.Save_struct.S_N[7]-0x30;
	math_a=math_a|math_b;				
	Original_Data.Buffer.S_N_1 					= math_a;//後面
*/
	
	
	Original_Data.Buffer.Item1 = 1;
	//Original_Data.Buffer.Item2 = 0;
	//Original_Data.Buffer.Item3 = 0;
	

	
	
	
		
	
	//將前面一些固定的資料擺入要傳送的暫存器
	//前置的固定資料 ====> 	Customer_Pannal_12.Start
	math_a=sizeof(Word)-1;		
	for(math_a=math_a;math_a>0;math_a--)
	{
		*index1=*index2;
		index1++;
		index2++;
	}	
	index1++;
	
	
	//取得整理過後Coulomb_Data(不包含轉換計算)的位置
	//並且將資料由原本的資料拆成一個一個的BYTE，然後放在另一個要整理的區域Customer_Pannal_12.Start
	//Coulomb_Data ====> Customer_Pannal_12.Start
	
	index4 =&	Original_Data.Buffer.Item1;	
	math_a = *index4;
	

	if(Coulomb_Data.Current_statue==1)//電流逆接(放電)
	{	
		if(IC_Data.Count_CSTP==1)
		{
			Original_Data.Item3Bits.CGDS = 1;
			Original_Data.Item3Bits.CSTP = 1;
			IC_Data.Count_CSTP++;
		}
		else
		{	
			IC_Data.Count_CSTP=0;
			Original_Data.Item3Bits.CSTP = 0;
		}		
		if(Original_Data.Buffer.Battery_Power<=ON_CGDS_Warrning || Original_Data.Buffer.Voltage <= ON_CGDS_Voltage_Warrning)
		{
			Original_Data.Item3Bits.CGDS = 0;//原始設計電容量小於66.0時候會亮，我們自己設計是60%提醒電池要預備充電了
		}		
		else
		{
			Original_Data.Item3Bits.CGDS = 1;//原始設計電容量小於66.0時候會亮，我們自己設計是60%提醒電池要預備充電了
		}		
		if(Original_Data.Buffer.Battery_Power<=ON_CHG1_Warrning || Original_Data.Buffer.Voltage <= ON_CHG1_Voltage_Warrning)
		{
			Original_Data.Item3Bits.CHG2 = 1;//原始設計是電容量小於60.2時候會亮，我們自己設計是50%提醒充電
		}	
		else
		{
			Original_Data.Item3Bits.CHG2 = 0;
		}
        if(Original_Data.Buffer.Voltage >= Check_Voltage-4 && Original_Data.Buffer.Voltage <= Check_Voltage){
            if(Original_Data.Buffer.Battery_Power > 72)
            {
                Original_Data.Item3Bits.CHG2 = 1;
            }
            else
            {
                Original_Data.Item3Bits.CHG2 = 0;
            }
        }
        
		Over_charge_Voltage_Count = Count_Over_charge_Voltage;
		
		if(Original_Data.Buffer.Current<110)IC_Data.Car_Statue=0;//待機
		else if(Original_Data.Buffer.Current>=110 && Original_Data.Buffer.Current<=900)IC_Data.Car_Statue=1;//行走
	}
	else//電流正接(充電)
	{	
		if(Original_Data.Buffer.Current>=1500)IC_Data.Car_Statue=3;//充電
		else if(Original_Data.Buffer.Current<180)IC_Data.Car_Statue=0;//待機
		
		
		Original_Data.Item3Bits.CGDS = 0;//充電時候CGDS要關閉
		Original_Data.Item3Bits.CHG2 = 0;//充電時候CHG1要關閉		
		
		if(IC_Data.Charge_Voltage_Avg!=0)
		{
			
			//if()//如果庫倫計讀到的電壓，超過預設的滿電電壓值 或者充電流流小於150A時候
		//	if(Original_Data.Buffer.Battery_Power>=FULL_Charge	 || Coulomb_Data.Voltage >= FULL_Battery_Capacity_Voltage  || Original_Data.Buffer.Current <FULL_Battery_Capacity_Current )//如果庫倫計讀到的電壓，超過預設的滿電電壓值 或者充電流流小於150A時候
			if(Coulomb_Data.Voltage >= FULL_Battery_Capacity_Voltage  || Original_Data.Buffer.Current <FULL_Battery_Capacity_Current )//如果庫倫計讀到的電壓，超過預設的滿電電壓值 或者充電流流小於150A時候
			{	
				if(Over_charge_Voltage_Count)
				{
					Over_charge_Voltage_Count--;
					if(Over_charge_Voltage_Count==0)
					{	
						IC_Data.Count_CSTP=1; //送第一次
						Original_Data.Item3Bits.CSTP = 1;					
						
						
						IC_Data.Save_struct.Now_Total_Capacity = Coulomb_Data.Residual_Electricity  ;	//將目前的電容量值存到目前的總電容量
						if(Coulomb_Data.Residual_Electricity<=(IC_Data.Save_struct.Now_Total_Capacity-5))//當電池老化之後，電容量值會降低，這邊是作電容值降低以後的重新紀錄
						{
						//	IC_Data.Save_struct.Now_Total_Capacity=Coulomb_Data.Residual_Electricity;	//將目前的電容量值存到目前的總電容量
							if(IC_Data.Save_struct.Now_Total_Capacity<=ON_MENT_Warrning)Original_Data.Item3Bits.MENT = 1; //如果目前總容量剩餘不到ON_MENT_Warrning時候起動警告
							IC_Data.Save_struct.Capacity_To_Voltage=Get_Capacity_To_Voltage_variable();	
							IC_Data_Save_IF.Now_Total_Capacity_IF = 1;
							IC_Data_Save_IF.Capacity_To_Voltage_IF = 1;
//							EEPROM.Save_Count=5000;						
						}							
					}
				}						
			}	
			else
			{
				Original_Data.Item3Bits.CSTP = 0;
				Over_charge_Voltage_Count=5;
			}			
		}
	}	











	for(math_b=0;math_b<Customer_Pannal_Data_Count;math_b++)
	{
		if(math_b==8)
		{
			/*
			if(Coulomb_Data.Current_statue==0)//電流逆接(放電)
			{		
				math_a=0xFFFF-math_a+1;	
			}		
			*/
			if(Coulomb_Data.Current_statue==1)//電流逆接(放電)
			{		
				math_a=0xFFFF-math_a+1;	
			}				
			
			
		}
		*index1 = (math_a&0xF000)>>12;
		index1++;	
		*index1 = (math_a&0xF00)>>8;
		index1++;	
		*index1  = (math_a&0xF0)>>4;
		index1++;	
		*index1  = math_a&0xF;		
		index1++;
		index4++;
		math_a = *index4;	
	}

	
	
	
	
	
	//---------------------將資料由數值BYTE轉換成文字---------------------------------
	math_c = Customer_Pannal_Data_Count*4;
	index1 = index5;
//	index1 = &Customer_Pannal_10.S1_1;
	for(math_a=0;math_a<math_c;math_a++)
	{	
		if( (*index1) >= 0 && (*index1) <= 9)
		{
			*index1=*index1+0x30;
		}
		else
		{
			*index1=*index1+0x37;
		}
		index1++;	
	}
	
	
	//-----------------------------------------------------------------------------
	//--------------------------計算出CHECK_SUM-----------------------------------
	//index1 = &Customer_Pannal_10.CHAR1;
	//math_b=0x00F6;
	//math_c=40;
	Get_CHeck_SUM();
		




}
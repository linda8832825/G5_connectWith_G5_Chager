#ifndef Customer_Pannal_define_H
#define Customer_Pannal_define_H

typedef struct tagLCD_Data_struct10 {	
	union
	{
		unsigned char 	CHAR[61];	
		struct
		{
			unsigned char 	Start;	
			unsigned char 	CHAR1;	
		  unsigned char 	CHAR2;  
			unsigned char 	CHAR3;	
		  unsigned char 	CHAR4; 		  
			unsigned char 	CHAR5;	
		  unsigned char 	CHAR6;  
			unsigned char 	CHAR7;	
		  unsigned char 	CHAR8; 		  
			unsigned char 	CHAR9;	
		  unsigned char 	CHAR10;  
			unsigned char 	CHAR11;	
		  unsigned char 	CHAR12; 		  
		  unsigned char 	CHAR13;  
			unsigned char 	CHAR14;	
		  unsigned char 	CHAR15; 
		  unsigned char 	CHAR16; 		  			  
			unsigned char 	S1_1;	
		  unsigned char 	S1_2;  
			unsigned char 	S1_3;	
		  unsigned char 	S1_4; 		  
			unsigned char 	S2_1;	
		  unsigned char 	S2_2;  
			unsigned char 	S2_3;	
		  unsigned char 	S2_4; //23
			unsigned char 	S3_1; //24
		  unsigned char 	S3_2;  
			unsigned char 	S3_3;	
		  unsigned char 	S3_4; 		  
		  unsigned char 	Voltage4;  
			unsigned char 	Voltage3;	
		  unsigned char 	Voltage2; 			  
			unsigned char 	Voltage1;	
		  unsigned char 	Temp4;  
			unsigned char 	Temp3;	
		  unsigned char 	Temp2; 		  
			unsigned char 	Temp1;	
		  unsigned char 	Battery_Capacity4;  
			unsigned char 	Battery_Capacity3;	
		  unsigned char 	Battery_Capacity2; 		  
			unsigned char 	Battery_Capacity1;	
		  unsigned char 	Month4;  
			unsigned char 	Month3;	
		  unsigned char 	Month2; 		  
			unsigned char 	Month1;	 
			unsigned char 	Day4;	
		  unsigned char 	Day3; 			  
		  unsigned char 	Day2; 		  
			unsigned char 	Day1;	
		  unsigned char 	Current4;  
			unsigned char 	Current3;	
		  unsigned char 	Current2; 
		  unsigned char 	Current1; 	
			unsigned char 	S4_1; //24
		  unsigned char 	S4_2;  
			unsigned char 	S4_3;	
		  unsigned char 	S4_4;
		  unsigned char 	Check_SUM2; 
		  unsigned char 	Check_SUM1; 
		  unsigned char 	END_Word1;
		  unsigned char 	END_Word2;			  	  			  
		};											
	};	
	
}LCD_Data_define10;

extern LCD_Data_define10 Customer_Pannal_10; 



typedef struct tagLCD_Data_struct12 {	
	union
	{
		unsigned char 	CHAR[69];	
		struct
		{
			unsigned char 	Start;	
			unsigned char 	CHAR1;	
		  unsigned char 	CHAR2;  
			unsigned char 	CHAR3;	
		  unsigned char 	CHAR4; 		  
			unsigned char 	CHAR5;	
		  unsigned char 	CHAR6;  
			unsigned char 	CHAR7;	
		  unsigned char 	CHAR8; 		  
			unsigned char 	CHAR9;	
		  unsigned char 	CHAR10;  
			unsigned char 	CHAR11;	
		  unsigned char 	CHAR12; 		  
		  unsigned char 	CHAR13;  
			unsigned char 	CHAR14;	
		  unsigned char 	CHAR15; 
		  unsigned char 	CHAR16; 		  			  
			unsigned char 	S1_1;	
		  unsigned char 	S1_2;  
			unsigned char 	S1_3;	
		  unsigned char 	S1_4; 		  
			unsigned char 	S2_1;	
		  unsigned char 	S2_2;  
			unsigned char 	S2_3;	
		  unsigned char 	S2_4; 
			unsigned char 	S3_1; 
		  unsigned char 	S3_2;  
			unsigned char 	S3_3;	
		  unsigned char 	S3_4; 		  
		  unsigned char 	Voltage4;  
			unsigned char 	Voltage3;	
		  unsigned char 	Voltage2; 			  
			unsigned char 	Voltage1;	
		  unsigned char 	Temp4;  
			unsigned char 	Temp3;	
		  unsigned char 	Temp2; 		  
			unsigned char 	Temp1;	
		  unsigned char 	Battery_Capacity4;  
			unsigned char 	Battery_Capacity3;	
		  unsigned char 	Battery_Capacity2; 		  
			unsigned char 	Battery_Capacity1;	
		  unsigned char 	Month4;  
			unsigned char 	Month3;	
		  unsigned char 	Month2; 		  
			unsigned char 	Month1;	 
			unsigned char 	Day4;	
		  unsigned char 	Day3; 			  
		  unsigned char 	Day2; 		  
			unsigned char 	Day1;	
		  unsigned char 	Current4;  
			unsigned char 	Current3;	
		  unsigned char 	Current2; 
		  unsigned char 	Current1; 	
			unsigned char 	S4_1; 
		  unsigned char 	S4_2;  
			unsigned char 	S4_3;	
		  unsigned char 	S4_4;
		  unsigned char 	SN_1;
		  unsigned char 	SN_2;		  
		  unsigned char 	SN_3;
		  unsigned char 	SN_4;
		  unsigned char 	SN_5;
		  unsigned char 	SN_6;		  	
		  unsigned char 	SN_7;
		  unsigned char 	SN_8;		  		  
		  unsigned char 	Check_SUM2; 
		  unsigned char 	Check_SUM1; 
		  unsigned char 	END_Word1;
		  unsigned char 	END_Word2;			  	  			  
		};											
	};	

}LCD_Data_define12;

extern LCD_Data_define12 	Customer_Pannal_12;
 
typedef struct tagOriginal_Data {	
 	union
	{
		struct
		{
			unsigned int Item1;								//  
			unsigned int Item2;								//  
			unsigned int Item3;								//  
			unsigned int Voltage;							//  電壓	0.000~50.000V or 50.00~400.00V
			unsigned int Temperature;					//  溫度	-55.0~125.0	
			unsigned int Battery_Power;				//  百分比或剩餘電量0.00~100.00%			
			unsigned int Mounth;							//  月份
			unsigned int Day;									//  日期
			unsigned int Current;							//  電流	0.000~50.000A or 50.00~655.35A	
			unsigned int Item10;							//  
			unsigned int S_N_1;							//
			unsigned int S_N_2;							//
		}Buffer;
		struct
		{
			unsigned    :16;
			unsigned		UCHG:1;
			unsigned		OCHG:1;			
			unsigned		TEMP:1;			
			unsigned		LOWV:1;
			unsigned		CHGN:1;			
			unsigned		CHGW:1;			
			unsigned		MMAT:1;			
			unsigned		THER:1;
			unsigned		CT:1;
			unsigned		COMB:1;
			unsigned		BATER:1;
			unsigned		BMSER:1;																		
		}Item2Bits;	
		struct
		{
			unsigned    :16;
			unsigned    :16;	
					
			unsigned		CHG0:1;
			unsigned		CHG1:1;			
			unsigned		CHG2:1;			
			unsigned		MENT:1;
			unsigned		CIDS:1;
			unsigned		CSTP:1;						
			unsigned		:1;			
			unsigned		FAN:1;			
			unsigned		ROM:1;
			unsigned		COMM:1;
			unsigned		CGDS:1;																		
		}Item3Bits;						
	};
}Original_Data_define;
extern Original_Data_define 	Original_Data;



typedef struct tagBMS_Return_Data {	
	union
	{
		unsigned char 	CHAR[30];	
		struct
		{
		  unsigned char 	Start;	
		  unsigned char 	Word1;
		  unsigned char 	Word2;
		  unsigned char 	Word3;
		  unsigned char 	Word4;
		  unsigned char 	Word5;
		  unsigned char 	Word6;
		  unsigned char 	Word7;
		  unsigned char 	Word8;
		  unsigned char 	Word9;
		  unsigned char 	Word10;
		  unsigned char 	Word11;
		  unsigned char 	Word12;
		  unsigned char 	Word13;
		  unsigned char 	Word14;	
		  unsigned char 	Word15;
		  unsigned char 	Word16;
		  unsigned char 	Word17;
		  unsigned char 	Word18;
		  unsigned char 	Word19;
		  unsigned char 	Word20;
		  unsigned char 	Word21;	
		  unsigned char 	Word22;
		  unsigned char 	Word23;
		  unsigned char 	Word24;
		  unsigned char 	Word25;
		  unsigned char 	Word26;		  		  		  		  		  		  		  		  
		  unsigned char 	Check_SUM2; 
		  unsigned char 	Check_SUM1; 
		  unsigned char 	END_Word1;
		  unsigned char 	END_Word2;			  	  			  
		}Word31_struct;				
		struct
		{
		  unsigned char 	Start;	
		  unsigned char 	Word1;
		  unsigned char 	Word2;
		  unsigned char 	Word3;
		  unsigned char 	Word4;  		  		  		  		  		  		  
		  unsigned char 	END_Word1;
		  unsigned char 	END_Word2;			  	  			  
		}Word7_struct;		
		struct
		{
		  unsigned char 	Start;	
		  unsigned char 	Word1;
		  unsigned char 	Word2;
		  unsigned char 	Word3;
		  unsigned char 	Word4; 
		  unsigned char 	Word5; 		  		  		  		  		  		  		  
		  unsigned char 	END_Word1;
		  unsigned char 	END_Word2;			  	  			  
		}Word8_struct;											
	};	
}BMS_Return_Data_define;
extern BMS_Return_Data_define BMS_Return_Data;

typedef struct tagSent_struct {	
	union
	{
		struct
		{		
			unsigned						IF:3;	
			unsigned						:1;
		};
		struct
		{
			unsigned  			 	TIF 		:1;		//資料傳送完成
			unsigned  			 	RIF 		:1;		//資料接收完成
			unsigned  			 	ERRIF		:1;	//資料接收或傳送錯誤		
			unsigned  			 	BusyIF	:1;	//	
			unsigned  			 	End_Flag:2;	//結束旗標	
			unsigned  			 	W_R			:2;	//0=W 1=讀 2=保留 3=保留					
		};
	};
	
	struct
	{		
		unsigned						Sent_Count:3;
		unsigned						Count:4;	
	};	
	unsigned char Index;					//要收資料
  unsigned char RTIndex;					//已收資料 	
  unsigned char *Data_Address;				//資料擺放位置
  unsigned char *Recent_Data_Address;				//資料擺放位置  
  unsigned int NO_RESPONSE_Time;			//沒有回應的倒數計時	
}Sent_struct_define;
extern Sent_struct_define Sent_struct; 

extern unsigned char const Word[17]; 
extern unsigned char const Word2[21]; 
extern unsigned char const Word3[7]; 
extern unsigned char const Word4[30];
extern unsigned char const Word5[7];



unsigned int  Get_Capacity_To_Voltage_variable(void);
unsigned int Capacity_To_Voltage_Fuctione(unsigned int Colom);
void Receive_Customer_Pannal(void);
void Conversion_Data_to_BMS(void);
void Sent_Data_To_Pannal(void);

#endif

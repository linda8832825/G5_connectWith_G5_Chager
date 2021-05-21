#ifndef Moxa_define_H
#define Moxa_define_H

#define Fuc_Erro				0x01
#define Reg_Add_Erro		0x02
#define Value_Erro			0x03
#define NoConnect_Erro	0x07
#define CRC_Erro				0x08
#define Lightning_Erro	0x09


typedef struct tagMOXA_Data {	
  unsigned char 	ID;						//編號
  unsigned char 	Fuc;					//功能
	union
	{
		struct
		{
			unsigned char 	Reg_H;	//因為傳輸時候是先傳輸高位元之後再傳輸低位元
		  unsigned char 	Reg_L;  //可是PIC是先從低位元開始擺放，所以會有高低位元交換的問題
		};												//故REG會是整個高低位元顛倒的情況，故之後有個重新整理的運算
		struct
		{
			unsigned char 	Chx;
		  unsigned char 	Regest; 
		};			
	};	  
	union
	{
		struct
		{
		  unsigned char 	Data_H;
			unsigned char 	Data_L;
			unsigned char 	CRC_L;
			unsigned char 	CRC_H;
		};
		
		struct
		{
			unsigned char 	Quantity_H;
		  unsigned char 	Quantity_L; 
		  unsigned char 	Total_Byte; 		   
		};		
		unsigned int DATA[30];	
		unsigned int Quantity;		   	
	};
	union
	{		 
		unsigned int Value;
		struct
		{
		  unsigned char 	Value_L;  
			unsigned char 	Value_H;	  
		};		
	};												
 	union
	{
		unsigned						IF:3;
		unsigned						Return_Mode:2;//回傳是回傳庫倫資料(1) 還是BMS的資料(0)
		struct
		{
			unsigned  			 	TIF :1;		//資料傳送完成
			unsigned  			 	RIF :1;		//資料接收完成
			unsigned  			 	ERRIF:1;	//資料接收或傳送錯誤				
		};
	};
	
  unsigned char Index;						//要收資料
  unsigned char RTIndex;					//已收資料
}MOXA_Data_define;

extern MOXA_Data_define MOXA; 


#endif

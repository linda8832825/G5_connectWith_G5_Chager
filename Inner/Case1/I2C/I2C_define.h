#ifndef I2C_define_H
#define I2C_define_H




#define DriverIC_I2C_Addr		0x10 //24HJ128GP310A
#define CaptureIC_I2C_Addr	0x20 //24FJ128GA006A
#define EROMIC_I2C_Addr			0xA0 //EEPROM	


#define I2CStat		I2C1CONbits.SEN = 1	

#define Comand_write				0
#define Comand_read					1




typedef struct tagI2C_Data_struct {
	union//第一筆資料
	{
		struct
		{
			unsigned  char XX;	
			unsigned  char Address;	
		};		
		struct
		{
			unsigned  char XX;	
		  unsigned  R_W:1;	
		  unsigned  Addr:7;
		};
		struct
		{
		  unsigned  		:1;	
		  unsigned  Ax	:2;
		};		
		struct
		{
			unsigned  char XX;	
		  unsigned  		:1;	
		  unsigned  A0	:1;
		  unsigned  A1	:1;		   
		};		
	};
	union//第二.三筆資料
	{
		struct
		{
		  unsigned  char Addr_H;//第二筆資料
		  unsigned  char Addr_L;//第三筆資料
		};
		struct
		{
			unsigned  char Command_Byte;
			unsigned  char Command_Set;			
		};			
	};
 	union
	{	
		unsigned	int				    ALL_IF;
		unsigned						 Statue_IF:4;			
		struct
		{
			unsigned  							TIF :1;				//資料傳送完成
			unsigned  							RIF :1;				//資料接收完成
			unsigned  					 Busy_IF:1;				//要傳送的裝置處於忙碌中
			unsigned  				 		 ERRIF:1;				//資料接收或傳送錯誤
			unsigned  				Address_IF:1;				//傳送位置
			unsigned  		 		 RStart_IF:1;				//重複啟動
			unsigned  					Data_R_W:1;				//資料要讀 還是寫		
			unsigned  						ASK_IF:1;				//回應對方ASK
			unsigned  					 RCEN_IF:1;				//啟動接收
			unsigned  		Device_Busy_IF:1;				//要傳送的裝置處於忙碌中		
		};
	};
  unsigned char Index1;						//要收或送的資料數量(前面的設定檔)
  unsigned char Index2;						//要收或送的資料數量(後面的資料數)  
  unsigned char RTIndex;					//已收或送的資料數量
  unsigned int Data_Addr;			//要接收或傳送的資料擺放位置，不使用原本的陣列是因為他可以連續，讀取比較方便 
} I2C_Data_struct;
extern  I2C_Data_struct I2C_Data;


extern  unsigned char *I2C_Buffer_index;


void I2C_Initial(void);
void I2C_Write(unsigned int Divice_ID , unsigned int Reg_Addr  , unsigned char *Buff_Addr   ,unsigned char Leng);
void I2C_Read(unsigned int Divice_ID , unsigned int Reg_Addr  ,unsigned char *Buff_Addr , unsigned char Leng);


#endif

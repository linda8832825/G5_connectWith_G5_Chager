#ifndef MAIN_define_H
#define MAIN_define_H



//T1CON 目前用在 計時用
//T2CON 目前用在 庫倫計的接收資料計時器


#include "p24FJ128GA106.h"

#include "./Coulomb/Coulomb_define.h"

#include "./BMS/BMS_define.h"

#include "./Flash/I2C_EEPROM_define.h"

#include "./I2C/I2C_define.h"

#include "./MOXA/MOXA_define.h"


#define Save_Data  						1 //是否要使用以儲存的資料
#define Voltage_Mode  					1 //1=真實資料 0=換算過後


#define Count_Over_charge_Voltage  	5 //超過幾次充電條件之後，判斷為充飽電
#define Bebe_ON 			 				1  // 1
#define Bebe_OFF 			 				0  // 0



#define Normal_Statue_MODE 			1
#define Factory_Test_MODE 				2
#define Boot_MODE 						3
#define ERRO_MODE 						4




#define FULL_Charge						90	//	電池的滿電百分比容量
#define FULL_Battery_Capacity 		525	//	電池的額定滿電容量52.5AH
#define Battery_Capacity_Low 			157//   電池的完全沒電容量15.7AH

#define FULL_Battery_Capacity_Voltage 	  		600//實際庫倫充飽電時候的電壓值60.0V
#define Fake_FULL_Battery_Capacity_Voltage 	580//偽造電壓充飽電時候的電壓值58.0V
#define Fake_Battery_NO_Capacity_Voltage 		460//偽造電壓沒電時候的電壓值46.0V

#define FULL_Battery_Capacity_Current 	  		150//充飽電時候的電流值<150A


#define ON_CHG1_Warrning							65  //啟動CHG1的最低界線(電容量百分比)67啟動後，到達充電站約剩65%
#define ON_CHG1_Voltage_Warrning                    530 //啟動CHG1的最低界線(電壓) 單電芯約 3.11v  
#define ON_CGDS_Warrning							90  //啟動CGDS的最低界線(電容量百分比)65
#define ON_CGDS_Voltage_Warrning					544 //啟動CGDS的最低界線(電壓) 單電芯約 3.17v
#define ON_MENT_Warrning							350 //啟動MENT的最低界線(是實際電容量不是電容量百分比)
#define Check_Voltage                               547 //檢查點


#define Coulomb_Read_Data_Timer 					1800    	//讀取庫倫計的間隔時間
#define Sent_Data_TO_BMS_Time 					1000			//如果電池傳送到面板(PLC)沒有回應的話，下次再傳送的等待時間
#define Coulomb_No_Reback_Time 					700			//要等待多久才會判定庫倫計沒有回應資料
#define Sent_Data_TO_PLC_NO_RESPONSE_Time 	700   	//如果電池傳送到面板(PLC)要等待多久之後才會確認是沒有回應的時間

#define Start_Fan_Level 							35    //溫度到達幾度後要啟動風扇




/*
#define FULL_Battery_Capacity 				525	//	電池的額定滿電容量52.5AH
#define Battery_Capacity_Low 					250//把總額的52.5降成50計算，乘以50% =25.0AH
#define FULL_Battery_Capacity_Voltage 580//充飽電時候的電壓值58.0V
#define Battery_NO_Capacity_Voltage 	465//沒電時候的電壓值46.5V
*/

#define LED_ON 				0
#define LED_OFF 				1

#define SW_Push 				0
#define SW_NoPush 			1

#define Output 				0
#define Input 					1
#define Customer_Pannal_Data_Count 					12 //總共有兩種版本 1:資料項目有12個(0x0C)   0:資料項目有10個(0x0A)


#define Flick_Fast 			2000  //越小越快
#define Flick_Middle 		5000
#define Flick_Slow 			8000
#define Brightness_Hz 		100
#define Flick_Freq 			Flick_Slow 


#define DimmyX1 				10//Brightness_Hz/10;
#define Battery_Led_Dimmy		1 //電量顯示的LED亮度 1~10  1最暗 10最亮 


typedef struct tagIC_data_Struct {
	
	struct
	{	
		unsigned 	int		Now_Total_Capacity;			//當下的電池滿電時候的正確容量
		unsigned 	int		Capacity_To_Voltage;		//電容量轉換成電壓計算變數
		unsigned 	int		Battery_Ohm;						//
		unsigned 	int		X1;						//保留		
		unsigned 	int		X2;		//保留		
		unsigned 	int		X3;		//保留			
		unsigned 	char	Struct1_index;		//儲存資料頁3指標
		unsigned 	char	Struct2_index;		//儲存資料頁4指標		
		unsigned 	char	Battery_ID;				//電池ID(或是車號),可由客戶自己輸入
		unsigned 	char	X7;		//保留					
		unsigned 	int 	Month;
		unsigned 	int 	Day;
		unsigned 	char 	Hour;
		unsigned 	char 	minute;
		unsigned 	char 	X8[10];
		unsigned 	char 	S_N[12];
	}Save_struct;		
	
	unsigned 	char 	Second;	
	unsigned 	int 	ms;			
	unsigned 	int		Car_Statue;						//車子目前在幹嘛
	unsigned 	int 	Fake_Voltage;					
	unsigned 	int 	Wait_Coulomb_Read;		//剛開機等待庫倫計完成開機的延遲時間，順便用這個時間來製造逼逼聲的間隔
	unsigned 	int 	Coulomb_No_Reback;
	unsigned 	char 	Return_ID;						//回應時候所需要的ID
	unsigned 	int 	Timer0_Count;	
	unsigned 	int 	Timer1_Count;
	unsigned 	int 	Timer2_Count;
	unsigned 	int 	Timer3_Count;		
	unsigned 	int 	Charge_Voltage_Struct[8];		
	unsigned 	int 	Charge_Voltage_Avg;
	unsigned 	char 	Charge_Voltage_Avg_Count;			
	struct
	{		
		union
		{
			unsigned 	char			IF;
			struct
			{	
				unsigned 	NowChargingMode:1;//1充電中 0放電中
			};							
		};	
		struct
		{					
			unsigned 	char 	Hour;
			unsigned 	char 	minute;
			unsigned 	char 	Second;	
			unsigned 	int 	Timer;		
		};
	}Charging;		
	
	unsigned 	int Real_Coulomb_Data_Voltage;
	
	struct
	{
		unsigned 	Timer0_Count_IF:1;			//可以用來計時用	
		unsigned 	Timer1_Count_IF:1;			//可以用來計時用	
		unsigned 	Timer2_Count_IF:1;			//可以用來計時用	
		unsigned 	Timer3_Count_IF:1;			//可以用來計時用
		unsigned 	IC_MODE_LED_SET:3;			//紀錄目前LED顯示的IC狀態
		
	};	
	unsigned 	char 	Count_CSTP; //計算次數用
	unsigned 	char 	My_ID;
		
}IC_data_Define;
extern IC_data_Define IC_Data;






typedef struct tagIC_Data_IF {
 	union
	{	
		unsigned long All_IF;
		struct
		{
			unsigned 	Struct_IF1 							:10;
			unsigned 	Struct_IF2 							:5;
			unsigned 	Struct_IF3 							:1;
		};					
		struct
		{
			unsigned 	Now_Total_Capacity_IF		:1; //1
			unsigned 	Capacity_To_Voltage_IF	:1; //2
			unsigned 	Battery_Ohm_IF					:1; //3		
			unsigned 	X1_IF										:1; //4
			unsigned 	X2_IF										:1; //5
			unsigned 	X3_IF										:1; //6
			unsigned 	Struct1_index_IF				:1;	//7	 
			unsigned 	Struct2_index_IF				:1; //8
			unsigned 	Battery_ID_IF						:1; //9
			unsigned 	X7_IF										:1; //10
			unsigned 	Month_IF								:1;	//11
			unsigned 	Day_IF									:1;	//12
			unsigned 	Hour_IF									:1;	//13		
			unsigned 	minute_IF								:1;	//14
			unsigned 	X8_IF										:1; //15		
			unsigned 	S_N_IF									:1;	//16
//----------------------------------------------------													
		};
	};
			
}IC_Data_IF;		
extern IC_Data_IF IC_Data_Save_IF;




typedef struct tagLED_Statue_Struct {
	
	struct
	{	
		unsigned 	int 	HZ_TO_Count;		//	
		unsigned 	int 	Count;					//		
		unsigned 	int 	Freq;						//						
		unsigned 				Stat_IF:1;			//
	}G_Flick;			
	struct
	{		
		unsigned 	int 	HZ_TO_Count;		//	
		unsigned 	int 	Count;					//		
		unsigned 	int 	Freq;						//						
		unsigned 				Stat_IF:1;			//
	}R_Flick;		
	struct
	{	
		unsigned 	int 	HZ_TO_Count;		//	
		unsigned 	int 	Count;					//		
		unsigned 	int 	Freq;						//						
		unsigned 				Stat_IF:1;			//
	}B_Flick;					


	struct
	{	
		unsigned 	char Dimmy;			//	0~10階
		unsigned 	int  Count;//		
		unsigned 	Stat_IF:1;			//
	}Battery_Led;		
	
	
}LED_Statue_Define;
extern LED_Statue_Define LED_Statue;




#define TRISE_Bebe TRISDbits.TRISD1
#define Bebe 			 LATDbits.LATD1

#define TRISE_LED_Green 		TRISBbits.TRISB3 	
#define TRISE_LED_Blue 			TRISBbits.TRISB4
#define TRISE_LED_Red 			TRISBbits.TRISB5 
#define LED_Green 					LATBbits.LATB3
#define LED_Blue 						LATBbits.LATB4
#define LED_Red 						LATBbits.LATB5



#define TRISE_LED_Battery0 	TRISBbits.TRISB8 	//D5
#define TRISE_LED_Battery1 	TRISBbits.TRISB9	//D6
#define TRISE_LED_Battery2 	TRISBbits.TRISB10 //D7
#define TRISE_LED_Battery3 	TRISBbits.TRISB11 //D8
#define TRISE_LED_Battery4 	TRISBbits.TRISB12 //D9
#define LED_Battery0 	LATBbits.LATB8 					//D5
#define LED_Battery1 	LATBbits.LATB9					//D6
#define LED_Battery2 	LATBbits.LATB10 				//D7
#define LED_Battery3 	LATBbits.LATB11 				//D8
#define LED_Battery4 	LATBbits.LATB12 				//D9


#define TRISE_SW1_Bootloader		TRISEbits.TRISE7	
#define TRISE_SW2_Factory_Test 	TRISEbits.TRISE6 
#define TRISE_SW3_Reset		 			TRISEbits.TRISE5




#define SW1_Bootloader		PORTEbits.RE7
#define SW2_Factory_Test 	PORTEbits.RE6
#define SW3_Reset		 			PORTEbits.RE5



 



#define TRISE_IO_0		 		TRISEbits.TRISE4
#define TRISE_IO_1				TRISEbits.TRISE3	
#define TRISE_IO_2		 		TRISEbits.TRISE2
#define TRISE_IO_3				TRISEbits.TRISE1 
#define TRISE_IO_4				TRISEbits.TRISE0 		
#define TRISE_IO_5		 		TRISFbits.TRISF1

#define TRISE_IO_5		 		TRISFbits.TRISF1

#define TRISE_U1RX		 		TRISFbits.TRISF2
#define TRISE_U1TX		 		TRISFbits.TRISF3

#define TRISx_SCL		 		TRISGbits.TRISG2
#define TRISx_SDA		 		TRISGbits.TRISG3

#define LATx_SCL		 		LATGbits.LATG2
#define LATx_SDA		 		LATGbits.LATG3

















void Initial_Clock(void); 
void Initial_IO(void);
void Initial_Coulomb_UART(void);
void Initial_MOXA_UART(void);
void Timer1_initial(void);
void Initial_UART2(void);
void I2C_Initial(void);	
void Unlock_Coulomb(void);
void feedback_MOXA_Data(unsigned char *readAddress);
	
#endif

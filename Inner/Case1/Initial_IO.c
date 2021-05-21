#include "Main_Define.H"

void Initial_IO(void)
{
	
	TRISE_Bebe 				 		= Output;
	TRISE_LED_Green 	 		= Output; 		
	TRISE_LED_Blue 		 		= Output;  			
	TRISE_LED_Red 		 		= Output;  			
	TRISE_LED_Battery0 		= Output;  	
	TRISE_LED_Battery1 		= Output;  	
	TRISE_LED_Battery2 		= Output;  	
	TRISE_LED_Battery3 		= Output;  	
	TRISE_LED_Battery4 		= Output;  	
	TRISE_SW1_Bootloader	= Input; 
	TRISE_SW3_Reset			 	= Input;		 		
	TRISE_SW2_Factory_Test= Input;		
	AD1PCFGL=0xFFFF;
	AD1PCFGH=0xFFFF;	
	

//	ODCFbits.ODF2 = 1;
//	ODCFbits.ODF3 = 1;

//	ODCFbits.ODF2 = 1;
//	ODCFbits.ODF3 = 1;

	Bebe = Bebe_ON;
 	IC_MODE_LED_SET(Normal_Statue_MODE);
	Battery_LED_SET(0);
	
	TRISE_U1RX = Input; 
	TRISE_U1TX = Output;	
	
}

void Battery_LED_SET(unsigned char LED)
{
	if(LED==0)
	{
		LED_Battery0 = LED_OFF;
		LED_Battery1 = LED_OFF;
		LED_Battery2 = LED_OFF;
		LED_Battery3 = LED_OFF;
		LED_Battery4 = LED_OFF;		
	}
	else if(LED==1)
	{
		LED_Battery0 = LED_ON;
		LED_Battery1 = LED_OFF;
		LED_Battery2 = LED_OFF;
		LED_Battery3 = LED_OFF;
		LED_Battery4 = LED_OFF;	
	}
	else if(LED==2)
	{
		LED_Battery0 = LED_ON;
		LED_Battery1 = LED_ON;
		LED_Battery2 = LED_OFF;
		LED_Battery3 = LED_OFF;
		LED_Battery4 = LED_OFF;		
	}
	else if(LED==3)
	{
		LED_Battery0 = LED_ON;
		LED_Battery1 = LED_ON;
		LED_Battery2 = LED_ON;
		LED_Battery3 = LED_OFF;
		LED_Battery4 = LED_OFF;		
	}
	else if(LED==4)
	{
		LED_Battery0 = LED_ON;
		LED_Battery1 = LED_ON;
		LED_Battery2 = LED_ON;
		LED_Battery3 = LED_ON;
		LED_Battery4 = LED_OFF;			
	}
	else if(LED==5)
	{
		LED_Battery0 = LED_ON;
		LED_Battery1 = LED_ON;
		LED_Battery2 = LED_ON;
		LED_Battery3 = LED_ON;
		LED_Battery4 = LED_ON;		
	}			
}

void IC_MODE_LED_SET(unsigned char MODE)
{
	if(MODE==0)
	{
		LED_Green 	 = LED_OFF;
		LED_Blue		 = LED_OFF;
		LED_Red 		 = LED_OFF;
	}
	else if(MODE==Normal_Statue_MODE)
	{
		LED_Green 	 = LED_ON;
		LED_Blue		 = LED_OFF;
		LED_Red 		 = LED_OFF;
	}
	else if(MODE==Factory_Test_MODE)
	{
		LED_Green 	 = LED_OFF;
		LED_Blue		 = LED_ON;
		LED_Red 		 = LED_OFF;	
	}
	else if(MODE==Boot_MODE)
	{
		LED_Green 	 = LED_ON;
		LED_Blue		 = LED_ON;
		LED_Red 		 = LED_OFF;
	}
	else if(MODE==ERRO_MODE)
	{
		LED_Green 	 = LED_OFF;
		LED_Blue		 = LED_OFF;
		LED_Red 		 = LED_ON;		
	}
		
}
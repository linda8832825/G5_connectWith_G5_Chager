#include "../Main_Define.H"


void I2C_Driver_Complete (void)
{
	if(NO_OLED_Display) 
	{
		CP_Data.Data_Value=1;
		I2C_Write(CaptureIC_I2C_Addr, Cmd_Driver_Complete, &CP_Data.Data[0] , 2);
		
	}		
}
void I2C_Driver_ID (void)
{
	if(NO_OLED_Display) 
	{
		CP_Data.Data_Value=	IC_Data.My_ID;	
		I2C_Write(CaptureIC_I2C_Addr, Cmd_Driver_ID , &CP_Data.Data[0] , 2);
	}		
}
void I2C_Driver_IN_OUT (void)
{
	if(NO_OLED_Display) 
	{
		CP_Data.Data_Value=	IC_Data.IN_Out;
		I2C_Write(CaptureIC_I2C_Addr, Cmd_Driver_IN_Out, &CP_Data.Data[0] , 2);
	}		
}

void I2C_LED_Connect (unsigned char Channal,unsigned char Statue)
{
	unsigned int math_a;
	if(NO_OLED_Display) 
	{
		CP_Data.Data[0]=0;	
		if(Statue)CP_Data.Data_Value=1;
		else CP_Data.Data_Value=0;
		
		math_a=Channal;
		math_a=(math_a<<12)|0x06;
		
		I2C_Write(CaptureIC_I2C_Addr, math_a, &CP_Data.Data[0] , 2);	
	}

	
}

void I2C_LED_Dimmy (unsigned char Channal,unsigned char Statue)
{
	unsigned int math_a;

	if(NO_OLED_Display) 
	{
		if(Channal==1)CP_Data.Dimmy=CH1.Dimmy;
		else if(Channal==2)CP_Data.Dimmy=CH2.Dimmy;	
		else if(Channal==3)CP_Data.Dimmy=CH3.Dimmy;
		else if(Channal==4)CP_Data.Dimmy=CH4.Dimmy;
				
		math_a=Channal;
		math_a=(math_a<<12)|0xA0;
		
		I2C_Write(CaptureIC_I2C_Addr, math_a, &CP_Data.Data[0] , 2);		
	}	
}

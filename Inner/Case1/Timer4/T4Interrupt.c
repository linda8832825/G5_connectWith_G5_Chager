#include "../Main_Define.H"


//0.1¬í¤¤Â_¤@¦¸
void __attribute__((interrupt, no_auto_psv)) _T4Interrupt(void)
{
	unsigned int  math_a,math_b;
	static unsigned int math_c=0;
	math_b=Flick_Freq;

	

	if(LED_Statue.G_Flick.Stat_IF)
	{
		LED_Statue.G_Flick.Count++;	
		if(LED_Statue.G_Flick.Count > LED_Statue.G_Flick.Freq)
		{
			LED_Statue.G_Flick.Count=0;
			LED_Green = !LED_Green;
		}
	}			
	
	if(LED_Statue.R_Flick.Stat_IF)
	{
		LED_Statue.R_Flick.Count++;	
		if(LED_Statue.R_Flick.Count > LED_Statue.R_Flick.Freq)
		{
			LED_Statue.R_Flick.Count=0;
			LED_Red = !LED_Red;	
		}
	}	
	
	
	if(LED_Statue.B_Flick.Stat_IF)
	{
		LED_Statue.B_Flick.Count++;	
		if(LED_Statue.B_Flick.Count > LED_Statue.B_Flick.Freq)
		{
			LED_Statue.B_Flick.Count=0;
			LED_Blue = !LED_Blue;
		}
	}	


		
	if(LED_Statue.Battery_Led.Stat_IF)
	{
		math_b = DimmyX1 * LED_Statue.Battery_Led.Dimmy;
		LED_Statue.Battery_Led.Count++;
			
		if(LED_Statue.Battery_Led.Count <= math_b)
		{
				if(Coulomb_Data.Battery_Power>=90)Battery_LED_SET(5);	
				else if (Coulomb_Data.Battery_Power>=80)Battery_LED_SET(4);	
				else if (Coulomb_Data.Battery_Power>=70)Battery_LED_SET(3);	
				else if (Coulomb_Data.Battery_Power>=60)Battery_LED_SET(2);	
				else if (Coulomb_Data.Battery_Power>=50)Battery_LED_SET(1);	
				else if (Coulomb_Data.Battery_Power<50)Battery_LED_SET(0);
				IC_MODE_LED_SET(IC_Data.IC_MODE_LED_SET);
		}	
		else
		{				
			if(LED_Statue.Battery_Led.Count >= Brightness_Hz)
			{				
				LED_Statue.Battery_Led.Count = 0;
			}
			else
			{
				IC_MODE_LED_SET(0);
				Battery_LED_SET(0);
			}			
		}			
	}	
	else
	{
			IC_MODE_LED_SET(IC_Data.IC_MODE_LED_SET);	
					if(Coulomb_Data.Battery_Power>=90)Battery_LED_SET(5);	
			else if (Coulomb_Data.Battery_Power>=80)Battery_LED_SET(4);	
			else if (Coulomb_Data.Battery_Power>=70)Battery_LED_SET(3);	
			else if (Coulomb_Data.Battery_Power>=60)Battery_LED_SET(2);	
			else if (Coulomb_Data.Battery_Power>=50)Battery_LED_SET(1);	
			else if (Coulomb_Data.Battery_Power<50)Battery_LED_SET(0);	
	}
			
	IFS1bits.T4IF=0;
}	

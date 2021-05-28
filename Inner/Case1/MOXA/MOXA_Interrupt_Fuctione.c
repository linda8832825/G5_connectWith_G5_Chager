#include "../Main_Define.H"

void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void)
{
	if(MOXA.RTIndex>0)
	{
		if(MOXA.Fuc==0x06)
		{
			if(MOXA.RTIndex==8)
			{
				MOXA.RIF=1;
			}		
			else
			{
				MOXA.ERRIF=1;	
				MOXA.RTIndex=0;
			}							
		}
		else if(MOXA.Fuc==0x03)
		{
			if(MOXA.RTIndex==8)
			{
				MOXA.RIF=1;
			}		
			else
			{
				MOXA.ERRIF=1;	
				MOXA.RTIndex=0;
			}				
		}
		else if(MOXA.Fuc==0x10)
		{
			if (MOXA.Index==MOXA.RTIndex)
			{
				MOXA.RIF=1;		
			}
			else
			{
				MOXA.ERRIF=1;	
				MOXA.RTIndex=0;
			}				
		}	
		else
		{
			MOXA.ERRIF=1;	
			MOXA.RTIndex=0;		
		}	
	
	}
	T3CONbits.TON=0;	
	IFS0bits.T3IF=0;
			
}	

void __attribute__((interrupt, no_auto_psv)) _U3RXInterrupt(void)
{		
		unsigned int math_a;
		static unsigned char *index;
		static unsigned char Fuction;
		
		if(MOXA.RIF==0)
		{
			TMR3=0;		
			if(!T3CONbits.TON)
			{
				T3CONbits.TON=1;
			}
			if(MOXA.RTIndex==0)
			{
				index=&MOXA.ID;
				*index=U3RXREG;
				index++;
				MOXA.RTIndex++;	
				Fuction=0;
			}
			else
			{
				if(MOXA.ID==IC_Data.My_ID||MOXA.ID==0x00)
				{
					TMR3=0;
					*index=U3RXREG;
					MOXA.RTIndex++;
					if(MOXA.RTIndex==2&&*index==0x10)Fuction=*index;
					if(MOXA.RTIndex==7&&Fuction==0x10)
					{
							MOXA.Index=*index+9;
					}					
					index++;
                    if(MOXA.RTIndex>8){
                        MOXA.RTIndex=0;
                        MOXA.ERRIF=1;	
                        T3CONbits.TON=0;
                    }
				}	
				else
				{
					T3CONbits.TON=0;
					math_a=U3RXREG;
					MOXA.RTIndex=0;	
				}
				
			}		
		}
		else
		{
			math_a=U3RXREG;
		}
		IFS5bits.U3RXIF=0;
}	

void __attribute__((interrupt, no_auto_psv)) _U3TXInterrupt(void)
{		
	
	static unsigned char *index;
	unsigned int math_a;
	
	if(MOXA.RTIndex<MOXA.Index)
	{
		if(MOXA.RTIndex==1)index=&MOXA.Fuc;
		U3TXREG=*index;
		index++;
		MOXA.RTIndex++;
		for (math_a=0;math_a<=20;math_a++)
		{
			asm("Nop");
		}	
	}
	else 
	{
		MOXA.RTIndex=0;
		MOXA.Index=0;
	}	

	IFS5bits.U3TXIF=0;
}



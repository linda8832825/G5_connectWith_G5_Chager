#include "Main_Define.H"

void Initial_Clock(void)
{	
	CLKDIVbits.RCDIV=0; //8Hz
	CLKDIVbits.DOZEN=0; //¥~³¡clock 1:1
	while(OSCCONbits.COSC != 1);			// Wait for new Oscillator to become FRC w/ PLL 
	while(OSCCONbits.LOCK != 1);			// Wait for Pll to Lock */  	
}

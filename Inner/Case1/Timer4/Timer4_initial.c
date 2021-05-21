#include "../Main_Define.H"

void Timer4_initial(void)
{
	T4CON=0;
	IEC1bits.T4IE=1;
	IFS1bits.T4IF=0;
	T4CONbits.TCKPS=1;
	T4CONbits.TCS=0;
	T4CONbits.TON=1;
	PR4=200;
}
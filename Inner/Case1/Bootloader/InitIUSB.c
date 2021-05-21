#include "../Main_Define.H"	

USB_Data_define USB; 

void InitIUSB(void)
{
	
	U1MODE=0x0008;//只使用UxTX跟UxRX腳位 UxRX腳位空閒電位為0	
	U1STA=0x2440;//UxTX腳位空閒電位為1
	//U1STAbits.URXISEL0=1;

	U1BRG = BR_115200;
	IFS0bits.U1RXIF = 0;		// Clear Interrupt flag11
	IFS0bits.U1TXIF = 0;		
	IEC0bits.U1RXIE = 1;		// Enable UART Interrupt		
	IEC0bits.U1TXIE = 0;		// Enable UART Interrupt	
		
	U1STAbits.UTXEN=1;
	U1MODEbits.UARTEN=1;		
	IPC2bits.U1RXIP=6;
	IPC3bits.U1TXIP=6;
	if(U1BRG == BR_9600)
	{
		T2CON=0;
		IEC0bits.T2IE=1;
		IFS0bits.T2IF=0;
		T2CONbits.TCKPS=1;
		T2CONbits.TCS=0;
		PR2=14500;			
	}
	else if(U1BRG == BR_115200)
	{
		T2CON=0;
		IEC0bits.T2IE=1;
		IFS0bits.T2IF=0;
		T2CONbits.TCKPS=1;
		T2CONbits.TCS=0;
		PR2=1250;	
	}

	
	TRISFbits.TRISF3=0;
	LATFbits.LATF3=1;
	
}	


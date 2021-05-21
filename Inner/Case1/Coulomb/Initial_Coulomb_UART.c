#include "../Main_Define.H"


ModBus_Receiver_Data_define ModBus_Receiver; 
ModBus_Sent_Data_struct_define ModBus_Sent; 

Coulomb_Data_struct_define Coulomb_Data; 

void Initial_Coulomb_UART(void)
{
	U1MODE=0x0008;//只使用UxTX跟UxRX腳位 UxRX腳位空閒電位為0	
	U1STA=0x2440;//UxTX腳位空閒電位為1
	U1STAbits.URXISEL=1;
	
	U1BRG = BR_9600;
	
/*
	把下面的選項指向PRx
	RPINR18.U1RXR<5:0>
	RPINR19.U2RXR<5:0>
	RPINR17.U3RXR<5:0>
	RPINR27.U4RXR<5:0>
	
	
	把RPORxbits.RPxR指向下面的哪一選項
	3 U1TX UART1 Transmit
	5 U2TX UART2 Transmit
	28 U3TX UART3 Transmit
	30 U4TX UART4 Transmit*/
		
	RPINR18bits.U1RXR = 30;
	RPOR8bits.RP16R = 3;
	
	IFS0bits.U1RXIF = 0;		// Clear Interrupt flag11
	IFS0bits.U1TXIF = 0;		
	IEC0bits.U1RXIE = 1;		// Enable UART Interrupt
	IEC0bits.U1TXIE = 1;		// Enable UART Interrupt
		
	IPC2bits.U1RXIP=6;
	IPC3bits.U1TXIP=6;
	U1MODEbits.UARTEN=1;
//	U1MODEbits.RXINV=1;
	U1STAbits.UTXEN=1;
	


	T2CON=0;
	IEC0bits.T2IE=1;
	IFS0bits.T2IF=0;
	T2CONbits.TCKPS=1;
	T2CONbits.TCS=0;
	if(U1BRG==BR_115200)
	{
		PR2=1250;
	}
	else if(U1BRG==BR_9600)
	{
		PR2=15000;
	}

	
}




#include "../Main_Define.H"




void Initial_UART2(void)
{
	U2MODE=0x0008;//只使用UxTX跟UxRX腳位 UxRX腳位空閒電位為0	
	U2STA=0x2440;//UxTX腳位空閒電位為1
	U2STAbits.URXISEL=1;
	
	U2BRG = BR_9600;
	
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
	
//原本		
	RPINR19bits.U2RXR = 10;
	RPOR8bits.RP17R = 5;


		//CON4
//	RPINR19bits.U2RXR = 7;//把RPINR17的U3RXR的功能 指向RP7
//	RPOR3bits.RP6R = 5;	//把RPOR3bits.RP7R的腳位 指向功能28 


//	RPINR19bits.U2RXR = 7;
//	RPOR3bits.RP6R 		= 5;	


	
	IFS1bits.U2RXIF = 0;		// Clear Interrupt flag11
	IFS1bits.U2TXIF = 0;		
	IEC1bits.U2RXIE = 1;		// Enable UART Interrupt
	IEC1bits.U2TXIE = 1;		// Enable UART Interrupt
		
//	IPC7bits.U2RXIP=5;
	IPC7bits.U2TXIP=5;
	U2MODEbits.UARTEN=1;
	U2STAbits.UTXEN=1;
	
	
}




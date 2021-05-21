#include "../Main_Define.H"

MOXA_Data_define MOXA; 
	
void Initial_MOXA_UART(void)
{
	
	U3MODE=0x0008;//只使用UxTX跟UxRX腳位 UxRX腳位空閒電位為0	
	U3STA=0x2440;//UxTX腳位空閒電位為1
	U3STAbits.URXISEL=1;	
	U3BRG = BR_115200;
	
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
	30 U4TX UART4 Transmit	
*/
	
		//CON5	
//	RPINR17bits.U3RXR = 2;//把RPINR17的U3RXR的功能 指向RP7
//	RPOR2bits.RP4R = 28;	//把RPOR3bits.RP7R的腳位 指向功能28 	
	
		//CON4原本
	RPINR17bits.U3RXR = 7;//把RPINR17的U3RXR的功能 指向RP7
	RPOR3bits.RP6R = 28;	//把RPOR3bits.RP7R的腳位 指向功能28 
	
		//CON3
//	RPINR17bits.U3RXR = 10;
//	RPOR8bits.RP17R = 28;


			
	IFS5bits.U3RXIF = 0;		// Clear Interrupt flag11
	IFS5bits.U3TXIF = 0;		
	IEC5bits.U3RXIE = 1;		// Enable UART Interrupt
	IEC5bits.U3TXIE = 1;		// Enable UART Interrupt
		
	IPC20bits.U3RXIP=5;
	IPC20bits.U3TXIP=5;
	U3STAbits.UTXEN=1;
	U3MODEbits.UARTEN=1;	
	
	
	
	T3CON=0;
	IEC0bits.T3IE=1;
	IFS0bits.T3IF=0;
	T3CONbits.TCKPS=1;
	T3CONbits.TCS=0;
	PR3=1250;
		
	
	MOXA.Return_Mode = 1;
	IC_Data.My_ID=1;
	

	
	
}
#include "../Main_Define.H"




void Initial_UART2(void)
{
	U2MODE=0x0008;//�u�ϥ�UxTX��UxRX�}�� UxRX�}��Ŷ��q�쬰0	
	U2STA=0x2440;//UxTX�}��Ŷ��q�쬰1
	U2STAbits.URXISEL=1;
	
	U2BRG = BR_9600;
	
/*
	��U�����ﶵ���VPRx
	RPINR18.U1RXR<5:0>
	RPINR19.U2RXR<5:0>
	RPINR17.U3RXR<5:0>
	RPINR27.U4RXR<5:0>
	
	
	��RPORxbits.RPxR���V�U�������@�ﶵ
	3 U1TX UART1 Transmit
	5 U2TX UART2 Transmit
	28 U3TX UART3 Transmit
	30 U4TX UART4 Transmit*/
	
//�쥻		
	RPINR19bits.U2RXR = 10;
	RPOR8bits.RP17R = 5;


		//CON4
//	RPINR19bits.U2RXR = 7;//��RPINR17��U3RXR���\�� ���VRP7
//	RPOR3bits.RP6R = 5;	//��RPOR3bits.RP7R���}�� ���V�\��28 


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




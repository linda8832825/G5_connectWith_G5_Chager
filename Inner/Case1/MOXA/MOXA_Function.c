#include "../Main_Define.H"

unsigned int MOXA_CRC_Check(void) //howmuch是有多少個!!  5格數字就填5    不是從0開始數
{
	unsigned int CRC_CODE=0xFFFF,math_a,math_b;
	unsigned char CRC_Length=0,i,*CRC_Address;
	


	CRC_Address=&MOXA.ID;
	CRC_Length=MOXA.RTIndex-2;	
	
	while(CRC_Length--)
	{
		CRC_CODE^=*CRC_Address++;//先XOR完後再把地址+1
		for(i=0;i<8;i++)
		{
			if(CRC_CODE&0x01)//如果最後一個位元是1把CRC_CODE右移1位之後與0xA001做XOR
			{
				CRC_CODE=(CRC_CODE>>1)^0xA001;
			}
			else
			{
				CRC_CODE=(CRC_CODE>>1);
			}	
		}
	}		
		

	CRC_Address=&MOXA.ID;
	CRC_Address+=MOXA.RTIndex-2;	

	
	math_a=*CRC_Address;
	math_a=math_a<<8;
	CRC_Address++;
	math_a=math_a|(*CRC_Address);
	
	//因為當初寫錯了其實CRC應該是先L 在H 可是寫反了 所以 變成先H在L 或者先L在H 都可以
	math_b=*CRC_Address;
	math_b=math_b<<8;
	CRC_Address--;
	math_b=math_b|(*CRC_Address);
	
	if (CRC_CODE == math_a || CRC_CODE == math_b)//當CRC確認之後 將資料重新整理
	{
		return 1;	
	}
	else 
	{
		return 0;
	}	
	
}

void Repeat_MOXA_Erro(unsigned char Erro_Code)
{
	unsigned int math_a;
	
	
	if(Erro_Code==0x10||Erro_Code==0x20||Erro_Code==0x30||Erro_Code==0x40)	MOXA.Fuc=0x22;
	else if(Erro_Code==0x11||Erro_Code==0x21||Erro_Code==0x31||Erro_Code==0x41)	MOXA.Fuc=0x22;	


	MOXA.Index=5;
	MOXA.RTIndex=0;
	
	MOXA.Fuc=MOXA.Fuc|0x80;
	MOXA.Reg_H=Erro_Code;
	math_a=CRC_Make(&MOXA ,3); 
	
	MOXA.Reg_L = math_a&0x00FF;
	MOXA.DATA[0] = (math_a&0xFF00)>>8;
		
//	MOXA.Reg_L=(math_a&0xff00)>>8;
//	MOXA.DATA[0]=math_a&0x00FF;


	if(!U3STAbits.UTXEN)
	{
		U3STAbits.UTXEN=1;
	}
	while(IFS5bits.U3TXIF)
	{
		IFS5bits.U3TXIF=0;		
		IEC5bits.U3TXIE = 1;		// Enable UART Interrupt	
	}
	U3TXREG=MOXA.ID;	
	MOXA.RTIndex++;

	
}


void Sent_MOXA_Data(unsigned char *Last_address)//只能回傳使用0x03讀取功能的函數
{
		
		unsigned int math_a;
		
		
		MOXA.Index=MOXA.Reg_H+3;
		MOXA.RTIndex=0;
		math_a=CRC_Make(&MOXA,MOXA.Index); //howmuch是有多少個!!  5格數字就填5    不
		
		
		*Last_address = (math_a&0xFF);
		Last_address++;
		*Last_address = (math_a&0xFF00)>>8;
				
//		*Last_address=(math_a&0xFF00)>>8;
//		Last_address++;
//		*Last_address=(math_a&0xFF);
		
		MOXA.Index+=2;	
		if(!U3STAbits.UTXEN)
		{
			U3STAbits.UTXEN=1;
		}
		while(IFS5bits.U3TXIF)
		{
			IFS5bits.U3TXIF=0;		
			IEC5bits.U3TXIE = 1;		// Enable UART Interrupt	
		}
		U3TXREG=MOXA.ID;	
		MOXA.RTIndex++;	
}

void feedback_MOXA_Data(unsigned char *readAddress) //回傳使用0x06讀取功能的函數
{
		
		unsigned int math_a;
		
		
		MOXA.Index=6;//有4個byte要傳01 + 06 + 寫入位置1 + 寫入位置2 + 寫入值1 + 寫入值2
		MOXA.RTIndex=0;
		math_a=CRC_Make(&MOXA,MOXA.Index); //howmuch是有多少個!!  5格數字就填5    不
		
		
				
		*readAddress=(math_a&0xFF00)>>8;
		readAddress++;
		*readAddress=(math_a&0xFF);
		
		MOXA.Index+=2;	
		if(!U3STAbits.UTXEN)
		{
			U3STAbits.UTXEN=1;
		}
		while(IFS5bits.U3TXIF)
		{
			IFS5bits.U3TXIF=0;		
			IEC5bits.U3TXIE = 1;		// Enable UART Interrupt	
		}
		U3TXREG=MOXA.ID;	
		MOXA.RTIndex++;	
}

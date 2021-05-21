#include "../Main_Define.H"

unsigned int MOXA_CRC_Check(void) //howmuch�O���h�֭�!!  5��Ʀr�N��5    ���O�q0�}�l��
{
	unsigned int CRC_CODE=0xFFFF,math_a,math_b;
	unsigned char CRC_Length=0,i,*CRC_Address;
	


	CRC_Address=&MOXA.ID;
	CRC_Length=MOXA.RTIndex-2;	
	
	while(CRC_Length--)
	{
		CRC_CODE^=*CRC_Address++;//��XOR����A��a�}+1
		for(i=0;i<8;i++)
		{
			if(CRC_CODE&0x01)//�p�G�̫�@�Ӧ줸�O1��CRC_CODE�k��1�줧��P0xA001��XOR
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
	
	//�]�����g���F���CRC���ӬO��L �bH �i�O�g�ϤF �ҥH �ܦ���H�bL �Ϊ̥�L�bH ���i�H
	math_b=*CRC_Address;
	math_b=math_b<<8;
	CRC_Address--;
	math_b=math_b|(*CRC_Address);
	
	if (CRC_CODE == math_a || CRC_CODE == math_b)//��CRC�T�{���� �N��ƭ��s��z
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


void Sent_MOXA_Data(unsigned char *Last_address)//�u��^�Ǩϥ�0x03Ū���\�઺���
{
		
		unsigned int math_a;
		
		
		MOXA.Index=MOXA.Reg_H+3;
		MOXA.RTIndex=0;
		math_a=CRC_Make(&MOXA,MOXA.Index); //howmuch�O���h�֭�!!  5��Ʀr�N��5    ��
		
		
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

void feedback_MOXA_Data(unsigned char *readAddress) //�^�Ǩϥ�0x06Ū���\�઺���
{
		
		unsigned int math_a;
		
		
		MOXA.Index=6;//��4��byte�n��01 + 06 + �g�J��m1 + �g�J��m2 + �g�J��1 + �g�J��2
		MOXA.RTIndex=0;
		math_a=CRC_Make(&MOXA,MOXA.Index); //howmuch�O���h�֭�!!  5��Ʀr�N��5    ��
		
		
				
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

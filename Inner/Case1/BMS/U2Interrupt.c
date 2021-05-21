#include "../Main_Define.H"
	
void __attribute__((interrupt, no_auto_psv)) _U2TXInterrupt(void)
{		
	unsigned int math_a;
	static unsigned char *index;
	static unsigned char Data_Statue;   //1=Master_Command  2=Slaver_return;	

	if(Sent_struct.RTIndex<Sent_struct.Index)
	{
		U2TXREG=*(Sent_struct.Data_Address);
		
	//	if(Sent_struct.W_R==0)
	//	{
	//		U3TXREG=*(Sent_struct.Data_Address);
	//	}
		
		Sent_struct.RTIndex++;
		Sent_struct.Data_Address++;
		
		if(Sent_struct.RTIndex==Sent_struct.Index)
		{
			Sent_struct.TIF=1;
		}
	}
	else 
	{
		Sent_struct.RTIndex=0;
		Sent_struct.Index=0;
	}	
	IFS1bits.U2TXIF = 0;		// Clear Interrupt flag11
	
}


void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void)
{		
	unsigned int math_a;
	
	Sent_struct.NO_RESPONSE_Time=Sent_Data_TO_PLC_NO_RESPONSE_Time;
	
	if(Sent_struct.RTIndex==0)
	{
			Sent_struct.Recent_Data_Address=&BMS_Return_Data.CHAR;
			Sent_struct.Index=sizeof(BMS_Return_Data.CHAR);
	}
	
	
	if(Sent_struct.RTIndex<=Sent_struct.Index)
	{
		
		do
		{
			*Sent_struct.Recent_Data_Address =U2RXREG;
			if(*Sent_struct.Recent_Data_Address==0x0D)
			{
				Sent_struct.End_Flag++;
			}
			if(Sent_struct.End_Flag==1 && *Sent_struct.Recent_Data_Address==0x0A)
			{
				Sent_struct.End_Flag++;
			}		
			if(Sent_struct.RTIndex==0 && *Sent_struct.Recent_Data_Address==0x15)
			{
				Sent_struct.Index=8;
			}
			Sent_struct.Recent_Data_Address++;
			Sent_struct.RTIndex++;		
		}while(U2STAbits.URXDA);

		
					
	}
	else//代表接收錯誤，已經超出所需要收的資訊
	{
	//	Sent_struct.RTIndex=0;	
		Sent_struct.NO_RESPONSE_Time=100;		
	}
	
	if(U2STAbits.OERR)
	{
		while(U2STAbits.OERR)
		{
			math_a=U2RXREG;
			U2STAbits.OERR=0;
		}
	}	
	
				
	IFS1bits.U2RXIF = 0;		// Clear Interrupt flag11
}	


#include "../Main_Define.H"
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void)
{	
	unsigned char math_a,math_c,math_d;
	unsigned int 	math_b;
	unsigned int 	*index1;
	unsigned char *index2,Quantity,*index3;
	
	unsigned char Erro_IF;
	
	index1=&ModBus_Sent.ID;
	index3=&ModBus_Sent.ID;
	index2=&ModBus_Receiver.ID;
	
	Erro_IF=0;
	
	IC_Data.Coulomb_No_Reback = Coulomb_No_Reback_Time;//庫倫計延時計時器的計時復歸
	if(ModBus_Receiver.RTIndex>0)
	{
		if(ModBus_Sent.W_R == Read)
		{
			if(CRC_Check())
			{
				IC_Data.Coulomb_No_Reback=0;	//確定資料正確後關閉庫倫計延時計時器
				ModBus_Receiver.ERR_Count=0;
				ModBus_Receiver.Value_L=ModBus_Sent.Reg_L;
				ModBus_Receiver.Value_H=ModBus_Sent.Reg_H;
				index1=&Coulomb_Data.ID;
				index1=index1+(ModBus_Receiver.Value);	
				//取得庫倫資料陣列從哪位置開始放資料
							
				Quantity = ModBus_Receiver.Reg_H/2;
				index2=&ModBus_Receiver.Reg_L;
				for(Quantity=Quantity;Quantity>0;Quantity--)
				{
					ModBus_Receiver.Value_H = *index2;
					*index2++;
					ModBus_Receiver.Value_L = *index2;
					*index1 = ModBus_Receiver.Value;
					index1++;
					index2++;
				}
				ModBus_Receiver.RIF=1;
				ModBus_Receiver.BusyIF=0;
				ModBus_Receiver.RTIndex=0;
			}
			else
			{
				ModBus_Receiver.RTIndex=0;
				ModBus_Receiver.ERRIF=1;
				ModBus_Receiver.BusyIF=0;
			}
			
		}
		else if(ModBus_Sent.W_R == Write)
		{
			if(ModBus_Receiver.RTIndex==8)
			{
				Erro_IF=0;
				for(math_a=0;math_a<8;math_a++)
				{
					math_c = *index3;
					math_d = *index2;
					if( 	math_c != math_d )Erro_IF=1;
					index3++;
					index2++;
				}
				if(Erro_IF)ModBus_Receiver.ERRIF=1;
				else ModBus_Receiver.TIF=1;
				ModBus_Receiver.BusyIF=0;
			}		
			else
			{
				ModBus_Receiver.ERRIF=1;	
				ModBus_Sent.RTIndex=0;
				ModBus_Receiver.BusyIF=0;
			}			
		}
	}	

	if(U1STAbits.OERR)
	{
		while(U1STAbits.OERR)
		{
			math_a=U1RXREG;
		}
	}
	T2CONbits.TON=0;	
	IFS0bits.T2IF=0;
}	

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{		unsigned int math_a;
		static unsigned char *index;
		static unsigned char Data_Statue;   //1=Master_Command  2=Slaver_return;	
		
		TMR2=0;		
		if(!T2CONbits.TON)
		{
			T2CONbits.TON=1;
		}
		if(ModBus_Receiver.RTIndex==0)
		{
			index=&ModBus_Receiver.ID;
			*index=U1RXREG;
			index++;
			ModBus_Receiver.RTIndex++;	
		}
		else
		{
			TMR2=0;
			math_a=sizeof(ModBus_Receiver);
			if(ModBus_Receiver.RTIndex<math_a)
			{
				*index=U1RXREG;
				index++;
				ModBus_Receiver.RTIndex++;			
			}
			else
			{
				*index=U1RXREG;
				ModBus_Receiver.RTIndex=0;
			}

			
		}		
		IFS0bits.U1RXIF = 0;		// Clear Interrupt flag11
}	
void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt(void)
{
	static unsigned char *index;
	unsigned int math_a;
	
	if(ModBus_Sent.RTIndex<ModBus_Sent.Index)
	{
		if(ModBus_Sent.RTIndex==1)index=&ModBus_Sent.Fuc;
		while(!U1STAbits.UTXBF && ModBus_Sent.RTIndex < ModBus_Sent.Index)
		{
			U1TXREG=*index;
			index++;
			ModBus_Sent.RTIndex++;
		}	
	}
	else 
	{
		ModBus_Sent.RTIndex=0;
		ModBus_Sent.Index=0;
	}		
	IFS0bits.U1TXIF = 0;		// Clear Interrupt flag11
}
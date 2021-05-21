#include "../Main_Define.H"


void Unlock_Coulomb()
{
  unsigned int math_a;
  unsigned char math_b;

  
  ModBus_Sent.ID='p';
  ModBus_Sent.Fuc='w'; 
  
  ModBus_Sent.Reg_H = 'd';
  ModBus_Sent.Reg_L = '=';
  
  ModBus_Sent.Quantity_H= '0';
  ModBus_Sent.Quantity_L = '4';
        ModBus_Sent.CRC_L = '3';
        ModBus_Sent.CRC_H = '0';
        
  ModBus_Sent.Index=8;
  ModBus_Sent.RTIndex=0;
 
  ModBus_Receiver.BusyIF=1;
  ModBus_Receiver.RIF=0;  
  ModBus_Receiver.TIF=0;  
 
   
  ModBus_Sent.W_R = Write;
  ModBus_Sent.RTIndex=1;
  if(IEC0bits.U1TXIE == 0)IEC0bits.U1TXIE = 1;
  U1TXREG=ModBus_Sent.ID;  
        while(ModBus_Sent.Index!=0); //等待庫倫計回應資料
        ModBus_Receiver.BusyIF=0;   
}

void Read_ALL_Coulomb_Data()
{
	if(ModBus_Receiver.BusyIF==0)
	{
		unsigned int math_a;
		unsigned char math_b;

		
		ModBus_Sent.ID=0x01;
		ModBus_Sent.Fuc=0x03;	
		
		ModBus_Sent.Reg_H = 0;
		ModBus_Sent.Reg_L = 0;
		
		ModBus_Sent.Quantity_H= 0;
		ModBus_Sent.Quantity_L = 0x22;
		
		ModBus_Sent.Index=6;
		ModBus_Sent.RTIndex=0;

		
		ModBus_Receiver.Index=0;
		ModBus_Receiver.RTIndex=0;
		ModBus_Receiver.BusyIF=1;
		ModBus_Receiver.RIF=0;		
		ModBus_Receiver.TIF=0;		
				
		math_a=CRC_Make(&ModBus_Sent,ModBus_Sent.Index);
		
		math_b = math_a&0xFF;
		ModBus_Sent.CRC_L = math_b;
		
		math_b = (math_a&0xFF00)>>8;
		ModBus_Sent.CRC_H = math_b;
		ModBus_Sent.Index+=2;			
		ModBus_Sent.W_R = Read;
		ModBus_Sent.RTIndex=1;
		if(IEC0bits.U1TXIE == 0)IEC0bits.U1TXIE = 1;
		U1TXREG=ModBus_Sent.ID;		
		IC_Data.Coulomb_No_Reback = Coulomb_No_Reback_Time;
		
	}
}	
void Read_Coulomb_Data(unsigned int Regest,unsigned char Quantity)
{
	
	if(ModBus_Receiver.BusyIF==0)
	{	
		unsigned int math_a;
		unsigned char math_b;

		ModBus_Sent.ID=0x01;
		ModBus_Sent.Fuc=0x03;	
		
		ModBus_Sent.Reg_H = (Regest&0xFF00)>>8;
		ModBus_Sent.Reg_L = Regest&0xFF;
		
		ModBus_Sent.Quantity_H= (Quantity&0xFF00)>>8;
		ModBus_Sent.Quantity_L = Quantity&0xFF;
		
		ModBus_Sent.Index=6;
		ModBus_Sent.RTIndex=0;	
				
		ModBus_Receiver.Index=0;
		ModBus_Receiver.RTIndex=0;
		ModBus_Receiver.BusyIF=1;
		ModBus_Receiver.RIF=0;		
		ModBus_Receiver.TIF=0;				

		
		
		math_a=CRC_Make(&ModBus_Sent,ModBus_Sent.Index);
		
		math_b = math_a&0xFF;
		ModBus_Sent.CRC_L = math_b;
		
		math_b = (math_a&0xFF00)>>8;
		ModBus_Sent.CRC_H = math_b;
		ModBus_Sent.Index+=2;			
		ModBus_Sent.W_R = Read;
		ModBus_Sent.RTIndex=1;
		if(IEC0bits.U1TXIE == 0)IEC0bits.U1TXIE = 1;
		U1TXREG=ModBus_Sent.ID;	
	}	
}	

void Write_Coulomb_Data(unsigned int Regest,unsigned int Data)
{
	unsigned int math_a;
	unsigned char math_b;
	
	if(ModBus_Receiver.BusyIF==0)
	{	

		ModBus_Sent.ID=0x01;
		ModBus_Sent.Fuc=0x06;	
		
		ModBus_Sent.Reg_H = (Regest&0xFF00)>>8;
		ModBus_Sent.Reg_L = Regest&0xFF;
		
		ModBus_Sent.Quantity_H = (Data & 0xFF00)>>8;
		ModBus_Sent.Quantity_L = Data & 0xFF;
		
		ModBus_Sent.Index=6;
		ModBus_Sent.RTIndex=0;	
		
		ModBus_Receiver.Index=0;
		ModBus_Receiver.RTIndex=0;
		ModBus_Receiver.BusyIF=1;
		ModBus_Receiver.RIF=0;		
		ModBus_Receiver.TIF=0;				
		IC_Data.Coulomb_No_Reback=1200;				
		
		math_a=CRC_Make(&ModBus_Sent,ModBus_Sent.Index);
		
		math_b = math_a&0xFF;
		ModBus_Sent.CRC_L = math_b;
		
		math_b = (math_a&0xFF00)>>8;
		ModBus_Sent.CRC_H = math_b;
		ModBus_Sent.Index+=2;			
		
		ModBus_Sent.W_R = Write;
		ModBus_Sent.RTIndex=1;
		if(IEC0bits.U1TXIE == 0)IEC0bits.U1TXIE = 1;
		U1TXREG=ModBus_Sent.ID;	
		
	}	
}	

unsigned int CRC_Check(void) //howmuch是有多少個!!  5格數字就填5    不是從0開始數
{
	unsigned int CRC_CODE=0xFFFF,math_a,math_b;
	unsigned char CRC_Length=0,i,*CRC_Address;
	

	
	CRC_Address=&ModBus_Receiver.ID;	
	CRC_Length=ModBus_Receiver.RTIndex-2;
	
	
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
	
	

	CRC_Address=&ModBus_Receiver.ID;	
	CRC_Address+=ModBus_Receiver.RTIndex-2;
	

	
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

 

unsigned int CRC_Make(unsigned char *Buffer , unsigned char Quantity) //howmuch是有多少個!!  5格數字就填5    不是從0開始數
{
	unsigned int CRC_CODE=0xFFFF;
	unsigned char CRC_Length=0,i,*CRC_Address;	
	
	CRC_Address=Buffer;
	CRC_Length=Quantity;		

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
	return CRC_CODE;
	
}	

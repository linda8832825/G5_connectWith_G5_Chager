#include "../Main_Define.H"

void Sent_Data_To_PLC(void)//�ǰe��ƨ쭱�O�h	
{
	unsigned int math_a;
	//static unsigned char Count=0;
	static  unsigned int math_b;
	Sent_struct.RTIndex=0;
//	Sent_struct.ERRIF=0;
	if(Sent_struct.ERRIF==1)
	{
		Sent_struct.IF=0;
		
		Sent_struct.Count++;
		if(Sent_struct.Count==4 || Sent_struct.Count==7)
		{
			if(Sent_struct.Count==7)Sent_struct.Count=1;
			
			if(Sent_struct.W_R==0)Sent_struct.W_R=1;
			else if(Sent_struct.W_R==1)Sent_struct.W_R=0;
		}
		
		if(Sent_struct.W_R==0)
		{
			math_a=Customer_Pannal_Data_Count;
			Original_Data.Item3Bits.COMM = 0;
			if(math_a==12)
			{
				Sent_struct.Index=sizeof(Customer_Pannal_12.CHAR);//��X�n�ǰe�X�����
				Sent_struct.Data_Address=&Customer_Pannal_12.CHAR[0];//��n�ǰe����ƪ���m�ǳƦn��bADDRESS�ǳ�
			}
			else
			{
				Sent_struct.Index=sizeof(Customer_Pannal_10.CHAR);//��X�n�ǰe�X�����
				Sent_struct.Data_Address=&Customer_Pannal_10.CHAR[0];//��n�ǰe����ƪ���m�ǳƦn��bADDRESS�ǳ�
			}	
			Sent_struct.W_R=0;
			Sent_struct.RTIndex=0;

		}
		else if(Sent_struct.W_R==1)
		{
			Sent_struct.Index=sizeof(Word2);
			Sent_struct.Data_Address=&Word2[0];
			Sent_struct.RTIndex=0;
			Sent_struct.W_R=1;
		}	
		Sent_struct.NO_RESPONSE_Time=Sent_Data_TO_PLC_NO_RESPONSE_Time;	

			
	}
	else //�V���O�ǰe���
	{
		Sent_struct.Count=0;
		if(Sent_struct.W_R==1)
		{
			math_a=Customer_Pannal_Data_Count;
			
			if(Original_Data.Item3Bits.COMM)
			{Original_Data.Item3Bits.COMM = 0;}
			else 
			{Original_Data.Item3Bits.COMM = 1;}

		
			if(math_a==12)
			{
				Sent_struct.Index=sizeof(Customer_Pannal_12.CHAR);//��X�n�ǰe�X�����
				Sent_struct.Data_Address=&Customer_Pannal_12.CHAR[0];//��n�ǰe����ƪ���m�ǳƦn��bADDRESS�ǳ�
			}
			else
			{
				Sent_struct.Index=sizeof(Customer_Pannal_10.CHAR);//��X�n�ǰe�X�����
				Sent_struct.Data_Address=&Customer_Pannal_10.CHAR[0];//��n�ǰe����ƪ���m�ǳƦn��bADDRESS�ǳ�
			}		
			Sent_struct.RTIndex=0;	
			Sent_struct.IF=0;
			Sent_struct.W_R=0;
		}
		else
		{
			Sent_struct.Index=sizeof(Word2);
			Sent_struct.Data_Address=&Word2[0];
			Sent_struct.RTIndex=0;
			Sent_struct.IF=0;	
			Sent_struct.W_R=1;	
		}	
		
		
		
		Sent_struct.NO_RESPONSE_Time=Sent_Data_TO_PLC_NO_RESPONSE_Time;

	}
	
	math_a=*(Sent_struct.Data_Address);
	U2TXREG=math_a;
	
//	if(Sent_struct.W_R==0)
//	{
//		U3TXREG=*(Sent_struct.Data_Address);
//	}

	Sent_struct.RTIndex++;
	Sent_struct.Data_Address++;


}	

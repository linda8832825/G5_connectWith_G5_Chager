#ifndef Moxa_define_H
#define Moxa_define_H

#define Fuc_Erro				0x01
#define Reg_Add_Erro		0x02
#define Value_Erro			0x03
#define NoConnect_Erro	0x07
#define CRC_Erro				0x08
#define Lightning_Erro	0x09


typedef struct tagMOXA_Data {	
  unsigned char 	ID;						//�s��
  unsigned char 	Fuc;					//�\��
	union
	{
		struct
		{
			unsigned char 	Reg_H;	//�]���ǿ�ɭԬO���ǿ鰪�줸����A�ǿ�C�줸
		  unsigned char 	Reg_L;  //�i�OPIC�O���q�C�줸�}�l�\��A�ҥH�|�����C�줸�洫�����D
		};												//�GREG�|�O��Ӱ��C�줸�A�˪����p�A�G���ᦳ�ӭ��s��z���B��
		struct
		{
			unsigned char 	Chx;
		  unsigned char 	Regest; 
		};			
	};	  
	union
	{
		struct
		{
		  unsigned char 	Data_H;
			unsigned char 	Data_L;
			unsigned char 	CRC_L;
			unsigned char 	CRC_H;
		};
		
		struct
		{
			unsigned char 	Quantity_H;
		  unsigned char 	Quantity_L; 
		  unsigned char 	Total_Byte; 		   
		};		
		unsigned int DATA[30];	
		unsigned int Quantity;		   	
	};
	union
	{		 
		unsigned int Value;
		struct
		{
		  unsigned char 	Value_L;  
			unsigned char 	Value_H;	  
		};		
	};												
 	union
	{
		unsigned						IF:3;
		unsigned						Return_Mode:2;//�^�ǬO�^�Ǯw�۸��(1) �٬OBMS�����(0)
		struct
		{
			unsigned  			 	TIF :1;		//��ƶǰe����
			unsigned  			 	RIF :1;		//��Ʊ�������
			unsigned  			 	ERRIF:1;	//��Ʊ����ζǰe���~				
		};
	};
	
  unsigned char Index;						//�n�����
  unsigned char RTIndex;					//�w�����
}MOXA_Data_define;

extern MOXA_Data_define MOXA; 


#endif

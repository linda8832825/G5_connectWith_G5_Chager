#ifndef I2C_define_H
#define I2C_define_H




#define DriverIC_I2C_Addr		0x10 //24HJ128GP310A
#define CaptureIC_I2C_Addr	0x20 //24FJ128GA006A
#define EROMIC_I2C_Addr			0xA0 //EEPROM	


#define I2CStat		I2C1CONbits.SEN = 1	

#define Comand_write				0
#define Comand_read					1




typedef struct tagI2C_Data_struct {
	union//�Ĥ@�����
	{
		struct
		{
			unsigned  char XX;	
			unsigned  char Address;	
		};		
		struct
		{
			unsigned  char XX;	
		  unsigned  R_W:1;	
		  unsigned  Addr:7;
		};
		struct
		{
		  unsigned  		:1;	
		  unsigned  Ax	:2;
		};		
		struct
		{
			unsigned  char XX;	
		  unsigned  		:1;	
		  unsigned  A0	:1;
		  unsigned  A1	:1;		   
		};		
	};
	union//�ĤG.�T�����
	{
		struct
		{
		  unsigned  char Addr_H;//�ĤG�����
		  unsigned  char Addr_L;//�ĤT�����
		};
		struct
		{
			unsigned  char Command_Byte;
			unsigned  char Command_Set;			
		};			
	};
 	union
	{	
		unsigned	int				    ALL_IF;
		unsigned						 Statue_IF:4;			
		struct
		{
			unsigned  							TIF :1;				//��ƶǰe����
			unsigned  							RIF :1;				//��Ʊ�������
			unsigned  					 Busy_IF:1;				//�n�ǰe���˸m�B�󦣸L��
			unsigned  				 		 ERRIF:1;				//��Ʊ����ζǰe���~
			unsigned  				Address_IF:1;				//�ǰe��m
			unsigned  		 		 RStart_IF:1;				//���ƱҰ�
			unsigned  					Data_R_W:1;				//��ƭnŪ �٬O�g		
			unsigned  						ASK_IF:1;				//�^�����ASK
			unsigned  					 RCEN_IF:1;				//�Ұʱ���
			unsigned  		Device_Busy_IF:1;				//�n�ǰe���˸m�B�󦣸L��		
		};
	};
  unsigned char Index1;						//�n���ΰe����Ƽƶq(�e�����]�w��)
  unsigned char Index2;						//�n���ΰe����Ƽƶq(�᭱����Ƽ�)  
  unsigned char RTIndex;					//�w���ΰe����Ƽƶq
  unsigned int Data_Addr;			//�n�����ζǰe������\���m�A���ϥέ쥻���}�C�O�]���L�i�H�s��AŪ�������K 
} I2C_Data_struct;
extern  I2C_Data_struct I2C_Data;


extern  unsigned char *I2C_Buffer_index;


void I2C_Initial(void);
void I2C_Write(unsigned int Divice_ID , unsigned int Reg_Addr  , unsigned char *Buff_Addr   ,unsigned char Leng);
void I2C_Read(unsigned int Divice_ID , unsigned int Reg_Addr  ,unsigned char *Buff_Addr , unsigned char Leng);


#endif

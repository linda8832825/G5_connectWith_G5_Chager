#include "../Main_Define.H"




void	I2C_Write(unsigned int Device_ID, unsigned int Reg_Addr  , unsigned char *Buff_Addr , unsigned char Leng)
{
	while(I2C1STATbits.BCL)
	{
		I2C1STATbits.BCL=0;
	}
	while(I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RCEN ||I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);
	
	
	I2C_Data.Address =	Device_ID;	 
	I2C_Data.R_W = 			Comand_write;
	I2C_Data.Addr_H =		(Reg_Addr&0xFF00)>>8;
	I2C_Data.Addr_L =		(Reg_Addr&0xFF);
	I2C_Data.Data_R_W = Comand_write;
	I2C_Data.ALL_IF=0;
	I2C_Data.RTIndex = 0;
	I2C_Data.Data_R_W = Comand_write;
	I2C_Data.Data_Addr=(unsigned int)Buff_Addr;		
	I2C_Data.Busy_IF=1;
	I2C_Data.Index1=3;		
	I2C_Data.Index2=Leng;
	
	I2C_Buffer_index=&I2C_Data.Address;//把IC2結構位置放入
	
	I2CStat;				// 發出啟始位元		
}
void	I2C_Read(unsigned int Device_ID , unsigned int Reg_Addr  ,unsigned char *Buff_Addr , unsigned char Leng)
{

	
	while(I2C1STATbits.BCL)
	{
		I2C1STATbits.BCL=0;
		I2C1CONbits.PEN = 1	;
	}
	while(I2C1CONbits.SEN || I2C1CONbits.PEN || I2C1CONbits.RCEN ||I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT);


	I2C_Data.Address =	Device_ID;	 
	I2C_Data.R_W = 			Comand_write;
	I2C_Data.Addr_H =		(Reg_Addr&0xFF00)>>8;
	I2C_Data.Addr_L =		(Reg_Addr&0xFF);
	I2C_Data.Data_R_W = Comand_read;//要先寫入位置
	I2C_Data.ALL_IF=0;
	I2C_Data.RTIndex = 0;
	I2C_Data.Data_R_W = Comand_read;
	I2C_Data.Data_Addr=(unsigned int)Buff_Addr;
	I2C_Data.Busy_IF=1;
	I2C_Data.Index1=3;		
	I2C_Data.Index2=Leng;	
			
	I2C_Buffer_index=&I2C_Data.Address;		
	I2CStat;				// 發出啟始位元	
		
}	



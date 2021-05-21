#include "../Main_Define.H"


void MOXA_Work_Function(void)
{
		unsigned int 	math_a,math_b,math_c,math_d;	
		unsigned char *Data_index,*index;//index:��ƭ�l��m Data_index:��ƭn���s�\�񪺦�m
		unsigned char Erro_IF=0;
		unsigned int 	math_e;
		//unsigned int 	math_g,math_h;// �M�Ϊ� ���i�H�� ���i�H��ƭ�
		unsigned long math_f;
		math_a=0;
		math_b=0;
		math_c=0;
		math_d=0;
		math_e=0;
		
		
		math_a=MOXA_CRC_Check();
		MOXA.RIF=0;
		if(math_a==1)
		{
			if(MOXA.ID==0)
			{
				
			}
			else
			{
				if(MOXA.Return_Mode ==1)//�^�Ǯw�ۭp����٬O�^��BMS���
				{
					if(MOXA.ID!=IC_Data.My_ID)MOXA.Fuc=0;
 					if(MOXA.Fuc==0x03)
					{
						if(MOXA.Reg_H==0x00)
						{						
							MOXA.Value_H=MOXA.Quantity_H;
							MOXA.Value_L=MOXA.Quantity_L;
							Data_index=&MOXA.Reg_L;//�n�ǰe����ư}�C���Ĥ@�Ӧ�m
							MOXA.Reg_H=0;//��ƶq�O�ƭ��m
							math_c=MOXA.Reg_L;
							math_b=0;
							math_d=MOXA.Value;
							while(math_d)
							{
								switch(math_c)
								{							

									case 0x01://Ū���q���q�y+-�H�Τp���I
											index=&Coulomb_Data.x1;
											math_b=2;				
										break;										
									case 0x02://Ū���q��
										//	index=&IC_Data.Fake_Voltage;
											index=&Coulomb_Data.Voltage;
											math_b=2;		
										break;
									case 0x03://Ū���q�y
											index=&Coulomb_Data.Current;
											math_b=2;						
										break;												
									case 0x04://Ū���ثe�q�e�q
											index=&Coulomb_Data.Residual_Electricity;
											math_b=2;											
										break;	
									case 0x05://Ū���B�w�q�e�q
											index=&Coulomb_Data.Nominal_Battery_Capacity;
											math_b=2;						
										break;												
									case 0x06://Ū���q�e�q�ʤ���
											index=&Coulomb_Data.Battery_Power;			
											math_b=2;											
										break;	
									case 0x07://Ū���ū�
											index=&Coulomb_Data.Temperature1;
											math_b=2;									
										break;	
									case 0x08://Ū��Battery_ID(���x���X �Ȥ�i�H�ۦ�]�w)
											math_e=IC_Data.Save_struct.Battery_ID;
											index=&math_e;
											math_b=2;					
										break;										
									case 0x09://Ū�����l���A
											math_e=IC_Data.Car_Statue;
											index=&math_e;
											math_b=2;					
										break;	
									case 0x0A://Ū���ϥΤ��
											index=&IC_Data.Save_struct.Month;
											math_b=2;					
										break;
									case 0x0B://Ū���ϥΤ��
											index = &IC_Data.Save_struct.Day;
											math_b=2;					
										break;
									case 0x0C://Ū���ϥΤp��
											math_e = IC_Data.Save_struct.Hour;
											index=&math_e;
											math_b=2;					
										break;										
									case 0x0D://Ū���ϥΤ���
											math_e = IC_Data.Save_struct.minute;
											index=&math_e;
											math_b=2;					
										break;		
									case 0x0E://Ū���q���Ѥƫ�A�q���ҳѾl���ݾl���B�e�q 
											math_e = IC_Data.Save_struct.Now_Total_Capacity;
											index=&math_e;
											math_b=2;					
										break;
									case 0x0F://Ū�����q��
											index=&IC_Data.Fake_Voltage;
											math_b=2;						
										break;		
                                    case 0x10:
                                            index=&Coulomb_Data.x2;
                                            math_b=2;						
                                        break;   
									case 0xA0://Ū���q���Ǹ�
											index=&IC_Data.Save_struct.S_N[0];
											math_b=8;
                                        break;
									case 0xA4://Ū��
														
										break;		
																																																														
									case 0xFF://Ū���^��MODE				
											math_e=MOXA.Return_Mode;
											index=&math_e;
											math_b=2;
										break;									
												
												
									default ://����g���g�s���ɭ� �^��0
											Repeat_MOXA_Erro(Reg_Add_Erro);
											Erro_IF=1;
										break;
																																								
								}
								if(!Erro_IF)
								{							
									if(math_b==2)
									{
										MOXA.Value_L=*index;				//���ư�HL�A��
										index++;					
										MOXA.Value_H=*index;				//���ư�HL�A��
	
										*Data_index=MOXA.Value_H;	//��n�ǰe����Ʃ��ǰe�ȦsBUFFER��
										Data_index++;							//�ǰe�ȦsBUFFER+1	(Byte)
										*Data_index=MOXA.Value_L;	//��n�ǰe����Ʃ��ǰe�ȦsBUFFER��	
										Data_index++;	
										MOXA.Reg_H+=2;
										math_c++;							//��Ū�������в��ʨ�U�@�ӭnŪ�����Ȧs��				
										math_d-=1;							//�nŪ�����Ȧs���ƶq�p��-1					
									}
									else
									{
										for(math_a=0;math_a<math_b;math_a++)
										{
											*Data_index=*index;	//��n�ǰe����Ʃ��ǰe�ȦsBUFFER�� 
											index++;						//�n�ǰe����ƪ���m+1	(Byte)
											Data_index++;				//�ǰe�ȦsBUFFER+1	(Byte)
											MOXA.Reg_H++;				//�ƶq�O��+1
											
										}
										math_d-=math_b/2;							//�nŪ�����Ȧs���ƶq�p��-1	
										math_c+=math_b/2;							//��Ū�������в��ʨ�U�@�ӭnŪ�����Ȧs��									
									}									
								}
								else
								{
									math_d=0;
								}							
							}						
							if(!Erro_IF)
							{
								Sent_MOXA_Data(Data_index);
							}								
						}				
					}
					else if(MOXA.Fuc==0x06)
					{
						if(MOXA.Reg_H==0x00)
						{						
							MOXA.Value_H=MOXA.Quantity_H;
							MOXA.Value_L=MOXA.Quantity_L;
							Data_index=&MOXA.Data_H;//�n�Q�g�J������ư}�C���Ĥ@�Ӧ�m
							MOXA.Reg_H=0;//��ƶq�O�ƭ��m
							math_c=MOXA.Reg_L;
							math_b=0;
                            MOXA.Value = ((MOXA.Value_H<<8) + MOXA.Value_L); //�N�g�J���ƭȦX�_��
							math_d=MOXA.Value; //�g�J���ƭ�
							while(math_d)
							{
								switch(math_c)
								{	
                                    case 0x05://��reset�w�ɼƥi�H��_�쥻��
                                            math_e=0x0001;
                                            
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(0x09,0x0003);//0x0009  �зǹq���e�q 0.0~6553.5AH �אּ0.1ah
                                            while(!ModBus_Receiver.TIF);
                                            ModBus_Receiver.TIF=0;	
                                            
                                            
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(0x0A,0x0253);//�Nreset�q����^59.5V
                                            while(!ModBus_Receiver.TIF);
                                            ModBus_Receiver.TIF=0;
                                            
                                            
                                            index=&math_e; //�ثe�q���e�q
                                            math_b=2;
                                        break;
                                    case 0x06://�]���o�ͤF�w�ɼƬ�-�άO0�A�n�Nreset�w�ɼƪ��q���אּ39v �w�ɼƧאּ0.1�w��
                                            math_e=0x0001;
                                            
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(0x09,0x0002);//0x0009  �зǹq���e�q 0.0~6553.5AH �אּ0.1ah
                                            while(!ModBus_Receiver.TIF);
                                            ModBus_Receiver.TIF=0;	
                                            
                                            
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(0x0A,0x0186);//�Nreset�q���אּ39V
                                            while(!ModBus_Receiver.TIF);
                                            ModBus_Receiver.TIF=0;
                                            
                                            
                                            index=&math_e; //�ثe�q���e�q
                                            math_b=2;
                                        break;
                                    case 0x07://�N�w�ɼƧ令0.1Ah
                                            Coulomb_Data.Residual_Electricity = math_d; //�N�g�J�ȵ��ثe�q���e�q
                                            math_e=Coulomb_Data.Residual_Electricity;
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(math_c,Coulomb_Data.Residual_Electricity);//0x0007  �ثe�q���e�q 0.0~6553.5AH //�N�ثe�w�ɼƧ令0.1Ah
											index=&math_e;
											math_b=2;					
										break;
                                    case 0x09://���ɪ��ѤU�q�q�g��reset�w�ɼ�
                                            math_e=Coulomb_Data.Residual_Electricity;
                                            IC_Data.Save_struct.Now_Total_Capacity = Coulomb_Data.Residual_Electricity;
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(math_c,Coulomb_Data.Residual_Electricity);//0x0009  �зǹq���e�q 0.0~6553.5AH ���ɪ��ثe�q�e�q�g�캡�w��
                                            index=&math_e; //�ثe�q���e�q
                                            math_b=2;					
                                    break;
									case 0x08://Ū��Battery_ID(���x���X �Ȥ�i�H�ۦ�]�w)
											math_e=IC_Data.Save_struct.Battery_ID;
											index=&math_e;
											math_b=2;					
                                    break;
                                    default ://����g���g�s���ɭ� �^��0
                                        Repeat_MOXA_Erro(Reg_Add_Erro);
                                        Erro_IF=1;
                                    break;
								}
                                if(!Erro_IF)
								{							
									if(math_b==2)
									{
										MOXA.Value_L=*index;				//���ư�HL�A��
										index++;					
										MOXA.Value_H=*index;				//���ư�HL�A��
	
										*Data_index=MOXA.Value_H;	//��n�ǰe����Ʃ��ǰe�ȦsBUFFER��
										Data_index++;							//�ǰe�ȦsBUFFER+1	(Byte)
										*Data_index=MOXA.Value_L;	//��n�ǰe����Ʃ��ǰe�ȦsBUFFER��	
										Data_index++;
										math_d=0;							//�nŪ�����Ȧs���ƶq�p���k0				
									}
									else
									{
										for(math_a=0;math_a<math_b;math_a++)
										{
											*Data_index=*index;	//��n�ǰe����Ʃ��ǰe�ȦsBUFFER�� 
											index++;						//�n�ǰe����ƪ���m+1	(Byte)
											Data_index++;				//�ǰe�ȦsBUFFER+1	(Byte)
											MOXA.Reg_H++;				//�ƶq�O��+1
											
										}
										math_d-=math_b/2;							//�nŪ�����Ȧs���ƶq�p��-1	
										math_c+=math_b/2;							//��Ū�������в��ʨ�U�@�ӭnŪ�����Ȧs��									
									}									
								}
								else
								{
									math_d=0;
								}
                                
							}
                            if(!Erro_IF)
							{
								feedback_MOXA_Data(Data_index);
							}
						}										
					}
					else
					{
							Repeat_MOXA_Erro(Fuc_Erro);
					}						
				}
				else if(MOXA.Return_Mode ==0)//�^�Ǯw�ۭp����٬O�^��BMS���
				{
					if(MOXA.ID!=IC_Data.My_ID)MOXA.Fuc=0;
					if(MOXA.Fuc==0x03)
					{
						if(MOXA.Reg_H==0x00)
						{						
							MOXA.Value_H=MOXA.Quantity_H;
							MOXA.Value_L=MOXA.Quantity_L;
							Data_index=&MOXA.Reg_L;//�n�ǰe����ư}�C���Ĥ@�Ӧ�m
							MOXA.Reg_H=0;//��ƶq�O�ƭ��m
							math_c=MOXA.Reg_L;
							math_b=0;
							math_d=MOXA.Value;
							while(math_d)
							{
								switch(math_c)
								{							

									case 0x01://Ū���q���q�y+-�H�Τp���I
											index=&Coulomb_Data.x1;
											math_b=2;				
										break;										
									case 0x02://Ū���q��
											index=&IC_Data.Fake_Voltage;
											math_b=2;		
										break;
									case 0x03://Ū���q�y
											index=&Coulomb_Data.Current;
											math_b=2;						
										break;												
									case 0x04://Ū���q�e�q�ʤ���
											index=&Coulomb_Data.Battery_Power;
											math_b=2;													
										break;	
									case 0x05://Ū���ū�
											index=&Coulomb_Data.Temperature1;
											math_b=2;		
										break;												
									case 0x06://Ū���Ǹ�
											index=&IC_Data.Save_struct.S_N;
											math_b=12;		
										break;	
									case 0x07://Ū���ϥ�
											index=&IC_Data.Save_struct.Month;
											math_b=4;	
										break;										
									case 0x08:		
											index=&IC_Data.Save_struct.Day;
											math_b=4;	
										break;									
												
									default ://����g���g�s���ɭ� �^��0
											Repeat_MOXA_Erro(Reg_Add_Erro);
											Erro_IF=1;
										break;
																																								
								}
								if(!Erro_IF)
								{							
									if(math_b==2)
									{
										MOXA.Value_L=*index;				//���ư�HL�A��
										index++;					
										MOXA.Value_H=*index;				//���ư�HL�A��
	
										*Data_index=MOXA.Value_H;	//��n�ǰe����Ʃ��ǰe�ȦsBUFFER��
										Data_index++;							//�ǰe�ȦsBUFFER+1	(Byte)
										*Data_index=MOXA.Value_L;	//��n�ǰe����Ʃ��ǰe�ȦsBUFFER��	
										Data_index++;	
										MOXA.Reg_H+=2;
										math_c++;							//��Ū�������в��ʨ�U�@�ӭnŪ�����Ȧs��				
										math_d-=1;							//�nŪ�����Ȧs���ƶq�p��-1					
									}
									else
									{
										for(math_a=0;math_a<math_b;math_a++)
										{
											*Data_index=*index;	//��n�ǰe����Ʃ��ǰe�ȦsBUFFER�� 
											index++;						//�n�ǰe����ƪ���m+1	(Byte)
											Data_index++;				//�ǰe�ȦsBUFFER+1	(Byte)
											MOXA.Reg_H++;				//�ƶq�O��+1
											
										}
										math_d-=math_b/2;							//�nŪ�����Ȧs���ƶq�p��-1	
										math_c+=math_b/2;							//��Ū�������в��ʨ�U�@�ӭnŪ�����Ȧs��									
									}									
								}
								else
								{
									math_d=0;
								}							
							}						
							if(!Erro_IF)
							{
								Sent_MOXA_Data(Data_index);
							}								
						}				
					}
					else if(MOXA.Fuc==0x06)
					{
						
					}
					else
					{
							Repeat_MOXA_Erro(Fuc_Erro);
					}											
				}							
			}			
		}
}

#include "../Main_Define.H"


void MOXA_Work_Function(void)
{
		unsigned int 	math_a,math_b,math_c,math_d;	
		unsigned char *Data_index,*index;//index:資料原始位置 Data_index:資料要重新擺放的位置
		unsigned char Erro_IF=0;
		unsigned int 	math_e;
		//unsigned int 	math_g,math_h;// 專用的 不可以動 不可以填數值
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
				if(MOXA.Return_Mode ==1)//回傳庫倫計資料還是回傳BMS資料
				{
					if(MOXA.ID!=IC_Data.My_ID)MOXA.Fuc=0;
 					if(MOXA.Fuc==0x03)
					{
						if(MOXA.Reg_H==0x00)
						{						
							MOXA.Value_H=MOXA.Quantity_H;
							MOXA.Value_L=MOXA.Quantity_L;
							Data_index=&MOXA.Reg_L;//要傳送的資料陣列的第一個位置
							MOXA.Reg_H=0;//資料量記數重置
							math_c=MOXA.Reg_L;
							math_b=0;
							math_d=MOXA.Value;
							while(math_d)
							{
								switch(math_c)
								{							

									case 0x01://讀取電壓電流+-以及小數點
											index=&Coulomb_Data.x1;
											math_b=2;				
										break;										
									case 0x02://讀取電壓
										//	index=&IC_Data.Fake_Voltage;
											index=&Coulomb_Data.Voltage;
											math_b=2;		
										break;
									case 0x03://讀取電流
											index=&Coulomb_Data.Current;
											math_b=2;						
										break;												
									case 0x04://讀取目前電容量
											index=&Coulomb_Data.Residual_Electricity;
											math_b=2;											
										break;	
									case 0x05://讀取額定電容量
											index=&Coulomb_Data.Nominal_Battery_Capacity;
											math_b=2;						
										break;												
									case 0x06://讀取電容量百分比
											index=&Coulomb_Data.Battery_Power;			
											math_b=2;											
										break;	
									case 0x07://讀取溫度
											index=&Coulomb_Data.Temperature1;
											math_b=2;									
										break;	
									case 0x08://讀取Battery_ID(機台號碼 客戶可以自行設定)
											math_e=IC_Data.Save_struct.Battery_ID;
											index=&math_e;
											math_b=2;					
										break;										
									case 0x09://讀取車子狀態
											math_e=IC_Data.Car_Statue;
											index=&math_e;
											math_b=2;					
										break;	
									case 0x0A://讀取使用月份
											index=&IC_Data.Save_struct.Month;
											math_b=2;					
										break;
									case 0x0B://讀取使用日期
											index = &IC_Data.Save_struct.Day;
											math_b=2;					
										break;
									case 0x0C://讀取使用小時
											math_e = IC_Data.Save_struct.Hour;
											index=&math_e;
											math_b=2;					
										break;										
									case 0x0D://讀取使用分鐘
											math_e = IC_Data.Save_struct.minute;
											index=&math_e;
											math_b=2;					
										break;		
									case 0x0E://讀取電池老化後，電池所剩餘的殘餘滿額容量 
											math_e = IC_Data.Save_struct.Now_Total_Capacity;
											index=&math_e;
											math_b=2;					
										break;
									case 0x0F://讀取假電壓
											index=&IC_Data.Fake_Voltage;
											math_b=2;						
										break;		
                                    case 0x10:
                                            index=&Coulomb_Data.x2;
                                            math_b=2;						
                                        break;   
									case 0xA0://讀取電池序號
											index=&IC_Data.Save_struct.S_N[0];
											math_b=8;
                                        break;
									case 0xA4://讀取
														
										break;		
																																																														
									case 0xFF://讀取回傳MODE				
											math_e=MOXA.Return_Mode;
											index=&math_e;
											math_b=2;
										break;									
												
												
									default ://當對方寫錯讚存器時候 回傳0
											Repeat_MOXA_Erro(Reg_Add_Erro);
											Erro_IF=1;
										break;
																																								
								}
								if(!Erro_IF)
								{							
									if(math_b==2)
									{
										MOXA.Value_L=*index;				//把資料做HL顛倒
										index++;					
										MOXA.Value_H=*index;				//把資料做HL顛倒
	
										*Data_index=MOXA.Value_H;	//把要傳送的資料放到傳送暫存BUFFER裡
										Data_index++;							//傳送暫存BUFFER+1	(Byte)
										*Data_index=MOXA.Value_L;	//把要傳送的資料放到傳送暫存BUFFER裡	
										Data_index++;	
										MOXA.Reg_H+=2;
										math_c++;							//把讀取的指標移動到下一個要讀取的暫存器				
										math_d-=1;							//要讀取的暫存器數量計數-1					
									}
									else
									{
										for(math_a=0;math_a<math_b;math_a++)
										{
											*Data_index=*index;	//把要傳送的資料放到傳送暫存BUFFER裡 
											index++;						//要傳送的資料的位置+1	(Byte)
											Data_index++;				//傳送暫存BUFFER+1	(Byte)
											MOXA.Reg_H++;				//數量記數+1
											
										}
										math_d-=math_b/2;							//要讀取的暫存器數量計數-1	
										math_c+=math_b/2;							//把讀取的指標移動到下一個要讀取的暫存器									
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
							Data_index=&MOXA.Data_H;//要被寫入的的資料陣列的第一個位置
							MOXA.Reg_H=0;//資料量記數重置
							math_c=MOXA.Reg_L;
							math_b=0;
                            MOXA.Value = ((MOXA.Value_H<<8) + MOXA.Value_L); //將寫入的數值合起來
							math_d=MOXA.Value; //寫入的數值
							while(math_d)
							{
								switch(math_c)
								{	
                                    case 0x05://放reset安時數可以恢復原本的
                                            math_e=0x0001;
                                            
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(0x09,0x0003);//0x0009  標準電池容量 0.0~6553.5AH 改為0.1ah
                                            while(!ModBus_Receiver.TIF);
                                            ModBus_Receiver.TIF=0;	
                                            
                                            
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(0x0A,0x0253);//將reset電壓改回59.5V
                                            while(!ModBus_Receiver.TIF);
                                            ModBus_Receiver.TIF=0;
                                            
                                            
                                            index=&math_e; //目前電池容量
                                            math_b=2;
                                        break;
                                    case 0x06://因為發生了安時數為-或是0，要將reset安時數的電壓改為39v 安時數改為0.1安時
                                            math_e=0x0001;
                                            
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(0x09,0x0002);//0x0009  標準電池容量 0.0~6553.5AH 改為0.1ah
                                            while(!ModBus_Receiver.TIF);
                                            ModBus_Receiver.TIF=0;	
                                            
                                            
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(0x0A,0x0186);//將reset電壓改為39V
                                            while(!ModBus_Receiver.TIF);
                                            ModBus_Receiver.TIF=0;
                                            
                                            
                                            index=&math_e; //目前電池容量
                                            math_b=2;
                                        break;
                                    case 0x07://將安時數改成0.1Ah
                                            Coulomb_Data.Residual_Electricity = math_d; //將寫入值給目前電池容量
                                            math_e=Coulomb_Data.Residual_Electricity;
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(math_c,Coulomb_Data.Residual_Electricity);//0x0007  目前電池容量 0.0~6553.5AH //將目前安時數改成0.1Ah
											index=&math_e;
											math_b=2;					
										break;
                                    case 0x09://把當時的剩下電量寫到reset安時數
                                            math_e=Coulomb_Data.Residual_Electricity;
                                            IC_Data.Save_struct.Now_Total_Capacity = Coulomb_Data.Residual_Electricity;
                                            Unlock_Coulomb();
                                            Write_Coulomb_Data(math_c,Coulomb_Data.Residual_Electricity);//0x0009  標準電池容量 0.0~6553.5AH 把當時的目前電容量寫到滿安時
                                            index=&math_e; //目前電池容量
                                            math_b=2;					
                                    break;
									case 0x08://讀取Battery_ID(機台號碼 客戶可以自行設定)
											math_e=IC_Data.Save_struct.Battery_ID;
											index=&math_e;
											math_b=2;					
                                    break;
                                    default ://當對方寫錯讚存器時候 回傳0
                                        Repeat_MOXA_Erro(Reg_Add_Erro);
                                        Erro_IF=1;
                                    break;
								}
                                if(!Erro_IF)
								{							
									if(math_b==2)
									{
										MOXA.Value_L=*index;				//把資料做HL顛倒
										index++;					
										MOXA.Value_H=*index;				//把資料做HL顛倒
	
										*Data_index=MOXA.Value_H;	//把要傳送的資料放到傳送暫存BUFFER裡
										Data_index++;							//傳送暫存BUFFER+1	(Byte)
										*Data_index=MOXA.Value_L;	//把要傳送的資料放到傳送暫存BUFFER裡	
										Data_index++;
										math_d=0;							//要讀取的暫存器數量計數歸0				
									}
									else
									{
										for(math_a=0;math_a<math_b;math_a++)
										{
											*Data_index=*index;	//把要傳送的資料放到傳送暫存BUFFER裡 
											index++;						//要傳送的資料的位置+1	(Byte)
											Data_index++;				//傳送暫存BUFFER+1	(Byte)
											MOXA.Reg_H++;				//數量記數+1
											
										}
										math_d-=math_b/2;							//要讀取的暫存器數量計數-1	
										math_c+=math_b/2;							//把讀取的指標移動到下一個要讀取的暫存器									
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
				else if(MOXA.Return_Mode ==0)//回傳庫倫計資料還是回傳BMS資料
				{
					if(MOXA.ID!=IC_Data.My_ID)MOXA.Fuc=0;
					if(MOXA.Fuc==0x03)
					{
						if(MOXA.Reg_H==0x00)
						{						
							MOXA.Value_H=MOXA.Quantity_H;
							MOXA.Value_L=MOXA.Quantity_L;
							Data_index=&MOXA.Reg_L;//要傳送的資料陣列的第一個位置
							MOXA.Reg_H=0;//資料量記數重置
							math_c=MOXA.Reg_L;
							math_b=0;
							math_d=MOXA.Value;
							while(math_d)
							{
								switch(math_c)
								{							

									case 0x01://讀取電壓電流+-以及小數點
											index=&Coulomb_Data.x1;
											math_b=2;				
										break;										
									case 0x02://讀取電壓
											index=&IC_Data.Fake_Voltage;
											math_b=2;		
										break;
									case 0x03://讀取電流
											index=&Coulomb_Data.Current;
											math_b=2;						
										break;												
									case 0x04://讀取電容量百分比
											index=&Coulomb_Data.Battery_Power;
											math_b=2;													
										break;	
									case 0x05://讀取溫度
											index=&Coulomb_Data.Temperature1;
											math_b=2;		
										break;												
									case 0x06://讀取序號
											index=&IC_Data.Save_struct.S_N;
											math_b=12;		
										break;	
									case 0x07://讀取使用
											index=&IC_Data.Save_struct.Month;
											math_b=4;	
										break;										
									case 0x08:		
											index=&IC_Data.Save_struct.Day;
											math_b=4;	
										break;									
												
									default ://當對方寫錯讚存器時候 回傳0
											Repeat_MOXA_Erro(Reg_Add_Erro);
											Erro_IF=1;
										break;
																																								
								}
								if(!Erro_IF)
								{							
									if(math_b==2)
									{
										MOXA.Value_L=*index;				//把資料做HL顛倒
										index++;					
										MOXA.Value_H=*index;				//把資料做HL顛倒
	
										*Data_index=MOXA.Value_H;	//把要傳送的資料放到傳送暫存BUFFER裡
										Data_index++;							//傳送暫存BUFFER+1	(Byte)
										*Data_index=MOXA.Value_L;	//把要傳送的資料放到傳送暫存BUFFER裡	
										Data_index++;	
										MOXA.Reg_H+=2;
										math_c++;							//把讀取的指標移動到下一個要讀取的暫存器				
										math_d-=1;							//要讀取的暫存器數量計數-1					
									}
									else
									{
										for(math_a=0;math_a<math_b;math_a++)
										{
											*Data_index=*index;	//把要傳送的資料放到傳送暫存BUFFER裡 
											index++;						//要傳送的資料的位置+1	(Byte)
											Data_index++;				//傳送暫存BUFFER+1	(Byte)
											MOXA.Reg_H++;				//數量記數+1
											
										}
										math_d-=math_b/2;							//要讀取的暫存器數量計數-1	
										math_c+=math_b/2;							//把讀取的指標移動到下一個要讀取的暫存器									
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

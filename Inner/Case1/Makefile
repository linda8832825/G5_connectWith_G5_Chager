# MPLAB IDE generated this makefile for use with GNU make.
# Project: Inner_Case1.mcp
# Date: Wed Mar 13 20:34:45 2019

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

Inner_Case1.hex : Inner_Case1.cof
	$(HX) "Inner_Case1.cof"

Inner_Case1.cof : Main.o Initial_IO.o Initial_clock.o Timer1.o I2C_Initial.o I2C_EEROM_Function.o I2C_Interrupt.o Coulomb_Fuctione.o Initial_Coulomb_UART.o U1Interrup.o Conversion_Data_to_BMS.o Sent_Data_To_Pannal.o Initial_MOXA_UART.o MOXA_Interrupt_Fuctione.o MOXA_Work_Function.o Initial_BMS_UART.o MOXA_Function.o BMS_Fuction.o Timer4_initial.o T4Interrupt.o
	$(CC) -mcpu=24FJ128GA106 "Main.o" "Initial_IO.o" "Initial_clock.o" "Timer1.o" "I2C_Initial.o" "I2C_EEROM_Function.o" "I2C_Interrupt.o" "Coulomb_Fuctione.o" "Initial_Coulomb_UART.o" "U1Interrup.o" "Conversion_Data_to_BMS.o" "Sent_Data_To_Pannal.o" "Initial_MOXA_UART.o" "MOXA_Interrupt_Fuctione.o" "MOXA_Work_Function.o" "Initial_BMS_UART.o" "MOXA_Function.o" "BMS_Fuction.o" "Timer4_initial.o" "T4Interrupt.o" -o"Inner_Case1.cof" -Wl,--script="p24FJ128GA106.gld",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=__ICD2RAM=1,-Map="Inner_Case1.map",--report-mem

Main.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Main.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Main.c" -o"Main.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Initial_IO.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Initial_IO.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Initial_IO.c" -o"Initial_IO.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Initial_clock.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Initial_clock.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Initial_clock.c" -o"Initial_clock.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Timer1.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Timer1/Timer1.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Timer1\Timer1.c" -o"Timer1.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

I2C_Initial.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H I2C/I2C_Initial.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "I2C\I2C_Initial.c" -o"I2C_Initial.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

I2C_EEROM_Function.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Flash/I2C_EEROM_Function.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Flash\I2C_EEROM_Function.c" -o"I2C_EEROM_Function.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

I2C_Interrupt.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H I2C/I2C_Interrupt.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "I2C\I2C_Interrupt.c" -o"I2C_Interrupt.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Coulomb_Fuctione.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Coulomb/Coulomb_Fuctione.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Coulomb\Coulomb_Fuctione.c" -o"Coulomb_Fuctione.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Initial_Coulomb_UART.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Coulomb/Initial_Coulomb_UART.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Coulomb\Initial_Coulomb_UART.c" -o"Initial_Coulomb_UART.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

U1Interrup.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Coulomb/U1Interrup.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Coulomb\U1Interrup.c" -o"U1Interrup.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Conversion_Data_to_BMS.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Customer_Pannal/Conversion_Data_to_BMS.C
	$(CC) -mcpu=24FJ128GA106 -x c -c "Customer_Pannal\Conversion_Data_to_BMS.C" -o"Conversion_Data_to_BMS.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Sent_Data_To_Pannal.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Customer_Pannal/Sent_Data_To_Pannal.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Customer_Pannal\Sent_Data_To_Pannal.c" -o"Sent_Data_To_Pannal.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Initial_MOXA_UART.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H MOXA/Initial_MOXA_UART.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "MOXA\Initial_MOXA_UART.c" -o"Initial_MOXA_UART.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

MOXA_Interrupt_Fuctione.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H MOXA/MOXA_Interrupt_Fuctione.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "MOXA\MOXA_Interrupt_Fuctione.c" -o"MOXA_Interrupt_Fuctione.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

MOXA_Work_Function.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H MOXA/MOXA_Work_Function.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "MOXA\MOXA_Work_Function.c" -o"MOXA_Work_Function.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Initial_BMS_UART.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Customer_Pannal/Initial_BMS_UART.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Customer_Pannal\Initial_BMS_UART.c" -o"Initial_BMS_UART.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

MOXA_Function.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H MOXA/MOXA_Function.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "MOXA\MOXA_Function.c" -o"MOXA_Function.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

BMS_Fuction.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Customer_Pannal/BMS_Fuction.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Customer_Pannal\BMS_Fuction.c" -o"BMS_Fuction.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

Timer4_initial.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Timer4/Timer4_initial.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Timer4\Timer4_initial.c" -o"Timer4_initial.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

T4Interrupt.o : MOXA/MOXA_define.h I2C/I2C_define.h Flash/I2C_EEPROM_define.h Customer_Pannal/Customer_Pannal_define.h Coulomb/Coulomb_define.h p24FJ128GA106.h Main_Define.H Timer4/T4Interrupt.c
	$(CC) -mcpu=24FJ128GA106 -x c -c "Timer4\T4Interrupt.c" -o"T4Interrupt.o" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

clean : 
	$(RM) "Main.o" "Initial_IO.o" "Initial_clock.o" "Timer1.o" "I2C_Initial.o" "I2C_EEROM_Function.o" "I2C_Interrupt.o" "Coulomb_Fuctione.o" "Initial_Coulomb_UART.o" "U1Interrup.o" "Conversion_Data_to_BMS.o" "Sent_Data_To_Pannal.o" "Initial_MOXA_UART.o" "MOXA_Interrupt_Fuctione.o" "MOXA_Work_Function.o" "Initial_BMS_UART.o" "MOXA_Function.o" "BMS_Fuction.o" "Timer4_initial.o" "T4Interrupt.o" "Inner_Case1.cof" "Inner_Case1.hex"


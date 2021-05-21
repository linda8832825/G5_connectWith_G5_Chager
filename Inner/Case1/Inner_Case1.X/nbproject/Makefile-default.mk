#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Inner_Case1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Inner_Case1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../Timer4/Timer4_initial.c ../Timer4/T4Interrupt.c ../Coulomb/Coulomb_Fuctione.c ../Coulomb/Initial_Coulomb_UART.c ../Coulomb/U1Interrup.c ../I2C/I2C_Initial.c ../I2C/I2C_Interrupt.c ../MOXA/Initial_MOXA_UART.c ../MOXA/MOXA_Interrupt_Fuctione.c ../MOXA/MOXA_Work_Function.c ../MOXA/MOXA_Function.c ../BMS/BMS_Fuction.c ../BMS/Conversion_Data_to_BMS.c ../BMS/Initial_BMS_UART.c ../BMS/Sent_Data_To_PLC.c ../BMS/U2Interrupt.c ../Timer1/Timer1.c ../Main.c ../Initial_IO.c ../Initial_clock.c ../Flash/I2C_EEROM_Function.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1705463586/Timer4_initial.o ${OBJECTDIR}/_ext/1705463586/T4Interrupt.o ${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o ${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o ${OBJECTDIR}/_ext/941913586/U1Interrup.o ${OBJECTDIR}/_ext/1360894859/I2C_Initial.o ${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o ${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o ${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o ${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o ${OBJECTDIR}/_ext/761784582/MOXA_Function.o ${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o ${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o ${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o ${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o ${OBJECTDIR}/_ext/1360888985/U2Interrupt.o ${OBJECTDIR}/_ext/1705463589/Timer1.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/Initial_IO.o ${OBJECTDIR}/_ext/1472/Initial_clock.o ${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1705463586/Timer4_initial.o.d ${OBJECTDIR}/_ext/1705463586/T4Interrupt.o.d ${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o.d ${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o.d ${OBJECTDIR}/_ext/941913586/U1Interrup.o.d ${OBJECTDIR}/_ext/1360894859/I2C_Initial.o.d ${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o.d ${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o.d ${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o.d ${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o.d ${OBJECTDIR}/_ext/761784582/MOXA_Function.o.d ${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o.d ${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o.d ${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o.d ${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o.d ${OBJECTDIR}/_ext/1360888985/U2Interrupt.o.d ${OBJECTDIR}/_ext/1705463589/Timer1.o.d ${OBJECTDIR}/_ext/1472/Main.o.d ${OBJECTDIR}/_ext/1472/Initial_IO.o.d ${OBJECTDIR}/_ext/1472/Initial_clock.o.d ${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1705463586/Timer4_initial.o ${OBJECTDIR}/_ext/1705463586/T4Interrupt.o ${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o ${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o ${OBJECTDIR}/_ext/941913586/U1Interrup.o ${OBJECTDIR}/_ext/1360894859/I2C_Initial.o ${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o ${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o ${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o ${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o ${OBJECTDIR}/_ext/761784582/MOXA_Function.o ${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o ${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o ${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o ${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o ${OBJECTDIR}/_ext/1360888985/U2Interrupt.o ${OBJECTDIR}/_ext/1705463589/Timer1.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/Initial_IO.o ${OBJECTDIR}/_ext/1472/Initial_clock.o ${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o

# Source Files
SOURCEFILES=../Timer4/Timer4_initial.c ../Timer4/T4Interrupt.c ../Coulomb/Coulomb_Fuctione.c ../Coulomb/Initial_Coulomb_UART.c ../Coulomb/U1Interrup.c ../I2C/I2C_Initial.c ../I2C/I2C_Interrupt.c ../MOXA/Initial_MOXA_UART.c ../MOXA/MOXA_Interrupt_Fuctione.c ../MOXA/MOXA_Work_Function.c ../MOXA/MOXA_Function.c ../BMS/BMS_Fuction.c ../BMS/Conversion_Data_to_BMS.c ../BMS/Initial_BMS_UART.c ../BMS/Sent_Data_To_PLC.c ../BMS/U2Interrupt.c ../Timer1/Timer1.c ../Main.c ../Initial_IO.c ../Initial_clock.c ../Flash/I2C_EEROM_Function.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Inner_Case1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA106
MP_LINKER_FILE_OPTION=,--script="..\p24FJ128GA106.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1705463586/Timer4_initial.o: ../Timer4/Timer4_initial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1705463586" 
	@${RM} ${OBJECTDIR}/_ext/1705463586/Timer4_initial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1705463586/Timer4_initial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Timer4/Timer4_initial.c  -o ${OBJECTDIR}/_ext/1705463586/Timer4_initial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1705463586/Timer4_initial.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1705463586/Timer4_initial.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1705463586/T4Interrupt.o: ../Timer4/T4Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1705463586" 
	@${RM} ${OBJECTDIR}/_ext/1705463586/T4Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1705463586/T4Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Timer4/T4Interrupt.c  -o ${OBJECTDIR}/_ext/1705463586/T4Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1705463586/T4Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1705463586/T4Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o: ../Coulomb/Coulomb_Fuctione.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/941913586" 
	@${RM} ${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o.d 
	@${RM} ${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Coulomb/Coulomb_Fuctione.c  -o ${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o: ../Coulomb/Initial_Coulomb_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/941913586" 
	@${RM} ${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Coulomb/Initial_Coulomb_UART.c  -o ${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/941913586/U1Interrup.o: ../Coulomb/U1Interrup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/941913586" 
	@${RM} ${OBJECTDIR}/_ext/941913586/U1Interrup.o.d 
	@${RM} ${OBJECTDIR}/_ext/941913586/U1Interrup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Coulomb/U1Interrup.c  -o ${OBJECTDIR}/_ext/941913586/U1Interrup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/941913586/U1Interrup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/941913586/U1Interrup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360894859/I2C_Initial.o: ../I2C/I2C_Initial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360894859" 
	@${RM} ${OBJECTDIR}/_ext/1360894859/I2C_Initial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360894859/I2C_Initial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../I2C/I2C_Initial.c  -o ${OBJECTDIR}/_ext/1360894859/I2C_Initial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360894859/I2C_Initial.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360894859/I2C_Initial.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o: ../I2C/I2C_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360894859" 
	@${RM} ${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../I2C/I2C_Interrupt.c  -o ${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o: ../MOXA/Initial_MOXA_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761784582" 
	@${RM} ${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MOXA/Initial_MOXA_UART.c  -o ${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o: ../MOXA/MOXA_Interrupt_Fuctione.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761784582" 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o.d 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MOXA/MOXA_Interrupt_Fuctione.c  -o ${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o: ../MOXA/MOXA_Work_Function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761784582" 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o.d 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MOXA/MOXA_Work_Function.c  -o ${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761784582/MOXA_Function.o: ../MOXA/MOXA_Function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761784582" 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Function.o.d 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MOXA/MOXA_Function.c  -o ${OBJECTDIR}/_ext/761784582/MOXA_Function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761784582/MOXA_Function.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/761784582/MOXA_Function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o: ../BMS/BMS_Fuction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/BMS_Fuction.c  -o ${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o: ../BMS/Conversion_Data_to_BMS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/Conversion_Data_to_BMS.c  -o ${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o: ../BMS/Initial_BMS_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/Initial_BMS_UART.c  -o ${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o: ../BMS/Sent_Data_To_PLC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/Sent_Data_To_PLC.c  -o ${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/U2Interrupt.o: ../BMS/U2Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/U2Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/U2Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/U2Interrupt.c  -o ${OBJECTDIR}/_ext/1360888985/U2Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/U2Interrupt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/U2Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1705463589/Timer1.o: ../Timer1/Timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1705463589" 
	@${RM} ${OBJECTDIR}/_ext/1705463589/Timer1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1705463589/Timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Timer1/Timer1.c  -o ${OBJECTDIR}/_ext/1705463589/Timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1705463589/Timer1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1705463589/Timer1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Main.c  -o ${OBJECTDIR}/_ext/1472/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Initial_IO.o: ../Initial_IO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Initial_IO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Initial_IO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Initial_IO.c  -o ${OBJECTDIR}/_ext/1472/Initial_IO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Initial_IO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Initial_IO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Initial_clock.o: ../Initial_clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Initial_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Initial_clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Initial_clock.c  -o ${OBJECTDIR}/_ext/1472/Initial_clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Initial_clock.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Initial_clock.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o: ../Flash/I2C_EEROM_Function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2146075967" 
	@${RM} ${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o.d 
	@${RM} ${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Flash/I2C_EEROM_Function.c  -o ${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1705463586/Timer4_initial.o: ../Timer4/Timer4_initial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1705463586" 
	@${RM} ${OBJECTDIR}/_ext/1705463586/Timer4_initial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1705463586/Timer4_initial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Timer4/Timer4_initial.c  -o ${OBJECTDIR}/_ext/1705463586/Timer4_initial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1705463586/Timer4_initial.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1705463586/Timer4_initial.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1705463586/T4Interrupt.o: ../Timer4/T4Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1705463586" 
	@${RM} ${OBJECTDIR}/_ext/1705463586/T4Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1705463586/T4Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Timer4/T4Interrupt.c  -o ${OBJECTDIR}/_ext/1705463586/T4Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1705463586/T4Interrupt.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1705463586/T4Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o: ../Coulomb/Coulomb_Fuctione.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/941913586" 
	@${RM} ${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o.d 
	@${RM} ${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Coulomb/Coulomb_Fuctione.c  -o ${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/941913586/Coulomb_Fuctione.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o: ../Coulomb/Initial_Coulomb_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/941913586" 
	@${RM} ${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Coulomb/Initial_Coulomb_UART.c  -o ${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/941913586/Initial_Coulomb_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/941913586/U1Interrup.o: ../Coulomb/U1Interrup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/941913586" 
	@${RM} ${OBJECTDIR}/_ext/941913586/U1Interrup.o.d 
	@${RM} ${OBJECTDIR}/_ext/941913586/U1Interrup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Coulomb/U1Interrup.c  -o ${OBJECTDIR}/_ext/941913586/U1Interrup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/941913586/U1Interrup.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/941913586/U1Interrup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360894859/I2C_Initial.o: ../I2C/I2C_Initial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360894859" 
	@${RM} ${OBJECTDIR}/_ext/1360894859/I2C_Initial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360894859/I2C_Initial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../I2C/I2C_Initial.c  -o ${OBJECTDIR}/_ext/1360894859/I2C_Initial.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360894859/I2C_Initial.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360894859/I2C_Initial.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o: ../I2C/I2C_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360894859" 
	@${RM} ${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../I2C/I2C_Interrupt.c  -o ${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360894859/I2C_Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o: ../MOXA/Initial_MOXA_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761784582" 
	@${RM} ${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MOXA/Initial_MOXA_UART.c  -o ${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/761784582/Initial_MOXA_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o: ../MOXA/MOXA_Interrupt_Fuctione.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761784582" 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o.d 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MOXA/MOXA_Interrupt_Fuctione.c  -o ${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/761784582/MOXA_Interrupt_Fuctione.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o: ../MOXA/MOXA_Work_Function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761784582" 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o.d 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MOXA/MOXA_Work_Function.c  -o ${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/761784582/MOXA_Work_Function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/761784582/MOXA_Function.o: ../MOXA/MOXA_Function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/761784582" 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Function.o.d 
	@${RM} ${OBJECTDIR}/_ext/761784582/MOXA_Function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MOXA/MOXA_Function.c  -o ${OBJECTDIR}/_ext/761784582/MOXA_Function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/761784582/MOXA_Function.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/761784582/MOXA_Function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o: ../BMS/BMS_Fuction.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/BMS_Fuction.c  -o ${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/BMS_Fuction.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o: ../BMS/Conversion_Data_to_BMS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/Conversion_Data_to_BMS.c  -o ${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/Conversion_Data_to_BMS.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o: ../BMS/Initial_BMS_UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/Initial_BMS_UART.c  -o ${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/Initial_BMS_UART.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o: ../BMS/Sent_Data_To_PLC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/Sent_Data_To_PLC.c  -o ${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/Sent_Data_To_PLC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360888985/U2Interrupt.o: ../BMS/U2Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360888985" 
	@${RM} ${OBJECTDIR}/_ext/1360888985/U2Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360888985/U2Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../BMS/U2Interrupt.c  -o ${OBJECTDIR}/_ext/1360888985/U2Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360888985/U2Interrupt.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360888985/U2Interrupt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1705463589/Timer1.o: ../Timer1/Timer1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1705463589" 
	@${RM} ${OBJECTDIR}/_ext/1705463589/Timer1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1705463589/Timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Timer1/Timer1.c  -o ${OBJECTDIR}/_ext/1705463589/Timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1705463589/Timer1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1705463589/Timer1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Main.c  -o ${OBJECTDIR}/_ext/1472/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Initial_IO.o: ../Initial_IO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Initial_IO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Initial_IO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Initial_IO.c  -o ${OBJECTDIR}/_ext/1472/Initial_IO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Initial_IO.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Initial_IO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Initial_clock.o: ../Initial_clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Initial_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Initial_clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Initial_clock.c  -o ${OBJECTDIR}/_ext/1472/Initial_clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Initial_clock.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Initial_clock.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o: ../Flash/I2C_EEROM_Function.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2146075967" 
	@${RM} ${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o.d 
	@${RM} ${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Flash/I2C_EEROM_Function.c  -o ${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I".." -I"../Coulomb" -I"../Flash" -I"../I2C" -I"../MOXA" -I"." -msmart-io=1 -Wall -msfr-warn=off   
	@${FIXDEPS} "${OBJECTDIR}/_ext/2146075967/I2C_EEROM_Function.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Inner_Case1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../p24FJ128GA106.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Inner_Case1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/Inner_Case1.X.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Inner_Case1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../p24FJ128GA106.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Inner_Case1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--library-path=".",--no-force-link,--smart-io,-Map="${DISTDIR}/Inner_Case1.X.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Inner_Case1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

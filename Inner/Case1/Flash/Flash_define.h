#ifndef FLASH_DEFINE_H
#define FLASH_DEFINE_H

#define	UINT32	unsigned long
#define	UINT16	unsigned int
#define	UINT8	unsigned char

#define FLASH_ERASEPAGE 0x4042


#define FLASH_PROGLINE  0x4001

#define EEprom_first_use				 0x15400


#define Ch1_Rom_Add EEprom_first_use+0x4
#define Ch2_Rom_Add EEprom_first_use+0x44
#define Ch3_Rom_Add EEprom_first_use+0x84
#define Ch4_Rom_Add EEprom_first_use+0xC4

void FlashReadData(UINT32 ,UINT16 *,UINT8);
void FlashErasePage(UINT32 );
void FlashWriteData(UINT32 ,UINT16 *,UINT8);


/*
#define EEprom_channal_1_Address 0xAAA0
#define EEprom_channal_2_Address 0xAAC8	
#define EEprom_channal_3_Address 0xAB00
#define EEprom_channal_4_Address 0xAB28



void read_all_EEROM_information();

void Write_EEROM_information();
char Read_first_information();
*/
#endif

//	�����`��USB �f�W�^�����o�̓L�b�g�p���C�u����
//		Ver001	2011/06/12	����

#include <p18f2550.h>
#include "asv_io.h"

//�֐���		�F	asv_io_init
//ASOOVU���f�W�^�����o�̓L�b�g�ɍ��킹�ď��������܂�
void asv_io_init(void)
{
    ADCON1 |= 0x0F;	//���ׂăf�W�^�����͂ɂ���

	TRISA = 0x3F;	//RA0/1/2/3/4/5�����
	TRISB = 0;		//RB���o��
	TRISC = 0x07;	//RC0/1/2�����

	ASV_IO_LED1 = ASV_IO_LED_OFF;
	ASV_IO_LED2 = ASV_IO_LED_OFF;
	ASV_IO_LED3 = ASV_IO_LED_OFF;
	ASV_IO_LED4 = ASV_IO_LED_OFF;
	ASV_IO_LED5 = ASV_IO_LED_OFF;
	ASV_IO_LED6 = ASV_IO_LED_OFF;
	ASV_IO_LED7 = ASV_IO_LED_OFF;
	ASV_IO_LED8 = ASV_IO_LED_OFF;
}	


//�֐���		�F	asv_io_set_LED(unsigned char no,unsigned char onff)
//�w�肳�ꂽLED�i�o�́j��ON/OFF���܂�
//����no		�F	LED(�o�́j�̔ԍ��i�P�`8�j
//����onoff	�F	0��OFF�^1��ON
void asv_io_set_LED(unsigned char no, unsigned char onoff)
{
	if(onoff == 0 || onoff == 1)
	{
		switch(no)
		{
			case 1:	ASV_IO_LED1 = onoff;	break;
			case 2:	ASV_IO_LED2 = onoff;	break;
			case 3:	ASV_IO_LED3 = onoff;	break;
			case 4:	ASV_IO_LED4 = onoff;	break;
			case 5:	ASV_IO_LED5 = onoff;	break;
			case 6:	ASV_IO_LED6 = onoff;	break;
			case 7:	ASV_IO_LED7 = onoff;	break;
			case 8:	ASV_IO_LED8 = onoff;	break;
			default: break;
		}
	}	
}	


//�֐���		�F	asv_io_get_SW(unsigned char no)
//�w�肳�ꂽ�X�C�b�`�i���́j�̏�Ԃ�Ԃ��܂�
//����no		�F	�X�C�b�`(���́j�̔ԍ��i1�`10�j
//�Ԃ�l		�F	0��ON�^1��OFF�^�X�C�b�`�ԍ���1�`10�ł͖����Ƃ���0xff
char asv_io_get_SW(unsigned char no)
{
	switch(no)
	{
		case 1:	return ASV_IO_SW1;
		case 2:	return ASV_IO_SW2;
		case 3:	return ASV_IO_SW3;
		case 4:	return ASV_IO_SW4;
		case 5:	return ASV_IO_SW5;
		case 6:	return ASV_IO_SW6;
		case 7:	return ASV_IO_SW7;
		case 8:	return ASV_IO_SW8;
		case 9:	return ASV_IO_SW9;
		case 10:	return ASV_IO_SW10;
		default: return 0xff;
	}	
}
	
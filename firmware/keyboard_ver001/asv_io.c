//	あそ～ぶUSB デジタル入出力キット用ライブラリ
//		Ver001	2011/06/12	初版

#include <p18f2550.h>
#include "asv_io.h"

//関数名		：	asv_io_init
//ASOOVUをデジタル入出力キットに合わせて初期化します
void asv_io_init(void)
{
    ADCON1 |= 0x0F;	//すべてデジタル入力にする

	TRISA = 0x3F;	//RA0/1/2/3/4/5を入力
	TRISB = 0;		//RBを出力
	TRISC = 0x07;	//RC0/1/2を入力

	ASV_IO_LED1 = ASV_IO_LED_OFF;
	ASV_IO_LED2 = ASV_IO_LED_OFF;
	ASV_IO_LED3 = ASV_IO_LED_OFF;
	ASV_IO_LED4 = ASV_IO_LED_OFF;
	ASV_IO_LED5 = ASV_IO_LED_OFF;
	ASV_IO_LED6 = ASV_IO_LED_OFF;
	ASV_IO_LED7 = ASV_IO_LED_OFF;
	ASV_IO_LED8 = ASV_IO_LED_OFF;
}	


//関数名		：	asv_io_set_LED(unsigned char no,unsigned char onff)
//指定されたLED（出力）をON/OFFします
//引数no		：	LED(出力）の番号（１～8）
//引数onoff	：	0でOFF／1でON
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


//関数名		：	asv_io_get_SW(unsigned char no)
//指定されたスイッチ（入力）の状態を返します
//引数no		：	スイッチ(入力）の番号（1～10）
//返り値		：	0でON／1でOFF／スイッチ番号が1～10では無いときは0xff
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
	
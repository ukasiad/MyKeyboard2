//	あそ～ぶUSB デジタル入出力キット用ライブラリ
//		Ver001	2011/06/12	初版


#define	ASV_IO_LED_OFF		0
#define ASV_IO_LED_ON		1

#define ASV_IO_LED1		LATCbits.LATC6
#define ASV_IO_LED2		LATCbits.LATC7
#define ASV_IO_LED3		LATBbits.LATB0
#define ASV_IO_LED4		LATBbits.LATB1
#define ASV_IO_LED5		LATBbits.LATB2
#define ASV_IO_LED6		LATBbits.LATB3
#define ASV_IO_LED7		LATBbits.LATB4
#define ASV_IO_LED8		LATBbits.LATB5
#define ASV_IO_SW1		PORTCbits.RC2
#define ASV_IO_SW2		PORTCbits.RC1
#define ASV_IO_SW3		PORTCbits.RC0
#define ASV_IO_SW4		PORTAbits.RA5
#define ASV_IO_SW5		PORTAbits.RA4
#define ASV_IO_SW6		PORTAbits.RA3
#define ASV_IO_SW7		PORTAbits.RA2
#define ASV_IO_SW8		PORTAbits.RA1
#define ASV_IO_SW9		PORTAbits.RA0
#define ASV_IO_SW10		PORTEbits.RE3


//関数名		：	asv_io_init
//ASOOVUをデジタル入出力キットに合わせて初期化します
void asv_io_init(void);


//関数名		：	asv_io_set_LED(unsigned char no,unsigned char onff)
//指定されたLED（出力）をON/OFFします
//引数no		：	LED(出力）の番号（１～8）
//引数onoff	：	0でOFF／1でON
void asv_io_set_LED(unsigned char no, unsigned char onoff);


//関数名		：	asv_io_get_SW(unsigned char no)
//指定されたスイッチ（入力）の状態を返します
//引数no		：	スイッチ(入力）の番号（1～10）
//返り値		：	0でON／1でOFF
char asv_io_get_SW(unsigned char no);

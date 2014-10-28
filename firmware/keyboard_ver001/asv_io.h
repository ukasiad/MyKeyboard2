//	�����`��USB �f�W�^�����o�̓L�b�g�p���C�u����
//		Ver001	2011/06/12	����


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


//�֐���		�F	asv_io_init
//ASOOVU���f�W�^�����o�̓L�b�g�ɍ��킹�ď��������܂�
void asv_io_init(void);


//�֐���		�F	asv_io_set_LED(unsigned char no,unsigned char onff)
//�w�肳�ꂽLED�i�o�́j��ON/OFF���܂�
//����no		�F	LED(�o�́j�̔ԍ��i�P�`8�j
//����onoff	�F	0��OFF�^1��ON
void asv_io_set_LED(unsigned char no, unsigned char onoff);


//�֐���		�F	asv_io_get_SW(unsigned char no)
//�w�肳�ꂽ�X�C�b�`�i���́j�̏�Ԃ�Ԃ��܂�
//����no		�F	�X�C�b�`(���́j�̔ԍ��i1�`10�j
//�Ԃ�l		�F	0��ON�^1��OFF
char asv_io_get_SW(unsigned char no);

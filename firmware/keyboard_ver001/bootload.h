/*
	PIC18F2550 USBでつく～る用Boolloader用ヘッダファイル
		ver1.00	2010/11/03	初版
	
	このファイルをインクルードするとBOOTLOADER対応ソフトが簡単に作成出来ます。
*/

//コンフィギュレーション
#pragma config PLLDIV   = 2				//
#pragma config CPUDIV   = OSC1_PLL2	
#pragma config USBDIV   = 2
#pragma config FOSC     = HSPLL_HS
#pragma config FCMEN    = OFF
#pragma config IESO     = OFF
#pragma config PWRT     = OFF
#pragma config BOR      = OFF
#pragma config BORV     = 0
#pragma config VREGEN   = ON
#pragma config WDT      = OFF
#pragma config WDTPS    = 1
#pragma config MCLRE    = OFF
#pragma config LPT1OSC  = OFF
#pragma config PBADEN   = OFF
#pragma config CCP2MX   = OFF
#pragma config STVREN   = OFF
#pragma config LVP      = OFF
#pragma config XINST    = OFF
#pragma config DEBUG	= OFF
#pragma config CP0      = OFF
#pragma config CP1      = OFF
#pragma config CP2      = OFF
#pragma config CP3      = OFF
#pragma config CPB      = OFF
#pragma config CPD      = OFF
#pragma config WRT0     = OFF
#pragma config WRT1     = OFF
#pragma config WRT2     = OFF
#pragma config WRT3     = OFF
#pragma config WRTB     = OFF
#pragma config WRTC     = OFF
#pragma config WRTD     = OFF
#pragma config EBTR0    = OFF
#pragma config EBTR1    = OFF
#pragma config EBTR2    = OFF
#pragma config EBTR3    = OFF
#pragma config EBTRB    = OFF


void isr_high(void);	//高位レベル割り込み
void isr_low(void);		//定位レベル割り込み

#define REMAPPED_RESET_VECTOR_ADDRESS			0x1000
#define REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS	0x1008
#define REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS	0x1018

extern void _startup(void);

#pragma code REMAPPED_RESET_VECTOR = REMAPPED_RESET_VECTOR_ADDRESS
void _reset(void)
{
	_asm goto _startup _endasm
}

#pragma code REMAPPED_HIGH_INTERRUPT_VECTOR = REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS
void Remapped_High_ISR (void)
{
     _asm goto isr_high _endasm
}
#pragma code REMAPPED_LOW_INTERRUPT_VECTOR = REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS
void Remapped_Low_ISR (void)
{
     _asm goto isr_low _endasm
}


#pragma code
#pragma interrupt isr_high
#pragma interruptlow isr_low 

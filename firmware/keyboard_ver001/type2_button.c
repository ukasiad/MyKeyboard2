#include <string.h>

#include <p18f2550.h>

#include "type2_button.h"

// �L�[�R�[�h���|�[�g�T�C�Y
#define REPORT_BUFF_SIZE 6

// ���o�̓s����
#define OUTPUT_PIN_MAX  10
#define INPUT_PIN_MAX   8

// �`���^�����O�}���p臒l�B1������̎��Ԃ͓�B
#define CHATTAERING_THRESHOLD   10

// Fn�L�[��0xFF�Ƃ���B�������ꂪ�g����悤�ɂȂ�����Ȃ�Ƃ�����B
#define KB_FN 0xFF
// USB�L�[�R�[�h
#define KB_A            0x04
#define KB_B            0x05
#define KB_C            0x06
#define KB_D            0x07
#define KB_E            0x08
#define KB_F            0x09
#define KB_G            0x0A
#define KB_H            0x0B
#define KB_I            0x0C
#define KB_J            0x0D
#define KB_K            0x0E
#define KB_L            0x0F
#define KB_M            0x10
#define KB_N            0x11
#define KB_O            0x12
#define KB_P            0x13
#define KB_Q            0x14
#define KB_R            0x15
#define KB_S            0x16
#define KB_T            0x17
#define KB_U            0x18
#define KB_V            0x19
#define KB_W            0x1A
#define KB_X            0x1B
#define KB_Y            0x1C
#define KB_Z            0x1D
#define KB_1            0x1E
#define KB_2            0x1F
#define KB_3            0x20
#define KB_4            0x21
#define KB_5            0x22
#define KB_6            0x23
#define KB_7            0x24
#define KB_8            0x25
#define KB_9            0x26
#define KB_0            0x27
#define KB_ENTER        0x28
#define KB_ESPACE       0x29
#define KB_BACKSPACE    0x2A
#define KB_TAB          0x2B
#define KB_SPACE        0x2C
#define KB_HYPHEN       0x2D
#define KB_EQALS        0x2E
#define KB_BRACKET_L    0x2F
#define KB_BRACKET_R    0x30
#define KB_BACKSLASH    0x31
// #define KB_NON_US 0x32
#define KB_SEMI_COLON   0x33
#define KB_APOSTROPHE   0x34
#define KB_GRAVE_ACCENT 0x35
#define KB_COMMA        0x36
#define KB_PERIOD       0x37
#define KB_SLASH        0x38
#define KB_CAPS_LOCK    0x39
#define KB_F1           0x3A
#define KB_F2           0x3B
#define KB_F3           0x3C
#define KB_F4           0x3D
#define KB_F5           0x3E
#define KB_F6           0x3F
#define KB_F7           0x40
#define KB_F8           0x41
#define KB_F9           0x42
#define KB_F10          0x43
#define KB_F11          0x44
#define KB_F12          0x45
#define KB_PRINT_SCREEN 0x46
#define KB_SCROLL_LOCK  0x47
#define KB_PAUSE        0x48
#define KB_INSERT       0x49
#define KB_HOME         0x4A
#define KB_PAGE_UP      0x4B
#define KB_DELETE       0x4C
#define KB_END          0x4D
#define KB_PAGE_DOWN    0x4E
#define KB_RIGHT        0x4F
#define KB_LEFT         0x50
#define KB_DOWN         0x51
#define KB_UP           0x52
#define KB_NUM_LOCK     0x53
// USB�L�[�R�[�h(modifier keys)
#define KB_CONTROL_L 0xE0
#define KB_SHIFT_L   0xE1
#define KB_ALT_L     0xE2
#define KB_GUI_L     0xE3
#define KB_CONTROL_R 0xE4
#define KB_SHIFT_R   0xE5
#define KB_ALT_R     0xE6
#define KB_GUI_R     0xE7

// �L�[�R�[�h�e�[�u��(�ʏ펞)
static unsigned char KEY_TABLE_NORMAL[OUTPUT_PIN_MAX][INPUT_PIN_MAX] = {
    // left side
    { KB_ESPACE,         KB_1, KB_2,     KB_3,     KB_4,  KB_5,     KB_6, 0},
    {         0,       KB_TAB, KB_Q,     KB_W,     KB_E,  KB_R,     KB_T, 0},
    {         0, KB_CONTROL_L, KB_A,     KB_S,     KB_D,  KB_F,     KB_G, 0},
    {         0,   KB_SHIFT_L, KB_Z,     KB_X,     KB_C,  KB_V,     KB_B, 0},
    {         0,            0,    0, KB_GUI_L, KB_ALT_L, KB_FN, KB_SPACE, 0},
    // right side
    {    KB_7,  KB_8,     KB_9,      KB_0,     KB_HYPHEN,      KB_EQALS, KB_BACKSLASH, KB_GRAVE_ACCENT},
    {    KB_Y,  KB_U,     KB_I,      KB_O,          KB_P,  KB_BRACKET_L, KB_BRACKET_R,    KB_BACKSPACE},
    {    KB_H,  KB_J,     KB_K,      KB_L, KB_SEMI_COLON, KB_APOSTROPHE,     KB_ENTER,               0},
    {    KB_N,  KB_M, KB_COMMA, KB_PERIOD,      KB_SLASH,    KB_SHIFT_R,            0,               0},
    {KB_SPACE, KB_FN, KB_ALT_R,  KB_GUI_R,             0,             0,            0,               0}
};

// �L�[�R�[�h�e�[�u��(Fn�L�[������)
static unsigned char KEY_TABLE_FN[OUTPUT_PIN_MAX][INPUT_PIN_MAX] = {
    // left side
    {0,        KB_F1,   KB_F2,    KB_F3,    KB_F4, KB_F5, KB_F6, 0},
    {0,            0,       0,    KB_UP,        0,     0,     0, 0},
    {0, KB_CONTROL_L, KB_LEFT,  KB_DOWN, KB_RIGHT,     0,     0, 0},
    {0,   KB_SHIFT_L,       0,        0,        0,     0,     0, 0},
    {0,            0,       0, KB_GUI_L, KB_ALT_L, KB_FN,     0, 0},
    // right side
    {KB_F7, KB_F8,           KB_F9,           KB_F10,   KB_F11,     KB_F12, KB_INSERT,         0},
    {    0,     0, KB_PRINT_SCREEN,   KB_SCROLL_LOCK, KB_PAUSE,          0,         0, KB_DELETE},
    {    0,     0,         KB_HOME,       KB_PAGE_UP,        0,          0,         0,         0},
    {    0,     0,          KB_END,     KB_PAGE_DOWN,        0, KB_SHIFT_R,         0,         0},
    {    0, KB_FN,        KB_ALT_R,         KB_GUI_R,        0,          0,         0,         0}
};

// �L�[�X�L�����p�o�b�t�@
static signed short countBuff[OUTPUT_PIN_MAX][INPUT_PIN_MAX];

// USB���M�p�o�b�t�@
static unsigned char sendBuff[REPORT_BUFF_SIZE];

// Fn�L�[��������Ă��邩�ǂ���
static unsigned char isFn = 0;

void mykbInit() {
	
	TRISA = 0x3F;	//RA0/1/2/3/4/5�����
	TRISB = 0x00;	//RB���o��
	TRISC = 0x03;	//RC0/1�����

	PORTA = 0;
	PORTB = 0;
	PORTC = 0;

	memset(countBuff, 0, sizeof(countBuff));
	memset(sendBuff, 0, sizeof(sendBuff));
}

// 2���@����
unsigned char mykbGetModifierKeyBit(unsigned char modKeyCode) {
	switch(modKeyCode) {
		case KB_CONTROL_L: return 0;
		case KB_SHIFT_L  : return 1;
		case KB_ALT_L    : return 2;
		case KB_GUI_L    : return 3;
		case KB_CONTROL_R: return 4;
		case KB_SHIFT_R  : return 5;
		case KB_ALT_R    : return 6;
		case KB_GUI_R    : return 7;
	}
	return 0;
}

void myKbPinOut(unsigned char pinNo, unsigned char onoff) {
    switch (pinNo) {
        case  0: LATBbits.LATB7 = onoff; break;
        case  1: LATBbits.LATB6 = onoff; break;
        case  2: LATBbits.LATB5 = onoff; break;
        case  3: LATBbits.LATB4 = onoff; break;
        case  4: LATBbits.LATB3 = onoff; break;
        case  5: LATBbits.LATB2 = onoff; break;
        case  6: LATBbits.LATB1 = onoff; break;
        case  7: LATBbits.LATB0 = onoff; break;
        case  8: LATCbits.LATC7 = onoff; break;
        case  9: LATCbits.LATC6 = onoff; break;
    }
}

unsigned char myKbChkIn(unsigned char pinNo) {
    switch (pinNo) {
        case 0: return PORTAbits.RA0;
        case 1: return PORTAbits.RA1;
        case 2: return PORTAbits.RA2;
        case 3: return PORTAbits.RA3;
        case 4: return PORTAbits.RA4;
        case 5: return PORTAbits.RA5;
        case 6: return PORTCbits.RC0;
        case 7: return PORTCbits.RC1;
    }
    return 0;
}

void mykbKeyScan(unsigned char p[]) {
    int reportIndex = 0;
	int i = 0;
	int j = 0;
	unsigned char c = 0x00;
	unsigned short oldCnt = 0;
	signed short *pCnt;
	unsigned char modifier = 0x00;

    memset(sendBuff, 0, sizeof(sendBuff));

    for (i = 0; i < OUTPUT_PIN_MAX; i++) {
        // high
        myKbPinOut(i, 1);
        for (j = 0; j < INPUT_PIN_MAX; j++) {

			// �J�E���^�A�h���X
			pCnt = &countBuff[i][j];

			// �ʏ펞�̃L�[����������擾
			c = KEY_TABLE_NORMAL[i][j];

			// �`�F�b�N�O�̃J�E���g��ۑ�
			oldCnt = (*pCnt);

			// �L�[�����`�F�b�N
            if (myKbChkIn(j)) {
                if ((*pCnt) <= CHATTAERING_THRESHOLD) {
                    (*pCnt)++;
                }
            } else {
				(*pCnt) = 0;
/*
                if ((*pCnt) > 0) {
                    (*pCnt)--;
                }
*/
            }

			if(c == KB_FN && oldCnt > 0 && (*pCnt) < 1) {
				// Fn�L�[�A���A�O��l��0���傫���A���A����l��1��菬����
				isFn = 0; // Fn�L�[�͕����ꂽ

			} else if ((*pCnt) > CHATTAERING_THRESHOLD) {
				// ���o��臒l�𒴂���
				if(c == KB_FN) {
					// Fn�L�[��
					isFn = 1;
				}

				if(isFn) {
					// Fn�L�[������Ԃ̏ꍇ
					c = KEY_TABLE_FN[i][j];
				}

				if(KB_CONTROL_L <= c && c <= KB_GUI_R) {
					// �C���L�[��
					modifier |= (1 << mykbGetModifierKeyBit(c));

				} else if (c != 0x00){
					// ��L�ȊO
	                sendBuff[reportIndex] = c;
	                reportIndex++;
				}
            }

            if (reportIndex >= REPORT_BUFF_SIZE) {
                break;
            }
        }
        // low
        myKbPinOut(i, 0);
        if (reportIndex >= REPORT_BUFF_SIZE) {
            break;
        }
    }
	
	p[0] = modifier;
	p[1] = 0;
	
    memcpy(&p[2], sendBuff, sizeof(sendBuff));
}



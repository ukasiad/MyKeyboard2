/*
	PIC18F2550 あそ～ぶUSB用USBキーボードサンプル
		ver1.00	2010/11/03	初版(MCHPFSUSBのサンプルから作成)
	
	RA0にスイッチを繋ぎ、押すと、[ENTER]キーが押されます。
	[Caps lock][Num lock]の状態によってLEDが点灯します。
*/

#ifndef KEYBOARD_C
#define KEYBOARD_C

/** INCLUDES *******************************************************/
#include "Microchip/Include/USB/usb.h"
#include "HardwareProfile.h"
#include "Microchip/Include/USB/usb_function_hid.h"
#include "bootload.h"

#include "type2_button.h"

/** VARIABLES ******************************************************/
#pragma udata
char buffer[8];
unsigned char OutBuffer[8];
USB_HANDLE lastINTransmission;
USB_HANDLE lastOUTTransmission;
BOOL Keyboard_out;
DWORD CountdownTimerToShowUSBStatusOnLEDs;

/** PRIVATE PROTOTYPES *********************************************/
static void InitializeSystem(void);
void ProcessIO(void);
void UserInit(void);
void Keyboard(void);

void USBHIDCBSetReportComplete(void);

/** VECTOR REMAPPING ***********************************************/
#pragma code
	
void isr_high()
{
	#if defined(USB_INTERRUPT)
	USBDeviceTasks();
	#endif
}	//This return will be a "retfie fast", since this is in a #pragma interrupt section 
void isr_low()
{
}	//This return will be a "retfie", since this is in a #pragma interruptlow section 


void main(void)
{
    InitializeSystem();

    #if defined(USB_INTERRUPT)
        USBDeviceAttach();
    #endif

    while(1)
    {
        #if defined(USB_POLLING)
	        USBDeviceTasks(); // Interrupt or polling method.  If using polling, must call
        #endif
        ProcessIO();        
    }//end while
}//end main

static void InitializeSystem(void)
{
    ADCON1 |= 0x0F;                 // Default all pins to digital

    #if defined(USE_USB_BUS_SENSE_IO)
    tris_usb_bus_sense = INPUT_PIN; // See HardwareProfile.h
    #endif
    #if defined(USE_SELF_POWER_SENSE_IO)
    tris_self_power = INPUT_PIN;	// See HardwareProfile.h
    #endif
    
    UserInit();

    USBDeviceInit();	//usb_device.c.  Initializes USB module SFRs and firmware
}//end InitializeSystem



/******************************************************************************
 * Function:        void UserInit(void)
 *****************************************************************************/
void UserInit(void)
{
	mykbInit();

    lastINTransmission = 0;
    lastOUTTransmission = 0;
}//end UserInit


/********************************************************************
 * Function:        void ProcessIO(void)
 *******************************************************************/
void ProcessIO(void)
{   
    // User Application USB tasks
    if((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1)) return;

	//Call the function that behaves like a keyboard  
    Keyboard();        
     
}//end ProcessIO


void Keyboard(void)
{
    if(!HIDTxHandleBusy(lastINTransmission))
    {
		memset(hid_report_in, 0, sizeof(hid_report_in));

		mykbKeyScan(hid_report_in);

		//Send the 8 byte packet over USB to the host.
		lastINTransmission = HIDTxPacket(HID_EP, (BYTE*)hid_report_in, 0x08);
    }
    
    if(!HIDRxHandleBusy(lastOUTTransmission))
    {
		lastOUTTransmission = HIDRxPacket(HID_EP,(BYTE*)&hid_report_out,1);
	} 

    return;
}//end keyboard()



// ******************************************************************************************************
// ************** USB Callback Functions ****************************************************************
// ******************************************************************************************************

/******************************************************************************
 * Function:        void USBCBSuspend(void)
 *****************************************************************************/
void USBCBSuspend(void)
{
}

/******************************************************************************
 * Function:        void USBCBWakeFromSuspend(void)
 *****************************************************************************/
void USBCBWakeFromSuspend(void)
{
}

/********************************************************************
 * Function:        void USBCB_SOF_Handler(void)
 *******************************************************************/
void USBCB_SOF_Handler(void)
{
}

/*******************************************************************
 * Function:        void USBCBErrorHandler(void)
 *******************************************************************/
void USBCBErrorHandler(void)
{
}

/*******************************************************************
 * Function:        void USBCBCheckOtherReq(void)
 *******************************************************************/
void USBCBCheckOtherReq(void)
{
    USBCheckHIDRequest();
}//end


/*******************************************************************
 * Function:        void USBCBStdSetDscHandler(void)
 *******************************************************************/
void USBCBStdSetDscHandler(void)
{
}//end


/*******************************************************************
 * Function:        void USBCBInitEP(void)
 *******************************************************************/
void USBCBInitEP(void)
{
    //enable the HID endpoint
    USBEnableEndpoint(HID_EP,USB_IN_ENABLED|USB_OUT_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);

	lastOUTTransmission = HIDRxPacket(HID_EP,(BYTE*)&hid_report_out,1);

}

/********************************************************************
 * Function:        void USBCBSendResume(void)
 *******************************************************************/
void USBCBSendResume(void)
{
    static WORD delay_count;
    
    USBResumeControl = 1;                // Start RESUME signaling
    
    delay_count = 1800U;                // Set RESUME line for 1-13 ms
    do
    {
        delay_count--;
    }while(delay_count);
    USBResumeControl = 0;
}


/*******************************************************************
 * Function:        BOOL USER_USB_CALLBACK_EVENT_HANDLER(
 *                        USB_EVENT event, void *pdata, WORD size)
 *******************************************************************/
BOOL USER_USB_CALLBACK_EVENT_HANDLER(USB_EVENT event, void *pdata, WORD size)
{
    switch(event)
    {
        case EVENT_CONFIGURED: 
            USBCBInitEP();
            break;
        case EVENT_SET_DESCRIPTOR:
            USBCBStdSetDscHandler();
            break;
        case EVENT_EP0_REQUEST:
            USBCBCheckOtherReq();
            break;
        case EVENT_SOF:
            USBCB_SOF_Handler();
            break;
        case EVENT_SUSPEND:
            USBCBSuspend();
            break;
        case EVENT_RESUME:
            USBCBWakeFromSuspend();
            break;
        case EVENT_BUS_ERROR:
            USBCBErrorHandler();
            break;
        case EVENT_TRANSFER:
            Nop();
            break;
        default:
            break;
    }
    return TRUE; 
}


// *****************************************************************************
// ************** USB Class Specific Callback Function(s) **********************
// *****************************************************************************

/********************************************************************
 * Function:        void USBHIDCBSetReportHandler(void)
 *******************************************************************/
void USBHIDCBSetReportHandler(void)
{
	USBEP0Receive((BYTE*)&CtrlTrfData, USB_EP0_BUFF_SIZE, USBHIDCBSetReportComplete);
}

void USBHIDCBSetReportComplete(void)
{
}	
/** EOF Keyboard.c **********************************************/
#endif

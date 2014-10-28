# MPLAB IDE generated this makefile for use with GNU make.
# Project: keyboard_sample.mcp
# Date: Fri Sep 19 19:27:23 2014

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

keyboard_sample.cof : usb_descriptors.o usb_device.o usb_function_hid.o Keyboard.o type2_button.o
	$(LD) /p18F2550 /l"C:\mcc18\lib" "rm18f2550 - HID Bootload.lkr" "usb_descriptors.o" "usb_device.o" "usb_function_hid.o" "Keyboard.o" "type2_button.o" /u_CRUNTIME /z__MPLAB_BUILD=1 /m"keyboard_sample.map" /w /o"keyboard_sample.cof"

usb_descriptors.o : usb_descriptors.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdio.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdlib.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/string.h Microchip/Include/usb/usb_common.h Microchip/Include/usb/usb_device.h Microchip/Include/usb/usb_hal.h usb_descriptors.c Microchip/Include/USB/usb.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/GenericTypeDefs.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stddef.h Microchip/Include/Compiler.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f2550.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdarg.h usb_config.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/limits.h Microchip/Include/usb/usb_ch9.h Microchip/Include/USB/usb_hal_pic18.h Microchip/Include/USB/usb_function_hid.h
	$(CC) -p=18F2550 /i"C:\MCC18\h" "usb_descriptors.c" -fo="usb_descriptors.o" -pa=4

usb_device.o : Microchip/USB/usb_device.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdio.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdlib.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/string.h Microchip/Include/usb/usb_common.h Microchip/Include/usb/usb_device.h Microchip/Include/usb/usb_hal.h Microchip/USB/usb_device.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/GenericTypeDefs.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stddef.h Microchip/Include/Compiler.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f2550.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdarg.h Microchip/Include/USB/USB.h usb_config.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/limits.h Microchip/Include/usb/usb_ch9.h Microchip/Include/USB/usb_hal_pic18.h HardwareProfile.h HardwareProfile\ -\ PICDEM\ FSUSB.h
	$(CC) -p=18F2550 /i"C:\MCC18\h" "Microchip\USB\usb_device.c" -fo="usb_device.o" -pa=4

usb_function_hid.o : Microchip/USB/HID\ Device\ Driver/usb_function_hid.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdio.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdlib.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/string.h Microchip/Include/usb/usb_common.h Microchip/Include/usb/usb_device.h Microchip/Include/usb/usb_hal.h Microchip/USB/HID\ Device\ Driver/usb_function_hid.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/GenericTypeDefs.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stddef.h Microchip/Include/Compiler.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f2550.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdarg.h Microchip/Include/USB/usb.h usb_config.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/limits.h Microchip/Include/usb/usb_ch9.h Microchip/Include/USB/usb_hal_pic18.h Microchip/Include/USB/usb_function_hid.h
	$(CC) -p=18F2550 /i"C:\MCC18\h" "Microchip\USB\HID Device Driver\usb_function_hid.c" -fo="usb_function_hid.o" -pa=4

Keyboard.o : Keyboard.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdio.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdlib.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/string.h Microchip/Include/usb/usb_common.h Microchip/Include/usb/usb_device.h Microchip/Include/usb/usb_hal.h bootload.h type2_button.h Keyboard.c Microchip/Include/USB/usb.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/GenericTypeDefs.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stddef.h Microchip/Include/Compiler.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f2550.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stdarg.h usb_config.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/limits.h Microchip/Include/usb/usb_ch9.h Microchip/Include/USB/usb_hal_pic18.h HardwareProfile.h HardwareProfile\ -\ PICDEM\ FSUSB.h Microchip/Include/USB/usb_function_hid.h
	$(CC) -p=18F2550 /i"C:\MCC18\h" "Keyboard.c" -fo="Keyboard.o" -pa=4

type2_button.o : type2_button.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/string.h type2_button.h type2_button.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/stddef.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f2550.h
	$(CC) -p=18F2550 /i"C:\MCC18\h" "type2_button.c" -fo="type2_button.o" -pa=4

clean : 
	$(RM) "usb_descriptors.o" "usb_device.o" "usb_function_hid.o" "Keyboard.o" "type2_button.o" "keyboard_sample.cof" "keyboard_sample.hex" "keyboard_sample.map"


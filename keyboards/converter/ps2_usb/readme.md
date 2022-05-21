# Keyboard converter for PS/2 keyboard

This is a port of TMK's converter/ps2_usb to QMK.


## Connection

Keyboard | ATMega32U4
:------- | :---------
Data     |  PD0
Clock    |  PD1

And VCC and GND, of course. See Resource section for keyboard connector pin assign.


## Build

```
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
qmk compile -kb converter/ps2_usb -km default
```

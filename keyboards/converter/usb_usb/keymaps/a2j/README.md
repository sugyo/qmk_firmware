# compile

```
~/qmk$ python3.8 -m venv venv
...
~/qmk$ source venv/bin/activate
(venv) ~/qmk$ pip install qmk
...
(venv) ~/qmk$ git clone git@github.com:..../qmk_firmware.git
...
(venv) ~/qmk$ cd qmk_firmware/
(venv) ~/qmk$ ./util/qmk_install.sh
...
(venv) ~/qmk$ make git-submodule
...
(venv) ~/qmk/qmk_firmware$ qmk compile -kb converter/usb_usb/pro_micro -km a2j
Ψ Compiling keymap with make --jobs=1 converter/usb_usb/pro_micro:a2j


QMK Firmware 0.16.9
Making converter/usb_usb/pro_micro with keymap a2j
...
(venv) ~/qmk/qmk_firmware$ ls converter_usb_usb_pro_micro_a2j.hex
converter_usb_usb_pro_micro_a2j.hex
(venv) ~/qmk/qmk_firmware$
```

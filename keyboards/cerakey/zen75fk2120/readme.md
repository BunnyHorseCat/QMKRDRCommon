# Zen75

A customizable 85key keyboard.



* Keyboard Maintainer: [LiWenLiu](https://github.com/LiuLiuQMK)
* Hardware Supported: Zen75/FinalKey FK2120 PCB with es32fs026 microcontroller

Make example for this keyboard (after setting up your build environment):

    make cerakey/zen75fk2120:default

Flashing example for this keyboard:

    make cerakey/zen75fk2120:default:flash

This board uses a Mass Storage bootloader, so it will appear as a mass storage device when connected in DFU mode. Drag and drop the .bin firmware file to flash the board.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Esc key) and plug in the keyboard
* **Physical reset**: Short the Reset (NRST) and Ground (GND) pads on the underside of the PCB near the spacebar socket

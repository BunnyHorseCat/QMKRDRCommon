# EPOMAKER Galaxy100 Lite

A customizable 96% (1800) keyboard with 100 keys and a rotary knob, built around
the same ES32 FS026 microcontroller as the other Epomaker wireless boards in this
tree (TH40, Luma40, Galaxy68, TH85). It uses the open-source
[`lib/rdmctmzt_common`](../../../lib/rdmctmzt_common/README.md) library instead of
the closed-source `rdr_lib` shipped by the vendor.

* Keyboard Maintainer: [CarlosEDP](https://github.com/carlosedp)
* Hardware Supported: EPOMAKER Galaxy100 Lite PCB with es32fs026 microcontroller

Make example for this keyboard (after setting up your build environment):

    make epomaker/galaxy100_lite:default

Flashing example for this keyboard:

1. Hold ESC while plugging it in wired mode to enter flash mode
2. Create the binary with make
3. Copy the binary on the mounted flash drive
4. The flash drive should disappear and the keyboard restarts with the new firmware

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## VIA

VIA is enabled in the default keymap. Load
[`VIA_Mapping_Galaxy100_Lite.json`](VIA_Mapping_Galaxy100_Lite.json) as a design
file in VIA (Settings -> Show Design tab -> Design -> Load). The vendor's original
file is kept alongside it as `Epomaker Galaxy100 Lite.JSON` for reference; the
maintained one fixes the RGB effect indices (the vendor list had
`rainbow_moving_chevron` and the two `starlight` variants in the wrong order) and
the custom keycode list, and matches the brightness cap actually built into the
firmware.

## Layout notes

`LAYOUT_1800_ansi` has 102 positions: 100 keys, the knob switch on `(5, 8)`, and
`(5, 3)`, which is the slot the vendor's VIA file attaches the encoder widget to.
Both carry `KC_MUTE` in the default keymap so the knob mutes regardless of which
of the two the push actually scans on. The vendor's own VIA file omits `(5, 8)`
entirely — that is a bug in it, and the maintained mapping here restores the key.

LED 17 is wired to `(5, 8)`; the encoder slot `(5, 3)` has no LED.

## Macro storage

The stock firmware only left 194 bytes for VIA macros. This build raises the
emulated-EEPROM budget (see the comment in `config.h`) to **1138 bytes** while
keeping 8 dynamic keymap layers.

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Esc key) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB

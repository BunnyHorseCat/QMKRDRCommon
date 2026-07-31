# GEONIX REV.2.5 1U (Open-Source Port)

A 40% wireless keyboard supporting BLE, 2.4 GHz, and USB modes, with a split 1U spacebar.

This is the 1U spacebar variant of the GEONIX REV.2.5. It has 48 per-key LEDs (vs 47 on the 2U
variant) because the second spacebar at matrix position [3,1] is a real key rather than an empty
slot. This is an open-source port replacing the original closed-source `librdrcommon.a` with
[carlosedp's `rdmctmzt_common` library](https://github.com/carlosedp/qmk_firmware/tree/geonixr2).

* Keyboard Maintainer: [bofhgit](https://github.com/bofhgit)
* Hardware Supported: GEONIX REV.2.5 1U PCB with ES32 FS026 microcontroller
* Hardware Availability: GEONIX REV.2.5 1U

Make example for this keyboard (after setting up your build environment):

    make chosfox/geonix_rev25/geonix41:default

Flashing example for this keyboard:

    make chosfox/geonix_rev25/geonix41:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Flashing

Hold **TAB + Q** while plugging in the keyboard. A `NO_NAME` drive will appear — drop the `.bin` file into it.

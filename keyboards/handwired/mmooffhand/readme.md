# handwired/mmooffhand

![handwired/mmooffhand](imgur.com image replace me!)

A macro pad setup to be used with World of Warcraft and other varous MMO games.

* Keyboard Maintainer: [Bill Golden](https://github.com/Droth-The-Destroyer)
* Hardware Supported: Raspberry Pi Pico
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make handwired/mmooffhand:default

Flashing example for this keyboard:

    make handwired/mmooffhand:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

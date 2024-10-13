QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7735_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
ENCODER_MAP_ENABLE = yes
DIP_SWITCH_ENABLE = yes
BOOTMAGIC_ENABLE = no
BOOTLOADER = rp2040
SRC += display/display.c
SRC += display/images/frog.qgf.c
SRC += display/images/frog_open.qgf.c
SRC += display/lvgl_helper.c

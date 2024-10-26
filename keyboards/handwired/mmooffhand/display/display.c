#include "qp.h"
#include "qp_lvgl.h"
#include <time.h>
#include <stdlib.h>
#include "noto_sans_10.c"
#include "noto_sans_12.c"
#include "ui/uihandler.c"

void keyboard_post_init_kb(void) {
    painter_device_t tft = qp_st7735_make_spi_device(TFT_WIDTH , TFT_HEIGHT , TFT_CS_PIN, TFT_DC_PIN, TFT_RESET_PIN, 4, 0);
    qp_init(tft, TFT_ROTATION);

    qp_power(tft, true);

    if (qp_lvgl_attach(tft)) {     // Attach LVGL to the display
        lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), LV_STATE_DEFAULT);
        ui_init();
    }
    keyboard_post_init_user();
}

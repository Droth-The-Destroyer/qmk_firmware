#include "qp.h"
#include "lvgl_helper.h"
#include "display/images/frog.qgf.c"

static painter_device_t tft;
static painter_image_handle_t frog_;

void display_animation(void) {

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_exec_xcb_t lv_obj_set_x;
    lv_anim_set_exec_cb(&a, lv_obj_set_x);
    lv_anim_set_var(&a, obj);
    lv_animimg_set_duration(&a, 1850);
    lv_anim_set_values(&a, 0, 1850);

    lv_img_dsc_t my_img_dsc = {
        .header.always_zero = 0,
        .header.w = 100,
        .header.h = 100,
        .data_size = 100 * 100 * 16 / 8,
        .header.cf = LV_IMG_CF_TRUE_COLOR,
    };

    lv_draw_img_dsc_t dsc;
    lv_draw_img_dsc_init(&dsc);
    lv_canvas_draw_img(frog_, 0, 0, &my_img_dsc, &dsc);
}

void display_image(void) {
    tft = qp_st7735_make_spi_device(TFT_WIDTH , TFT_HEIGHT , TFT_CS_PIN, TFT_DC_PIN, TFT_RESET_PIN, 4, 0);
    frog_ = qp_load_image_mem(gfx_frog);
    qp_drawimage(tft, 32, 91, frog_);
    qp_flush(tft);

    lv_img_dsc_t my_img_dsc = {
        .header.always_zero = 0,
        .header.w = 100,
        .header.h = 100,
        .data_size = 100 * 100 * 16 / 8,
        .header.cf = LV_IMG_CF_TRUE_COLOR,
    };

    lv_draw_img_dsc_t dsc;
    lv_draw_img_dsc_init(&dsc);
    lv_canvas_draw_img(frog_, 0, 0, &my_img_dsc, &dsc);
    qp_close_image(frog_);
    qp_flush(tft);

}

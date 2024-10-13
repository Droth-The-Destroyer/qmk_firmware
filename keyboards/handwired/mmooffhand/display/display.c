#include "qp.h"
#include "qp_lvgl.h"
// #include "images/frog.qgf.h"
#include "images/frog_open.qgf.h"

// static  painter_device_t tft;
// static  painter_image_handle_t frog_i;
// static  deferred_token frog_a;
// static  painter_image_handle_t frog_open_i;
// static  deferred_token frog_open_a;


void keyboard_post_init_kb(void) {
    painter_device_t tft = qp_st7735_make_spi_device(TFT_WIDTH , TFT_HEIGHT , TFT_CS_PIN, TFT_DC_PIN, TFT_RESET_PIN, 4, 0);
    qp_init(tft, TFT_ROTATION);

    qp_power(tft, true);

    if (qp_lvgl_attach(tft)) {     // Attach LVGL to the display
        // lv_frog();
    }

    // qp_rect(tft, 0, 0, 128, 160, 0, 0, 0, true);
    // frog_i = qp_load_image_mem(gfx_frog);
    // frog_i = qp_load_image_mem(gfx_frog);
    // frog_a = qp_animate(tft, 32, 91, frog_open_i);

    keyboard_post_init_user();
}


/*void lv_frog(void) {
    LV_IMG_DECLARE(frog);
    lv_obj_t * frog_ = lv_img_create(lv_scr_act());
    lv_img_set_src(frog_, &frog_open);
    lv_obj_align(frog_, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_size(frog_, 64, 64);

    static lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, frog_);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_x);
    lv_anim_set_time(&a, 2520);
    lv_anim_set_values(&a, 32, 91);
    lv_anim_start(&a);
}*/

// static  painter_image_handle_t frog_open_i;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // frog_open_i = qp_load_image_mem(gfx_frog_open);
    switch (keycode) {
        case KC_PAST:
            // qp_stop_animation(frog_a);
            // frog_open_a = qp_animate(tft, 32, 91, frog_open_i);
            return true;
        break;
        case KC_1:
            // qp_stop_animation(frog_a);
            // frog_open_a = qp_animate(tft, 32, 91, frog_open_i);
            return true;
        break;
    }
    return true;
}

// Runs after each key press, check if activity occurred
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PAST:
        // qp_rect(tft, 32, 91, 96, 155, 212, 255, 125, true);
        break;
    }
}


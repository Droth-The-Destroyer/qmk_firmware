#include "qp.h"
#include "images/frog.qgf.h"
#include "images/frog_open.qgf.h"

static painter_device_t tft;

void keyboard_post_init_kb(void) {
    painter_device_t tft = qp_st7735_make_spi_device(TFT_WIDTH , TFT_HEIGHT , TFT_CS_PIN, TFT_DC_PIN, TFT_RESET_PIN, 4, 0);
    qp_init(tft, TFT_ROTATION);

    qp_power(tft, true);
    qp_rect(tft, 0, 0, 128, 160, 0, 0, 0, true);
    // qp_rect(tft, 32, 91, 96, 155, 212, 255, 125, true);

    painter_image_handle_t frog_i = qp_load_image_mem(gfx_frog);
    qp_animate(tft, 32, 91, frog_i);
    // qp_drawimage(tft, 10, 10, frog);

    keyboard_post_init_user();
}

static uint8_t anim_tracker;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_PAST:
      if (record->event.pressed) {
        anim_tracker++;
        painter_image_handle_t frog_open_i = qp_load_image_mem(gfx_frog_open);
        qp_animate(tft, 32, 91, frog_open_i);
        register_code(keycode);
        return false;
      }
    break;
  }
  return true;
}

// Runs after each key press, check if activity occurred
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PAST:
            if (!record->event.pressed) {
                anim_tracker--;
                if (!anim_tracker) {
                }
            }
      break;
    }
}
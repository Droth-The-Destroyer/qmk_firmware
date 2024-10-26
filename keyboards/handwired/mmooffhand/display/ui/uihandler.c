#include "background.c"
#include "settings_edit.c"
#include "settings_selector.c"
#include <display/anims/animhandler.c>

typedef union {
  uint32_t raw;
  struct {
    bool        set_rgb_mode :1;
    uint8_t     set_rgb_static_color;
    uint8_t     set_rgb_zone1_color;
    uint8_t     set_rgb_zone2_color;
    uint8_t     set_rgb_zone3_color;
    uint8_t     set_rgb_zone4_color;
    uint8_t     set_rgb_zone5_color;
    uint8_t     set_screen_color;
    uint8_t     set_pet;
    uint8_t     set_encoderscroll;
  };
} user_config_t;

user_config_t user_config;
user_config_t user_config_cache;

#define rgb_static  HSV_ORANGE
#define rgb_zone1   HSV_RED
#define rgb_zone2   HSV_GOLD
#define rgb_zone3   HSV_GREEN
#define rgb_zone4   HSV_PURPLE
#define rgb_zone5   HSV_WHITE

static lv_style_t default_style;
static lv_style_t list_style;

bool setting_changed = false;

void set_default_style(void) {
    lv_style_init(&default_style);

    lv_style_set_radius(&default_style, 0);
    lv_style_set_bg_opa(&default_style, LV_OPA_COVER);
    lv_style_set_bg_color(&default_style, lv_color_black());
    lv_style_set_border_width(&default_style, 0);
    lv_style_set_border_opa(&default_style, LV_OPA_TRANSP);
    lv_style_set_pad_all(&default_style, 0);

    lv_style_set_text_color(&default_style, lv_color_white());
    lv_style_set_text_letter_space(&default_style, 1);
    lv_style_set_text_line_space(&default_style, 1);
    lv_style_set_text_decor(&default_style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&default_style, &noto_sans_12);
    lv_style_set_text_align(&default_style, LV_TEXT_ALIGN_CENTER);
}

void set_list_style(void) {
    lv_style_init(&list_style);

    lv_style_set_radius(&list_style, 0);
    lv_style_set_bg_opa(&list_style, LV_OPA_COVER);
    lv_style_set_bg_color(&list_style, lv_color_black());
    lv_style_set_border_width(&list_style, 0);
    lv_style_set_border_opa(&list_style, LV_OPA_TRANSP);
    lv_style_set_pad_all(&list_style, 0);

    lv_style_set_text_color(&list_style, lv_color_white());
    lv_style_set_text_letter_space(&list_style, 1);
    lv_style_set_text_line_space(&list_style, 1);
    lv_style_set_text_decor(&list_style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&list_style, &noto_sans_10);
    lv_style_set_text_align(&list_style, LV_TEXT_ALIGN_LEFT);
}

void ui_init(void) {
    user_config.raw = eeconfig_read_user();
    set_default_style();
    set_list_style();
    LV_IMG_DECLARE(background);
    lv_obj_t * background_img = lv_img_create(lv_scr_act());
    lv_img_set_src(background_img, &background);
    lv_obj_align(background_img, LV_ALIGN_CENTER, 0, 0);

    // Encoder Left Symbol
    lv_obj_t * encoder_left = lv_label_create(lv_scr_act());
    lv_obj_add_style(encoder_left, &default_style, 0);
    lv_obj_set_style_text_font(encoder_left, &lv_font_montserrat_14, 0);
    lv_label_set_text(encoder_left, LV_SYMBOL_VOLUME_MID);
    lv_obj_align(encoder_left, LV_ALIGN_BOTTOM_MID, -28, -18);

    // Encoder Click Symbol
    lv_obj_t * encoder_click = lv_label_create(lv_scr_act());
    lv_obj_add_style(encoder_click, &default_style, 0);
    lv_obj_set_style_text_font(encoder_click, &lv_font_montserrat_14, 0);
    lv_label_set_text(encoder_click, LV_SYMBOL_SETTINGS);
    lv_obj_align(encoder_click, LV_ALIGN_BOTTOM_MID, 0, -18);

    // Encoder Right Symbol
    lv_obj_t * encoder_right = lv_label_create(lv_scr_act());
    lv_obj_add_style(encoder_right, &default_style, 0);
    lv_obj_set_style_text_font(encoder_right, &lv_font_montserrat_14, 0);
    lv_label_set_text(encoder_right, LV_SYMBOL_VOLUME_MAX);
    lv_obj_align(encoder_right, LV_ALIGN_BOTTOM_MID, 28, -18);

    lv_obj_t * welcome = lv_label_create(lv_scr_act());
    lv_obj_add_style(welcome, &default_style, 0);
    lv_label_set_text(welcome, "MMO Offhand");
    lv_obj_align(welcome, LV_ALIGN_TOP_MID, 0, 5);

    animation_show();
}

void ui_settings_rgbmode_options(void) {
    LV_IMG_DECLARE(settings_selector);
    lv_obj_t * rgbmode_options1 = lv_label_create(lv_scr_act());
    lv_obj_add_style(rgbmode_options1, &list_style, 0);
    lv_label_set_text(rgbmode_options1, "Static");
    lv_obj_align(rgbmode_options1, LV_ALIGN_TOP_LEFT, 24, 50);

    lv_obj_t * rgbmode_options2 = lv_label_create(lv_scr_act());
    lv_obj_add_style(rgbmode_options2, &list_style, 0);
    lv_label_set_text(rgbmode_options2, "Zones");
    lv_obj_align(rgbmode_options2, LV_ALIGN_TOP_LEFT, 24, 63);

    lv_obj_t * settings_selector_img = lv_img_create(lv_scr_act());
    lv_img_set_src(settings_selector_img, &settings_selector);
    if (!user_config_cache.set_rgb_mode) {
        lv_obj_align(settings_selector_img, LV_ALIGN_TOP_LEFT, 5, 50);
        rgblight_setrgb_range(rgb_zone1, 0, 41);
    }
    if (user_config_cache.set_rgb_mode) {
        lv_obj_align(settings_selector_img, LV_ALIGN_TOP_LEFT, 5, 63);
        rgblight_setrgb_range(rgb_static, 0, 41);
    }
}

void ui_settings_rgbmode(void) {
    lv_obj_t * rgbmode = lv_label_create(lv_scr_act());
    lv_obj_add_style(rgbmode, &default_style, 0);
    lv_label_set_text(rgbmode, "RGB Mode");
    lv_obj_align(rgbmode, LV_ALIGN_TOP_MID, 0, 25);
    ui_settings_rgbmode_options();
}

void ui_settings_rgbcolors(void) {
    lv_obj_t * rgbcolors = lv_label_create(lv_scr_act());
    lv_obj_add_style(rgbcolors, &default_style, 0);
    lv_label_set_text(rgbcolors, "RGB Colors");
    lv_obj_align(rgbcolors, LV_ALIGN_TOP_MID, 0, 25);
}

void ui_settings_screencolor(void) {
    lv_obj_t * screencolor = lv_label_create(lv_scr_act());
    lv_obj_add_style(screencolor, &default_style, 0);
    lv_label_set_text(screencolor, "Screen Color");
    lv_obj_align(screencolor, LV_ALIGN_TOP_MID, 0, 25);
}

void ui_settings_pet(void) {
    lv_obj_t * pet = lv_label_create(lv_scr_act());
    lv_obj_add_style(pet, &default_style, 0);
    lv_label_set_text(pet, "Pet");
    lv_obj_align(pet, LV_ALIGN_TOP_MID, 0, 25);
}

void ui_settings_encoderscroll(void) {
    lv_obj_t * encoderscroll = lv_label_create(lv_scr_act());
    lv_obj_add_style(encoderscroll, &default_style, 0);
    lv_label_set_text(encoderscroll, "Encoder Scroll");
    lv_obj_align(encoderscroll, LV_ALIGN_TOP_MID, 0, 25);
}

void ui_settings_done(void) {
    lv_obj_t * done = lv_label_create(lv_scr_act());
    lv_obj_add_style(done, &default_style, 0);
    lv_label_set_text(done, "Done");
    lv_obj_align(done, LV_ALIGN_TOP_MID, 0, 25);
}

void ui_settings(int settings_sel) {
    animation_hide();
    lv_obj_clean(lv_scr_act());
    lv_obj_t * background_img = lv_img_create(lv_scr_act());
    lv_img_set_src(background_img, &background);
    lv_obj_align(background_img, LV_ALIGN_CENTER, 0, 0);

    if (setting_changed) {
        LV_IMG_DECLARE(settings_edit);
        lv_obj_t * setting_changed_img = lv_img_create(lv_scr_act());
        lv_img_set_src(setting_changed_img, &settings_edit);
        lv_obj_align(setting_changed_img, LV_ALIGN_TOP_RIGHT, -5, 5);
    }

    // Encoder Left Symbol
    lv_obj_t * encoder_left = lv_label_create(lv_scr_act());
    lv_obj_add_style(encoder_left, &default_style, 0);
    lv_obj_set_style_text_font(encoder_left, &lv_font_montserrat_14, 0);
    lv_label_set_text(encoder_left, LV_SYMBOL_LEFT);
    lv_obj_align(encoder_left, LV_ALIGN_BOTTOM_MID, -28, -18);

    // Encoder Click Symbol
    lv_obj_t * encoder_click = lv_label_create(lv_scr_act());
    lv_obj_add_style(encoder_click, &default_style, 0);
    lv_obj_set_style_text_font(encoder_click, &lv_font_montserrat_14, 0);
    lv_label_set_text(encoder_click, LV_SYMBOL_OK);
    lv_obj_align(encoder_click, LV_ALIGN_BOTTOM_MID, 0, -18);

    // Encoder Right Symbol
    lv_obj_t * encoder_right = lv_label_create(lv_scr_act());
    lv_obj_add_style(encoder_right, &default_style, 0);
    lv_obj_set_style_text_font(encoder_right, &lv_font_montserrat_14, 0);
    lv_label_set_text(encoder_right, LV_SYMBOL_RIGHT);
    lv_obj_align(encoder_right, LV_ALIGN_BOTTOM_MID, 28, -18);

    // Settings Symbol
    lv_obj_t * setting = lv_label_create(lv_scr_act());
    lv_obj_add_style(setting, &default_style, 0);
    lv_obj_set_style_text_font(setting, &lv_font_montserrat_14, 0);
    lv_label_set_text(setting, LV_SYMBOL_SETTINGS);
    lv_obj_align(setting, LV_ALIGN_TOP_MID, 0, 5);

    if (settings_sel == 1) {
        ui_settings_rgbmode();
    }
    if (settings_sel == 2) {
        ui_settings_rgbcolors();
    }
    if (settings_sel == 3) {
        ui_settings_screencolor();
    }
    if (settings_sel == 4) {
        ui_settings_pet();
    }
    if (settings_sel == 5) {
        ui_settings_encoderscroll();
    }
    if (settings_sel == 6) {
        ui_settings_done();
    }
}

void ui_settings_rgbmode_click(int settings_sel) {
    switch (user_config_cache.set_rgb_mode) {
        case false:
            user_config_cache.set_rgb_mode = true;
            break;
        case true:
            user_config_cache.set_rgb_mode = false;
            break;
    }
    ui_settings(settings_sel);
}

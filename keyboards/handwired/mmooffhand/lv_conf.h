#pragma once

#include_next <lv_conf.h>

#undef LV_USE_GIF
#define LV_USE_GIF 1

#undef LV_FONT_CUSTOM_DECLARE
#define LV_FONT_CUSTOM_DECLARE  LV_FONT_DECLARE(noto_sans_10) LV_FONT_DECLARE(noto_sans_12) LV_FONT_DECLARE(noto_sans_14)

#undef LV_FONT_DEFAULT
#define LV_FONT_DEFAULT &noto_sans_12

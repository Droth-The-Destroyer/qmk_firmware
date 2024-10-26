#include "standby/1.c"
#include "standby/2.c"
#include "standby/3.c"
#include "standby/4.c"
#include "standby/5.c"
#include "standby/6.c"

void anim_standby(void) {

    #define NUM_IMAGES 6

    LV_IMG_DECLARE(owl_standby1)
    LV_IMG_DECLARE(owl_standby2)
    LV_IMG_DECLARE(owl_standby3)
    LV_IMG_DECLARE(owl_standby4)
    LV_IMG_DECLARE(owl_standby5)
    LV_IMG_DECLARE(owl_standby6)
    static const lv_img_dsc_t * frog_standby[NUM_IMAGES] = {
        &owl_standby1,
        &owl_standby2,
        &owl_standby3,
        &owl_standby4,
        &owl_standby5,
        &owl_standby6,
    };
    lv_obj_t * afrog_standby = lv_animimg_create(lv_scr_act());
    lv_obj_align(afrog_standby, LV_ALIGN_BOTTOM_MID, 0, -53);
    lv_animimg_set_src(afrog_standby, (lv_img_dsc_t **) frog_standby, NUM_IMAGES);
    lv_animimg_set_duration(afrog_standby, 1000);
    lv_animimg_set_repeat_count(afrog_standby, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(afrog_standby);
}

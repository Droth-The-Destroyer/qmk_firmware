#include "standby/1.c"
#include "standby/2.c"
#include "standby/3.c"
#include "standby/4.c"
#include "standby/5.c"
#include "standby/6.c"

void anim_frog_standby(void) {

    #define NUM_IMAGES 6

    LV_IMG_DECLARE(frog_standby1)
    LV_IMG_DECLARE(frog_standby2)
    LV_IMG_DECLARE(frog_standby3)
    LV_IMG_DECLARE(frog_standby4)
    LV_IMG_DECLARE(frog_standby5)
    LV_IMG_DECLARE(frog_standby6)
    static const lv_img_dsc_t * frog_standby[NUM_IMAGES] = {
        &frog_standby1,
        &frog_standby2,
        &frog_standby3,
        &frog_standby4,
        &frog_standby5,
        &frog_standby6,
    };
    lv_obj_t * afrog_standby = lv_animimg_create(lv_scr_act());
    lv_obj_align(afrog_standby, LV_ALIGN_BOTTOM_MID, 0, -53);
    lv_animimg_set_src(afrog_standby, (lv_img_dsc_t **) frog_standby, NUM_IMAGES);
    lv_animimg_set_duration(afrog_standby, 1000);
    lv_animimg_set_repeat_count(afrog_standby, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(afrog_standby);
}

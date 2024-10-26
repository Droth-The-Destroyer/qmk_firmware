#include "open/1.c"
#include "open/2.c"
#include "open/3.c"
#include "open/4.c"
#include "open/5.c"
#include "open/6.c"
#include "open/coin/1.c"
#include "open/coin/2.c"
#include "open/coin/3.c"
#include "open/coin/4.c"
#include "open/coin/5.c"
#include "open/gem/1.c"
#include "open/gem/2.c"
#include "open/gem/3.c"
#include "open/gem/4.c"
#include "open/gem/5.c"
#include "open/scroll/1.c"
#include "open/scroll/2.c"
#include "open/scroll/3.c"
#include "open/scroll/4.c"
#include "open/scroll/5.c"
#include "open/skull/1.c"
#include "open/skull/2.c"
#include "open/skull/3.c"
#include "open/skull/4.c"
#include "open/skull/5.c"

const lv_img_dsc_t ** frog_openbuild(int item){
    LV_IMG_DECLARE(frog_open1)
    LV_IMG_DECLARE(frog_open2)
    LV_IMG_DECLARE(frog_open3)
    LV_IMG_DECLARE(frog_open4)
    LV_IMG_DECLARE(frog_open5)
    LV_IMG_DECLARE(frog_open6)
    LV_IMG_DECLARE(frog_open_coin1)
    LV_IMG_DECLARE(frog_open_coin2)
    LV_IMG_DECLARE(frog_open_coin3)
    LV_IMG_DECLARE(frog_open_coin4)
    LV_IMG_DECLARE(frog_open_coin5)
    LV_IMG_DECLARE(frog_open_gem1)
    LV_IMG_DECLARE(frog_open_gem2)
    LV_IMG_DECLARE(frog_open_gem3)
    LV_IMG_DECLARE(frog_open_gem4)
    LV_IMG_DECLARE(frog_open_gem5)
    LV_IMG_DECLARE(frog_open_scroll1)
    LV_IMG_DECLARE(frog_open_scroll2)
    LV_IMG_DECLARE(frog_open_scroll3)
    LV_IMG_DECLARE(frog_open_scroll4)
    LV_IMG_DECLARE(frog_open_scroll5)
    LV_IMG_DECLARE(frog_open_skull1)
    LV_IMG_DECLARE(frog_open_skull2)
    LV_IMG_DECLARE(frog_open_skull3)
    LV_IMG_DECLARE(frog_open_skull4)
    LV_IMG_DECLARE(frog_open_skull5)
    if (item == 0){
        static const lv_img_dsc_t * frog_open[16] = {
            &frog_open1,
            &frog_open2,
            &frog_open3,
            &frog_open4,
            &frog_open5,
            &frog_open6,
            &frog_open_coin1,
            &frog_open_coin2,
            &frog_open_coin3,
            &frog_open_coin4,
            &frog_open_coin5,
            &frog_open_coin5,
            &frog_open_coin5,
            &frog_open_coin5,
            &frog_open_coin5,
            &frog_open_coin5,
        };
        return frog_open;
    }
    else if (item == 1) {
        static const lv_img_dsc_t * frog_open[16] = {
            &frog_open1,
            &frog_open2,
            &frog_open3,
            &frog_open4,
            &frog_open5,
            &frog_open6,
            &frog_open_gem1,
            &frog_open_gem2,
            &frog_open_gem3,
            &frog_open_gem4,
            &frog_open_gem5,
            &frog_open_gem5,
            &frog_open_gem5,
            &frog_open_gem5,
            &frog_open_gem5,
            &frog_open_gem5,
        };
        return frog_open;
    }
    else if (item == 2) {
        static const lv_img_dsc_t * frog_open[16] = {
            &frog_open1,
            &frog_open2,
            &frog_open3,
            &frog_open4,
            &frog_open5,
            &frog_open6,
            &frog_open_scroll1,
            &frog_open_scroll2,
            &frog_open_scroll3,
            &frog_open_scroll4,
            &frog_open_scroll5,
            &frog_open_scroll5,
            &frog_open_scroll5,
            &frog_open_scroll5,
            &frog_open_scroll5,
            &frog_open_scroll5,
        };
        return frog_open;
    }
    else if (item == 3) {
        static const lv_img_dsc_t * frog_open[16] = {
            &frog_open1,
            &frog_open2,
            &frog_open3,
            &frog_open4,
            &frog_open5,
            &frog_open6,
            &frog_open_skull1,
            &frog_open_skull2,
            &frog_open_skull3,
            &frog_open_skull4,
            &frog_open_skull5,
            &frog_open_skull5,
            &frog_open_skull5,
            &frog_open_skull5,
            &frog_open_skull5,
            &frog_open_skull5,
        };
        return frog_open;
    }
    else {
        static const lv_img_dsc_t * frog_open[16] = {
            &frog_open1,
            &frog_open2,
            &frog_open3,
            &frog_open4,
            &frog_open5,
            &frog_open6,
            &frog_open6,
            &frog_open6,
            &frog_open6,
            &frog_open6,
            &frog_open6,
            &frog_open6,
            &frog_open6,
            &frog_open6,
            &frog_open6,
            &frog_open6,
        };
        return frog_open;
    }
}


lv_obj_t * anim_frog_open(int item){
    // Main loop
    lv_obj_t * afrog_open = lv_animimg_create(lv_scr_act());
    lv_obj_align(afrog_open, LV_ALIGN_BOTTOM_MID, 0, -53);
    lv_animimg_set_src(afrog_open, (lv_img_dsc_t **) frog_openbuild(item), 16);
    lv_animimg_set_duration(afrog_open, 2000);
    lv_animimg_set_repeat_count(afrog_open, 1);
    lv_animimg_start(afrog_open);
    return afrog_open;
}

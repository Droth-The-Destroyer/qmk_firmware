#include "frog/frog_standby.c"
#include "frog/frog_open.c"

bool runonce = true;
bool show = true;
lv_obj_t * test1;

void animate_frog_open_timer(lv_timer_t * timer) {
    runonce = true;
    if (show == true) {
        anim_frog_standby();
    }
}

void animate(void) {
    if (runonce == true) {
        runonce = false;
        test1 = anim_frog_open(rand() % 3);
        lv_timer_t * timer = lv_timer_create(animate_frog_open_timer, 2000,  &runonce);
        lv_timer_set_repeat_count(timer, 1);
    }
}

void animation_show(void) {
    show = true;
    anim_frog_standby();
}

void animation_hide(void) {
    show = false;
}

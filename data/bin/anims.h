// anims.h -- anims functions for game Defuse The Bomb

#ifndef DTB_ANIMS_H
#define DTB_ANIMS_H

#include "../../include/txtanimation/txtanimation.h"
#include "constants.h"
#include "animsconstants.h"
#include "corefunctions.h"

void runa_loading(void) {
	run_animation(k_loading_anim[urandom(0, LOADING_ANIM_COUNT - 1)]);
}

void runa_intro(void) {
	run_animation(k_intro_anim[urandom(0, INTRO_ANIM_COUNT - 1)]);
}

#endif

// last edit: 28/07/2021
// developed by Dolfost

#include <grrlib.h>

#include "fish_0_png.h"
#include "fish_1_png.h"
#include "fish_2_png.h"
#include "fish_3_png.h"
#include "fish_4_png.h"
#include "fish_5_png.h"
#include "fish_6_png.h"
#include "fish_7_png.h"
#include "fish_8_png.h"
#include "fish_9_png.h"
#include "fish_10_png.h"
#include "fish_11_png.h"
#include "fish_12_png.h"
#include "fish_13_png.h"
#include "fish_14_png.h"
#include "fish_15_png.h"
#include "fish_16_png.h"
#include "fish_17_png.h"

GRRLIB_texImg *frames[18];

void init_frames() {
    // TODO: just replace this with something else, this is god awful
    frames[0] = GRRLIB_LoadTexture(fish_0_png);
    frames[1] = GRRLIB_LoadTexture(fish_1_png);
    frames[2] = GRRLIB_LoadTexture(fish_2_png);
    frames[3] = GRRLIB_LoadTexture(fish_3_png);
    frames[4] = GRRLIB_LoadTexture(fish_4_png);
    frames[5] = GRRLIB_LoadTexture(fish_5_png);
    frames[6] = GRRLIB_LoadTexture(fish_6_png);
    frames[7] = GRRLIB_LoadTexture(fish_7_png);
    frames[8] = GRRLIB_LoadTexture(fish_8_png);
    frames[9] = GRRLIB_LoadTexture(fish_9_png);
    frames[10] = GRRLIB_LoadTexture(fish_10_png);
    frames[11] = GRRLIB_LoadTexture(fish_11_png);
    frames[12] = GRRLIB_LoadTexture(fish_12_png);
    frames[13] = GRRLIB_LoadTexture(fish_13_png);
    frames[14] = GRRLIB_LoadTexture(fish_14_png);
    frames[15] = GRRLIB_LoadTexture(fish_15_png);
    frames[16] = GRRLIB_LoadTexture(fish_16_png);
    frames[17] = GRRLIB_LoadTexture(fish_17_png);
}

void free_frames() {
    int frame_count = sizeof(frames) / sizeof(GRRLIB_texImg * );

    for (int i = 0; i < frame_count; i++) {
        GRRLIB_FreeTexture(frames[i]);
    }
}
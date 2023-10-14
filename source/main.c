#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <asndlib.h>
#include <mp3player.h>
#include <grrlib.h>

#include "fish_intro_mp3.h"
#include "fish_loop_mp3.h"
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

#define GRRLIB_BLACK 0x000000FF
#define GRRLIB_WHITE 0xFFFFFFFF

int frame_index = 0;
int counter = 0;

int main(int argc, char **argv) {
    // yes
    GRRLIB_texImg* frames[] = {
            GRRLIB_LoadTexture(fish_0_png), GRRLIB_LoadTexture(fish_1_png),
            GRRLIB_LoadTexture(fish_2_png), GRRLIB_LoadTexture(fish_3_png),
            GRRLIB_LoadTexture(fish_4_png), GRRLIB_LoadTexture(fish_5_png),
            GRRLIB_LoadTexture(fish_6_png), GRRLIB_LoadTexture(fish_7_png),
            GRRLIB_LoadTexture(fish_8_png), GRRLIB_LoadTexture(fish_9_png),
            GRRLIB_LoadTexture(fish_10_png), GRRLIB_LoadTexture(fish_11_png),
            GRRLIB_LoadTexture(fish_12_png), GRRLIB_LoadTexture(fish_13_png),
            GRRLIB_LoadTexture(fish_14_png), GRRLIB_LoadTexture(fish_15_png),
            GRRLIB_LoadTexture(fish_16_png), GRRLIB_LoadTexture(fish_17_png)
    };

    GRRLIB_Init();
	WPAD_Init();

	ASND_Init();
	MP3Player_Init();

	MP3Player_PlayBuffer(fish_intro_mp3, fish_intro_mp3_size, NULL);

    int frame_count = sizeof(frames) / sizeof(GRRLIB_texImg*);

	while (1) {
        // this is a very bad way to loop the audio
        // and it isn't even completely seamless
        // TODO: replace with something better
        MP3Player_PlayBuffer(fish_loop_mp3, fish_loop_mp3_size, NULL);

		WPAD_ScanPads();
        GRRLIB_FillScreen(GRRLIB_BLACK);
        
		if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) {
            break;
        }

        // don't ask
        if ((counter = !counter)) {
            ++frame_index;
        }

        if (frame_index >= frame_count) {
            frame_index = 0;
        }

        GRRLIB_texImg* frame = frames[frame_index];

        // TODO: images might be of the wrong size
        // i assumed the wii used a different resolution and now the
        // fish isn't properly aligned on the screen
        GRRLIB_DrawImg(0, 0, frame, 0, 1, 1, GRRLIB_WHITE);
        GRRLIB_Render();
	}

    for (int i = 0; i < frame_count; i++) {
        GRRLIB_FreeTexture(frames[i]);
    }

    GRRLIB_Exit();
    exit(0);
	return 0;
}
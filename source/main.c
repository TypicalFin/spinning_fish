#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <asndlib.h>
#include <grrlib.h>

#include "oggplayer.h"
#include "frames.h"

#include "fish_intro_ogg.h"
#include "fish_loop_ogg.h"

#define GRRLIB_BLACK 0x000000FF
#define GRRLIB_WHITE 0xFFFFFFFF
#define ROTATE_EVERY_N_FRAMES 2

int frame_index = 0;
int counter = 0;

int main(int argc, char **argv) {
    GRRLIB_Init();
    WPAD_Init();

    ASND_Init();

    init_frames();
    int frame_count = sizeof(frames) / sizeof(GRRLIB_texImg * );

    // TODO: add the intro ogg
    //PlayOgg(fish_intro_ogg, fish_intro_ogg_size, 0, OGG_ONE_TIME);
    PlayOgg(fish_loop_ogg, fish_loop_ogg_size, 0, OGG_INFINITE_TIME);

    while (1) {
        WPAD_ScanPads();
        GRRLIB_FillScreen(GRRLIB_BLACK);

        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) {
            break;
        }

        // TODO: perhaps a video would be better lol
        if (++counter % ROTATE_EVERY_N_FRAMES == 0) {
            ++frame_index;
            counter = 0;
        }

        if (frame_index >= frame_count) {
            frame_index = 0;
        }

        GRRLIB_texImg *frame = frames[frame_index];

        // TODO: images might be of the wrong size
        // i assumed the wii used a different resolution and now the
        // fish isn't properly aligned on the screen
        GRRLIB_DrawImg(0, 0, frame, 0, 1, 1, GRRLIB_WHITE);
        GRRLIB_Render();
    }

    free_frames();

    GRRLIB_Exit();
    StopOgg();
    return 0;
}
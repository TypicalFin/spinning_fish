#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <asndlib.h>
#include <mp3player.h>
#include <grrlib.h>

#include "frames.h"

#include "fish_intro_mp3.h"
#include "fish_loop_mp3.h"

#define GRRLIB_BLACK 0x000000FF
#define GRRLIB_WHITE 0xFFFFFFFF

int frame_index = 0;
int counter = 0;

int main(int argc, char **argv) {
    GRRLIB_Init();
    WPAD_Init();

    ASND_Init();
    MP3Player_Init();

    MP3Player_PlayBuffer(fish_intro_mp3, fish_intro_mp3_size, NULL);

    init_frames();
    int frame_count = sizeof(frames) / sizeof(GRRLIB_texImg * );

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

        if ((counter = !counter)) {
            ++frame_index;
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
    return 0;
}
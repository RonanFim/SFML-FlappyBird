#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_


#define SCREEN_WIDTH    384
#define SCREEN_HEIGHT   512

#define FRAMES_PER_SECOND       50
#define MILISECONDS_PER_FRAME   (1000 / FRAMES_PER_SECOND)
#define PIPES_PIXELS_PER_MS     (SCREEN_WIDTH / 2000.0)         // A tela toda em 2000ms
#define PIPES_SPEED             int(PIPES_PIXELS_PER_MS * MILISECONDS_PER_FRAME)   // Pixels to move per frame

#define SPLASH_STATE_TIME   3.0     // Seconds

#define SPLASH_BACKGROUND_FILE      "Resources/Splash Background.png"
#define MENU_BACKGROUND_FILE        "Resources/sky.png"
#define GAME_BACKGROUND_FILE        "Resources/sky.png"
#define GAMEOVER_BACKGROUND_FILE    "Resources/sky.png"

#define PLAY_BUTTON_FILE        "Resources/PlayButton.png"
#define MENU_TITLE_FILE         "Resources/title.png"

#define GAME_LAND_FILE          "Resources/land.png"
#define PIPE_UP_FILE            "Resources/PipeUp.png"
#define PIPE_DOWN_FILE          "Resources/PipeDown.png"

#define GAMEOVER_TITLE_FILE     "Resources/Game-Over-Title.png"
#define GAMEOVER_BODY_FILE      "Resources/Game-Over-Body.png"


#endif

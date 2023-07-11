#pragma once

enum gameStates {
	ready,
	playing,
	gameOver
};

// Écran
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
#define LOGO_STATE_SHOW_TIME 3.0
#define FLASH_SPEED 1000
#define TIME_BEFORE_GAME_OVER_APPEARS 1.5

// Font
#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

// Pipe
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 3.0f 
#define MAX_PIPE_HEIGHT 261

// Oiseau
#define BIRD_ANIMATION_DURATION 0.4f
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3
#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define ROTATION_SPEED 100.0f

// Médales
#define BRONZE_MEDAL_FILEPATH "Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "Resources/res/Gold-Medal.png"
#define PLATINUM_MEDAL_FILEPATH "Resources/res/Platinum-Medal.png"

#define RONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 25
#define PLATINUM_MEDAL_SCORE 100

// Ressources
#define SPLASH_STATE_BACKGROUND_FILEPATH "Resources/res/SplashBackground.png"
#define MAIN_MENU_STATE_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/Game-Over-Title.png"
#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define LAND_FILEPATH "Resources/res/Land.png"
#define BIRD_FRAME_1_FILEPATH "Resources/res/BIRD-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/BIRD-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/BIRD-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/BIRD-04.png"
#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"

// Sons
#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"
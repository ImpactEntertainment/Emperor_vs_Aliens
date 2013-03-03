/**
 * \file game.h
 * \brief Interface que representa um jogo.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \author Edson Alves (edsonalves@unb.br)
 * \date 25/01/2012
 */
#ifndef GAME_H
#define	GAME_H

#include <string>
#include "exception.h"
#include "video.h"
#include "window.h"
#include "emperorvsaliens.h"
#include "timer.h"

#define FRAMES_PER_SECOND   20
#define WAVE_COOLDOWN       TEN_SECONDS

using namespace std;

typedef enum Difficulty {
    GAME_EASY,
    GAME_NORMAL,
    GAME_HARD
}Difficulty;

typedef struct GameConfig
{
    Difficulty      difficulty;
    Level           level;
}GameConfig;


namespace edge {

    class Game {
    public:
        virtual void gameBehaviour() = 0;
        virtual void callNextWave();

        Game();
        
        void init(GameConfig& config) throw(Exception);
        
        void loop() throw(Exception);
        void shutdown();
        
		void togglePause();
		void toggleFastForward();

		bool PAUSED;
		bool FAST_FORWARD;
		bool QUIT;
		bool GAME_ENDED;
		int  WAVES_LEFT;

        int RESOURCES_COOLDOWN;
        int timeForNextWave;

    //private:
        Video *video;
        Window *window;
		EmperorVsAliens eva;
		int allFrameCount;

        void initVideo() throw(Exception);
        void initWindow() throw(Exception);
    };
}

#endif


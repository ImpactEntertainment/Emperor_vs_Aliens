/**
 * \file game.h
 * \brief Interface que representa um jogo.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
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

namespace edge {

    class Game {
    public:
        Game();
        
        void init(const string& configFilePath) throw(Exception);
        void loop() throw(Exception);
        void shutdown();
        
		void togglePause();
		void toggleFastForward();
		void callNextWave();
        
        void gameBehaviour();

		bool PAUSED;
		bool FAST_FORWARD;
		bool QUIT;
		bool GAME_ENDED;
		int  WAVES_LEFT;

        int RESOURCES_COOLDOWN;
        int timeForNextWave;

        //easy
        int timeToLive;

    //private:
        Video *video;
        Window *window;
		EmperorVsAliens eva;
		int allFrameCount;

        void initVideo(const string& configFilePath) throw(Exception);
        void initWindow(const string& configFilePath) throw(Exception);
    };
}

#endif


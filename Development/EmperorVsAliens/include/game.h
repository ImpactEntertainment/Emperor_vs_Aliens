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
#include "gameconfig.h"
#include "menu.h"
#include "hud.h"

#define WAVE_COOLDOWN       TEN_SECONDS

using namespace std;

namespace edge {

    class Game {
    public:
        virtual void gameBehaviour() = 0;
        virtual void callNextWave();

        Game();
        
        void init(GameConfig& config) throw(Exception);
        
        void loop() throw(Exception);
        void shutdown();
        void close();
        
		void togglePause();
		void toggleFastForward();

		bool QUIT;
		bool GAME_ENDED;
        bool toggledFastForward;
        bool toggledPause;
		int  WAVES_LEFT;

        int RESOURCES_COOLDOWN;
        int timeForNextWave;
        int timeLeftForNextWave;

    //private:
        Video           *video;
        Window          *window;
        Field           *selected;
        Menu            *menu;
        HUD             *hud;
		EmperorVsAliens eva;
        GameConfig      *gameConfig;

		int allFrameCount;

       
        void initWindow() throw(Exception);
    };
}

#endif


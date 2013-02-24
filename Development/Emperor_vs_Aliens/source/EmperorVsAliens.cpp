/**
 * \file EmperorVsAliens.cpp
 * \brief Módulo principal do jogo EmperorVsAliens.
 *
 * Módulo principal do jogo EmperorVsAliens, responsável para inicialização
 * dos componentes e do laço principal.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 26/12/2012
 */
 
#include <iostream>
#include <SDL/SDL.h>

#include "video.h"
#include "windowfactory.h"
#include "boundingrectangle.h"
#include "game.h"

using namespace std;
using namespace edge;

#ifdef PS3
int main (s32 argc, const char* argv[]){
#else
int main (){
#endif
    VideoSettings videoSettings;
    videoSettings.videoBufferLocation = VIDEO_MEMORY;
    videoSettings.machineArchitecture = MULTI_CORE;

    Video *video = NULL;

    try {
        video = Video::getInstance();
        video->init();
        video->changeSettings(videoSettings);
    }
    catch (Exception &e) {
        cerr << e.getMessage() << endl;
        return -1;
    }

    WindowSettings windowSettings;
    windowSettings.width = 1920;
    windowSettings.height= 1080;
    windowSettings.title = "EmperorVsAliens";

    Window *window = NULL;

    try {
        window = WindowFactory::create(windowSettings);
    }
    catch (Exception &e) {
        cerr << e.getMessage() << endl;
        return -2;
    }

    Game game(window->getCanvas());
    game.LoadGame();
    game.Loop();

    return 0;
}

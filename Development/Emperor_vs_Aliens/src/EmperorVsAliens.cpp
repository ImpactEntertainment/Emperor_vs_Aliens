/**
 * \file tictactoe.cpp
 * \brief Módulo principal do jogo EmperorVsAliens.
 *
 * Módulo principal do jogo EmperorVsAliens, responsável para inicialização
 * dos componentes e do laço principal.
 *
 * \author Edson Alves (edsonalves@unb.br)
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

void init_board(char board[][3])
{
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            board[x][y] = 0;
        }
    }
}

void init_board_tiles(BoundingRectangle boardTiles[][3])
{
    int blackboardFrameSize = 40;
    int leftMargin = 14, topMargin = 14;
    int boardTileSize = 194;
    int markerWidth = 180;
    int boardTileMargin = (boardTileSize - markerWidth) / 2;
    int verticalBarWidth = 15, horizontalBarHeight = 15;

    int x = blackboardFrameSize + leftMargin + boardTileMargin;
    int y; 
    
    Rectangle rect(180, 180);
    
    for (int i = 0; i < 3; i++) {
        y = blackboardFrameSize + topMargin + boardTileMargin;
        
        for (int j = 0; j < 3; j++) {
            Point position(x, y);
            boardTiles[i][j].set(rect, position);
            
            y += (horizontalBarHeight + boardTileSize);
        }
        
        x += (verticalBarWidth + boardTileSize);
    }
}

int main()
{
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

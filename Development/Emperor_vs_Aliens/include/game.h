/**
 * \file game.h
 * \brief Interface que representa uma imagem.
 *
 * Esta interface representa uma imagem.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 06/02/2013
 */

#ifndef GAME_H
#define	GAME_H

#include "canvas.h"
#include "draw.h"

using namespace std;
using namespace edge;

class Game {
public:
	bool PAUSED;
	bool FAST_FORWARD;
	bool QUIT;
	SDL_Event event;

	void LoadGame();
	void Loop();

	Game(Canvas* canvas);

	void togglePause();
	void toggleFastForward();
	void callNextWave();
private:
	Canvas *mCanvas;

	void getInput();
	void drawScene();
};
#endif


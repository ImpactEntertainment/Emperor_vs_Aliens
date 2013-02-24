/**
 * \file game.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 06/02/2013
 */
 
#include <iostream>
#include <SDL/SDL.h>
#include "game.h"

Game::Game(Canvas* canvas)
: mCanvas(canvas)
{}
void Game::LoadGame()
{
	PAUSED=(false);
	FAST_FORWARD=(false);
	QUIT=(false);
}

void Game::togglePause()
{
	PAUSED = !PAUSED;
	printf("Pressed: PAUSE!\n");
}

void Game::toggleFastForward()
{
	FAST_FORWARD = !FAST_FORWARD;
	printf("Pressed: FAST_FORWARD!\n");
}

void Game::callNextWave()
{
	printf("Pressed: CALL_NEXT_WAVE!\n");}

void Game::Loop()
{
	while (!QUIT) {
		getInput();
		drawScene();
		SDL_Delay(1);
	}
}

void Game::drawScene()
{
	draw(mCanvas);
}

void Game::getInput(){
  #ifdef PS3
  	padInfo padinfo;
  	padData paddata;
  #endif
	while (SDL_PollEvent(&event)) {

	    switch (event.type) {
	    case SDL_QUIT:
	        QUIT = true;
	        break;
	        
	    case SDL_KEYDOWN:

	        switch (event.key.keysym.sym) {
	        case SDLK_ESCAPE:
	            QUIT = true;
	            break;		
	        case SDLK_SPACE:
	            togglePause();
	            break;	
	        case SDLK_f:
	            toggleFastForward();
	            break;	
	        case SDLK_x:
	            callNextWave();
	            break;
	        default:
	            break;
	        }

	    default:
	        break;
	    }
	}
}

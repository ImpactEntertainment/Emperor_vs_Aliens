/**
 * \file sdlwindow.h
 * \brief Classe que implementa uma janela em SDL.
 *
 * Esta classe representa uma janela em SDL. 
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 07/01/2013
 */
#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include <SDL/SDL.h>

#include "window.h"

namespace edge {

class SDL_Window : public Window {
public:
	SDL_Window();

	WindowSettings currentSettings() const;

	int getWidth() const;
	int getHeight() const;

	void applySettings(const WindowSettings& settings) throw (Exception);

private:
	WindowSettings settings;
	SDL_Surface *surface;
};

}

#endif


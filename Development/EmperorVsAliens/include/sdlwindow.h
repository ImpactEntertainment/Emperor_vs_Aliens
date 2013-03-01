/**
 * \file sdlwindow.h
 * \brief Classe que implementa uma janela em SDL.
 *
 * Esta classe representa uma janela em SDL. 
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 07/01/2013
 */
#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include <SDL/SDL.h>

#include "window.h"
#include "canvas.h"

namespace edge {

class SDL_Window : public Window {
public:
	SDL_Window();

	int getWidth() const;
	int getHeight() const;

	WindowSettings currentSettings() const;
	Canvas * getCanvas() const;

	void applySettings(const WindowSettings& settings) throw (Exception);

private:
	WindowSettings settings;
	Canvas *canvas;
	SDL_Surface *surface;
};

}

#endif


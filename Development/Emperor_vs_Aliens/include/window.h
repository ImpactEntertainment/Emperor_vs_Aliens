/**
 * \file window.h
 * \brief Classe que representa uma janela.
 *
 * Esta classe representa uma janela, com suas configurações. A janela
 * deve ser exibida com o método show() antes da chamada de qualquer
 * função de desenho.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 01/01/2013
 */
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL/SDL.h>

#include "exception.h"
#include "windowsettings.h"
#include "video.h"

namespace edge {

class Window {
public:
	Window(const Video *video, const WindowSettings& settings = WindowSettings());

	void show() throw (Exception);

	bool isVisible() const;

private:
	WindowSettings settings;
	const Video *video;
	SDL_Surface *screen;

	Uint32 getFlags() const;
	void validateSettings() throw (Exception);

};

}

#endif


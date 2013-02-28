/**
 * \file sdlwindowsettings.h
 * \brief Representação das opções de janela para a SDL.
 *
 * Esta classe representa as opções específicas de janela para SDL.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 08/01/2013
 */
#ifndef SDL_EDGE_WINDOW_SETTINGS_H
#define SDL_EDGE_WINDOW_SETTINGS_H

#include <ostream>

#include <SDL/SDL.h>
#include "windowsettings.h"

using namespace std;

namespace edge {

class SDL_WindowSettings : public WindowSettings {
public:	
	SDL_WindowSettings(const WindowSettings& settings);

	Uint32 getFlags() const;
	int getBitsPerPixel() const;

private:
	Uint32 getPresentationModeFlags() const;
	Uint32 getWindowSizeFlags() const;
};	

}

#endif


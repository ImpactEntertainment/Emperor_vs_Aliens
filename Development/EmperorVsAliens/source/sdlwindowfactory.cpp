/**
 * \file sdlwindowfactory.cpp
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 08/01/2013
 */
#include <iostream>
#include <cstdlib>

#include "video.h"
#include "sdlvideosettings.h"
#include "window.h"
#include "windowfactory.h"
#include "sdlwindow.h"

namespace edge {

Window * 
WindowFactory::create(const WindowSettings& settings) throw (Exception)
{
	Video *video = Video::getInstance();

	if (video->isUp() == false)
	{
		throw Exception("Video not initialized");
	}

	SDL_Window *window = new SDL_Window();

	if (window == NULL)
	{
		throw Exception("Sem memoria");
	}

	window->applySettings(settings);

	return window;
}

}


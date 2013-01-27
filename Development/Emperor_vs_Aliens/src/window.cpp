/**
 * \file window.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \date 01/01/2013
 */
#include <iostream>
#include <cstdlib>

#include "video.h"
#include "window.h"

namespace edge {

Window::Window(const Video *video, const WindowSettings& settings)
{
	this->settings = settings;
	this->video = video;
	screen = NULL;
}

void 
Window::show() throw(Exception)
{
	if (screen)
		return;

	validateSettings();

	Uint32 videoFlags = video->getFlags();
	Uint32 windowFlags = getFlags();
	Uint32 flags = videoFlags | windowFlags;

	int bitsPerPixel = video->getBitsPerPixel();

	screen = SDL_SetVideoMode(settings.width, settings.height, 
		bitsPerPixel, flags);

	if (screen == NULL)
	{
		throw Exception("Error on SDL_SetVideoMode()");
	} 
}

bool
Window::isVisible() const
{
	return screen != NULL;
}

void
Window::validateSettings() throw (Exception)
{
	if (settings.width == 0 || settings.height == 0)
		throw Exception("Invalid dimensions");
}

Uint32 
Window::getFlags() const
{
	Uint32 flags = 0;

	switch (settings.presentationMode)
	{
		case WINDOW:
			break;

		case NO_FRAME_WINDOW:
			flags |= SDL_NOFRAME;
			break;

		case FULLSCREEN:
			flags |= SDL_FULLSCREEN;
			break;
	}

	switch (settings.windowSize)
	{
		case RESIZABLE:
			flags |= SDL_RESIZABLE;
			break;

		case FIXED:
			break;
	}

	return flags;
}

}


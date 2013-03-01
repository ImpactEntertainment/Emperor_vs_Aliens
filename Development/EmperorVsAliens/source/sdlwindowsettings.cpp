/**
 * \file sdlwindowsettings.cpp
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 08/01/2013
 */
#include "sdlwindowsettings.h"

namespace edge {

SDL_WindowSettings::SDL_WindowSettings(const WindowSettings& settings)
	: WindowSettings(settings)
{
}

Uint32 
SDL_WindowSettings::getFlags() const
{
	Uint32 flags = 0;
	
	flags |= getPresentationModeFlags();
	flags |= getWindowSizeFlags();

	return flags;
}

Uint32
SDL_WindowSettings::getPresentationModeFlags() const
{
	switch (presentationMode)
	{
		case WINDOW:
			return 0;

		case NO_FRAME_WINDOW:
			return SDL_NOFRAME;

		case FULLSCREEN:
			return SDL_FULLSCREEN;
	}

	return 0;
}

Uint32
SDL_WindowSettings::getWindowSizeFlags() const
{
	switch (windowSize)
	{
		case RESIZABLE:
			return SDL_RESIZABLE;

		case FIXED:
			return 0;
	}

	return 0;
}

int 
SDL_WindowSettings::getBitsPerPixel() const
{
	int bitsPerPixel = 0;

	switch (colorDepth)
	{
		case SYSTEM:
			break;

		case INDEXED:
			bitsPerPixel = 8;
			break;

		case HICOLOR:
			bitsPerPixel = 16;
			break;

		case TRUE_COLOR:
			bitsPerPixel = 24;
			break;

		case RGBA:
			bitsPerPixel = 32;
			break;
	}

	return bitsPerPixel;
}

}


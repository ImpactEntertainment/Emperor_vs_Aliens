/**
 * \file sdlvideo.cpp
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 07/01/2013
 */
#include <iostream>
#include <cstdlib>

#include "sdlvideo.h"
#include "sdlvideosettings.h"

namespace edge {

static SDL_Video *video = NULL;

Video * 
Video::getInstance() throw (Exception)
{
	if (video == NULL)
	{
		video = new SDL_Video();

		if (video == NULL)
		{
			throw Exception("Sem memoria");
		}
	}

	return video;
}

void 
SDL_Video::shutdown()
{
	if (isUp())
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void 
SDL_Video::init() throw (Exception)
{
	if (isUp())
		return;

	int rc = SDL_Init(SDL_INIT_VIDEO);

	if (rc != 0)
	{
		throw Exception("Error on SDL video initialization");
	}
}

bool 
SDL_Video::isUp() const
{
	return SDL_WasInit(SDL_INIT_VIDEO) != 0;
}

VideoSettings 
SDL_Video::currentSettings() const
{
	return settings;
}

void 
SDL_Video::changeSettings(const VideoSettings& settings)
{
	validateSettings(settings);		
	this->settings = settings;
}

void
SDL_Video::validateSettings(const VideoSettings& settings) throw (Exception)
{
	SDL_VideoSettings sdl_settings(settings);

	int widthForSDL_VideoModeCheck = 640;
	int heigthForSDL_VideoModeCheck = 480;
	int bitsPerPixelForSDL_VideoModeCheck = 16;
	int flags = sdl_settings.getFlags();

	int rc = SDL_VideoModeOK(widthForSDL_VideoModeCheck, 
		heigthForSDL_VideoModeCheck, bitsPerPixelForSDL_VideoModeCheck, flags);

	if (rc == 0)
	{
		throw Exception("Unsupported video settings");
	}
}

}


/**
 * \file sdlvideosettings.cpp
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 08/01/2013
 */
#include "sdlvideosettings.h"

namespace edge {

SDL_VideoSettings::SDL_VideoSettings(const VideoSettings& settings)
	: VideoSettings(settings)
{
}

Uint32 
SDL_VideoSettings::getFlags() const
{
	Uint32 flags = SDL_ANYFORMAT;

	flags |= getBufferLocationFlags();
	flags |= getMachineArchitetureFlags();
	flags |= getBufferingModeFlags();

	return flags;
}

Uint32 
SDL_VideoSettings::getBufferLocationFlags() const
{
	switch (videoBufferLocation)
	{
		case VIDEO_MEMORY:
			return SDL_HWSURFACE;

		case SYSTEM_MEMORY:
			return SDL_SWSURFACE;
	}

	return 0;
}

Uint32 
SDL_VideoSettings::getMachineArchitetureFlags() const
{
	if (machineArchitecture == MULTI_CORE)
		return SDL_ASYNCBLIT;
	else
		return 0;
}

Uint32 
SDL_VideoSettings::getBufferingModeFlags() const
{
	if (bufferingMode == DOUBLE_BUFFER)
		return SDL_DOUBLEBUF;
	else
		return 0;
}

}


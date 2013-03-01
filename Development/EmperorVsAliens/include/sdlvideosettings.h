/**
 * \file sdlvideosettings.h
 * \brief Representação das opções de vídeo para a SDL.
 *
 * Esta classe representa as opções específicas de vídeo para SDL.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 08/01/2013
 */
#ifndef SDL_EDGE_VIDEO_SETTINGS_H
#define SDL_EDGE_VIDEO_SETTINGS_H

#include <ostream>

#include <SDL/SDL.h>
#include "videosettings.h"

using namespace std;

namespace edge {

class SDL_VideoSettings : public VideoSettings {
public:	
	SDL_VideoSettings(const VideoSettings& settings);
	Uint32 getFlags() const;

private:
	Uint32 getBufferLocationFlags() const;
	Uint32 getMachineArchitetureFlags() const;
	Uint32 getBufferingModeFlags() const; 
};	

}

#endif


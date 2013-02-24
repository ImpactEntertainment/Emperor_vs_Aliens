/**
 * \file video.h
 * \brief Interface que representa o vídeo.
 *
 * Esta interface representa o módulo de vídeo, com suas configurações.
 * A janela e a área desenhável fazem parte da interface Window.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 26/12/2012
 */
#ifndef VIDEO_H
#define VIDEO_H

#include <SDL/SDL.h>

#include "exception.h"
#include "videosettings.h"

#ifdef PS3
 	#ifndef VIDEO_H_PS3
	#define VIDEO_H_PS3
 		const string resourcesDirectory ="/dev_hdd0/game/EMPALIENS/USRDIR/data/";
 	#endif
#else
 	#ifndef VIDEO_H_PC
	#define VIDEO_H_PC
    const string resourcesDirectory ="data/";
    #endif
#endif



namespace edge {

class Video {
public:
	static Video * getInstance() throw (Exception);

	virtual void init() throw (Exception) = 0;
	virtual bool isUp() const = 0;
	virtual void shutdown() = 0;

	virtual VideoSettings currentSettings() const = 0;
	virtual void changeSettings(const VideoSettings& settings) = 0;

};

}

#endif


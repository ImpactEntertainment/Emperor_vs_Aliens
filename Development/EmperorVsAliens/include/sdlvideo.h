/**
 * \file video.h
 * \brief Classe que implementa o vídeo com a SDL.
 *
 * Esta classe implementa a interface vídeo, com suas configurações, utilizando
 * a SDL.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 07/01/2013
 */
#ifndef SDL_VIDEO_H
#define SDL_VIDEO_H

#include <SDL/SDL.h>

#include "video.h"

namespace edge {

class SDL_Video : public Video {
public:
	void init() throw (Exception);
	void shutdown();

	bool isUp() const;

	VideoSettings currentSettings() const;
	void changeSettings(const VideoSettings& settings);

private:
	VideoSettings settings;

	void validateSettings(const VideoSettings& settings) throw (Exception);
};

}

#endif


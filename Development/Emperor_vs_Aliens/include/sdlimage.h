/**
 * \file sdlimage.h
 * \brief Classe que representa uma imagem em SDL.
 *
 * Esta classe representa uma imagem em SDL.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 10/01/2013
 */

#ifndef SDLIMAGE_H
#define	SDLIMAGE_H

#include <SDL/SDL.h>

#include "exception.h"
#include "image.h"

namespace edge {

    class SDL_Image : public Image {
    public:
        SDL_Image(SDL_Surface *surface);
        ~SDL_Image();
        
        int width() const;
        int height() const;
        bool hasClip() const;
        
        SDL_Surface *surface;
    };
}

#endif


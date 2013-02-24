/**
 * \file sdlcanvas.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \date 09/01/2013
 */

#include <SDL/SDL_video.h>
#include <SDL/SDL_endian.h>
#include <SDL/SDL_mutex.h>


#include <iostream>
#include <cmath>

#include "sdlcanvas.h"
#include "sdlimage.h"

using namespace std;

namespace edge {

    SDL_Canvas::SDL_Canvas(SDL_Surface *surface) {
        if (surface == NULL) {
            this->surface = SDL_GetVideoSurface();
        } else {
            this->surface = surface;
        }
    }

    SDL_Canvas::~SDL_Canvas() {
        SDL_Surface *screen = SDL_GetVideoSurface();

        if (surface != screen) {
            SDL_FreeSurface(surface);
        }
    }

    void SDL_Canvas::erase(const Color& color) {
        Uint32 pixelColor = SDL_MapRGB(surface->format, color.red, color.green,
                color.blue);

        SDL_FillRect(surface, NULL, pixelColor);
    }
 

       
    void SDL_Canvas::drawImage(const Image *image, const Point& position)
    {
         const SDL_Image *sdlimage = dynamic_cast<const SDL_Image *>(image);
        
        
        SDL_Rect *source = NULL; 
        
        SDL_Rect rect;
        if(sdlimage->hasClip())
		{
		    rect.x = sdlimage->offsetX;
		    rect.y = sdlimage->offsetY;
		    rect.w = sdlimage->width();
		    rect.h = sdlimage->height();
		    source = &rect;
		}
		
        SDL_Rect dest;
        dest.x = position.x;
        dest.y = position.y;
        dest.w = sdlimage->width();
        dest.h = sdlimage->height();
        
        SDL_BlitSurface(sdlimage->surface, source, surface, &dest);
    }
    
    int SDL_Canvas::width() const {
        return surface->w;
    }

    int SDL_Canvas::height() const {
        return surface->h;
    }

    void SDL_Canvas::update() {
        SDL_Flip(surface);
    }
}

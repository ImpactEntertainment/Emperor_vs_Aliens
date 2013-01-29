/**
 * \file sdlcanvas.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \date 09/01/2013
 */

#include <SDL/SDL_video.h>
#include <SDL/SDL_endian.h>
#include <SDL/SDL_mutex.h>

#include "sdlcanvas.h"

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

    void SDL_Canvas::drawPixel(const Point& position, const Color& color) {

        SDL_PixelFormat *format = surface->format;
        int bytesPerPixel = format->BytesPerPixel;
        Uint8 *pixelAddress = (Uint8 *) surface->pixels
                + position.y * surface->pitch
                + position.x * bytesPerPixel;

        Uint32 pixelColor = SDL_MapRGB(format, color.red, color.green,
                color.blue);

        if (SDL_MUSTLOCK(surface)) {
            SDL_LockSurface(surface);
        }

        switch (bytesPerPixel) {
            case 1:
                *pixelAddress = pixelColor;
                break;

            case 2:
                *(Uint16 *) pixelAddress = pixelColor;
                break;

            case 3:
                if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                    pixelAddress[0] = (pixelColor >> 16) & 0xff;
                    pixelAddress[1] = (pixelColor >> 8) & 0xff;
                    pixelAddress[2] = pixelColor & 0xff;
                } else {
                    pixelAddress[0] = pixelColor & 0xff;
                    pixelAddress[1] = (pixelColor >> 8) & 0xff;
                    pixelAddress[2] = (pixelColor >> 16) & 0xff;
                }
                break;

            case 4:
                *(Uint32 *) pixelAddress = pixelColor;
                break;
        }

        if (SDL_MUSTLOCK(surface)) {
            SDL_UnlockSurface(surface);
        }
    }

    void SDL_Canvas::fillRectangle(const Rectangle& rectangle, 
                const Point& position, const Color& color) {
        
        SDL_Rect rect;
        rect.w = rectangle.width;
        rect.h = rectangle.height;
        rect.x = position.x;
        rect.y = position.y;
        
        Uint32 pixelColor = SDL_MapRGB(surface->format, color.red, color.green,
                color.blue);
        
        SDL_FillRect(surface, &rect, pixelColor);
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

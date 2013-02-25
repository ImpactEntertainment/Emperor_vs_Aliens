/**
 * \file sdlimage.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 09/01/2013
 */
#include <fstream>
#include <SDL/SDL_image.h>

#include "sdlimage.h"

using namespace std;

namespace edge
{

    Image *
    Image::load(const string& imagePath, int offsetX, int offsetY, int width, int height) throw (Exception)
    {

        ifstream file(imagePath.c_str());

        if (!file) {
            throw Exception("Image not found");
        }

        file.close();

        SDL_Surface *surface = IMG_Load(imagePath.c_str());

        if (surface == NULL) {
            throw Exception("Invalid image");
        }

        SDL_Surface *displayFormatSurface = SDL_DisplayFormatAlpha(surface);
        SDL_FreeSurface(surface);
        
        SDL_Image *image = new SDL_Image(displayFormatSurface);

		image->offsetX	= offsetX;
		image->offsetY	= offsetY;
		image->w		= width;
		image->h		= height;

        return image;
    }

    void
    Image::release(Image *image) throw (Exception)
    {
        if (image) {
            delete image;
        }
    }

    SDL_Image::~SDL_Image()
    {
        if (surface) {
            SDL_FreeSurface(surface);
        }
    }

    SDL_Image::SDL_Image(SDL_Surface * surface)
    {
        this->surface = surface;
    }

    int
    SDL_Image::width() const
    {
        return w;
    }

    int
    SDL_Image::height() const
    {
        return h;
    }
    
    bool
    SDL_Image::hasClip() const
    {
    	return (offsetX || offsetY || w || h);
    }
    
    Image *
	SDL_Image::select(const Point& position, const Rectangle& rect) const
	{
		SDL_Surface *selection = SDL_CreateRGBSurface(SDL_HWSURFACE,
			rect.width, rect.height, surface->format->BitsPerPixel,
			surface->format->Rmask, surface->format->Gmask,
			surface->format->Bmask, surface->format->Amask);
		
		if (selection == NULL) {
			return NULL;
		}
		
		SDL_Rect r, dest;
		r.x = position.x;
		r.y = position.y;
		r.w = rect.width;
		r.h = rect.height;
		
		dest.x = dest.y = 0;
		dest.w = rect.width;
		dest.h = rect.height;
		
		//SDL_BlitSurface(surface, &r, selection, &dest);
		//SDL_UpdateRect(selection, 0, 0, 0, 0);
		SDL_BlitSurface(selection, &dest, surface, &dest);
		SDL_UpdateRect(surface, 0, 0, 0, 0);
		
		return new SDL_Image(selection);
	}
}

/**
 * \file sdlimage.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 09/01/2013
 */
#include <fstream>

#include "sdlimage.h"

using namespace std;

namespace edge
{

    Image *  Image::load(const string& imagePath, int offsetX, int offsetY, int width, int height) throw (Exception){

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

    void Image::release(Image *image) throw (Exception){
        if (image) {
            delete image;
        }
    }

    SDL_Image::~SDL_Image(){
        if (surface) {
            SDL_FreeSurface(surface);
        }
    }

    SDL_Image::SDL_Image(SDL_Surface * surface){
        this->surface = surface;
    }

    int SDL_Image::width() const{
        return w;
    }

    int SDL_Image::height() const{
        return h;
    }
    
    bool  SDL_Image::hasClip() const{
    	return (offsetX || offsetY || w || h);
    }
    
}

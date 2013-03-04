/**
 * \file sdlcanvas.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 09/01/2013
 */

#include <SDL/SDL_video.h>
#include <SDL/SDL_endian.h>
#include <SDL/SDL_mutex.h>


#include <iostream>
#include <cmath>

#include "sdlcanvas.h"
#include "sdlimage.h"
#include "enviromentelement.h"

using namespace std;

namespace edge {

    SDL_Canvas::SDL_Canvas(SDL_Surface *surface) {
        if (surface == NULL) {
            this->surface = SDL_GetVideoSurface();
        } else {
            this->surface = surface;
        }
        background = Image::load("/opt/EmperorVsAliens/data/images/level_01.png");
        map_elements = Image::load("/opt/EmperorVsAliens/data/images/map_elements.png"); 
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

    void SDL_Canvas::drawImage(const Image *image){
        const SDL_Image *sdlimage = dynamic_cast<const SDL_Image *>(image);
        
        SDL_BlitSurface(sdlimage->surface, NULL, surface, NULL);
    
    }

    void SDL_Canvas::drawImage(const Image *image, const Point& position){
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
	
	void 
	SDL_Canvas::drawImage(const Image *image, const Rectangle& baseRect, const Point& position)
	{
		const SDL_Image *sdlimage = dynamic_cast<const SDL_Image *>(image);
        
		SDL_Rect srcrect;
		srcrect.x = baseRect.x;
		srcrect.y = baseRect.y;
		srcrect.w = baseRect.width;
		srcrect.h = baseRect.height;
		
        SDL_Rect rect;
        rect.x = position.x;
        rect.y = position.y;
        rect.w = sdlimage->width();
        rect.h = sdlimage->height();
        
        SDL_BlitSurface(sdlimage->surface, &srcrect, surface, &rect);
	}
	
	void SDL_Canvas::drawBottomGrass()
	{
	
		Rectangle rect;
		rect.x = 0;
		rect.y = 1020;
		rect.width = 1920;
		rect.height = 60;
		
		//Image *bottomGrass = 
		//Image::load("/opt/EmperorVsAliens/data/images/map_elements.png",
		//imageOffsetX,imageOffsetY,imageWidth,imageHeight);

		Point position;

		position.x = 0;
		position.y = 1020;

		drawImage(map_elements, rect, position);
		
		//Image::release(bottomGrass);
	}
	
	void SDL_Canvas::drawBackground() 
	{
		//Image *background = Image::load("/opt/EmperorVsAliens/data/images/level_01.png");

		Point position(0, 0);
		drawImage(background, position);
		
		//Image::release(background);
	}
	
	void SDL_Canvas::drawElementAt(const Element& element, int fieldIndex)
	{

		//Image *image = 
		//Image::load("/opt/EmperorVsAliens/data/images/map_elements.png",  element.mResource.x, element.mResource.y, element.mResource.width, element.mResource.height);

		Point position;

		position.x = (fieldIndex%16)*112+134-(element.mResource.width-112);
		position.y = (fieldIndex >> 4)*112+409-(element.mResource.height-112);

		drawImage(map_elements, position);
		
		//Image::release(image);
	}
	
	void SDL_Canvas::drawElement(const Element& element)
	{
	
		Point position;
		
		position.x = (element.mPosition->x)*112+134-(element.mResource.width-112);
		position.y = (element.mPosition->y)*112+409-(element.mResource.height-112);

		drawImage(element.image, position);
	}
	
	void SDL_Canvas::drawUnit(Unit& element){
		
		Point position;
		
		if(element.status == UNIT_MOVING)
		{
			int timeTraveling = element.travelTime - (element.ARRIVAL_TIME - Timer::get_currentFrameTick());
			position.x = (element.mPosition->x)*112 + element.speed.x * (timeTraveling) +134-(element.mResource.width-112);
			position.y = (element.mPosition->y)*112 + element.speed.y * (timeTraveling) +409-(element.mResource.height-112);	         
		}		
		else
		{        
			position.x = (element.mPosition->x)*112+134-(element.mResource.width-112);
			position.y = (element.mPosition->y)*112+409-(element.mResource.height-112);
		}
		drawImage(element.image, element.mResource, position);
	
	}
	
	void SDL_Canvas::drawEnviroment(vector<EnviromentElement>& enviroment) 
	{	
		vector<EnviromentElement>::iterator it;
		for(it = enviroment.begin(); it != enviroment.end(); it++)
			drawElement(*it);
	}
	
	void SDL_Canvas::drawUnits(list<Unit*>& units) 
	{	
		list<Unit*>::iterator it;
		for(it = units.begin(); it != units.end(); it++)
			drawUnit(**it);
	}
}

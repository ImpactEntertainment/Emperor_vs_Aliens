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

using namespace std;

namespace edge {

    SDL_Canvas::SDL_Canvas(SDL_Surface *surface) {
        if (surface == NULL) {
            this->surface = SDL_GetVideoSurface();
        } else {
            this->surface = surface;
        }

        display 	     = Image::load("/opt/Emperor_vs_Aliens/data/images/unitdisplay.png");
 		currentHPDisplay = Image::load("/opt/Emperor_vs_Aliens/data/images/currentHPDisplay.png");
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
	SDL_Canvas::drawImage(const Image *image, const Rectangle& baseRect, const Point& position){
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
        
        SDL_BlitSurface(sdlimage->surface,&srcrect, surface, &rect);
	}
	
	void SDL_Canvas::drawBottomGrass(const EnviromentElement* bottomGrass){
	
		Point position;

		position.x = bottomGrass->mPosition->x;
		position.y = bottomGrass->mPosition->y;

		drawImage(bottomGrass->image, bottomGrass->mResource, position);
	}
	
	void SDL_Canvas::drawBackground(const Image* background) 
	{
		drawImage(background);
	}
	
	void SDL_Canvas::drawMenu(const Menu& element){

		Point position;
		
		position.x = (element.mPosition->x)*112+134-(element.mResource.width-112);
		position.y = (element.mPosition->y)*112+409-(element.mResource.height-112/2);

		drawImage(element.image, element.mResource, position);
	}

	void SDL_Canvas::drawMenu(const HUD& element){	
		drawImage(element.image);
	}
	
	void SDL_Canvas::drawDisplay(const Display& element){	
		drawImage(element.image,element.position);
	}
	
	void SDL_Canvas::drawElement(const Element& element){
	
		Point position;
		
		position.x = (element.mPosition->x)*112+134-(element.mResource.width-112);
		position.y = (element.mPosition->y)*112+409-(element.mResource.height-112);

		drawImage(element.image, element.mResource, position);
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
		drawUnitStatus(element.MAX_HITPOINTS, element.attributes.hitpoints, position);
	}

	void SDL_Canvas::drawUnitStatus(int maxHP, int currentHP, const Point& position){
		Rectangle statusDisplay;
		statusDisplay.width = 112;
		statusDisplay.height= 112;
		statusDisplay.x 	= 0;
		statusDisplay.y 	= 0;
		drawImage(display,statusDisplay,position);
		
		statusDisplay.width = 34 + (int)(67 * (1.0-(maxHP - currentHP*1.0)/maxHP));
		drawImage(currentHPDisplay,statusDisplay,position); 
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
	
	void SDL_Canvas::drawBuilding(Building& element){
	
		Point position;
		
		position.x = 0;
		position.y = 0;

		drawImage(element.image, element.mResource, position);
	}
}

/**
 * \file sdlcanvas.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
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

    void SDL_Canvas::drawPixel(const Point& position, const Color& color) {

        if (SDL_MUSTLOCK(surface)) {
            SDL_LockSurface(surface);
        }

        putPixel(position, color);

        if (SDL_MUSTLOCK(surface)) {
            SDL_UnlockSurface(surface);
        }
    }

    void SDL_Canvas::putPixel(const Point& position, const Color& color) {

        SDL_PixelFormat *format = surface->format;
        int bytesPerPixel = format->BytesPerPixel;
        Uint8 *pixelAddress = (Uint8 *) surface->pixels
                + position.y * surface->pitch
                + position.x * bytesPerPixel;

        Uint32 pixelColor = SDL_MapRGB(format, color.red, color.green,
                color.blue);

        if (position.x < 0 || position.x >= surface->w)
            return;

        if (position.y < 0 || position.y >= surface->h)
            return;

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

    void SDL_Canvas::drawRectangle(const Rectangle& rectangle,
            const Point& position, const Color& color) {

        Point topLeft(position.x, position.y);
        Point topRight(position.x + rectangle.width, position.y);
        Point bottomLeft(position.x, position.y + rectangle.height);
        Point bottomRight(position.x + rectangle.width,
                position.y + rectangle.height);

        Point borderPoint;

        if (SDL_MUSTLOCK(surface)) {
            SDL_LockSurface(surface);
        }

        borderPoint.y = topLeft.y;
        for (int x = topLeft.x; x <= topRight.x; x++) {
            borderPoint.x = x;
            putPixel(borderPoint, color);
        }

        borderPoint.y = bottomLeft.y;
        for (int x = bottomLeft.x; x <= bottomRight.x; x++) {
            borderPoint.x = x;
            putPixel(borderPoint, color);
        }

        borderPoint.x = topLeft.x;
        for (int y = topLeft.y; y <= bottomLeft.y; y++) {
            borderPoint.y = y;
            putPixel(borderPoint, color);
        }

        borderPoint.x = topRight.x;
        for (int y = topRight.y; y <= bottomRight.y; y++) {
            borderPoint.y = y;
            putPixel(borderPoint, color);
        }

        if (SDL_MUSTLOCK(surface)) {
            SDL_UnlockSurface(surface);
        }
    }

    void SDL_Canvas::drawLine(const Line& position, const Color& color) {

        int x1 = position.begin.x;
        int x2 = position.end.x;
        int y1 = position.begin.y;
        int y2 = position.end.y;

        // Bresenham's line algorithm
        const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
        if (steep) {
            std::swap(x1, y1);
            std::swap(x2, y2);
        }

        if (x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        const float dx = x2 - x1;
        const float dy = fabs(y2 - y1);

        float error = dx / 2.0f;
        const int ystep = (y1 < y2) ? 1 : -1;
        int y = (int) y1;

        const int maxX = (int) x2;

        if (SDL_MUSTLOCK(surface)) {
            SDL_LockSurface(surface);
        }

        for (int x = (int) x1; x < maxX; x++) {
            if (steep) {
                putPixel(Point(y, x), color);
            } else {
                putPixel(Point(x, y), color);
            }

            error -= dy;

            if (error < 0) {
                y += ystep;
                error += dx;
            }
        }

        if (SDL_MUSTLOCK(surface)) {
            SDL_UnlockSurface(surface);
        }
    }

    void SDL_Canvas::drawCircle(const Circle& circle, const Point& center,
            const Color& color) {

        // Algoritmo de Bresenham para círculos
        int error = 3 - (circle.radius << 1);
        int i = 0, j = circle.radius;

        do {
            drawCirclePoints(center.x, center.y, i, j, color);

            if (error < 0) {
                error += (i << 2) + 6;
            } else {
                error += ((i - j) << 2) + 10;
                j--;
            }

            i++;
        } while (i <= j);

    }

    void SDL_Canvas::fillCircle(const Circle& circle, const Point& center,
            const Color& color) {

        // Algoritmo de Bresenham para círculos
        int error = 3 - (circle.radius << 1);
        int i = 0, j = circle.radius;

        do {
            fillCirclePoints(center.x, center.y, i, j, color);

            if (error < 0) {
                error += (i << 2) + 6;
            } else {
                error += ((i - j) << 2) + 10;
                j--;
            }

            i++;
        } while (i <= j);

    }

    void SDL_Canvas::drawCirclePoints(int cx, int cy,
            int x, int y, Color color) {

        putPixel(Point(cx + x, cy + y), color);
        putPixel(Point(cx + x, cy - y), color);
        putPixel(Point(cx - x, cy + y), color);
        putPixel(Point(cx - x, cy - y), color);
        putPixel(Point(cx + y, cy + x), color);
        putPixel(Point(cx + y, cy - x), color);
        putPixel(Point(cx - y, cy + x), color);
        putPixel(Point(cx - y, cy - x), color);
    }

    void SDL_Canvas::fillCirclePoints(int cx, int cy, int x, int y, 
            Color color) {
        for (int j = x; j <= y; j++) {
            putPixel(Point(cx + x, cy + j), color);
            putPixel(Point(cx + x, cy - j), color);
            putPixel(Point(cx - x, cy + j), color);
            putPixel(Point(cx - x, cy - j), color);
            putPixel(Point(cx + j, cy + x), color);
            putPixel(Point(cx + j, cy - x), color);
            putPixel(Point(cx - j, cy + x), color);
            putPixel(Point(cx - j, cy - x), color);
        }
    }

    void 
    SDL_Canvas::drawImage(const Image *image, const Point& position)
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
	
	void 
	SDL_Canvas::drawImage(const Image *image, const Point& basePosition,
			const Rectangle& baseRect, const Point& position)
	{
		const SDL_Image *sdlimage = dynamic_cast<const SDL_Image *>(image);
        
		SDL_Rect srcrect;
		srcrect.x = basePosition.x;
		srcrect.y = basePosition.y;
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
		int imageOffsetX = 0;
		int imageOffsetY = 1020;
		
		int imageWidth	 = 1920;
		int imageHeight	 = 60;

		Image *bottomGrass = 
		Image::load("/opt/EmperorVsAliens/resources/map_elements.png",
		imageOffsetX,imageOffsetY,imageWidth,imageHeight);

		Point position;

		position.x = 0;
		position.y = 1020;

		drawImage(bottomGrass, position);
		
		Image::release(bottomGrass);
	}
	
	void SDL_Canvas::drawBackground() 
	{
		Image *background = Image::load("/opt/EmperorVsAliens/resources/level_01.png");

		Point position(0, 0);
		drawImage(background, position);
		
		Image::release(background);
	}
	
	void SDL_Canvas::drawElementAt(const Element& element, int fieldIndex)
	{

		Image *image = 
		Image::load("/opt/EmperorVsAliens/resources/map_elements.png",  element.mResource.x, element.mResource.y, element.mResource.width, element.mResource.height);

		Point position;

		position.x = (fieldIndex%16)*112+134-(element.mResource.width-112);
		position.y = (fieldIndex >> 4)*112+409-(element.mResource.height-112);

		drawImage(image, position);
		
		Image::release(image);
	}
	
	/**drawElement(Unit& unit)
	* ...
	*  position = calcularPosition();
	*   factor = MOVING ? FACTOR_CORRIDO : 1
	*   position.x += 112/(112*unit.speed.x);
	*   position.y += 112/(112*unit.speed.y);
	* ...
	*/
	void SDL_Canvas::drawElement(const Element& element)
	{
	
		Point position;
		
		position.x = (element.mPosition.x)*112+134-(element.mResource.width-112);
		position.y = (element.mPosition.y)*112+409-(element.mResource.height-112);

		drawImage(element.image, position);
	}
	
	void SDL_Canvas::drawUnit(const Unit& element){
		Point position;
		
		position.x = (element.mPosition.x)*112+134-(element.mResource.width-112);
		position.y = (element.mPosition.y)*112+409-(element.mResource.height-112);

		drawImage(element.image, position);
	
	}
	
	void SDL_Canvas::drawEnviroment(vector<EnviromentElement>& enviroment) 
	{	
		vector<EnviromentElement>::iterator it;
		for(it = enviroment.begin(); it < enviroment.end(); it++)
			drawElement(*it);
	}
	
	void SDL_Canvas::drawUnits(vector<Unit>& units) 
	{	
		vector<Unit>::iterator it;
		for(it = units.begin(); it < units.end(); it++)
			drawUnit(*it);
	}
}

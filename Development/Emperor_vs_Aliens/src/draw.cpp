/**
 * \file draw.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \co-author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 24/12/2012
 */
#include <iostream>
#include <cmath>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <draw.h>

using namespace std;

// Função retirada da implementação da SDL

Uint32 getPixel(SDL_Surface *surface, int x, int y) {
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *) surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp) {
        case 1:
            return *p;

        case 2:
            return *(Uint16 *) p;

        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;

        case 4:
            return *(Uint32 *) p;

        default:
            return 0;
    }
}

// Função retirada da implementação da SDL

void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel) {
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *) surface->pixels + y * surface->pitch + x * bpp;
    
    switch (bpp) {
        case 1:
            *p = pixel;
            break;

        case 2:
            *(Uint16 *) p = pixel;
            break;

        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            } else {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4:
            *(Uint32 *) p = pixel;
            break;
    }
}

void fillPoints(SDL_Surface *screen, int cx, int cy, int x, int y, Uint32 color) {
    for (int j = x; j <= y; j++) {
        putPixel(screen, cx + x, cy + j, color);
        putPixel(screen, cx + x, cy - j, color);
        putPixel(screen, cx - x, cy + j, color);
        putPixel(screen, cx - x, cy - j, color);
        putPixel(screen, cx + j, cy + x, color);
        putPixel(screen, cx + j, cy - x, color);
        putPixel(screen, cx - j, cy + x, color);
        putPixel(screen, cx - j, cy - x, color);
    }
}

void drawCircle(SDL_Surface *screen, int radius, int x, int y, SDL_Color color) {
    Uint32 pixelColor = SDL_MapRGB(screen->format, color.r, color.g, color.b);

    // Algoritmo de Bresenham para círculos
    int error = 3 - (radius << 1);
    int i = 0, j = radius;

    do {
        fillPoints(screen, x, y, i, j, pixelColor);

        if (error < 0) {
            error += (i << 2) + 6;
        } else {
            error += ((i - j) << 2) + 10;
            j--;
        }

        i++;
    } while (i <= j);

}

void drawLine(SDL_Surface *screen, int x1, int y1, int x2, int y2,
        SDL_Color color) {
    Uint32 pixelColor = SDL_MapRGB(screen->format, color.r, color.g, color.b);

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

    for (int x = (int) x1; x < maxX; x++) {
        if (steep) {
            putPixel(screen, y, x, pixelColor);
        } else {
            putPixel(screen, x, y, pixelColor);
        }

        error -= dy;

        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
}

void drawBackground(Canvas *canvas) {
	Image *background = Image::load("/opt/EmperorVsAliens/resources/level_01.png");

	Point position(0, 0);
    canvas->drawImage(background, position);
    
    Image::release(background);
}

void drawBottomGrass(Canvas *canvas) {

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

    canvas->drawImage(bottomGrass, position);
    
    Image::release(bottomGrass);
}

void drawElementAt(Canvas *canvas, const Element& element, int fieldIndex)
{

    Image *image = 
    Image::load("/opt/EmperorVsAliens/resources/map_elements.png",  element.mResourcePositionX, element.mResourcePositionY, 	     element.mWidth, element.mHeight);

    Point position;

    position.x = (fieldIndex%16)*112+134-(element.mWidth-112);;
    position.y = (fieldIndex >> 4)*112+409-(element.mHeight-112);

    canvas->drawImage(image, position);
    
    Image::release(image);
}

void drawEnviroment(Canvas *canvas) {
	Element cherryTree;
	cherryTree.loadCherryTree();
	
	drawElementAt(canvas,cherryTree,11);
	drawElementAt(canvas,cherryTree,68);
	drawElementAt(canvas,cherryTree,94);
	
	Element largeRock01,
			largeRock03,
			smallRock01;
			
	largeRock01.loadLargeRock01();
	largeRock03.loadLargeRock03();
	smallRock01.loadSmallRock01();
	
	drawElementAt(canvas,largeRock01,68);
	drawElementAt(canvas,largeRock03,91);
	drawElementAt(canvas,smallRock01,11);
	
}

void draw(Canvas *canvas) {
    drawBackground(canvas);
    drawEnviroment(canvas);
    drawBottomGrass(canvas);

    canvas->update();
}

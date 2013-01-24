// Autor: Edson Alves
// Data: 24/12/2012
// e-mail: edsonalves@unb.br
#include <iostream>
#include <cmath>
#include <SDL/SDL.h>

#include <draw.h>

using namespace std;

// Função retirada da implementação da SDL
Uint32 getPixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0; 
    }
}

// Função retirada da implementação da SDL
void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
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
        *(Uint32 *)p = pixel;
        break;
    }
}

void draw(SDL_Surface *screen)
{
	drawMap(screen,"/opt/EmperorVsAliens/resources/level_01.bmp");

	Element element;
	
	element.mFilename = "/opt/EmperorVsAliens/resources/cerejeira.bmp";
	
	element.mPositionX = 350;
	element.mPositionY = 344;
	drawElement(screen,element);
	
	element.mPositionX = 329;
	element.mPositionY = 836;
	drawElement(screen,element);
	
	element.mPositionX = 774;
	element.mPositionY = 492;
	drawElement(screen,element);
	
	element.mPositionX = 1442;
	element.mPositionY = 399;
	drawElement(screen,element);
	element.mFilename = "/opt/EmperorVsAliens/resources/rock.bmp";
	
	element.mPositionX = 488;
	element.mPositionY = 687;
	drawElement(screen,element);
	
	element.mPositionX = 848;
	element.mPositionY = 576;
	drawElement(screen,element);
	
	element.mPositionX = 1262;
	element.mPositionY = 724;
	drawElement(screen,element);
	
	element.mPositionX = 1421;
	element.mPositionY = 474;
	drawElement(screen,element);
	
	element.mPositionX = 1219;
	element.mPositionY = 984;
	drawElement(screen,element);
	
	element.mFilename = "/opt/EmperorVsAliens/resources/nuvem.bmp";
	
	element.mPositionX = 159;
	element.mPositionY = 84;
	drawElement(screen,element);
	
	element.mPositionX = 1166;
	element.mPositionY = 102;
	drawElement(screen,element);	
	
	element.mFilename = "/opt/EmperorVsAliens/resources/sol.bmp";
	
	element.mPositionX = 779;
	element.mPositionY = 98;
	drawElement(screen,element);
	
	element.mFilename = "/opt/EmperorVsAliens/resources/muralha.bmp";
	
	element.mPositionX = 1;
	element.mPositionY = 334;
	drawElement(screen,element);
	
	SDL_UpdateRect(screen, 0, 0, 0, 0);
}

void drawBackground(SDL_Surface *screen)
{
	SDL_Surface *background = SDL_LoadBMP("/opt/EmperorVsAliens/resources/blackboard.bmp");

	if (!background)
	{
		cerr << "Erro no carregamento do background" << endl;
	}

	SDL_BlitSurface(background, NULL, screen, NULL);	
}

void drawMap(SDL_Surface *screen, const std::string filename)
{
	SDL_Surface *map = SDL_LoadBMP(filename.c_str());
	SDL_BlitSurface(map, NULL, screen, NULL);
}

void drawElement(SDL_Surface *screen, const Element& element)
{
	SDL_Surface *elementBMP = SDL_LoadBMP(element.mFilename.c_str());
	SDL_Rect destination;
	destination.x = element.mPositionX;
	destination.y = element.mPositionY;
	SDL_BlitSurface(elementBMP, NULL, screen, &destination);
}

void fillPoints(SDL_Surface *screen, int cx, int cy, int x, int y, Uint32 color)
{
	for (int j = x; j <= y; j++)
	{
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

void drawCircle(SDL_Surface *screen, int radius, int x, int y, SDL_Color color)
{
	Uint32 pixelColor = SDL_MapRGB(screen->format, color.r, color.g, color.b);

	// Algoritmo de Bresenham para círculos
	int error = 3 - (radius << 1);
	int i = 0, j = radius;

	do 
	{
		fillPoints(screen, x, y, i, j, pixelColor);

		if (error < 0)
		{
			error += (i << 2) + 6;
		} else 
		{
			error += ((i - j) << 2) + 10;
			j--;
		}	

		i++;
	} while (i <= j);

}

void drawLine(SDL_Surface *screen, int x1, int y1, int x2, int y2, 
	SDL_Color color)
{
	Uint32 pixelColor = SDL_MapRGB(screen->format, color.r, color.g, color.b);
	
	// Bresenham's line algorithm
	const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
	if(steep)
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
	}
 
	if(x1 > x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
 
	const float dx = x2 - x1;
	const float dy = fabs(y2 - y1);
 
	float error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y = (int)y1;
 
	const int maxX = (int)x2;
 
	for(int x=(int)x1; x<maxX; x++)
	{
		if(steep)
        {
            putPixel(screen, y, x, pixelColor);
        }
		else
        {
            putPixel(screen, x, y, pixelColor);
        }
 
           error -= dy;

	    if(error < 0)
        {
	        y += ystep;
	        error += dx;
        }
	}
}


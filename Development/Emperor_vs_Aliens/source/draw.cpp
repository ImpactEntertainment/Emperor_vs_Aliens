#include <iostream>
#include <cmath>
#include <SDL/SDL.h>

#include <draw.hpp>

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



void drawBackground(SDL_Surface *screen){

	SDL_Color blue;
	blue.r = 50;
	blue.g = 50;
	blue.b = 255;
	
	SDL_Color lightgreen;
	lightgreen.r = 90;
	lightgreen.g = 200;
	lightgreen.b = 100;

	SDL_PixelFormat *format = screen->format;
	
	Uint32 bluePixel = SDL_MapRGB(format, blue.r, blue.g, blue.b);	
	Uint32 lightgreenPixel = SDL_MapRGB(format, lightgreen.r, lightgreen.g, lightgreen.b);
	
	SDL_Rect sky;
	sky.x = 0;
	sky.y = 0;
	sky.w = 800;
	sky.h = 300;

	SDL_FillRect(screen, &sky, bluePixel);
	
	SDL_Rect ground;
	ground.x = 0;
	ground.y = 300;
	ground.w = 800;
	ground.h = 300;

	SDL_FillRect(screen, &ground, lightgreenPixel);
}

void drawMontains(SDL_Surface *screen){
    SDL_Color darkgreen;
	darkgreen.r = 0;
	darkgreen.g = 80;
	darkgreen.b = 10;
	
	SDL_Color middlegreen;
	middlegreen.r = 20;
	middlegreen.g = 170;
	middlegreen.b = 40;


	SDL_PixelFormat *format = screen->format;
    Uint32 darkgreenPixel = SDL_MapRGB(format, darkgreen.r, darkgreen.g, darkgreen.b);
	Uint32 middlegreenPixel = SDL_MapRGB(format, middlegreen.r, middlegreen.g, middlegreen.b);


	SDL_Rect mountainleft;
	mountainleft.x = 25;
	mountainleft.y = 170;
	mountainleft.w = 380;
	mountainleft.h = 150;

	SDL_FillRect(screen, &mountainleft, darkgreenPixel);

	SDL_Rect mountainright;
	mountainright.x = 430;
	mountainright.y = 150;
	mountainright.w = 300;
	mountainright.h = 180;

	SDL_FillRect(screen, &mountainright, middlegreenPixel);

}

void drawMap(SDL_Surface *screen){

	SDL_Color darkgray;
	darkgray.r = darkgray.g = darkgray.b = 60;
	
	SDL_Color gray;
	gray.r = gray.g = gray.b = 127;
	
	SDL_Color lightgray;
	lightgray.r = lightgray.g = lightgray.b = 190;
	

	SDL_Color lightpink;
	lightpink.r = 240;
	lightpink.g = 180;
	lightpink.b = 240;
	
	SDL_PixelFormat *format = screen->format;


	Uint32 darkgrayPixel = SDL_MapRGB(format, darkgray.r, darkgray.g, darkgray.b);
	Uint32 grayPixel = SDL_MapRGB(format, gray.r, gray.g, gray.b);
	Uint32 lightgrayPixel = SDL_MapRGB(format, lightgray.r, lightgray.g, lightgray.b);

	

	SDL_Rect wall;
	wall.x = 5;
	wall.y = 290;
	wall.w = 80;
	wall.h = 310;

	SDL_FillRect(screen, &wall, grayPixel);

	
	SDL_Rect rockA;
	rockA.x = 280;
	rockA.y = 350;
	rockA.w = 40;
	rockA.h = 40;

	SDL_FillRect(screen, &rockA, darkgrayPixel);
	
	SDL_Rect rockB;
	rockB.x = 255;
	rockB.y = 520;
	rockB.w = 40;
	rockB.h = 40;

	SDL_FillRect(screen, &rockB, darkgrayPixel);
	
	SDL_Rect rockC;
	rockC.x = 480;
	rockC.y = 380;
	rockC.w = 40;
	rockC.h = 40;

	SDL_FillRect(screen, &rockC, darkgrayPixel);
	
	SDL_Rect rockD;
	rockD.x = 460;
	rockD.y = 540;
	rockD.w = 40;
	rockD.h = 40;

	SDL_FillRect(screen, &rockD, darkgrayPixel);
	
	SDL_Rect woodA;
	woodA.x = 410;
	woodA.y = 420;
	woodA.w = 20;
	woodA.h = 60;

	SDL_FillRect(screen, &woodA, lightgrayPixel);
	
	SDL_Rect leafsA;
	leafsA.x = 420;
	leafsA.y = 350;
	leafsA.w = 60;
	leafsA.h = 60;
    drawCircle(screen, 40, 420, 380, lightpink);

	
	SDL_Rect woodB;
	woodB.x = 610;
	woodB.y = 540;
	woodB.w = 20;
	woodB.h = 60;

	SDL_FillRect(screen, &woodB, lightgrayPixel);
	
	SDL_Rect leafsB;
	leafsB.x = 590;
	leafsB.y = 480;
	leafsB.w = 60;
	leafsB.h = 60;
    drawCircle(screen, 40, 620, 500, lightpink);
    
	SDL_UpdateRect(screen, 0, 0, 0, 0);

/*
	SDL_Color blue;
	blue.r = blue.g = 0;
	blue.b = 255;

	for (int i = 0; i < 35; i++){
		drawLine(screen, 35 + i, 35, 180 + i, 215, blue);
		drawLine(screen, 35 + i, 215, 180 + i, 35, blue);
	}*/
}

void drawSun(SDL_Surface *screen){
	SDL_Color yellow;
	yellow.r = 230;
	yellow.g = 230;
	yellow.b = 90;

	drawCircle(screen, 30, 360, 40, yellow);
}

void fillPoints(SDL_Surface *screen, int cx, int cy, int x, int y, Uint32 color){

	for (int j = x; j <= y; j++){
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

void drawCircle(SDL_Surface *screen, int radius, int x, int y, SDL_Color color){

	Uint32 pixelColor = SDL_MapRGB(screen->format, color.r, color.g, color.b);

	// Algoritmo de Bresenham para círculos
	int error = 3 - (radius << 1);
	int i = 0, j = radius;

	do{
		fillPoints(screen, x, y, i, j, pixelColor);

		if (error < 0)		{
			error += (i << 2) + 6;
		} else {
			error += ((i - j) << 2) + 10;
			j--;
		}	

		i++;
	} while (i <= j);

}

void drawLine(SDL_Surface *screen, int x1, int y1, int x2, int y2, 	SDL_Color color){
	Uint32 pixelColor = SDL_MapRGB(screen->format, color.r, color.g, color.b);
	
	// Bresenham's line algorithm
	const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
	if(steep){
		std::swap(x1, y1);
		std::swap(x2, y2);
	}
 
	if(x1 > x2){
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
 
	const float dx = x2 - x1;
	const float dy = fabs(y2 - y1);
 
	float error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y = (int)y1;
 
	const int maxX = (int)x2;
 
	for(int x=(int)x1; x<maxX; x++){
		if(steep){
            putPixel(screen, y, x, pixelColor);
        }
		else{
            putPixel(screen, x, y, pixelColor);
        }
 
           error -= dy;

	    if(error < 0){
	        y += ystep;
	        error += dx;
        }
	}
}

void drawCloud(SDL_Surface *screen){

	SDL_Color white;
	white.r = white.g = white.b = 255;
	
	SDL_PixelFormat *format = screen->format;
	
	Uint32 whitePixel = SDL_MapRGB(format, white.r, white.g, white.b);
		
	SDL_Rect cloudleft;
	cloudleft.x = 105;
	cloudleft.y = 25;
	cloudleft.w = 80;
	cloudleft.h = 50;

	SDL_FillRect(screen, &cloudleft, whitePixel);

	SDL_Rect cloudright;
	cloudright.x = 405;
	cloudright.y = 35;
	cloudright.w = 80;
	cloudright.h = 50;

	SDL_FillRect(screen, &cloudright, whitePixel);
}


void draw(SDL_Surface *screen)
{
	drawBackground(screen);
	drawMontains(screen);	
	drawSun(screen);
	drawCloud(screen);
	drawMap(screen);
	SDL_UpdateRect(screen, 0, 0, 0, 0);
}

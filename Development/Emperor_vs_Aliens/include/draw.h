// Autor: Edson Alves
// Data: 24/12/2012
// e-mail: edsonalves@unb.br
#ifndef DRAW_H
#define DRAW_H

#include <string>
#include <SDL/SDL.h>
#include <element.h>

extern Uint32 getPixel(SDL_Surface *surface, int x, int y);
extern void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

extern void drawCircle(SDL_Surface *screen, int radius, int x, int y, 
	SDL_Color color);
extern void drawLine(SDL_Surface *screen, int x0, int y0, int x1, int y1,
	SDL_Color color);

extern void draw(SDL_Surface *screen);
extern void drawBackground(SDL_Surface *screen);
extern void drawMap(SDL_Surface *screen, const std::string filename);
extern void drawElement(SDL_Surface *screen, const Element& element);

#endif


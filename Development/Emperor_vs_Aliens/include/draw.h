/**
 * \file draw.h
 * \brief Classe que contém as funções de desenho.
 *
 * As funções de desenho estão todas baseadas na SDL, trabalhando com a
 * superfície diretamente. Este módulo deverá ser refatorado nas próximas
 * versões.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \co-author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 24/12/2012
 */
#ifndef DRAW_H
#define DRAW_H

#include <SDL/SDL.h>
#include <canvas.h>
#include <element.h>


#ifdef PS3
 	#ifndef VIDEO_H_PS3
	#define VIDEO_H_PS3
 		const string resourcesDirectory ="/dev_hdd0/game/EMPALIENS/USRDIR/data/";
 	#endif
#else
 	#ifndef VIDEO_H_PC
	#define VIDEO_H_PC
    const string resourcesDirectory ="data/";
    #endif
#endif

using namespace edge;

extern Uint32 getPixel(SDL_Surface *surface, int x, int y);
extern void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

extern void drawCircle(SDL_Surface *screen, int radius, int x, int y, 
	SDL_Color color);
extern void drawLine(SDL_Surface *screen, int x0, int y0, int x1, int y1,
	SDL_Color color);

extern void draw(Canvas *canvas);

#endif


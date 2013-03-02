/**
 * \file draw.h
 * \brief Classe que contém as funções de desenho.
 *
 * As funções de desenho estão todas baseadas na SDL, trabalhando com a
 * superfície diretamente. Este módulo deverá ser refatorado nas próximas
 * versões.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \co-author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 24/12/2012
 */
#ifndef DRAW_H
#define DRAW_H

#include <SDL/SDL.h>
#include <canvas.h>
#include <element.h>

using namespace edge;

extern Uint32 getPixel(SDL_Surface *surface, int x, int y);
extern void putPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

extern void draw(Canvas *canvas);

#endif


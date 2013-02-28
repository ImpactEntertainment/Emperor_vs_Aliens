/**
 * \file draw.cpp
 * \author Edson Alves (edsonalves@unb.br)
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

void drawX(Canvas *canvas) {
    Image *x = Image::load("/opt/tictactoe/data/images/x.png");

    int blackboardFrameSize = 40;
    int leftMargin = 14, topMargin = 14;
    int boardTileSize = 194;
    int boardTileMargin = (boardTileSize - x->width()) / 2;

    Point position;

    position.x = blackboardFrameSize + leftMargin + boardTileMargin;
    position.y = blackboardFrameSize + topMargin + boardTileMargin;
    
    canvas->drawImage(x, position);
    
    Image::release(x);
}

void drawO(Canvas *canvas) {
    Image *y = Image::load("/opt/tictactoe/data/images/o.png");

    int blackboardFrameSize = 40;
    int leftMargin = 14, topMargin = 14;
    int boardTileSize = 194;
    int barHeight = 15;
    int boardTileMargin = (boardTileSize - y->width()) / 2;

    Point position;
    position.x = blackboardFrameSize + leftMargin + boardTileMargin +
            boardTileSize * 2 + barHeight * 2;
    position.y = blackboardFrameSize + topMargin + boardTileMargin +
            boardTileSize + barHeight;

    canvas->drawImage(y, position);
    
    Image::release(y);
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


/**
 * \file sdlcanvas.h
 * \brief Classe que representa a área desenhável da janela em SDL.
 *
 * Esta classe representa a área desenhável da janela em SDL.
 * O vídeo deve estar inicializado para o uso do canvas.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 08/01/2013
 */
#ifndef SDL_CANVAS_H
#define SDL_CANVAS_H

#include "exception.h"
#include "canvas.h"

namespace edge {

    class SDL_Canvas : public Canvas {
    public:
        SDL_Canvas(SDL_Surface *surface = NULL);
        ~SDL_Canvas();
        
        int width() const;
        int height() const;
        
        void update();
        
        void drawPixel(const Point& position, const Color& color);
        void fillRectangle(const Rectangle& rectangle, const Point& position, 
                const Color& color);
        
    private:
        SDL_Surface *surface;
    };

}

#endif


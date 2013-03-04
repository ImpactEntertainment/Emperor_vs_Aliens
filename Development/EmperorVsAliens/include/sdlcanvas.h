/**
 * \file sdlcanvas.h
 * \brief Classe que representa a área desenhável da janela em SDL.
 *
 * Esta classe representa a área desenhável da janela em SDL.
 * O vídeo deve estar inicializado para o uso do canvas.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 08/01/2013
 */
#ifndef SDL_CANVAS_H
#define SDL_CANVAS_H

#include "exception.h"
#include "canvas.h"
#include "rectangle.h"

namespace edge {

    class SDL_Canvas : public Canvas {
    public:
        SDL_Canvas(SDL_Surface *surface = NULL);
        ~SDL_Canvas();

        int width() const;
        int height() const;

        void erase(const Color& color);
        void update();

        void drawImage(const Image *image);
        void drawImage(const Image *image, const Point& position);
        void drawImage(const Image *image, const Rectangle& baseRect, const Point& position);    
        
        void drawBackground();
        void drawBottomGrass();
        void drawEnviroment(vector<EnviromentElement>& enviroment);
        void drawUnits(list<Unit*>& units);
        
        void drawElementAt(const Element& element, int fieldIndex);
        void drawMenu(const Menu& element);
        void drawElement(const Element& element);
        void drawUnit(Unit& element);
            

    private:
        SDL_Surface *surface;
        Image *map_elements,*background;
    };

}

#endif

/**
 * \file display.h
 * \brief Classe que representa o HUD do jogador.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 08/02/2012
 */
#ifndef DISPLAY_H
#define	DISPLAY_H

#include <string>
#include "exception.h"
#include "image.h"
#include "point.h"
#include "font.h"
#include "color.h"

using namespace std;

namespace edge {

    class Display {
    public:
        Display();
        Display(string* infoTracked, int x, int y, int size, int r, int g, int b);
        
        void init(int size);
        void shutdown();
        void update();

        Point position;
        Image *image;
        string  *infoDisplayed;
        Color color;
        Font *font;
    };
    
}

#endif

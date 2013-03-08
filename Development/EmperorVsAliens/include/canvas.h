/**
 * \file canvas.h
 * \brief Interface que representa a área desenhável da janela.
 *
 * Esta interface representa a área desenhável da janela.
 * O vídeo deve estar inicializado para o uso do canvas.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 26/12/2012
 */
#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "exception.h"
#include "point.h"
#include "color.h"
#include "rectangle.h"
#include "image.h"
#include "element.h"
#include "enviromentelement.h"
#include "unit.h"
#include "menu.h"
#include "hud.h"
#include "display.h"

namespace edge {

    class Canvas {
    public:
        virtual int width() const = 0;
        virtual int height() const = 0;

        virtual void erase(const Color& color) = 0;
        virtual void update() = 0;

        virtual void drawImage(const Image *image) = 0;
        virtual void drawImage(const Image *image, const Point& position) = 0;
		virtual void drawImage(const Image *image, const Rectangle& baseRect, const Point& position) = 0;
      
     	virtual void drawBackground(const Image* background) = 0;
     	virtual void drawBottomGrass(const EnviromentElement* bottomGrass) = 0;
     	virtual void drawEnviroment(vector<EnviromentElement>& enviroment) = 0;
     	virtual void drawUnits(list<Unit*>& units) = 0;
     	
     	virtual void drawElement(const Element& element)=0;
        virtual void drawMenu(const Menu& element)=0;
        virtual void drawMenu(const HUD& element)=0;
        virtual void drawDisplay(const Display& element)=0;
    	virtual void drawUnit(Unit& element)=0;

    };

}

#endif

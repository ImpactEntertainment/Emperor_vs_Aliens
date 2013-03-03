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
#include <boost/ptr_container/ptr_vector.hpp>

#include "exception.h"
#include "point.h"
#include "color.h"
#include "rectangle.h"
#include "image.h"
#include "element.h"
#include "enviromentelement.h"
#include "unit.h"

namespace edge {

    class Canvas {
    public:
        virtual int width() const = 0;
        virtual int height() const = 0;

        virtual void erase(const Color& color) = 0;
        virtual void update() = 0;

      
        virtual void drawImage(const Image *image, const Point& position) = 0;
		virtual void drawImage(const Image *image, const Rectangle& baseRect, const Point& position) = 0;
      
     	virtual void drawBackground() = 0;
     	virtual void drawBottomGrass() = 0;
     	virtual void drawEnviroment(vector<EnviromentElement>& enviroment) = 0;
     	virtual void drawUnits(list<Unit*>& units) = 0;
     	
     	virtual void drawElementAt(const Element& element, int fieldIndex) = 0;
     	virtual void drawElement(const Element& element)=0;
    	virtual void drawUnit(Unit& element)=0;
    };

}

#endif

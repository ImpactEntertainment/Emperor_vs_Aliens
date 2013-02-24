/**
 * \file canvas.h
 * \brief Interface que representa a área desenhável da janela.
 *
 * Esta interface representa a área desenhável da janela.
 * O vídeo deve estar inicializado para o uso do canvas.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 26/12/2012
 */
#ifndef CANVAS_H
#define CANVAS_H

#include "exception.h"
#include "color.h"
#include "point.h"
 /*


#include "rectangle.h"
#include "line.h"
#include "circle.h"*/
#include "image.h"

namespace edge {

    class Canvas {
    public:
        virtual int width() const = 0;
        virtual int height() const = 0;

        virtual void erase(const Color& color) = 0;
        virtual void update() = 0;

        virtual void drawImage(const Image *image, const Point& position) = 0;


    };

}

#endif

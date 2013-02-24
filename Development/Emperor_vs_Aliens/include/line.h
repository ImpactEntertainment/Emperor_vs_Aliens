/**
 * \file line.h
 * \brief Classe que representa uma reta no espaço bidimensional.
 *
 * Esta classe representa uma reta no espaço bidimensional. Para efeitos de
 * generalidade, são permitidas coordenadas negativas, embora a maior parte das
 * vezes apenas coordenadas não negativas são suficiente.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 09/01/2012
 */
#ifndef LINE_H
#define	LINE_H

#include "point.h"

namespace edge {

    class Line {
    public:
        Line(const Point& begin = Point(), const Point& end = Point());

        Point begin;
        Point end;
    };
}


#endif


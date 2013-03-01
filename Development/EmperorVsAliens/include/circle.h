/**
 * \file circle.h
 * \brief Classe que representa um círculo no espaço bidimensional.
 *
 * Esta classe representa um círculo no espaço bidimensional. 
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 10/01/2012
 */
#ifndef CIRCLE_H
#define	CIRCLE_H

namespace edge {

    class Circle {
    public:
        Circle(unsigned int radius = 1);

        unsigned int radius;
    };
}

#endif


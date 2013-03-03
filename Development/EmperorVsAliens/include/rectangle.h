/**
 * \file rectangle.h
 * \brief Classe que representa um retângulo no espaço bidimensional.
 *
 * Esta classe representa um retângulo no espaço bidimensional. 
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 09/01/2012
 */
#ifndef RECTANGLE_H
#define	RECTANGLE_H

namespace edge {

    class Rectangle {
    public:
        Rectangle(unsigned int width = 1, unsigned int height = 0);

		int x, y;
        int width;
        int height;
    };
}

#endif


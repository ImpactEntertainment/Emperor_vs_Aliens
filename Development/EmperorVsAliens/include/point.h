/**
 * \file point.h
 * \brief Classe que representa um ponto no espaço bidimensional.
 *
 * Esta classe representa um ponto no espaço bidimensional. Para efeitos de
 * generalidade, são permitidas coordenadas negativas, embora a maior parte das
 * vezes apenas coordenadas não negativas são suficiente.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 09/01/2012
 */
#ifndef POINT_H
#define	POINT_H

namespace edge {

    class Point {
    public:
        Point(int x = 0, int y = 0);
				int getX();
				int getY();

        int x;
        int y;
    };
}

#endif


/**
 * \file point.h
 * \brief Classe que representa um ponto no espaço bidimensional.
 *
 * Esta classe representa um ponto no espaço bidimensional. Para efeitos de
 * generalidade, são permitidas coordenadas negativas, embora a maior parte das
 * vezes apenas coordenadas não negativas são suficiente.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \co-author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 09/01/2012
 */
#ifndef POINT_H
#define	POINT_H


#define NORTHWEST	0
#define NORTH		1
#define NORTHEAST	2
#define WEST		3
#define EAST		4
#define SOUTHWEST	5
#define SOUTH		6
#define SOUTHEAST	7

class Element;

namespace edge {

    class Point {
    public:
        Point(int x = 0, int y = 0);

		Element *habitant;
		Point   *path[8];
        int x;
        int y;
    };
}

#endif


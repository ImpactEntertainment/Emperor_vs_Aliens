/**
 * \file Field.h
 * \brief Classe que representa um ponto no espaço bidimensional.
 *
 * Esta classe representa um ponto no espaço bidimensional. Para efeitos de
 * generalidade, são permitidas coordenadas negativas, embora a maior parte das
 * vezes apenas coordenadas não negativas são suficiente.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \co-author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 09/01/2012
 */
#ifndef FIELD_H
#define	FIELD_H


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

    class Field {
    public:
        Field(int x = 0, int y = 0);

		Element *habitant;
        Field   *path[8];
		int x;
        int y;
    };
}

#endif


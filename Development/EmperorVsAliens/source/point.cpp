/**
 * \file sdlcanvas.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \date 09/01/2013
 */

#include "point.h"

namespace edge {

    Point::Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
		
		int Point::getX() {
				return this->x;
		}
		int Point::getY() {
				return this->y;
		}

}

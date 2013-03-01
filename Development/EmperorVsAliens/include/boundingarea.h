/**
 * \file boundingarea.h
 * \brief Interface que representa uma região para detecção de colisão.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 25/01/2012
 */
#ifndef BOUNDING_AREA_H
#define	BOUNDING_AREA_H

#include "point.h"

namespace edge {

    class BoundingArea {
    public:
        virtual bool hit(const Point& point) const = 0;
    };
}

#endif


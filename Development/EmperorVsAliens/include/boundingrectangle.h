/**
 * \file boundingarea.h
 * \brief Interface que representa uma região para detecção de colisão.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 25/01/2012
 */
#ifndef BOUNDING_RECTANGLE_H
#define	BOUNDING_RECTANGLE_H

#include "boundingarea.h"
#include "rectangle.h"

namespace edge {

    class BoundingRectangle : public BoundingArea {
    public:
        BoundingRectangle(const Rectangle& rect = Rectangle(), 
                const Point& position = Point());
        
        void set(const Rectangle& rect, const Point& position);
        Point getPosition() const;
        
        bool hit(const Point& point) const;
        
    private:
        int xmin;
        int xmax;
        int ymin;
        int ymax;
    };
}

#endif


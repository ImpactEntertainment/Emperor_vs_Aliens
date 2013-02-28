#include "boundingrectangle.h"

namespace edge
{

    BoundingRectangle::BoundingRectangle(const Rectangle& rect,
        const Point& position)
    {
        set(rect, position);
    }
    
    void
    BoundingRectangle::set(const Rectangle& rect, const Point& position)
    {
        xmin = position.x;
        xmax = position.x + rect.width - 1;
        ymin = position.y;
        ymax = position.y + rect.height - 1;
    }
        
    Point 
    BoundingRectangle::getPosition() const
    {
        return Point(xmin, ymin);
    }
    
    bool 
    BoundingRectangle::hit(const Point& point) const
    {
        int x = point.x;
        int y = point.y;
        
        return (x >= xmin) && (x <= xmax) && (y >= ymin) && (y <= ymax);
    }

}
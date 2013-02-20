#include "marker.h"

namespace edge
{

    Marker::Marker()
    {
        image = 0;
    }

    void
    Marker::init()
    {
    	mWidth	= 112;
		mHeight	= 112;
		mResourcePositionX = 0;
		mResourcePositionY = 0;
        image = Image::load("/opt/EmperorVsAliens/resources/map_elements.png",mResourcePositionX,mResourcePositionY,mWidth,mHeight);
    }

    void
    Marker::shutdown()
    {
        Image::release(image);
    }

    void
    Marker::draw(Canvas* canvas)
    {
        canvas->drawImage(image, position);
    }
}

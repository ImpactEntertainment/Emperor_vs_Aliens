#include "marker.h"

namespace edge
{

    Marker::Marker()
    {
        image = 0;
    }

    void
    Marker::loadRectangle()
    {
    	mResource.width	= 112;
		mResource.height= 112;
		mResource.x		= 0;
		mResource.y		= 0;
	}
	
	void
	Marker::loadImage()
	{
		image = Image::load("/opt/EmperorVsAliens/resources/map_elements.png",mResource.x,mResource.y,mResource.width,mResource.height);
	}
}

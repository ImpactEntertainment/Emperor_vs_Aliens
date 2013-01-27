/**
 * \file windowsettings.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \date 30/12/2012
 */
#include "windowsettings.h"

namespace edge {

ostream& 
operator<<(ostream& os, PresentationMode presentationMode)
{
	switch (presentationMode)
	{
		case WINDOW: 
			os << "Window";
			break;

		case NO_FRAME_WINDOW: 
			os << "No frame window";
			break;
		case FULLSCREEN:
			os << "Fullscreen";
			break;
	}

	return os;
}

ostream& 
operator<<(ostream& os, WindowSize windowSize)
{
	switch (windowSize)
	{
		case RESIZABLE: 
			os << "Resizable window";
			break;

		case FIXED: 
			os << "Fixed-size window";
			break;
	}

	return os;
}

ostream& 
operator<<(ostream& os, const WindowSettings settings)
{
	os << "Dimensions: " << settings.width << "x" << settings.height << endl;
	os << "Title: " << settings.title << endl;
	os << "Presentation mode: " << settings.presentationMode << endl;
	os << "Window size: " << settings.windowSize << endl;

	return os;
}

WindowSettings::WindowSettings(unsigned short width, unsigned short height,
	string title, PresentationMode presentationMode, WindowSize windowSize)
{
	this->width = width;
	this->height = height;
	this->title = title;
	this->presentationMode = presentationMode;
	this->windowSize = windowSize;
}

}


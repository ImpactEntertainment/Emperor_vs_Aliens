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
operator<<(ostream& os, ColorDepth colorDepth)
{
	switch (colorDepth)
	{
		case SYSTEM:
			os << "Same as OS";
			break;

		case INDEXED: 
			os << "Indexed";
			break;

		case HICOLOR: 
			os << "Hicolor";
			break;

		case TRUE_COLOR: 
			os << "True color";
			break;

		case RGBA:
			os << "32-bit";
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
	os << "Color depth: " << settings.colorDepth << endl;
	os << "Window size: " << settings.windowSize << endl;

	return os;
}

WindowSettings::WindowSettings()
{
	width = 800; 
	height = 600;
	title = "Window"; 
	presentationMode = FULLSCREEN;		
	windowSize = FIXED;
	colorDepth = SYSTEM;
}

WindowSettings& 
WindowSettings::operator=(const WindowSettings& settings)
{
	width = settings.width;
	height = settings.height;
	title = settings.title;
	presentationMode = settings.presentationMode;
	colorDepth = settings.colorDepth;
	windowSize = settings.windowSize;

	return *this;
}

bool 
WindowSettings::operator!=(const WindowSettings& settings)
{
	if (width != settings.width)
		return true;

	if (height != height)
		return true;

	if (title != settings.title)
		return true;

	if (presentationMode != settings.presentationMode)
		return true;

	if (colorDepth != settings.colorDepth)
		return true;

	if (windowSize != settings.windowSize)
		return true;

	return false;
}

}


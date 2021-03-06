/**
 * \file sdlwindow.cpp
 * \author Edson Alves (edsonalves@unb.br)
 * \date 07/01/2013
 */
#include <iostream>
#include <cstdlib>

#include "video.h"
#include "sdlwindow.h"
#include "sdlcanvas.h"
#include "sdlvideosettings.h"
#include "sdlwindowsettings.h"

namespace edge {

SDL_Window::SDL_Window(){
	canvas = NULL;
	surface = NULL;
}

void 
SDL_Window::applySettings(const WindowSettings& settings) throw (Exception){
	Video *video = Video::getInstance();
	VideoSettings videoSettings = video->currentSettings();

	SDL_VideoSettings sdlVideoSettings(videoSettings);
	SDL_WindowSettings sdlWindowSettings(settings);

	Uint32 videoFlags = sdlVideoSettings.getFlags();
	Uint32 windowFlags = sdlWindowSettings.getFlags();
	Uint32 flags = videoFlags | windowFlags;

	int bitsPerPixel = sdlWindowSettings.getBitsPerPixel();

	surface = SDL_SetVideoMode(settings.width, settings.height, 
		bitsPerPixel, flags);

	if (surface == NULL){
		throw Exception("Error on SDL_SetVideoMode()");
	} 

	if (canvas)
		delete canvas;
	
	canvas = new SDL_Canvas();

	if (!canvas){
		throw Exception("Sem memoria");
	}

        SDL_WM_SetCaption(sdlWindowSettings.title.c_str(), NULL);
        
	this->settings = settings;
}

WindowSettings 
SDL_Window::currentSettings() const
{
	return settings;
}

int 
SDL_Window::getWidth() const
{
	return surface->w;
}

int 
SDL_Window::getHeight() const
{
	return surface->h;
}

Canvas * 
SDL_Window::getCanvas() const
{
	return canvas;
}

}


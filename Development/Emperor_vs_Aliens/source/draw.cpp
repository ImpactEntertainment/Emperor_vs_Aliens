/**
 * \file draw.cpp
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \co-author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com.br)
 * \date 24/12/2012
 */
#include <iostream>
#include <cmath>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <draw.h>

using namespace std;

void drawBackground(Canvas *canvas) {
    string imagesrc= resourcesDirectory+"images/level_01.png";
   
	Image *background = Image::load(imagesrc.c_str());

	Point position(0, 0);
    canvas->drawImage(background, position);
    
    Image::release(background);
}

void drawBottomGrass(Canvas *canvas) {

	int imageOffsetX = 0;
	int imageOffsetY = 1020;
	int imageWidth	 = 1920;
	int imageHeight	 = 60;
    string imagesrc= resourcesDirectory+"images/map_elements.png";
    Image *bottomGrass = 
    Image::load(imagesrc.c_str(),
    imageOffsetX,imageOffsetY,imageWidth,imageHeight);

    Point position;

    position.x = 0;
    position.y = 1020;

    canvas->drawImage(bottomGrass, position);
    
    Image::release(bottomGrass);
}

void drawElementAt(Canvas *canvas, const Element& element, int fieldIndex)
{
    string imagesrc= resourcesDirectory+"images/map_elements.png";
    Image *image = 
    Image::load(imagesrc.c_str(),  element.mResourcePositionX, element.mResourcePositionY, 	     element.mWidth, element.mHeight);

    Point position;

    position.x = (fieldIndex%16)*112+134-(element.mWidth-112);;
    position.y = (fieldIndex >> 4)*112+409-(element.mHeight-112);

    canvas->drawImage(image, position);
    
    Image::release(image);
}

void drawEnviroment(Canvas *canvas) {
	Element cherryTree;
	cherryTree.loadCherryTree();
	
	drawElementAt(canvas,cherryTree,11);
	drawElementAt(canvas,cherryTree,68);
	drawElementAt(canvas,cherryTree,94);
	
	Element largeRock01,
			largeRock03,
			smallRock01;
			
	largeRock01.loadLargeRock01();
	largeRock03.loadLargeRock03();
	smallRock01.loadSmallRock01();
	
	drawElementAt(canvas,largeRock01,68);
	drawElementAt(canvas,largeRock03,91);
	drawElementAt(canvas,smallRock01,11);
	
}

void draw(Canvas *canvas) {
    drawBackground(canvas);
    drawEnviroment(canvas);
    drawBottomGrass(canvas);

    canvas->update();
}

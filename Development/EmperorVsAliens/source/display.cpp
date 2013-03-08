#include <iostream>

#include "font.h"
#include "display.h"
#include "sdltext.h"

using namespace std;

namespace edge {

	Display::Display()
	{
		infoDisplayed = new string("EMPTY");
		color.red = 255;
		color.green = 0;
		color.blue = 0;
		position.x = 0;
		position.y = 0;

	}

	Display::Display(string* infoTracked, int x, int y, int size, int r, int g, int b)
	{
	    init(size);
	    infoDisplayed = infoTracked;
	    position.x = x;
	    position.y = y;
	    color.red = r;
	    color.green = g;
	    color.blue = b;
	}

	void Display::update()
	{
		SDL_Text text(infoDisplayed->c_str());
		image = text.render(font, color);	
	}

	void
	Display::init(int size)
	{
		font = Font::load("/opt/EmperorVsAliens/data/fonts/tribal.ttf", size);
		if (!font) {
			cerr << "Erro no carregamento da fonte" << endl;
			return;
		}
		/*
		Font *font = Font::load("/opt/EmperorVsAliens/data/fonts/tribal.ttf", 200);

		if (!font) {
			cerr << "Erro no carregamento da fonte" << endl;
			return;
		}

		string s = "Victory!!";
		SDL_Text text(s);
		Color gold(220, 220, 55);

		victoryMessage = text.render(font, gold);		
		victoryMessagePosition.x = 120;
		victoryMessagePosition.y = 240;

		text.set("Defeat");
		Color red(255, 0, 0);
		defeatMessage = text.render(font, red);		
		defeatMessagePosition.x = 180;
		defeatMessagePosition.y = 240;

		delete font;
		font = Font::load("/opt/EmperorVsAliens/data/fonts/Tribal.ttf", 100);

		Color white(255, 255, 255);
		text.set("Player X");
		xPlayerLabel = text.render(font, white);

		xPlayerLabelPosition.x = 750;
		xPlayerLabelPosition.y = 75;

		text.set("Player O");
		oPlayerLabel = text.render(font, white);

		oPlayerLabelPosition.x = 750;
		oPlayerLabelPosition.y = 375;

		delete font;
		xStatus.winsPosition.x = 800;
		xStatus.winsPosition.y = 175;

		xStatus.losesPosition.x = xStatus.winsPosition.x;
		xStatus.losesPosition.y = xStatus.winsPosition.y + 50;

		xStatus.drawsPosition.x = xStatus.winsPosition.x;
		xStatus.drawsPosition.y = xStatus.losesPosition.y + 50;

		oStatus.winsPosition.x = 800;
		oStatus.winsPosition.y = 475;

		oStatus.losesPosition.x = oStatus.winsPosition.x;
		oStatus.losesPosition.y = oStatus.winsPosition.y + 50;

		oStatus.drawsPosition.x = oStatus.winsPosition.x;
		oStatus.drawsPosition.y = oStatus.losesPosition.y + 50;
		*/
	}

	void
	Display::shutdown()
	{
		if(image)
			delete image;
		if(font)
			delete font;
/*
		if (xPlayerLabel)
			delete xPlayerLabel;

		if (oPlayerLabel)
			delete oPlayerLabel;
*/
	}
}
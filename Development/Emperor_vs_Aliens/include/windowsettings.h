/**
 * \file windowsettings.h
 * \brief Representação das opções de janela. 
 *
 * Esta classe representa as opções específicas de janela. As opções
 * de vídeo estão na classe WindowSettings.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \co-author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 30/12/2012
 */
#ifndef EDGE_WINDOW_SETTINGS_H
#define EDGE_WINDOW_SETTINGS_H

#include <ostream>

using namespace std;

namespace edge {

typedef enum {WINDOW, NO_FRAME_WINDOW, FULLSCREEN} PresentationMode;
typedef enum {RESIZABLE, FIXED} WindowSize;

ostream& operator<<(ostream& os, PresentationMode presentationMode);
ostream& operator<<(ostream& os, WindowSize windowSize);

class WindowSettings {
	friend ostream& operator<<(ostream& os, const WindowSettings settings);
	
public:
	WindowSettings(unsigned short width = 800, unsigned short height = 600,
		string title = "Window", PresentationMode presentationMode = WINDOW,		WindowSize windowSize = FIXED);

	unsigned short width;
	unsigned short height;
	string title;
	PresentationMode presentationMode;
	WindowSize windowSize;
};	

}

#endif


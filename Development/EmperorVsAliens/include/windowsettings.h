/**
 * \file windowsettings.h
 * \brief Representação das opções de janela. 
 *
 * Esta classe representa as opções específicas de janela. As opções
 * de vídeo estão na classe WindowSettings.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 30/12/2012
 */
#ifndef EDGE_WINDOW_SETTINGS_H
#define EDGE_WINDOW_SETTINGS_H

#include <ostream>

using namespace std;

namespace edge {

typedef enum {SYSTEM, INDEXED, HICOLOR, TRUE_COLOR, RGBA} ColorDepth;
typedef enum {WINDOW, NO_FRAME_WINDOW, FULLSCREEN} PresentationMode;
typedef enum {RESIZABLE, FIXED} WindowSize;

ostream& operator<<(ostream& os, PresentationMode presentationMode);
ostream& operator<<(ostream& os, WindowSize windowSize);
ostream& operator<<(ostream& os, ColorDepth colorDepth);

class WindowSettings {
	friend ostream& operator<<(ostream& os, const WindowSettings settings);
	
public:
	WindowSettings();

	WindowSettings& operator=(const WindowSettings& settings);
	bool operator!=(const WindowSettings& settings);

	unsigned short width;
	unsigned short height;
	string title;
	PresentationMode presentationMode;
	ColorDepth colorDepth;
	WindowSize windowSize;
};	

}

#endif


/**
 * \file mainGUI.h
 * \brief Graphical User Interface da janela principal (primeira janela) do jogo EVA.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */

#ifndef MAIN_GUI_H
#define	MAIN_GUI_H

#include "gui.h"
#include "GUIfactory.h"

using namespace std;

class MainGUI : public GUI {
public:
	void loadImage();
    void handleClick(int index);
    void loadButtons();
    void loadSubmenus();
    void beDone();
};

#endif


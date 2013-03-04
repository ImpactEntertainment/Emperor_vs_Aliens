/**
 * \file levelselectGUI.h
 * \brief Graphical User Interface da janela para selecao de niveis do jogo EVA.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */

#ifndef LEVEL_SELECT_GUI_H
#define	LEVEL_SELECT_GUI_H

#include "gui.h"
#include "GUIfactory.h"

using namespace std;

class LevelSelectGUI : public GUI {
public:
	void loadImage();
    void handleClick(int index);
    void loadButtons();
    void loadSubmenus();
};

#endif


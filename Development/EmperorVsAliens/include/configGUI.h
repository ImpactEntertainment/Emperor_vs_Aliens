/**
 * \file configGUI.h
 * \brief Graphical User Interface da janela para selecao de niveis do jogo EVA.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */

#ifndef CONFIG_GUI_H
#define	CONFIG_GUI_H

#include "gui.h"
#include "GUIfactory.h"

using namespace std;

class ConfigGUI : public GUI {
public:
	void loadImage();
    void handleClick(int index);
    void loadButtons();
    void loadSubmenus();
};

#endif


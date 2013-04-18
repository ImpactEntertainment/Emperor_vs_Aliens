/**
 * \file GUIfactory.h
 * \brief Classe que implementa o metodo fabrica para instanciar menus diferentes.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef GUI_FACTORY_H
#define GUI_FACTORY_H

#include "mainGUI.h"
#include "levelselectGUI.h"
#include "configGUI.h"

typedef enum GUI_Option
{
	GUI_MAIN,
	GUI_LEVEL_SELECT,
	GUI_CONFIG
}GUI_Option;

class GUIFactory {
public:
    static GUI *create_GUI(GUI_Option choice);
};

#endif


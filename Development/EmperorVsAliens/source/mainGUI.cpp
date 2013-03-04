#include "mainGUI.h"

void MainGUI::loadSubmenus()
{
    addSubmenu(GUIFactory::create_GUI(GUI_MAIN));
}

void MainGUI::loadButtons()
{
    addButton(0,0,150,150);
    addButton(0,150,150,150);
    addButton(0,300,150,150);
}

void MainGUI::handleClick(int index)
{
    switch(index)
    {
    case 0:
        openSubmenu(0);
    break;
    case 1:
        openSubmenu(0);
    break;
    case 2:
        openSubmenu(0);
    break;
    }
}

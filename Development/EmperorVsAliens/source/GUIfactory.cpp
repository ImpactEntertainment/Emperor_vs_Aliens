#include "GUIfactory.h"

GUI *GUIFactory::create_GUI(GUI_Option choice)
{
    switch(choice)
    {   
    case GUI_MAIN:
        return new MainGUI;
    break;
    default:
        return 0;
    break;
    }
}

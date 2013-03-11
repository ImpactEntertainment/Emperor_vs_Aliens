#include "GUIfactory.h"

GUI *GUIFactory::create_GUI(GUI_Option choice)
{
    switch(choice)
    {   
    case GUI_MAIN:
        return new MainGUI;
    break;
    case GUI_LEVEL_SELECT:
        return new LevelSelectGUI;
    break;
    case GUI_CONFIG:
        return new ConfigGUI;
    break;
    default:
        return 0;
    break;
    }
}

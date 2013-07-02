/**
 * \file GUI.h
 * \brief Graphical User Interface.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */

#ifndef GUI_H
#define	GUI_H

#include <vector>
#include "exception.h"
#include "video.h"
#include "window.h"
#include "gameconfig.h"
#include "button.h"

using namespace std;

class GUI {
public:
    virtual void handleClick(int index) =0;
    virtual void loadButtons()          =0;
    virtual void loadSubmenus()         =0;
    virtual void loadImage()            =0;

    virtual void beDone();

    GUI();

    void init(GameConfig& config) throw(Exception);
    
    void loop() throw(Exception);
    void shutdown();
    void die();
    void handleMouseEvent(SDL_MouseButtonEvent &event);
    bool click(Button& area);
    void addButton(int x, int y, int w, int h);
    void addSubmenu(GUI* submenu);
    void openSubmenu(int index);
    void close();


    bool done;
    Point clicked;
    vector<Button*> buttons;
    vector<GUI*>    submenus;
    GameConfig      *gameConfig;
    Image           *background;
//private:
    Video *video;
    Window *window;

    void initVideo() throw(Exception);
    void initWindow() throw(Exception);
};

#endif


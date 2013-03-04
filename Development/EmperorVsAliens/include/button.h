#ifndef BUTTON_H
#define BUTTON_H

#include "rectangle.h"

using namespace edge;

class Button{
public:
    Button(int x, int y, int w, int h);

    int         index;
    Rectangle   rect;

};

#endif
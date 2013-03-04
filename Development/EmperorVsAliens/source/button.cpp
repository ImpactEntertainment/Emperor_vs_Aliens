#include "button.h"

Button::Button(int x, int y, int w, int h)
: rect(x,y)
{
    rect.width = w;
    rect.height = h;
}

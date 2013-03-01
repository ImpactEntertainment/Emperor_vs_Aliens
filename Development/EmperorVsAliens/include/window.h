/**
 * \file window.h
 * \brief Interface que representa uma janela.
 *
 * Esta interface representa uma janela, com suas configurações. A janela
 * deve ser exibida com o método show() antes da chamada de qualquer
 * função de desenho.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 01/01/2013
 */
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL/SDL.h>

#include "exception.h"
#include "windowsettings.h"
#include "canvas.h"

namespace edge {

class Window {
public:
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0; 

	virtual Canvas * getCanvas() const = 0;
	virtual WindowSettings currentSettings() const = 0;
};

}

#endif


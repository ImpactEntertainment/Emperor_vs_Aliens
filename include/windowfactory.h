/**
 * \file windowfactory.h
 * \brief Interface para a classe responsável pela criação de janelas.
 *
 * Cria janelas a partir das configurações dadas.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 08/01/2013
 */
#ifndef WINDOW_FACTORY_H
#define WINDOW_FACTORY_H

#include <SDL/SDL.h>

#include "exception.h"
#include "window.h"

namespace edge {

class WindowFactory {
public:
	static Window * create(const WindowSettings& settings) throw (Exception);
};

}

#endif


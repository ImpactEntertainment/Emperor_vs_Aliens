/**
 * \file  Level_01.h
 * \brief Classe que representa o level 01.
 *
 * \author Luis Gustavo Souza Silva (luisgustavodd@hotmail.com)
 * \date 25/01/2012
 */
#ifndef LEVEL_01_H
#define	LEVEL_01_H

#include "map.h"

using namespace std;
	
class Level_01 : public Map
{
public:
private:
	void loadWaves();
	void loadEnviroment();
};
#endif


/**
 * \file font.h
 * \brief Interface que representa uma fonte.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 80/02/2012
 */

#ifndef FONT_H
#define	FONT_H

#include <string>

#include "exception.h"

using namespace std;

namespace edge {
	
	class Font {
	public:
		virtual int size() const = 0;
		static Font * load(const string& fontPath, int size) throw (Exception);
	};
}

#endif	/* FONT_H */


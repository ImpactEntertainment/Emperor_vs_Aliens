/**
 * \file text.h
 * \brief Interface que representa um texto.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 80/02/2012
 */

#ifndef TEXT_H
#define	TEXT_H

#include <string>

#include "exception.h"
#include "font.h"
#include "image.h"
#include "color.h"

using namespace std;

namespace edge {
	
	class Text {
	public:
		Text(const string& text = "");
		
		int length() const;
		string toString() const;
		
		void set(const string& text);
		
		virtual Image * render(Font *font, const Color& color) const 
			throw (Exception) = 0;
		
	protected:
		string text;
	};
}

#endif


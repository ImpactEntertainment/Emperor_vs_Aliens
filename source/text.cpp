#include "text.h"

namespace edge {

	Text::Text(const string& text){
		set(text);
	}

	int
	Text::length() const
	{
		return text.size();
	}

	string
	Text::toString() const
	{
		return text;
	}

	void
	Text::set(const string& text){
		this->text = text;
	}

}

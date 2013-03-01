#ifndef FIELD_H
#define	FIELD_H

#include "element.h"

using namespace std;

class Field : public Point
{
private:

public:
	Element* habitant;
	Field*	 boundries[8];
};
#endif


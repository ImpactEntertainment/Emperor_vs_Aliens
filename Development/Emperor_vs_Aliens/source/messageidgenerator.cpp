#include "messageidgenerator.h"

namespace edge {
	
	MessageID 
	MessageIDGenerator::nextID() {
		return freeID++;
	}
		
	MessageID MessageIDGenerator::freeID = 0;
	
}

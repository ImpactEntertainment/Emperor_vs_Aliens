#include "object.h"
#include "messageidgenerator.h"

namespace edge {

	MessageID Object::addChildID = MessageIDGenerator::nextID();
	MessageID Object::removeChildID = MessageIDGenerator::nextID();
	
	Object::Object(Object *parent)
	{
		changeParent(parent);
	}

	Object::~Object()
	{

	}

	void 
	Object::changeParent(Object *newParent) 
	{
		if (parent) {
			sendMessage(removeChildID, NULL, NULL);
		}
		
		parent = newParent;
		
		if (parent) {
			sendMessage(addChildID, NULL, NULL);
		}
	}
	
	Object *
	Object::getParent() const {
		return parent;
	}
	
	bool 
	Object::isRoot() const {
		return parent == NULL;
	}

	void 
	Object::sendMessage(MessageID id, const void *inputs, void *outputs)
	{
		if (parent) {
			parent->receiveMessage(id, this, inputs, outputs);
		}
	}
	
}

#include "BaseElement.h"

BaseElement::BaseElement(){
}

BaseElement::~BaseElement(){
}

bool BaseElement::has_cleared() const {
	return cleared;
}

void BaseElement::clear() {
	cleared = true;
}
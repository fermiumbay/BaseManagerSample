#pragma once
#include "BaseElement.h"
#include <vector>

class BaseManager{
public:
	BaseManager();
	~BaseManager();
	virtual void add(BaseElement* e);
	virtual void update();
	
protected:
	std::vector<BaseElement*> elements;

};


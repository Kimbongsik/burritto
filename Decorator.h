#pragma once
#include "Burito.h"
class Decorator :
	public Burito
{
public:
	Decorator();
	~Decorator();

public:
	virtual int getCost();
	virtual string getDescription();
};


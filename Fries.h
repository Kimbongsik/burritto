#pragma once
#include "Decorator.h"
class Fries :
	public Decorator
{
public:
	Fries();
	Fries(Burito* b);
	~Fries();

	int getCost();
	string getDescription();

private:
	Burito* burito;
};


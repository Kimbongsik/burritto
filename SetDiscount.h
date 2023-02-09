#pragma once
#include "Decorator.h"
class SetDiscount :
	public Decorator
{
public:
	SetDiscount();
	SetDiscount(Burito* b);
	~SetDiscount();

	int getCost();
	string getDescription();

private:
	Burito* burito;
};


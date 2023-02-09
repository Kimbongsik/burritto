#pragma once
#include "Decorator.h"
class ComboDiscount :
	public Decorator
{
public:
	ComboDiscount();
	ComboDiscount(Burito* b);
	~ComboDiscount();

	int getCost();
	string getDescription();

private:
	Burito* burito;
};


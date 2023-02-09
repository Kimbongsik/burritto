#pragma once
#include "Burito.h"
class BaseBurito :
	public Burito
{
public:
	BaseBurito();
	~BaseBurito();

	int getCost();
	string getDescription();
};


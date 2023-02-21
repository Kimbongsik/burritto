#include <iostream>
#include "Drink.h"

using namespace std;

Drink::Drink()
{
}

Drink::Drink(Burito* b)
{
	this->burito = b;
}

Drink::~Drink()
{
}

int Drink::getCost() {
	return burito->getCost() + 1000;
}

string Drink::getDescription() {
	string description = "+ À½·á¼ö\n";
	return burito->getDescription() + description;
}
#include <iostream>
#include "Fries.h"

using namespace std;

Fries::Fries() {
	//Burito* burito;
}

Fries::Fries(Burito* b) {
	this->burito = b;
}

Fries::~Fries() {
	//Burito* burito;
}

int Fries::getCost() {
	return burito->getCost() + 2000;
}

string Fries::getDescription() {
	string description = "°¨ÀÚÆ¢±è + ";
	return burito->getDescription() + description;
}
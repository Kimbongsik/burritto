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
	delete this->burito;
}

int Fries::getCost() {
	return burito->getCost() + 2000;
}

string Fries::getDescription() {
	string description = "+ °¨ÀÚÆ¢±è\n";
	return burito->getDescription() + description;
}
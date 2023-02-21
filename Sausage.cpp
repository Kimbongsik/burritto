#include <iostream>
#include "Sausage.h"

using namespace std;


Sausage::Sausage() {

};

Sausage::~Sausage() {
	delete this->burito;
};

Sausage::Sausage(Burito* b) {
	this->burito = b;
};

int Sausage::getCost() {
	return burito->getCost() + 1000;
}

string Sausage::getDescription() {
	string description = "+ ¼Ò½ÃÁö\n";
	return burito->getDescription() + description;
}
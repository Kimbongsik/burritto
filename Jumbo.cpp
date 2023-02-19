#include <iostream>
#include "Jumbo.h"

using namespace std;

Jumbo::Jumbo() {

};

Jumbo::Jumbo(Burito* b) {
	this->burito = b;
};

Jumbo::~Jumbo() {

};

int Jumbo::getCost() {
	return burito->getCost() + 1000;
}

string Jumbo::getDescription() {
	string description = "Á¡º¸ +";
	return burito->getDescription() + description;
}
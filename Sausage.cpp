#include <iostream>
#include "Sausage.h"

using namespace std;


Sausage::Sausage() {

};

Sausage::Sausage(Burito* b) {
	this->burito = b;
};

Sausage::~Sausage() {

};

int Sausage::getCost() {
	return burito->getCost() + 1000;
}

string Sausage::getDescription() {
	string description = "�ҽ��� +";
	return burito->getDescription() + description;
}
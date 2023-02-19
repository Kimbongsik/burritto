#include <iostream>
#include "SetDiscount.h"

using namespace std;

SetDiscount::SetDiscount() {

};

SetDiscount::SetDiscount(Burito* b) {
	this->burito = b;
};


SetDiscount::~SetDiscount() {

};

int SetDiscount::getCost() {
	return burito->getCost() + 500;
}

string SetDiscount::getDescription() {
	string description = "¼¼Æ® +";
	return burito->getDescription() + description;
}
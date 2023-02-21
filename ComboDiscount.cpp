#include <iostream>
#include "ComboDiscount.h"
#include "ComboDiscount.h"
#include "ComboDiscount.h"
#include "ComboDiscount.h"

using namespace std;

ComboDiscount::ComboDiscount(){
}

ComboDiscount::ComboDiscount(Burito* b){
	this->burito = b;
}

ComboDiscount::~ComboDiscount()
{
}

int ComboDiscount::getCost() {
	return burito->getCost() - 300;
}

string ComboDiscount::getDescription() {
	string description = "- ÄÞº¸\n";
	return burito->getDescription() + description;
}
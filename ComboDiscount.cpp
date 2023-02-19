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
	return 300; //ÄÞº¸ ÇÒÀÎ°¡
}

string ComboDiscount::getDescription() {
	string description = "ÄÞº¸ +";
	return description;
}
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
	return 300; //�޺� ���ΰ�
}

string ComboDiscount::getDescription() {
	string description = "�޺� +";
	return description;
}
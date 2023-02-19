#include <iostream>
#include "BuritoFactory.h"
#include "BaseBurito.h"

BuritoFactory::BuritoFactory()
{
}

BuritoFactory::~BuritoFactory()
{
}

//base Burito 제작
Burito* BuritoFactory::makeOrderedMenu(int type) {
	Burito* ordered = new BaseBurito();

	switch (type) {
	case 1: //단품
		return ordered;
		break;

	case 2: //콤보(부리또 + 음료수)
		ordered = new Drink(ordered);
		ordered = new ComboDiscount(ordered);
		return ordered;
		break;

	case 3: //세트(부리또 + 음료수 + 감자튀김)
		ordered = new Drink(ordered);
		ordered = new Fries(ordered);
		ordered = new ComboDiscount(ordered);
		return ordered;
		break;
	}
}
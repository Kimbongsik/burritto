#include <iostream>
#include "BuritoFactory.h"
#include "BaseBurito.h"

BuritoFactory::BuritoFactory()
{
}

BuritoFactory::~BuritoFactory()
{
}

//base Burito ����
Burito* BuritoFactory::makeOrderedMenu(int type) {
	Burito* ordered = new BaseBurito();

	switch (type) {
	case 1: //��ǰ
		return ordered;
		break;

	case 2: //�޺�(�θ��� + �����)
		ordered = new Drink(ordered);
		ordered = new ComboDiscount(ordered);
		return ordered;
		break;

	case 3: //��Ʈ(�θ��� + ����� + ����Ƣ��)
		ordered = new Drink(ordered);
		ordered = new Fries(ordered);
		ordered = new ComboDiscount(ordered);
		return ordered;
		break;
	}
}
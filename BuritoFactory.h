#pragma once
#include "BaseBurito.h"
#include "Drink.h"
#include "Fries.h"
#include "Sausage.h"
#include "Jumbo.h"
#include "ComboDiscount.h"
#include "SetDiscount.h"

class BuritoFactory
{
public:
	BuritoFactory();
	~BuritoFactory();

	Burito* makeOrderedMenu(int type);
};


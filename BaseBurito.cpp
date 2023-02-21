#include <iostream>
#include "BaseBurito.h"

using namespace std;

BaseBurito::BaseBurito()
{
}


BaseBurito::~BaseBurito()
{
}

int BaseBurito::getCost() {
	return 3000;
}

string BaseBurito::getDescription() {
	string description = "ºÎ¸®¶Ç\n";
	return description;
}
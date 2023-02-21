#include <iostream>
#include "Transaction.h"

Transaction::Transaction()
{
}

Transaction::~Transaction()
{
}

void Transaction::setorderID(int _orderID) {
	orderID = _orderID;
}

int Transaction::getorderID()
{
	return orderID;
}

void Transaction::setingredientsInfo(vector<int> newIngredientsInfo)
{
	ingredientsInfo = newIngredientsInfo;
}

vector<int> Transaction::getingredientsInfo()
{
	return ingredientsInfo;
}

void Transaction::setorderedMenu(Burito* b)
{
	orderedMenu = b;
}

Burito* Transaction::getorderedMenu()
{
	return orderedMenu;
}



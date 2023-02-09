#pragma once
#include <vector>
#include "Burito.h"
using namespace std;

class Transaction
{
public:
	Transaction();
	~Transaction();

private:
	int orderID;
	vector<int> ingredientsInfo;
	Burito* orderedMenu;
};


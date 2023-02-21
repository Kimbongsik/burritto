#pragma once
#include <vector>
#include "Burito.h"
using namespace std;

class Transaction
{
public:
	Transaction();
	~Transaction();

	void setorderID(int);
	int getorderID();
	
	void setingredientsInfo(vector<int>);
	vector<int> getingredientsInfo();

	void setorderedMenu(Burito*);
	Burito* getorderedMenu();
	
private:
	int orderID;
	vector<int> ingredientsInfo;
	Burito* orderedMenu;
};
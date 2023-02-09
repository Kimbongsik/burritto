#pragma once
#include "BuritoFactory.h"
#include "TransactionManger.h"
class App
{
public:
	App();
	~App();

	void run();

private:
	void readTransaction();
	void writeTransaction();

private:
	BuritoFactory* bf;
	TransactionManger* tm;
};


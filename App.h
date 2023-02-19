#pragma once
#include "BuritoFactory.h"
#include "TransactionManager.h"
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
	TransactionManager* tm;
};


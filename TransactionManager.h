#pragma once
#include "Transaction.h"

class TransactionManager
{
public:
	TransactionManager();
	~TransactionManager();

	void addTransaction(Transaction* newTransaction);
	void processFrontTransaction();
	void printTransaction();
	void deleteTransaction(int index);
	vector<Transaction> getorderTransactions();

private:
	vector<Transaction> orderTransactions;
};

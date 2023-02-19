#pragma once
#include "Transaction.h"
class TransactionManager
{
public:
	TransactionManager();
	~TransactionManager();

	int addTransaction(Transaction* newTransaction);
	void processFrontTransaction(Transaction* newTransaction);
	void printTransaction();
	void deleteTransaction(int index);

private:
	vector<Transaction> orderTransactions;
};


#pragma once
#include "Transaction.h"
class TransactionManger
{
public:
	TransactionManger();
	~TransactionManger();

	void addTransaction(Transaction* newTransaction);
	void processFrontTransaction();
	void printTransaction();
	void deleteTransaction(int index);

private:
	vector<Transaction> orderTransactions;
};


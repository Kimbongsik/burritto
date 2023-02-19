#include <iostream>
#include <vector>
#include <algorithm>
#include "TransactionManager.h"
using namespace std;

TransactionManager::TransactionManager()
{
}

TransactionManager::~TransactionManager()
{
}

int TransactionManager::addTransaction(Transaction* newTransaction)
{
	orderTransactions.push_back(*newTransaction);
	return 0;
}

void TransactionManager::processFrontTransaction(Transaction* newTransaction)
{
	cout << newTransaction->getorderID();
}

void TransactionManager::printTransaction()
{
	int i, j;
	
	for (i = 0; i < orderTransactions.size(); i++) {
		cout << i+1 << ". ";

		int typeID = orderTransactions[i].getingredientsInfo()[0];

		if (typeID == 1) cout << "단품 +";
		else if (typeID == 2) cout << "콤보 +";
		else if (typeID == 3) cout << "세트 +";
		
		for (j = 1; j < orderTransactions[i].getingredientsInfo().size(); j++) {
			int ingredients = orderTransactions[i].getingredientsInfo()[j];

			if (ingredients == 1) cout << "점보";
			else if (ingredients == 2) cout << "소시지";
			else if (ingredients == 3) cout << "감자튀김";
			else if (ingredients == 4) cout << "음료수";
			else
				cout << "추가될 수 없는 주문입니다. 프로그램을 재시작해주세요." << '\n';

			if(j!= orderTransactions[i].getingredientsInfo().size()-1)
				cout << " + ";
		}
	}
	
	cout << '\n';
}

void TransactionManager::deleteTransaction(int index)
{
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "TransactionManager.h"
using namespace std;

TransactionManager::TransactionManager()
{
}

TransactionManager::~TransactionManager()
{
}


void TransactionManager::addTransaction(Transaction* newTransaction)
{
	orderTransactions.push_back(*newTransaction);
}


void TransactionManager::processFrontTransaction()
{

	cout << "-----------주문 내용-------------" << '\n';
	cout << orderTransactions[0].getorderID() << "번 주문" << '\n';
	cout << "-----------상세 내용-------------" << '\n';
	//기본 메뉴
	int typeID = orderTransactions[0].getingredientsInfo()[0];

	cout << orderTransactions[0].getorderedMenu()->getDescription() << '\n';
	cout << "가격: " << orderTransactions[0].getorderedMenu()->getCost() << '\n';

	orderTransactions.erase(orderTransactions.begin());
}

void TransactionManager::printTransaction()
{
	int i, j;

	cout << "-----------주문 목록-------------" << '\n';
	
	for (i = 0; i < orderTransactions.size(); i++) {
		cout << orderTransactions[i].getorderID() << ". ";

		int typeID = orderTransactions[i].getingredientsInfo()[0];

		if (typeID == 1) cout << "단품";
		else if (typeID == 2) cout << "콤보";
		else if (typeID == 3) cout << "세트";
		
		cout << " + ";
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
		cout << "\n";
	}
	cout << "\n";
	cout << "-----------------------------" << '\n';
}

void TransactionManager::deleteTransaction(int index)
{
	for (int i = 0; i < orderTransactions.size(); i++) {
		if(index == orderTransactions[i].getorderID())
			orderTransactions.erase(orderTransactions.begin() + i);
	}
}

vector<Transaction> TransactionManager::getorderTransactions()
{
	return orderTransactions;
}


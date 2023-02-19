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

		if (typeID == 1) cout << "��ǰ +";
		else if (typeID == 2) cout << "�޺� +";
		else if (typeID == 3) cout << "��Ʈ +";
		
		for (j = 1; j < orderTransactions[i].getingredientsInfo().size(); j++) {
			int ingredients = orderTransactions[i].getingredientsInfo()[j];

			if (ingredients == 1) cout << "����";
			else if (ingredients == 2) cout << "�ҽ���";
			else if (ingredients == 3) cout << "����Ƣ��";
			else if (ingredients == 4) cout << "�����";
			else
				cout << "�߰��� �� ���� �ֹ��Դϴ�. ���α׷��� ��������ּ���." << '\n';

			if(j!= orderTransactions[i].getingredientsInfo().size()-1)
				cout << " + ";
		}
	}
	
	cout << '\n';
}

void TransactionManager::deleteTransaction(int index)
{
}

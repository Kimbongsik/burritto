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

	cout << "-----------�ֹ� ����-------------" << '\n';
	cout << orderTransactions[0].getorderID() << "�� �ֹ�" << '\n';
	cout << "-----------�� ����-------------" << '\n';
	//�⺻ �޴�
	int typeID = orderTransactions[0].getingredientsInfo()[0];

	cout << orderTransactions[0].getorderedMenu()->getDescription() << '\n';
	cout << "����: " << orderTransactions[0].getorderedMenu()->getCost() << '\n';

	orderTransactions.erase(orderTransactions.begin());
}

void TransactionManager::printTransaction()
{
	int i, j;

	cout << "-----------�ֹ� ���-------------" << '\n';
	
	for (i = 0; i < orderTransactions.size(); i++) {
		cout << orderTransactions[i].getorderID() << ". ";

		int typeID = orderTransactions[i].getingredientsInfo()[0];

		if (typeID == 1) cout << "��ǰ";
		else if (typeID == 2) cout << "�޺�";
		else if (typeID == 3) cout << "��Ʈ";
		
		cout << " + ";
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


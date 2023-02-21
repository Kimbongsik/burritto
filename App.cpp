#include <fstream>
#include <iostream>
#include <string>
#include "App.h"

using namespace std;

static int orderID = 0;
ofstream ofs;

//App Ŭ���� ������
App::App() {
	tm = new TransactionManager();
}

App::~App()
{
	delete tm;
}

//App Ŭ���� ��� �Լ� run()
void App::run() {

	int orderNumber = 0;
	int menuNumber = 0;
	int addIngredient = 0;
	
	
	//���Ͽ� �ִ� �θ��� �а� ����
	readTransaction();

	while (1) {

		cout << "�θ��� �ֹ� ���� ���α׷�" << '\n';
		cout << "-----------�ֹ� ���-------------" << '\n';
		cout << "1. �ֹ� �߰�" << '\n';
		cout << "2. �ֹ� ���" << '\n';
		cout << "3. �ֹ� ó��" << '\n';

		cin >> orderNumber;

		if (!cin) {
			cout << "���ڸ� �ٽ� �Է����ּ���" << '\n';
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if (orderNumber == 1) {

			Transaction* add = new Transaction();
			vector<int> newIngredientsInfo = {};
			bf = new BuritoFactory();

			orderID++;
			add->setorderID(orderID);
			
			cout << "�ֹ� �޴�" << '\n';
			cout << "---------------------" << '\n';
			cout << "1. ��ǰ (�θ���, 3000��)" << '\n';
			cout << "2. �޺� (�θ��� + ����, 3700��)" << '\n';
			cout << "3. ��Ʈ (�θ��� + ���� + ����Ƣ��, 4500��)" << '\n';
			cout << "---------------------" << '\n';

			//orderNumber ����
			cout << ": ";
			cin >> menuNumber;

			if (!cin) {
				cout << "���ڸ� �ٽ� �Է����ּ���" << '\n';
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}

			Burito* burito = bf->makeOrderedMenu(menuNumber);
			newIngredientsInfo.push_back(menuNumber);
			
			while (addIngredient != 5) {
				
				//�߰� �޴� ����
				cout << "�߰� �޴� ����" << '\n';
				cout << "---------------------" << '\n';
				cout << "1. ���� (1000��)" << '\n';
				cout << "2. �ҽ��� (1000��)" << '\n';
				cout << "3. ����Ƣ�� (2000��)" << '\n';
				cout << "4. ����� (1000��)" << '\n';
				cout << "5. �׸� �߰�" << '\n';
				cout << "---------------------" << '\n';

				cout << ": ";
				cin >> addIngredient;

				if (!cin) {
					cout << "���ڸ� �ٽ� �Է����ּ���" << '\n';
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}

				switch (addIngredient) {
				case 1:
					burito = new Jumbo(burito);
					newIngredientsInfo.push_back(1);
					break;
				case 2:
					burito = new Sausage(burito);
					newIngredientsInfo.push_back(2);
					break;
				case 3:
					burito = new Fries(burito);
					newIngredientsInfo.push_back(3);
					break;
				case 4:
					burito = new Drink(burito);
					newIngredientsInfo.push_back(4);
					break;
				case 5:
					break;
				}
			}

			menuNumber = 0;
			addIngredient = 0;

			add->setorderedMenu(burito);
			writeTransaction(newIngredientsInfo);

			add->setingredientsInfo(newIngredientsInfo);

			tm->addTransaction(add);
			
			tm->printTransaction();
		}
		
		else if (orderNumber == 2) {
			int index;

			if (tm->getorderTransactions().empty() == false) {
				cout << "�ֹ� ���: " << '\n';
				tm->printTransaction();
				cout << "-----------�� ����-------------" << '\n';
				cout << ": ";
				cin >> index;
				if (!cin) {
					cout << "���ڸ� �ٽ� �Է����ּ���" << '\n';
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}

				tm->deleteTransaction(index);

				tm->printTransaction();
			}

			else cout << "�Էµ� �ֹ��� �������� �ʽ��ϴ�. �ֹ� �� �õ����ּ���. \n" << '\n';
		}

		else if (orderNumber == 3) {

			if (tm->getorderTransactions().empty() == false) {
					cout << "�ֹ� ó��!: " << '\n';

					tm->processFrontTransaction();
			}

			else cout << "�Էµ� �ֹ��� �������� �ʽ��ϴ�. �ֹ� �� �õ����ּ���. \n" << '\n';

		}

		else
			cout << "�߸��� ��û�Դϴ�. �ٽ� �������ּ���." << '\n';

		writeNewTransaction();
	}
}

//���Ͽ� �ִ� �θ��� �ε�
void App::readTransaction()
{
	ifstream ifs("order.txt");
	if (ifs.fail()) cerr << "file not found\n";
	string list_size, menuNumber, ingredient;

	while (!ifs.eof()) {

		list_size = ifs.get();

		if (list_size == "\n" || list_size == "\t") {
			continue;
		}

		if (ifs.eof())
			break;

		Transaction* add = new Transaction();
		vector<int> newIngredientsInfo = {};
		bf = new BuritoFactory();

		orderID++;
		add->setorderID(orderID);
		
		menuNumber = ifs.get();
		menuNumber = ifs.get();

		Burito* burito = bf->makeOrderedMenu(stoi(menuNumber));

		for (int i = 0; i < stoi(list_size) * 2; i++) {
			ingredient = ifs.get();

			if (ingredient == "\t" || ingredient == "\n")
				continue;

			switch (stoi(ingredient)) {
			case 1:
				burito = new Jumbo(burito);
				newIngredientsInfo.push_back(1);
				break;
			case 2:
				burito = new Sausage(burito);
				newIngredientsInfo.push_back(2);
				break;
			case 3:
				burito = new Fries(burito);
				newIngredientsInfo.push_back(3);
				break;
			case 4:
				burito = new Drink(burito);
				newIngredientsInfo.push_back(4);
				break;
			case 5:
				break;
			}
		}

		add->setorderedMenu(burito);
		add->setingredientsInfo(newIngredientsInfo);
		tm->addTransaction(add);
	}

	ifs.close();
}

void App::writeTransaction(vector<int> newIngredientsInfo)
{
	ofs.open("order.txt", ios::app);
	
	if (ofs.fail())
		cerr << "file open error\n";

	ofs << int(newIngredientsInfo.size());
	ofs << "\t";

	for (int i = 0; i < newIngredientsInfo.size(); i++) {
		ofs << newIngredientsInfo[i];
		ofs << "\t";
	}

	ofs << "\n";

	ofs.close();
}

void App::writeNewTransaction() {
	ofs.open("order.txt");

	if (ofs.fail())
		cerr << "file open error\n";

	for (int i = 0; i < tm->getorderTransactions().size(); i++) {
		ofs << int(tm->getorderTransactions()[i].getingredientsInfo().size()); //list_size
		ofs << "\t";

		for (int j = 0; j < tm->getorderTransactions()[i].getingredientsInfo().size(); j++) {
			ofs << tm->getorderTransactions()[i].getingredientsInfo()[j];
			ofs << "\t";
		}
		ofs << "\n";
	}

	ofs.close();
}

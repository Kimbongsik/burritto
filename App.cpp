#include <iostream>
#include "App.h"

using namespace std;

static int orderID = 0;

//App Ŭ���� ������
App::App() {
	run();
}

App::~App()
{
}

//App Ŭ���� ��� �Լ� run()
void App::run() {

	int orderNumber = 0;
	int menuNumber = 0;
	int addIngredient = 0;
		
	while (1) {

		cout << "�θ��� �ֹ� ���� ���α׷�" << '\n';
		cout << "-----------�ֹ� ���-------------" << '\n';
		cout << "1. �ֹ� �߰�" << '\n';
		cout << "2. �ֹ� ���" << '\n';
		cout << "3. �ֹ� ó��" << '\n';

		cin >> orderNumber;

		if (orderNumber == 1) {

			Transaction* add = new Transaction();
			vector<int> newIngredientsInfo = {};
			tm = new TransactionManager();
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

			add->setingredientsInfo(newIngredientsInfo);
			tm->addTransaction(add);
		}
		
		else if (orderNumber == 2) {
			
		}

		else if (orderNumber == 3) {
			
			cout << "-----------�ֹ� ���-------------" << '\n';

			
			//�ֹ� ��� readTransaction()

		}

		else
			cout << "�߸��� ��û�Դϴ�. �ٽ� �������ּ���." << '\n';


		tm->printTransaction();
	}
}


void App::readTransaction()
{

}

void App::writeTransaction()
{

}

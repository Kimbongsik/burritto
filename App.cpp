#include <iostream>
#include "App.h"

using namespace std;

static int orderID = 0;

//App 클래스 생성자
App::App() {
	run();
}

App::~App()
{
}

//App 클래스 멤버 함수 run()
void App::run() {

	int orderNumber = 0;
	int menuNumber = 0;
	int addIngredient = 0;
		
	while (1) {

		cout << "부리또 주문 관리 프로그램" << '\n';
		cout << "-----------주문 목록-------------" << '\n';
		cout << "1. 주문 추가" << '\n';
		cout << "2. 주문 취소" << '\n';
		cout << "3. 주문 처리" << '\n';

		cin >> orderNumber;

		if (orderNumber == 1) {

			Transaction* add = new Transaction();
			vector<int> newIngredientsInfo = {};
			tm = new TransactionManager();
			bf = new BuritoFactory();

			orderID++;
			add->setorderID(orderID);
			
			cout << "주문 메뉴" << '\n';
			cout << "---------------------" << '\n';
			cout << "1. 단품 (부리또, 3000원)" << '\n';
			cout << "2. 콤보 (부리또 + 음료, 3700원)" << '\n';
			cout << "3. 세트 (부리또 + 음료 + 감자튀김, 4500원)" << '\n';
			cout << "---------------------" << '\n';

			//orderNumber 저장
			cout << ": ";
			cin >> menuNumber;

			Burito* burito = bf->makeOrderedMenu(menuNumber);
			newIngredientsInfo.push_back(menuNumber);
			
			while (addIngredient != 5) {
				
				//추가 메뉴 선택
				cout << "추가 메뉴 선택" << '\n';
				cout << "---------------------" << '\n';
				cout << "1. 점보 (1000원)" << '\n';
				cout << "2. 소시지 (1000원)" << '\n';
				cout << "3. 감자튀김 (2000원)" << '\n';
				cout << "4. 음료수 (1000원)" << '\n';
				cout << "5. 그만 추가" << '\n';
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
			
			cout << "-----------주문 목록-------------" << '\n';

			
			//주문 목록 readTransaction()

		}

		else
			cout << "잘못된 요청입니다. 다시 선택해주세요." << '\n';


		tm->printTransaction();
	}
}


void App::readTransaction()
{

}

void App::writeTransaction()
{

}

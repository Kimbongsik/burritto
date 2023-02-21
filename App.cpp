#include <fstream>
#include <iostream>
#include <string>
#include "App.h"

using namespace std;

static int orderID = 0;
ofstream ofs;

//App 클래스 생성자
App::App() {
	tm = new TransactionManager();
}

App::~App()
{
	delete tm;
}

//App 클래스 멤버 함수 run()
void App::run() {

	int orderNumber = 0;
	int menuNumber = 0;
	int addIngredient = 0;
	
	
	//파일에 있는 부리또 읽고 생성
	readTransaction();

	while (1) {

		cout << "부리또 주문 관리 프로그램" << '\n';
		cout << "-----------주문 목록-------------" << '\n';
		cout << "1. 주문 추가" << '\n';
		cout << "2. 주문 취소" << '\n';
		cout << "3. 주문 처리" << '\n';

		cin >> orderNumber;

		if (!cin) {
			cout << "숫자를 다시 입력해주세요" << '\n';
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		if (orderNumber == 1) {

			Transaction* add = new Transaction();
			vector<int> newIngredientsInfo = {};
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

			if (!cin) {
				cout << "숫자를 다시 입력해주세요" << '\n';
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}

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

				if (!cin) {
					cout << "숫자를 다시 입력해주세요" << '\n';
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
				cout << "주문 취소: " << '\n';
				tm->printTransaction();
				cout << "-----------상세 내용-------------" << '\n';
				cout << ": ";
				cin >> index;
				if (!cin) {
					cout << "숫자를 다시 입력해주세요" << '\n';
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}

				tm->deleteTransaction(index);

				tm->printTransaction();
			}

			else cout << "입력된 주문이 존재하지 않습니다. 주문 후 시도해주세요. \n" << '\n';
		}

		else if (orderNumber == 3) {

			if (tm->getorderTransactions().empty() == false) {
					cout << "주문 처리!: " << '\n';

					tm->processFrontTransaction();
			}

			else cout << "입력된 주문이 존재하지 않습니다. 주문 후 시도해주세요. \n" << '\n';

		}

		else
			cout << "잘못된 요청입니다. 다시 선택해주세요." << '\n';

		writeNewTransaction();
	}
}

//파일에 있는 부리또 로드
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

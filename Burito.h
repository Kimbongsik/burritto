#pragma once
#include <string>
using namespace std;
class Burito
{
public:
	~Burito(); //자식클래스 소멸자 정상 호출

public:
	virtual int getCost() = 0;
	virtual string getDescription() = 0;
};


#pragma once
#include <string>
using namespace std;
class Burito
{
public:
	~Burito(); //�ڽ�Ŭ���� �Ҹ��� ���� ȣ��

public:
	virtual int getCost() = 0;
	virtual string getDescription() = 0;
};


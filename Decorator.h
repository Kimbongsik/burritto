#pragma once
#include "Burito.h"
class Decorator :
	public Burito
{
public:
	//생성자 안 쓰면 필요 없음
	virtual ~Decorator(); //자식 클래스의 소멸자 정상 호출
};
#pragma once
#include <iostream>
// 간단한 테스트를 위한 클래스

using namespace std;

class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B" << endl;
	}
};
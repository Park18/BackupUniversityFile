#pragma once
#include <iostream>
// ������ �׽�Ʈ�� ���� Ŭ����

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
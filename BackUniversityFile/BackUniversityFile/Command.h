#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "Route.h"

using namespace std;

class Command
{
private:
	route::Subject* ptrSubject;

public:
	Command() { setPtrSubject(); }
	~Command() { delete getPtrSubject(); }

	void setPtrSubject() { this->ptrSubject = new route::Subject(); }
	route::Subject* getPtrSubject() { return this->ptrSubject; }

	// ��ɾ�� �� ��Ҹ� ã�Ƽ� ��ȯ�ϴ� �޼���
	std::string findAction(std::string command);
	std::string findSubject(std::string command);
	std::string findElement(std::string command);
	bool findOption(std::string command);

	// �ܼ� ȭ���� �����ϴ� �޼���
	void clear();

	// ���α׷��� �����ϴ� �޼���
	void _exit();

	// subject/�����.txt�� ������ �߰��ϴ� �޼���
	void add(std::string command);

	// subject/�����.txt���� ������ �����ϴ� �޼���
	void _delete(std::string command);

	// subject/�����.txt���� ������ ����ϴ� �޼���
	void print(std::string command);

	// ����ڿ��� index�� �Է¹޴� �޼���
	int getUserIndex();

	// ��ɾ� �ý��� �޼���
	void commandSystem();
};


#endif // !COMMAND


#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "Route.h"

const std::string OPTION_F = "-f";

// root�� ��ɾ�� �����ϴ� Ŭ����
// ��� ��ɾ �����ϴ� Ŭ����
class Command
{
private:
	route::Subject* ptrSubject;	// ������� �����ϴ� ��ü

	// ��ɾ�� �� ��Ҹ� ã�Ƽ� ��ȯ�ϴ� �޼���
	std::string findAction(std::string command);
	std::string findSubject(std::string command);
	std::string findElement(std::string command);
	bool findOption(std::string command);

public:
	Command() { setPtrSubject(); }
	~Command() { delete getPtrSubject(); }

	// set
	void setPtrSubject() { this->ptrSubject = new route::Subject(); }
	// get
	route::Subject* getPtrSubject() { return this->ptrSubject; }


	// �ܼ� ȭ���� �����ϴ� �޼���
	void clear();

	// ���α׷��� �����ϴ� �޼���
	void _exit();

	// root�� �߰��ϴ� �޼���
	void add(std::string command);

	// root�� �����ϴ� �޼���
	void _delete(std::string command);

	// root�� ����ϴ� �޼���
	void print(std::string command);

	// ����ڿ��� index�� �Է¹޴� �޼���
	int getUserIndex();

	// ��ɾ� �ý��� �޼���
	void commandSystem();
};


#endif // !COMMAND


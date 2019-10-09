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

	// 명령어에서 각 요소를 찾아서 반환하는 메서드
	std::string findAction(std::string command);
	std::string findSubject(std::string command);
	std::string findElement(std::string command);
	bool findOption(std::string command);

	// 콘솔 화면을 정리하는 메서드
	void clear();

	// 프로그램을 종료하는 메서드
	void _exit();

	// subject/과목명.txt에 정보를 추가하는 메서드
	void add(std::string command);

	// subject/과목명.txt에서 정보를 제거하는 메서드
	void _delete(std::string command);

	// subject/과목명.txt에서 정보를 출력하는 메서드
	void print(std::string command);

	// 사용자에게 index를 입력받는 메서드
	int getUserIndex();

	// 명령어 시스템 메서드
	void commandSystem();
};


#endif // !COMMAND


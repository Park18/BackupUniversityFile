#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "Route.h"

const std::string OPTION_F = "-f";

// root를 명령어로 관리하는 클래스
// 백업 명령어를 실행하는 클래스
class Command
{
private:
	route::Subject* ptrSubject;	// 과목명을 관리하는 객체

	// 명령어에서 각 요소를 찾아서 반환하는 메서드
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


	// 콘솔 화면을 정리하는 메서드
	void clear();

	// 프로그램을 종료하는 메서드
	void _exit();

	// root를 추가하는 메서드
	void add(std::string command);

	// root를 제거하는 메서드
	void _delete(std::string command);

	// root를 출력하는 메서드
	void print(std::string command);

	// 사용자에게 index를 입력받는 메서드
	int getUserIndex();

	// 명령어 시스템 메서드
	void commandSystem();
};


#endif // !COMMAND


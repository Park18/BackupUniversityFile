#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include "Subject.h"

namespace phw
{

/***
 * 사용자에게 명령어를 입력받아 과목/경로를 관리하는 클래스
 */
class Manager
{
private:
	phw::Subject* ptrSubject;

public:
	Manager() { setPtrSubject(); }
	~Manager() { delete getPtrSubject(); }

	void setPtrSubject() { this->ptrSubject = new phw::Subject(); }
	phw::Subject* getPtrSubject() { return ptrSubject; }

	/**
	 * 입력받은 명령어에서 action을 반환하는 메서드
	 */
	std::string findAction(std::string command);

	/**
	 * 입력받은 명령어에서 subject를 반환하는 메서드
	 */
	std::string findSubject(std::string command);

	/**
	 * 입력받은 명령어에서 element를 반환하는 메서드
	 */
	std::string findElement(std::string command);

	/**
	 * 옵션 확인 메서드
	 */
	bool isOption(std::string command);

	/**
	 * 추가 명령어 메서드
	 */
	void add(bool isOption, std::string subject, std::string element);

	/**
	 * 화면 청소 명령어 메서드
	 */
	void clear();
};

}// !namespace phw

#endif // !MANAGER_H
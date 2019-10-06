#pragma once
#ifndef BACKUPUNIVERSITYFILE_H
#define BACKUPUNIVERSITYFILE_H

#include "Subject.h"
namespace phw
{

class BackupUniversityFile
{
private:
	phw::Subject* ptrSubject;
	std::string action;
	//int option;
	std::string mainAgent;
	std::string element;

public:
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
	 * 명령어 분활 메서드
	 */
	void ramifyCommand(std::string command);

	/**
	 * 옵션 확인 메서드
	 */
	bool isOption(std::string command);

	/**
	 * 추가 명령어 메서드
	 */
	void add(bool option, std::string subject, std::string element);

	/**
	 * 삭제 명령어 메서드
	 */
	void _delete(bool option, std::string subject, int index);

	/**
	 * 출력 명령어 메서드
	 */
	void print(bool option, std::string subject);

	/**
	 * 화면 청소 명령어 메서드
	 */
	void clear();

	/**
	 * main 메서드
	 */
	void backupUniversityFile();

	// test
	void testFolderRoute();
	void testSubject();
};

} // !namespace pwh

#endif // !BACKUPUNIVERSITYFILE_H
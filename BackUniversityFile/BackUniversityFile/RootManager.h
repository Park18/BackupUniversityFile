#pragma once
#ifndef ROOTMANAGER_H
#define ROTTMANAGER_H	

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define BACKUPROOTFILE "Backup\\BackupRoot.txt"

// root로 지정된 폴더를 관리하는 클래스
// 해당 폴더만 백업을 실행한다.
// 만약 폴더가 없다면 - 에러 발생, 메시지 출력, 프로그램 종료
class RootManager
{
private:
	std::vector<std::string>* ptrRootManager;

	// 백업을 하는 메서드
	void setBackup();

	// 백업된 정보를 가져오는 메서드
	void getBackup();

public:
	RootManager() { setPtrRootManager(); getBackup(); }
	~RootManager() { setBackup(); delete getPtrRootManager(); }

	// set/get
	void setPtrRootManager() { this->ptrRootManager = new std::vector<std::string>; }
	std::vector<std::string>* getPtrRootManager() { return this->ptrRootManager; }

	// root 폴더를 추가하는 메서드
	void add(std::string);

	// root 폴더를 삭제하는 메서드
	void _delete();

	// root 폴더를 출력하는 메서드
	void print();
};

#endif // !ROOTMANAGER_H


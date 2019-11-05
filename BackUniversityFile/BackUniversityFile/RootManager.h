#pragma once
#ifndef ROOTMANAGER_H
#define ROTTMANAGER_H	

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost\filesystem.hpp>
#include <boost\filesystem\fstream.hpp>
#include <boost\foreach.hpp>

#define BACKUPROOTFILE "Backup\\BackupRoot.txt"

/**
 * @class RootManager
 * @date 2019/11/05
 * @author 박현우
 * @brief root 폴더를 관리하기 위한 클래스
 * @details txt 파일에 저장된 root 폴더를 시작할 때 가져와서 vector에 저장하고
			 종료될 때 vector에서 txt 파일에 백업한다.
 */
class RootManager
{
private:
	//*********************************************************************************
	//									변수 필드
	//*********************************************************************************

	/* root 폴더를 저장하는 vector */
	std::vector<std::string>* ptrRootManager;


	//*********************************************************************************
	//									메소드 필드
	//*********************************************************************************

	/**
	 * @brief vector에 저장된 root 폴더를 txt 파일에 백업하는 메소드
	 * @return void
	 */
	void setBackup();

	/**
	 * @brief txt 파일에 백업된 root 폴더를 vector에 저장하는 메소드
	 * @return void
	 */
	void getBackup();

public:
	//*********************************************************************************
	//									메소드 필드
	//*********************************************************************************
	RootManager() { setPtrRootManager(); getBackup(); }
	~RootManager() { setBackup(); delete getPtrRootManager(); }

	/* set|get */
	void setPtrRootManager() { this->ptrRootManager = new std::vector<std::string>; }
	std::vector<std::string>* getPtrRootManager() { return this->ptrRootManager; }

	/**
	 * @brief vector에 저장된 root 폴더가 실제 존재하는 폴더인지 확인하는 메소드
	 * @return void
	 */
	void checkRoot();

	/**
	 * @brief root 폴더의 상위 경로를 반환하는 메소드
	 * @param string root : root 폴더 경로
	 * @return string : root 폴더의 상위 경로
	 */
	std::string upperRoot(std::string root);

	/**
	 * @brief root 폴더를 vector에 저장하는 메소드
	 * @param string root : root 폴더 경로
	 * @return void
	 */
	void add(std::string);

	/**
	 * @brief vector에 저장된 root 폴더를 삭제하는 메소드
	 * @return void
	 */
	void _delete();

	/**
	 * @brief root 폴더를 출력하는 메소드
	 * @return void
	 */
	void print();
};

#endif // !ROOTMANAGER_H


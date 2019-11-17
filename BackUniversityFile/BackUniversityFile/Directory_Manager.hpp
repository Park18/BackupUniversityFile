#pragma once
#ifndef DIRECTORY_MANAGER_HPP
#define DIRECTORY_MANAGER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <boost\filesystem.hpp>
#include <boost\foreach.hpp>


#define IS_HAVE_DIRETORY(x) boost::filesystem::is_directory(x)

/**
 @class		Base_Directory_Manager
 @date		2019/11/15
 @author	박현우
 @brief		directory를 관리하기 위한 클래스
 @details	txt 파일로 root_directory를 저장하고
			프로그램 실행시 vector에 저장해여 관리한다.
 */
class Base_Directory_Manager
{
protected:
	std::vector<std::string>* ptr_directory;

protected:
	void set_ptr_directory(std::vector<std::string>* ptr_root_directory) { this->ptr_directory = ptr_root_directory; }
	std::vector<std::string>* get_ptr_directory() { return ptr_directory; }

	int get_directory_size() { return get_ptr_directory()->size(); }


	/**
	 @brief	프로그램 종료시 root_directory를 백업하는 메소드
	 */
	void set_backup();

	/**
	 @brief	프로그램 초기화시 백업된 root_directory를 vector변수에 대입하는 메소드
	 */
	void get_backup();

public:

	/**
	 @brief		생성자
	 @details	프로그램이 시작할 때 directory 백업본을 가져온다.
	 */
	Base_Directory_Manager() { set_ptr_directory(new std::vector<std::string>); get_backup(); }

	/**
	 @brief		소멸자
	 @details	프로그램이 종료될 때 directory를 백업하고
				동적 할당된 vector를 해제한다.
	 */
	~Base_Directory_Manager() { set_backup(); delete get_ptr_directory(); }

	/**
	 @brief	vector에 root_directory를 저장하는 메소드
	 @param	root_directory: 추가할 root_directory
	 */
	void add(std::string root_directory);

	/**
	 @brief	vector에 저장된 root_directory를 삭제하는 메소드
	 */
	void _delete();

	/**
	 @brief	vector에 저장된 root_directory를 출력하는 메소드
	 */
	void print();
};

#define ROOT_DIRECTORY_FILE	"Backup\\root_directory.txt"
/**
 @class		root_directory를 관리하는 클래스
 @date		2019/11/15
 @author	박현우
 @detials	Base_Directory_Manager를 상속받는다.
 */
class Root_Directory_Manager : public Base_Directory_Manager
{

};

#define COPY_DIRECTORY_FILE	"Backup\\copy_directory.txt"
/**
 @class		copy_directory를 관리하는 클래스
 @date		2019/11/15
 @author	박현우
 @detials	Base_Directory_Manager를 상속받는다.
 */
class Copy_Directory_Manager : public Base_Directory_Manager
{

};

#endif // !DIRECTORY_MANAGER_HPP
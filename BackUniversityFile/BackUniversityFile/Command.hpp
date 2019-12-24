#pragma once
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "Directory_Manager.hpp"

#define ACTION_ADD "add"
#define ACTION_DELETE "delete"
#define ACTION_PRINT "print"
#define ACTION_BACKUP "backup"
#define ACTION_EXIT "exit"

#define OPTION_ROOT "-root" // 옵션 root
#define OPTION_COPY "-copy"	// 옵션 copy

#define EXIT(code) exit(code)	// 종료 매크로
#define CLEAR() system("cls")	// 화면 청소 매크로

//------------명령어-------------//
// 추가: action, option, directory
// 삭제: action, option
// 출력: action, option
// 백업: action
//----------명령어 형식----------//
// action -option directory
// 
// action:		수행할 메서드
// option:		root/copy
// directory:	폴더 경로
//----------명령어 예------------//
// add -root d:/gitbub
// add -copy c/users/hyunwoo/download
// backup
//----------명령어 명세----------//
// 명령어가 입력
// 명령어 분활, 정상 명령어인지 확인

/**
 @brief
 */

/**
 @class		Command
 @date		2019/11/18
 @author	박현우
 @brief		프로그램의 명령어 실행에 관여하는 클래스
 */
class Command
{
private:
	Root_Directory_Manager* ptr_root_manager; // root_directory를 관여하는 객체
	Copy_Directory_Manager* ptr_copy_manager; // copy_directory를 관여하는 객체
	
protected:
	void set_ptr_root_manager(Root_Directory_Manager* ptr_root_manager) { this->ptr_root_manager = ptr_root_manager; }
	void set_ptr_copy_manager(Copy_Directory_Manager* ptr_copy_manager) { this->ptr_copy_manager = ptr_copy_manager; }

	Root_Directory_Manager* get_ptr_root_manager() { return ptr_root_manager; }
	Copy_Directory_Manager* get_ptr_copy_manager() { return ptr_copy_manager; }

public:	// 임시 public, 원래 protected
	/**
	 @brief		명령어의 행동을 찾는 메서드
	 @param		command: 사용자가 입력한 명령어(정상적인 입력이라고 가정)
	 @return	수행해야할 행동 반환
	 */
	std::string command_action(const std::string command);

	/**
	 @brief		명령어의 옵션을 찾는 메서드
	 @param		command: 사용자가 입력한 명령어(정상적인 입력이라고 가정)
	 @return	옵션 반환
	 */
	std::string command_option(const std::string command);

	/**
	 @brief		명령어의 폴더경로를 찾는 메서드
	 @param		command: 사용자가 입력한 명령어(정상적인 입력이라고 가정)
	 @return	directory_path 반환
	 */
	std::string command_deirectory(const std::string command);

	/**
	 @brief		옳바른 명령어가 입력되었는지 확인하는 메소드
	 @param		command: 사용자가 입력한 명령어
	 @return	true: 옳바른 명령어 / false: 잘못된 명령어
	 @details	1. action만 필요한 명령어
					- 명령어와 command_action이 같아야 한다.

				2. action option만 필요한 명령어(분기가 하나)
					- command_action과 command_option 확인

				3. action option directory가 필요한 명령어(분기가 2개)
					- 

				분기의 개수를 파악하고 그에 맞는 명령어인지를 확인,
				그 외에는 모두 틀린 명령어
	 */
	bool check_command(const std::string command);

public:

	/**
	 @brief		경로를 추가하는 메서드
	 @param		command: 사용자가 입력한 명령어
	 @details	add -option directory
	 */
	void add(std::string command);
	
	/**
	 @brief		경로를 제거하는 메서드
	 @param		command: 사용자가 입력한 명령어
	 @details	delete -option
				root/copy 출력후 삭제 인덱스 입력
	 */
	void _delete(std::string command);

	/**
	 @brief		경로를 출력하는 메서드
	 @param		command: 사용자가 입력한 명령어
	 @details	print -option
	 */
	void print(std::string command);

	/**
	 @brief		백업을 실행하는 메서드
	 @details	backup
				root_directory -> copy_directory 로 복사
	 */
	void backup();

	/**
	 @brief		명령어의 사용법을 출력하는 메서드
	 */
	void help();

	/**
	 @brief		명령어를 주관하는 시스템
	 @details	사용자의 명령어를 입력받고 action를 판단하여
				행동 메서드에게 전달한다.
				행동 메서드에게 전달할 때 잘라서 보낼 것인가?
	 @bug		명령어들이 실행이 왼됨
	 */
	void command_system();
};


#endif // !COMMAND_HPP


#pragma once
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "Directory_Manager.hpp"

#define OPTION_ROOT "-root" // 옵션 root
#define OPTION_COPY "-copy"	// 옵션 copy
const std::string ACTION[] = { "add","delete","print","exit","clear" };

#define EXIT(code) exit(code)
#define CLEAR() system("cls")

//------------명령어-------------//
// 추가: action, option, directory
// 삭제: action, option, directory
// 출력: action, option, directory
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

/**
 @brief
 */

/**
 @class		Command
 @date		2019/11/18
 @author	박현우
 @brief		프로그램의 명령어 실행에 관여하는 클래스
 */
class Command2
{
private:
	Root_Directory_Manager* ptr_root_manager; // root_directory를 관여하는 객체
	Copy_Directory_Manager* ptr_copy_manager; // copy_directory를 관여하는 객체

	std::string action;		// 명령어의 action
	std::string option;		// 명령어의 option
	std::string directory;	// 명령어의 directory
	
protected:
	/**
	 @brief		명령어의 행동을 찾는 메서드
	 @param		command: 사용자가 입력한 명령어
	 @return	수행해야할 행동 반환
	 */
	std::string find_action(const std::string command);

	/**
	 @brief		명령어의 옵션을 찾는 메서드
	 @param		command: 사용자가 입력한 명령어
	 @return	옵션 반환
	 */
	std::string find_option(const std::string command);

	/**
	 @brief		명령어의 폴더경로를 찾는 메서드
	 @return	directory_path 반환
	 */
	std::string find_directory(const std::string command);

public:

	/**
	 @brief		경로를 추가하는 메서드
	 @param		command: 사용자가 입력한 명령어
	 */
	void add(std::string command);
	
	/**
	 @brief		경로를 제거하는 메서드
	 @param		command: 사용자가 입력한 명령어
	 */
	void _delete(std::string command);

	/**
	 @brief		경로를 출력하는 메서드
	 @param		command: 사용자가 입력한 명령어
	 */
	void print(std::string command);

	/**
	 @brief		명령어를 주관하는 시스템
	 @details	사용자의 명령어를 입력받고 action를 판단하여
				행동 메서드에게 전달한다.
				*행동 메서드에게 전달할 때 잘라서 보낼 것인가?
	 */
	void command_system();
};


#endif // !COMMAND_HPP


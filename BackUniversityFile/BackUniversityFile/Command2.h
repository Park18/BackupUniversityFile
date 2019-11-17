#pragma once
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "Directory_Manager.hpp"

#define OPTION_ROOT "-root" // �ɼ� root
#define OPTION_COPY "-copy"	// �ɼ� copy
const std::string ACTION[] = { "add","delete","print","exit","clear" };

#define EXIT(code) exit(code)
#define CLEAR() system("cls")

//------------��ɾ�-------------//
// �߰�: action, option, directory
// ����: action, option, directory
// ���: action, option, directory
// ���: action
//----------��ɾ� ����----------//
// action -option directory
// 
// action:		������ �޼���
// option:		root/copy
// directory:	���� ���
//----------��ɾ� ��------------//
// add -root d:/gitbub
// add -copy c/users/hyunwoo/download
// backup

/**
 @brief
 */

/**
 @class		Command
 @date		2019/11/18
 @author	������
 @brief		���α׷��� ��ɾ� ���࿡ �����ϴ� Ŭ����
 */
class Command2
{
private:
	Root_Directory_Manager* ptr_root_manager; // root_directory�� �����ϴ� ��ü
	Copy_Directory_Manager* ptr_copy_manager; // copy_directory�� �����ϴ� ��ü

	std::string action;		// ��ɾ��� action
	std::string option;		// ��ɾ��� option
	std::string directory;	// ��ɾ��� directory
	
protected:
	/**
	 @brief		��ɾ��� �ൿ�� ã�� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 @return	�����ؾ��� �ൿ ��ȯ
	 */
	std::string find_action(const std::string command);

	/**
	 @brief		��ɾ��� �ɼ��� ã�� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 @return	�ɼ� ��ȯ
	 */
	std::string find_option(const std::string command);

	/**
	 @brief		��ɾ��� ������θ� ã�� �޼���
	 @return	directory_path ��ȯ
	 */
	std::string find_directory(const std::string command);

public:

	/**
	 @brief		��θ� �߰��ϴ� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 */
	void add(std::string command);
	
	/**
	 @brief		��θ� �����ϴ� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 */
	void _delete(std::string command);

	/**
	 @brief		��θ� ����ϴ� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 */
	void print(std::string command);

	/**
	 @brief		��ɾ �ְ��ϴ� �ý���
	 @details	������� ��ɾ �Է¹ް� action�� �Ǵ��Ͽ�
				�ൿ �޼��忡�� �����Ѵ�.
				*�ൿ �޼��忡�� ������ �� �߶� ���� ���ΰ�?
	 */
	void command_system();
};


#endif // !COMMAND_HPP


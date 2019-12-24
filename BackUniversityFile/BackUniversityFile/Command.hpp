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

#define OPTION_ROOT "-root" // �ɼ� root
#define OPTION_COPY "-copy"	// �ɼ� copy

#define EXIT(code) exit(code)	// ���� ��ũ��
#define CLEAR() system("cls")	// ȭ�� û�� ��ũ��

//------------��ɾ�-------------//
// �߰�: action, option, directory
// ����: action, option
// ���: action, option
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
//----------��ɾ� ��----------//
// ��ɾ �Է�
// ��ɾ� ��Ȱ, ���� ��ɾ����� Ȯ��

/**
 @brief
 */

/**
 @class		Command
 @date		2019/11/18
 @author	������
 @brief		���α׷��� ��ɾ� ���࿡ �����ϴ� Ŭ����
 */
class Command
{
private:
	Root_Directory_Manager* ptr_root_manager; // root_directory�� �����ϴ� ��ü
	Copy_Directory_Manager* ptr_copy_manager; // copy_directory�� �����ϴ� ��ü
	
protected:
	void set_ptr_root_manager(Root_Directory_Manager* ptr_root_manager) { this->ptr_root_manager = ptr_root_manager; }
	void set_ptr_copy_manager(Copy_Directory_Manager* ptr_copy_manager) { this->ptr_copy_manager = ptr_copy_manager; }

	Root_Directory_Manager* get_ptr_root_manager() { return ptr_root_manager; }
	Copy_Directory_Manager* get_ptr_copy_manager() { return ptr_copy_manager; }

public:	// �ӽ� public, ���� protected
	/**
	 @brief		��ɾ��� �ൿ�� ã�� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�(�������� �Է��̶�� ����)
	 @return	�����ؾ��� �ൿ ��ȯ
	 */
	std::string command_action(const std::string command);

	/**
	 @brief		��ɾ��� �ɼ��� ã�� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�(�������� �Է��̶�� ����)
	 @return	�ɼ� ��ȯ
	 */
	std::string command_option(const std::string command);

	/**
	 @brief		��ɾ��� ������θ� ã�� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�(�������� �Է��̶�� ����)
	 @return	directory_path ��ȯ
	 */
	std::string command_deirectory(const std::string command);

	/**
	 @brief		�ǹٸ� ��ɾ �ԷµǾ����� Ȯ���ϴ� �޼ҵ�
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 @return	true: �ǹٸ� ��ɾ� / false: �߸��� ��ɾ�
	 @details	1. action�� �ʿ��� ��ɾ�
					- ��ɾ�� command_action�� ���ƾ� �Ѵ�.

				2. action option�� �ʿ��� ��ɾ�(�бⰡ �ϳ�)
					- command_action�� command_option Ȯ��

				3. action option directory�� �ʿ��� ��ɾ�(�бⰡ 2��)
					- 

				�б��� ������ �ľ��ϰ� �׿� �´� ��ɾ������� Ȯ��,
				�� �ܿ��� ��� Ʋ�� ��ɾ�
	 */
	bool check_command(const std::string command);

public:

	/**
	 @brief		��θ� �߰��ϴ� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 @details	add -option directory
	 */
	void add(std::string command);
	
	/**
	 @brief		��θ� �����ϴ� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 @details	delete -option
				root/copy ����� ���� �ε��� �Է�
	 */
	void _delete(std::string command);

	/**
	 @brief		��θ� ����ϴ� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 @details	print -option
	 */
	void print(std::string command);

	/**
	 @brief		����� �����ϴ� �޼���
	 @details	backup
				root_directory -> copy_directory �� ����
	 */
	void backup();

	/**
	 @brief		��ɾ��� ������ ����ϴ� �޼���
	 */
	void help();

	/**
	 @brief		��ɾ �ְ��ϴ� �ý���
	 @details	������� ��ɾ �Է¹ް� action�� �Ǵ��Ͽ�
				�ൿ �޼��忡�� �����Ѵ�.
				�ൿ �޼��忡�� ������ �� �߶� ���� ���ΰ�?
	 @bug		��ɾ���� ������ �޵�
	 */
	void command_system();
};


#endif // !COMMAND_HPP


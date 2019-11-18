#pragma once
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "Directory_Manager.hpp"

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


	/**
	 @brief		��ɾ��� �ൿ�� ã�� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�(�������� �Է��̶�� ����)
	 @return	�����ؾ��� �ൿ ��ȯ
	 */
	std::string find_action(const std::string command);

	/**
	 @brief		��ɾ��� �ɼ��� ã�� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�(�������� �Է��̶�� ����)
	 @return	�ɼ� ��ȯ
	 */
	std::string find_option(const std::string command);

	/**
	 @brief		��ɾ��� ������θ� ã�� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�(�������� �Է��̶�� ����)
	 @return	directory_path ��ȯ
	 */
	std::string find_directory(const std::string command);

	/**
	 @brief		�ǹٸ� ��ɾ �ԷµǾ����� Ȯ���ϴ� �޼ҵ�
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 @return	�ǹٸ� ��ɾ��̸� return true
				�ǹٸ��� ���� ��ɾ��̸� return false
	 @details	���� ���� �̽ǽ�
	 */
	bool is_pefect_command(const std::string command);

public:

	/**
	 @brief		��θ� �߰��ϴ� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 */
	void add(std::string command);
	
	/**
	 @brief		��θ� �����ϴ� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 @details	root/copy ����� ���� �ε��� �Է�
	 */
	void _delete(std::string command);

	/**
	 @brief		��θ� ����ϴ� �޼���
	 @param		command: ����ڰ� �Է��� ��ɾ�
	 */
	void print(std::string command);

	/**
	 @brief		����� �����ϴ� �޼���
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


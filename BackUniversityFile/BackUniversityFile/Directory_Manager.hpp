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
 @author	������
 @brief		directory�� �����ϱ� ���� Ŭ����
 @details	txt ���Ϸ� root_directory�� �����ϰ�
			���α׷� ����� vector�� �����ؿ� �����Ѵ�.
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
	 @brief	���α׷� ����� root_directory�� ����ϴ� �޼ҵ�
	 */
	void set_backup();

	/**
	 @brief	���α׷� �ʱ�ȭ�� ����� root_directory�� vector������ �����ϴ� �޼ҵ�
	 */
	void get_backup();

public:

	/**
	 @brief		������
	 @details	���α׷��� ������ �� directory ������� �����´�.
	 */
	Base_Directory_Manager() { set_ptr_directory(new std::vector<std::string>); get_backup(); }

	/**
	 @brief		�Ҹ���
	 @details	���α׷��� ����� �� directory�� ����ϰ�
				���� �Ҵ�� vector�� �����Ѵ�.
	 */
	~Base_Directory_Manager() { set_backup(); delete get_ptr_directory(); }

	/**
	 @brief	vector�� root_directory�� �����ϴ� �޼ҵ�
	 @param	root_directory: �߰��� root_directory
	 */
	void add(std::string root_directory);

	/**
	 @brief	vector�� ����� root_directory�� �����ϴ� �޼ҵ�
	 */
	void _delete();

	/**
	 @brief	vector�� ����� root_directory�� ����ϴ� �޼ҵ�
	 */
	void print();
};

#define ROOT_DIRECTORY_FILE	"Backup\\root_directory.txt"
/**
 @class		root_directory�� �����ϴ� Ŭ����
 @date		2019/11/15
 @author	������
 @detials	Base_Directory_Manager�� ��ӹ޴´�.
 */
class Root_Directory_Manager : public Base_Directory_Manager
{

};

#define COPY_DIRECTORY_FILE	"Backup\\copy_directory.txt"
/**
 @class		copy_directory�� �����ϴ� Ŭ����
 @date		2019/11/15
 @author	������
 @detials	Base_Directory_Manager�� ��ӹ޴´�.
 */
class Copy_Directory_Manager : public Base_Directory_Manager
{

};

#endif // !DIRECTORY_MANAGER_HPP
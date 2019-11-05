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
 * @author ������
 * @brief root ������ �����ϱ� ���� Ŭ����
 * @details txt ���Ͽ� ����� root ������ ������ �� �����ͼ� vector�� �����ϰ�
			 ����� �� vector���� txt ���Ͽ� ����Ѵ�.
 */
class RootManager
{
private:
	//*********************************************************************************
	//									���� �ʵ�
	//*********************************************************************************

	/* root ������ �����ϴ� vector */
	std::vector<std::string>* ptrRootManager;


	//*********************************************************************************
	//									�޼ҵ� �ʵ�
	//*********************************************************************************

	/**
	 * @brief vector�� ����� root ������ txt ���Ͽ� ����ϴ� �޼ҵ�
	 * @return void
	 */
	void setBackup();

	/**
	 * @brief txt ���Ͽ� ����� root ������ vector�� �����ϴ� �޼ҵ�
	 * @return void
	 */
	void getBackup();

public:
	//*********************************************************************************
	//									�޼ҵ� �ʵ�
	//*********************************************************************************
	RootManager() { setPtrRootManager(); getBackup(); }
	~RootManager() { setBackup(); delete getPtrRootManager(); }

	/* set|get */
	void setPtrRootManager() { this->ptrRootManager = new std::vector<std::string>; }
	std::vector<std::string>* getPtrRootManager() { return this->ptrRootManager; }

	/**
	 * @brief vector�� ����� root ������ ���� �����ϴ� �������� Ȯ���ϴ� �޼ҵ�
	 * @return void
	 */
	void checkRoot();

	/**
	 * @brief root ������ ���� ��θ� ��ȯ�ϴ� �޼ҵ�
	 * @param string root : root ���� ���
	 * @return string : root ������ ���� ���
	 */
	std::string upperRoot(std::string root);

	/**
	 * @brief root ������ vector�� �����ϴ� �޼ҵ�
	 * @param string root : root ���� ���
	 * @return void
	 */
	void add(std::string);

	/**
	 * @brief vector�� ����� root ������ �����ϴ� �޼ҵ�
	 * @return void
	 */
	void _delete();

	/**
	 * @brief root ������ ����ϴ� �޼ҵ�
	 * @return void
	 */
	void print();
};

#endif // !ROOTMANAGER_H


#pragma once
#ifndef ROOTMANAGER_H
#define ROTTMANAGER_H	

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define BACKUPROOTFILE "Backup\\BackupRoot.txt"

// root�� ������ ������ �����ϴ� Ŭ����
// �ش� ������ ����� �����Ѵ�.
// ���� ������ ���ٸ� - ���� �߻�, �޽��� ���, ���α׷� ����
class RootManager
{
private:
	std::vector<std::string>* ptrRootManager;

	// ����� �ϴ� �޼���
	void setBackup();

	// ����� ������ �������� �޼���
	void getBackup();

public:
	RootManager() { setPtrRootManager(); getBackup(); }
	~RootManager() { setBackup(); delete getPtrRootManager(); }

	// set/get
	void setPtrRootManager() { this->ptrRootManager = new std::vector<std::string>; }
	std::vector<std::string>* getPtrRootManager() { return this->ptrRootManager; }

	// root ������ �߰��ϴ� �޼���
	void add(std::string);

	// root ������ �����ϴ� �޼���
	void _delete();

	// root ������ ����ϴ� �޼���
	void print();
};

#endif // !ROOTMANAGER_H


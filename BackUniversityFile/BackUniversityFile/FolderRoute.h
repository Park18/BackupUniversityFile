#pragma once
#ifndef FOLDERROUTE_H
#define FOLDERROUTE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

namespace phw
{

/***
 * ������ ��ο� ���� Ŭ����
 */
class FolderRoute
{
private:
	std::string subjectName;
	std::vector<std::string>* ptrFolderRoute;

public:
	FolderRoute(std::string subjectName);
	~FolderRoute();

	void setSubjectName(std::string subjectName) { this->subjectName = subjectName; }
	void setPtrFolderRoute() { this->ptrFolderRoute = new std::vector<std::string>; }

	std::string getSubjectName() { return subjectName; }
	std::vector<std::string>* getPtrFolderRoute() { return ptrFolderRoute; }

	/**
	 * ptrFolderRoute�� ���� ����ϴ� �޼���
	 */
	void setFolderRouteBackup();

	/**
	 * ptrFolderRoute�� ����� ������ �������� �޼���
	 */
	void getFolderRouteBackup();

	/**
	 * ptrFolderRoute�� route�� �߰��ϴ� �޼���
	 */
	void addPtrFolderRoute(std::string route);

	/**
	 * ptrFolderRoute[index]�� ���� �����ϴ� �޼���
	 */
	void deletePtrFolderRoute(int index);

	/**
	 * ptrFolderRoute�� ��� ���� ����ϴ� �޼���
	 */
	void printPtrFolderRoute();
};
} // namespace phw
#endif // !FOLDERROUTE_H


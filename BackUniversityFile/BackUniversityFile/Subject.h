#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H	

#include "FolderRoute.h"

#define SUBJECTFILENAME "Backup\\subject.txt"

namespace phw
{

/***
 * ���� ���� Ŭ����
 * ������ �����ϸ� ��ε� �ڵ����� �����ȴ�.
 */
class Subject
{
private:
	std::vector<std::string>* ptrSubject;
	std::vector<FolderRoute*>* ptrFolderRoute;

public:
	Subject();
	~Subject();

	void setPtrSubject() { this->ptrSubject = new std::vector<std::string>; }
	void setPtrFolderRoute();

	std::vector<std::string>* getPtrSubject() { return ptrSubject; }
	std::string getPtrSubjectAt(int index) { return (*getPtrSubject())[index]; }
	int getPtrSubjectIndex(std::string subject);
	std::vector<FolderRoute*>* getPtrFolderRoute() { return ptrFolderRoute; }
	FolderRoute* getPtrFolderRouteAt(int index) { return (*getPtrFolderRoute())[index]; }

	/**
	 * ptrSubject�� ���� ����ϴ� �޼���
	 */
	void setSubjectBackup();

	/**
	 *  ptrSubject�� ����� ������ �������� �޼���
	 */
	void getSubjectBackup();

	/**
	 * ptrSubject�� suject�� �߰��ϴ� �޼���
	 */
	void addPtrSubject(std::string subject);

	/**
	 * ptrSubject[index]�� ���� �����ϴ� �޼���
	 */
	void deleteSubject(int index);

	/**
	 * ptrSubject�� ��� ���� ����ϴ� �޼���
	 */
	void printSubject();

	//void printPtrFolderRoute();
};

} // !namespace phw


#endif // !SUBJECT_H


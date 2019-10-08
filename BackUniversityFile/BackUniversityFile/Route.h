#pragma once
#ifndef ROUTEMANAGER_H
#define ROUTEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace route
{

//------------------------------------------//
//       		  BaseAction         		//
//------------------------------------------//
class BaseAction
{
public:
	// ����ϴ� �޼���
	virtual void setBackup() = 0;

	// ����� ������ �������� �޼���
	virtual void getBackup() = 0;

	// ������ �߰��ϴ� �޼���
	virtual void add(std::string) = 0;

	// ������ �����ϴ� �޼���
	virtual void _delete(int index) = 0;

	// ������ ����ϴ� �޼���
	virtual void print() = 0;
};

//------------------------------------------//
//		FolderRoute : public BaseAction		//
//------------------------------------------//
class FolderRoute : public BaseAction
{
private:
	std::string subject;
	std::vector<std::string>* ptrFolderRoute;

public:
	FolderRoute(std::string subject);
	~FolderRoute();

	void setSubject(std::string subject) { this->subject = subject; }
	void setPtrFolderRoute() { this->ptrFolderRoute = new std::vector<std::string>; }

	std::string getSubject() { return this->subject; }
	std::vector<std::string>* getPtrFolderRoute() { return this->ptrFolderRoute; }



	// BaseAction��(��) ���� ��ӵ�
	virtual void setBackup() override;

	virtual void getBackup() override;

	virtual void add(std::string) override;

	virtual void _delete(int index) override;

	virtual void print() override;

};

//------------------------------------------//
//        Subject : public BaseAction       //
//------------------------------------------//
#define SUBJECTFILENAME "Backup\\subject.txt"

class Subject : public BaseAction
{
private:
	std::vector<std::string>* ptrSubject;
	std::vector<FolderRoute*>* ptrFolderRoute;

public:
	Subject();
	~Subject();

	void setPrtSubject() { this->ptrSubject = new std::vector<std::string>; }
	void setPtrFolderRoute();

	std::vector<std::string>* getPtrSubject() { return this->ptrSubject; }
	std::vector<FolderRoute*>* getPtrFolderRoute() { return this->ptrFolderRoute; }

	// BaseAction��(��) ���� ��ӵ�
	virtual void setBackup() override;

	virtual void getBackup() override;

	virtual void add(std::string) override;

	virtual void _delete(int index) override;

	virtual void print() override;
};
} // namespace Route


#endif // !ROUTEMANAGER_H


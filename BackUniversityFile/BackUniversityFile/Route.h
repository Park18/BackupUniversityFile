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
	// 백업하는 메서드
	virtual void setBackup() = 0;

	// 백업된 정보를 가져오는 메서드
	virtual void getBackup() = 0;

	// 정보를 추가하는 메서드
	virtual void add(std::string) = 0;

	// 정보를 삭제하는 메서드
	virtual void _delete(int index) = 0;

	// 정보를 출력하는 메서드
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



	// BaseAction을(를) 통해 상속됨
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

	// BaseAction을(를) 통해 상속됨
	virtual void setBackup() override;

	virtual void getBackup() override;

	virtual void add(std::string) override;

	virtual void _delete(int index) override;

	virtual void print() override;
};
} // namespace Route


#endif // !ROUTEMANAGER_H


#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H	

#include "FolderRoute.h"

#define SUBJECTFILENAME "Backup\\subject.txt"

namespace phw
{

/***
 * 과목에 관한 클래스
 * 과목을 생성하면 경로도 자동으로 생성된다.
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
	 * ptrSubject의 값을 백업하는 메서드
	 */
	void setSubjectBackup();

	/**
	 *  ptrSubject의 백업된 정보를 가져오는 메서드
	 */
	void getSubjectBackup();

	/**
	 * ptrSubject에 suject를 추가하는 메서드
	 */
	void addPtrSubject(std::string subject);

	/**
	 * ptrSubject[index]의 값을 제거하는 메서드
	 */
	void deleteSubject(int index);

	/**
	 * ptrSubject의 모든 값을 출력하는 메서드
	 */
	void printSubject();

	//void printPtrFolderRoute();
};

} // !namespace phw


#endif // !SUBJECT_H


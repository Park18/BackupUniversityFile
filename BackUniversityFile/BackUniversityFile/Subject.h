#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H	

#include "FolderRoute.h"

#define SUBJECTFILENAME "Backup\\subject.txt"

namespace phw
{
class Subject
{
private:
	std::vector<std::string>* ptrSubject;
	std::vector<FolderRoute>* ptrFolderRoute;

public:
	Subject();
	~Subject();

	void setPtrSubject() { this->ptrSubject = new std::vector<std::string>; }
	void setPtrFolderRoute();

	std::vector<std::string>* getPtrSubject() { return ptrSubject; }
	std::vector<FolderRoute>* getPtrFolderRoute() { return ptrFolderRoute; }

	void setSubjectBackup();

	void getSubjectBackup();

	void addPtrSubject(std::string subject);

	void deleteSubject(int index);

	void printSubject();

	//void printPtrFolderRoute();
};

} // !namespace phw



#endif // !SUBJECT_H


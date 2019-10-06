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
 * 폴더의 경로에 관한 클래스
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
	 * ptrFolderRoute의 값을 백업하는 메서드
	 */
	void setFolderRouteBackup();

	/**
	 * ptrFolderRoute의 백업된 정보를 가져오는 메서드
	 */
	void getFolderRouteBackup();

	/**
	 * ptrFolderRoute에 route를 추가하는 메서드
	 */
	void addPtrFolderRoute(std::string route);

	/**
	 * ptrFolderRoute[index]의 값을 제거하는 메서드
	 */
	void deletePtrFolderRoute(int index);

	/**
	 * ptrFolderRoute의 모든 값을 출력하는 메서드
	 */
	void printPtrFolderRoute();
};
} // namespace phw
#endif // !FOLDERROUTE_H


#include "FolderRoute.h"

using namespace std;

phw::FolderRoute::FolderRoute(std::string subjectName)
{
	setSubjectName(subjectName);

	vector<string>* ptrFolderRoute = new vector<string>;
	setPtrFolderRoute(ptrFolderRoute);
}

phw::FolderRoute::~FolderRoute()
{
	delete getPtrFolderRoute();
}

void phw::FolderRoute::setFolderRouteBackup()
{
	string fileName = getSubjectName() + ".txt";
	ofstream writeFile(fileName);

	for (int index = 0; index < getPtrFolderRoute()->size(); index++)
		writeFile << getPtrFolderRoute() + index;

	writeFile.close();
}

void phw::FolderRoute::getFolderRouteBackup()
{
	string fileName = getSubjectName() + ".txt";
	ifstream readFile(fileName);

	string route;
	while (readFile.eof())
	{
		readFile >> route;
		addPtrFolderRoute(route);
	}
}

void phw::FolderRoute::addPtrFolderRoute(std::string route)
{
	getPtrFolderRoute()->push_back(route);
}

void phw::FolderRoute::deletePtrFolderRoute(int index)
{
	getPtrFolderRoute()->erase(getPtrFolderRoute()->begin() + index);
}

void phw::FolderRoute::printPtrFolderRoute()
{
	for (int index = 0; index < getPtrFolderRoute()->size(); index++)
		cout << index << " : " << getPtrFolderRoute()+index << endl;
}

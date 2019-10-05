#include "FolderRoute.h"

using namespace std;

phw::FolderRoute::FolderRoute(std::string subjectName)
{
	setSubjectName(subjectName);
	setPtrFolderRoute();

	getFolderRouteBackup();
}

phw::FolderRoute::~FolderRoute()
{
	setFolderRouteBackup();
	delete getPtrFolderRoute();
}

void phw::FolderRoute::setFolderRouteBackup()
{
	string fileName = "Backup\\" + getSubjectName() + ".txt";
	ofstream writeFile(fileName);

	for (int index = 0; index < getPtrFolderRoute()->size(); index++)
		writeFile << (*getPtrFolderRoute())[index] << endl;

	writeFile.close();
}

void phw::FolderRoute::getFolderRouteBackup()
{
	string fileName = "Backup\\"+getSubjectName() + ".txt";
	ifstream readFile(fileName);

	string route;
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			readFile >> route;
			addPtrFolderRoute(route);
		}
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
		cout << index << " : " << (*getPtrFolderRoute())[index] << endl;
}

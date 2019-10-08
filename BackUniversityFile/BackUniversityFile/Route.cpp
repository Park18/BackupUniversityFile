#include "Route.h"

using namespace std;

//------------------------------------------//
//		FolderRoute : public BaseAction		//
//------------------------------------------//
route::FolderRoute::FolderRoute(std::string subject)
{
	setSubject(subject);
	setPtrFolderRoute();
	getBackup();
}

route::FolderRoute::~FolderRoute()
{
	setBackup();
	delete getPtrFolderRoute();
}

route::Subject::Subject()
{
	setPrtSubject();
	this->getBackup();

	this->setPtrFolderRoute();
}

route::Subject::~Subject()
{
	this->setBackup();

	delete getPtrSubject();
	delete getPtrFolderRoute();
}

void route::Subject::setPtrFolderRoute()
{
	this->ptrFolderRoute = new std::vector<FolderRoute*>;

	for (int index = 0; index < getPtrSubject()->size(); index++)
		getPtrFolderRoute()->push_back(new route::FolderRoute((*getPtrSubject())[index]));
}

void route::FolderRoute::setBackup()
{
	ofstream writeFile("Backup\\" + getSubject() + ".txt");

	if (writeFile.is_open())
	{
		for (int index = 0; index < getPtrFolderRoute()->size(); index++)
			writeFile << *(getPtrFolderRoute()->begin() + index) << endl;
	}

	//else

	writeFile.close();
}

void route::FolderRoute::getBackup()
{
	ifstream readFile("Backup\\" + getSubject() + ".txt");
	
	if (readFile.is_open())
	{
		string route;
		while (readFile.peek() != EOF)
		{
			getline(readFile, route);
			this->add(route);
		}
	}
}

void route::FolderRoute::add(std::string route)
{
	getPtrFolderRoute()->push_back(route);
}

void route::FolderRoute::_delete(int index)
{
	getPtrFolderRoute()->erase(getPtrFolderRoute()->begin() + index);
}

void route::FolderRoute::print()
{
	for (int index = 0; index < getPtrFolderRoute()->size(); index++)
		cout << index << " : " << (*getPtrFolderRoute())[index] << endl;
}

//------------------------------------------//
//        Subject : public BaseAction       //
//------------------------------------------//
void route::Subject::setBackup()
{
	ofstream writeFile(SUBJECTFILENAME);

	for (int index = 0; index < getPtrSubject()->size(); index++)
		writeFile << (*getPtrSubject())[index] << endl;

	writeFile.close();
}

void route::Subject::getBackup()
{
	ifstream readFile(SUBJECTFILENAME);

	if (readFile.is_open())
	{
		string subject;
		while (readFile.peek() != EOF)
		{
			getline(readFile, subject);
			this->add(subject);
		}
	}
}

void route::Subject::add(std::string subject)
{
	getPtrSubject()->push_back(subject);
}

void route::Subject::_delete(int index)
{
	getPtrSubject()->erase(getPtrSubject()->begin() + index);
}

void route::Subject::print()
{
	for (int index = 0; index < getPtrSubject()->size(); index++)
		cout << index << " : " << (*getPtrSubject())[index] << endl;
}

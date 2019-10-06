#include "Subject.h"

using namespace std;

phw::Subject::Subject()
{
	setPtrSubject();
	getSubjectBackup();

	setPtrFolderRoute();
}

phw::Subject::~Subject()
{
	setSubjectBackup();
	delete getPtrSubject();
	delete getPtrFolderRoute();
}

void phw::Subject::setPtrFolderRoute()
{
	this->ptrFolderRoute = new std::vector<FolderRoute*>;

	for (int index = 0; index < getPtrSubject()->size(); index++)
		getPtrFolderRoute()->push_back(new FolderRoute(getPtrSubjectAt(index)));
	
}

int phw::Subject::getPtrSubjectIndex(std::string subject)
{
	for (int index = 0; index < getPtrSubject()->size(); index++)
		if (getPtrSubjectAt(index) == subject)
			return index;
	
	return -1;
}

void phw::Subject::setSubjectBackup()
{
	ofstream writeFile(SUBJECTFILENAME);

	for (int index = 0; index < getPtrSubject()->size(); index++)
		writeFile << (*getPtrSubject())[index] << endl;

	writeFile.close();
}

void phw::Subject::getSubjectBackup()
{
	ifstream readFile(SUBJECTFILENAME);

	string subject;
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			readFile >> subject;
			addPtrSubject(subject);
		}
	}
}

void phw::Subject::addPtrSubject(std::string subject)
{
	getPtrSubject()->push_back(subject);
}

void phw::Subject::deleteSubject(int index)
{
	getPtrSubject()->erase(getPtrSubject()->begin() + index);
}

void phw::Subject::printSubject()
{
	for (int index = 0; index < getPtrSubject()->size(); index++)
		cout << index << " : " << (*getPtrSubject())[index] << endl;
}

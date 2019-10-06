#include "BackupUniversityFile.h"

using namespace std;

void phw::BackupUniversityFile::testFolderRoute()
{
	phw::FolderRoute folderRoute("운영체제");
	folderRoute.printPtrFolderRoute();
}

void phw::BackupUniversityFile::testSubject()
{
	phw::Subject subject;
	
	subject.printSubject();

	for (int index = 0; index < subject.getPtrSubject()->size(); index++)
	{
		cout << "----------" << (*subject.getPtrSubject())[index] << "----------" << endl;
		subject.getPtrFolderRouteAt(index)->printPtrFolderRoute();
		cout << "----------" << (*subject.getPtrSubject())[index] << "----------" << endl;
	}
}

void phw::BackupUniversityFile::testManager()
{
	phw::Manager manager;

	string command;
	getline(cin, command);

	if (manager.findAction(command) == "add")
		manager.add(manager.isOption(command), manager.findSubject(command), manager.findElement(command));

	manager.getPtrSubject()->printSubject();
	cout << "----------------------------" << endl;	
	manager.getPtrSubject()->getPtrFolderRouteAt(manager.getPtrSubject()->getPtrSubjectIndex(manager.findSubject(command)));

}

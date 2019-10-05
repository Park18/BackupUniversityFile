#include "BackupUniversityFile.h"

using namespace std;

void BackupUniversityFile::testFolderRoute()
{
	phw::FolderRoute folderRoute("운영체제");
	folderRoute.printPtrFolderRoute();
}

void BackupUniversityFile::testSubject()
{
	phw::Subject subject;
	subject.printSubject();

	for (int index = 0; index < subject.getPtrSubject()->size(); index++)
	{
		cout << "----------" << (*subject.getPtrSubject())[index] << "----------" << endl;
		(*subject.getPtrFolderRoute())[index].printPtrFolderRoute();
		//cout << "----------" << (*subject.getPtrSubject())[index] << "----------" << endl;
	}
}

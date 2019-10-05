#include "BackupUniversityFile.h"

using namespace std;

void BackupUniversityFile::testFolderRoute()
{
	phw::FolderRoute folderRoute("�ü��");
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

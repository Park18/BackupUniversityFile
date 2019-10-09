#include"BackupUniversityFile.h"
#include "Route.h"
#include "Command.h"

using namespace std;

void folderRouteTest()
{
	route::FolderRoute folderRoute("운영체제");
	folderRoute.print();
}

void subjectTest()
{
	route::Subject subject;
	subject.print();

	
	for (int index = 0; index < subject.getPtrSubject()->size(); index++)
	{
		cout << "--------------" << (*subject.getPtrSubject())[index] << "--------------" << endl;
		(*subject.getPtrFolderRoute())[index]->print();
		cout << "--------------" << (*subject.getPtrSubject())[index] << "--------------" << endl;
	}
}

void commandTest1()
{
	Command command;

	string str;
	getline(cin, str);

	cout << "action : " << command.findAction(str) << endl;
	cout << "subject : " << command.findSubject(str) << endl;
	cout << "element : " << command.findElement(str) << endl;
	cout << "option : " << command.findOption(str) << endl;
}

void commandTest2()
{
	Command command;
	command.commandSystem();
}

int main()
{
	//folderRouteTest();
	//subjectTest();
	//commandTest1();
	commandTest2();
}
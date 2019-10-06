#include "BackupUniversityFile.h"

using namespace std;

std::string phw::BackupUniversityFile::findAction(std::string command)
{
	int pos = command.find(" ");
	return command.substr(0, pos);
}

std::string phw::BackupUniversityFile::findSubject(std::string command)
{
	int pos = command.find(" ");

	// 옵션이 있을 때
	if (isOption(command))
	{
		string subcommand(command.substr(pos + 1, command.length() - pos));
		pos = subcommand.find(" ");

		return subcommand.substr(pos + 1, subcommand.find_last_of(" ") - pos);
	}

	// 옵션이 없을 때
	return command.substr(pos + 1, command.find_last_of(" ") - pos);
}

std::string phw::BackupUniversityFile::findElement(std::string command)
{
	int pos = command.find_last_of(" ");
	return command.substr(pos + 1, command.length() - pos);
}

void phw::BackupUniversityFile::ramifyCommand(std::string command)
{
	
}

bool phw::BackupUniversityFile::isOption(std::string command)
{
	int pos = command.find("-");
	if (pos > 0)
	{
		if (command.substr(pos, 2) == "-f")
			return true;
	}

	return false;
}

void phw::BackupUniversityFile::add(bool option, std::string subject, std::string element)
{
	// 옵션이 있을 때(과목 경로 추가)
	if (option)
	{
		int index = getPtrSubject()->getSubjectIndex(subject);
		if (index == -1)
		{
			clear();
			cout << "존재하지 않은 과목입니다." << endl;
		}

		else
		{
			getPtrSubject()->getPtrFolderRouteAt(index)->addPtrFolderRoute(element);
		}
	}

	// 옵션이 없을 때(과목 추가)
	else
	{
		getPtrSubject()->addPtrSubject(element);
	}
}

void phw::BackupUniversityFile::clear()
{
	system("clas");
}

void phw::BackupUniversityFile::backupUniversityFile()
{
	
}

void phw::BackupUniversityFile::testFolderRoute()
{
	phw::FolderRoute folderRoute("운영체제");
	folderRoute.printPtrFolderRoute();
}

void phw::BackupUniversityFile::testSubject()
{
	phw::Subject subject;
	
	string command;
	getline(cin, command);

	add(isOption(command), findSubject(command), findElement(command));

	subject.getPtrFolderRouteAt(3)->printPtrFolderRoute();
}

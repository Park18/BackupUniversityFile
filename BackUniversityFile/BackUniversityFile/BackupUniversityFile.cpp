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

	// �ɼ��� ���� ��
	if (isOption(command))
	{
		string subcommand(command.substr(pos + 1, command.length() - pos));
		pos = subcommand.find(" ");

		return subcommand.substr(pos + 1, subcommand.find_last_of(" ") - pos);
	}

	// �ɼ��� ���� ��
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
	// �ɼ��� ���� ��(���� ��� �߰�)
	if (option)
	{
		int index = getPtrSubject()->getSubjectIndex(subject);
		if (index == -1)
		{
			clear();
			cout << "�������� ���� �����Դϴ�." << endl;
		}

		else
		{
			getPtrSubject()->getPtrFolderRouteAt(index)->addPtrFolderRoute(element);
		}
	}

	// �ɼ��� ���� ��(���� �߰�)
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
	phw::FolderRoute folderRoute("�ü��");
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

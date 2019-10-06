#include "Manager.h"

using namespace std;

std::string phw::Manager::findAction(std::string command)
{
	int pos = command.find(" ");
	return command.substr(0, pos);
}

std::string phw::Manager::findSubject(std::string command)
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

std::string phw::Manager::findElement(std::string command)
{
	int pos = command.find_last_of(" ");
	return command.substr(pos + 1, command.length() - pos);
}

bool phw::Manager::isOption(std::string command)
{
	int pos = command.find("-");
	if (pos > 0)
	{
		if (command.substr(pos, 2) == "-f")
			return true;
	}

	return false;
}

void phw::Manager::add(bool isOption, std::string subject, std::string element)
{
	// �ɼ��� ���� ��(���� ��� �߰�)
	if (isOption)
	{
		int index = getPtrSubject()->getPtrSubjectIndex(subject);
		if (index < 0)
		{
			clear();
			cout << "�������� ���� �����Դϴ�." << endl;
		}

		else
		{
			getPtrSubject()->getPtrFolderRouteAt(index)->addPtrFolderRoute(element);
		}
	}
}

void phw::Manager::clear()
{
	system("clas");
}

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
	// 옵션이 있을 때(과목 경로 추가)
	if (isOption)
	{
		int index = getPtrSubject()->getPtrSubjectIndex(subject);
		if (index < 0)
		{
			clear();
			cout << "존재하지 않은 과목입니다." << endl;
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

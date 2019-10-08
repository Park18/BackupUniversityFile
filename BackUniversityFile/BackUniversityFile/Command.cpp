#include "Command.h"

std::string Command::findAction(std::string command)
{
	int pos = command.find(" ");
	return command.substr(0, pos);
}

std::string Command::findSubject(std::string command)
{
	int pos = command.find(" ");

	if (findOption(command))
	{
		string subcommand(command.substr(pos + 1, command.length() - pos));
		pos = subcommand.find(" ");

		return subcommand.substr(pos + 1, subcommand.find_last_of(" ") - pos);
	}

	return command.substr(pos + 1, command.length() - pos);
}

std::string Command::findElement(std::string command)
{
	int pos = command.find_last_of(" ");
	return command.substr(pos + 1, command.length() - pos);
}

bool Command::findOption(std::string command)
{
	int pos = command.find("-");

	if (pos > 0)
	{
		if (command.substr(pos, 2) == "-f")
			return true;
	}

	return false;
}

void Command::clear()
{
	system("cls");
}

void Command::_exit()
{
	exit(0);
}

void Command::add(std::string command)
{
	// 옵션이 있다면(과목명.txt에 추가)
	if (findOption(command))
	{
		int index; // findSubject(command)에 해당하는 인덱스를 찾는다.
		(*getSubject()->getPtrFolderRoute())[index]->add(findElement(command));
	}

	// 옵션이 없다면(subject.txt에 추가)
	else
	{
		getSubject()->add(findSubject(command));
	}
}

void Command::_delete(std::string command)
{
	// 옵션이 있다면(과목명.txt 정보를 보여준 후 index를 입력받아 해당 인덱스 경로 삭제)
	if (findOption(command))
	{
		int index; // findSubject(command)에 해당하는 인덱스를 찾는다.
		(*getSubject()->getPtrFolderRoute())[index]->print();
		(*getSubject()->getPtrFolderRoute())[index]->_delete(getUserIndex());
	}

	// 옵션이 없다면(subject.txt 정보를 보여준 후 index를 입력받아 해당 인덱스 과목명 삭제)
	else
	{
		getSubject()->print();
		getSubject()->_delete(getUserIndex());
	}
}

void Command::print(std::string command)
{
	// 옵션이 있다면(과목명.txt의 모든 경로를 출력)
	if (findOption(command))
	{
		int index; // findSubject(command)에 해당하는 인덱스를 찾는다.
		(*getSubject()->getPtrFolderRoute())[index]->print();
	}

	// 옵션이 없다면(subject.txt의 모든 경로를 출력)
	else
	{
		getSubject()->print();
	}
}

int Command::getUserIndex()
{
	int index;
	while (true)
	{
		cout << "0 ~ 10 사이의 인덱스를 입력해주세요" << endl;
		cout << "index : ";
		cin >> index;

		if (index > 10 || index < 0)
		{
			cout << "잘못된 값을 입력했습니다. 다시 입력해주세요";
			continue;
		}

		else
			break;
	}

	return index;
}


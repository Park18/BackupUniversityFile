/*
#include "Command_delete.h"

using namespace std;

std::string Command::findAction(std::string command)
{
	int pos = command.find(" ");
	return command.substr(0, pos);
}

std::string Command::findSubject(std::string command)
{
	int pos = command.find(" ");

	// 옵션이 있다면
	if (findOption(command))
	{
		string subcommand(command.substr(pos + 1, command.length() - pos));
		pos = subcommand.find(" ");

		if(pos == subcommand.find_last_of(" "))
			return subcommand.substr(pos + 1, subcommand.length() - pos);

		return subcommand.substr(pos + 1, subcommand.find_last_of(" ") - pos);
	}

	// 옵션이 없다면
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
		int index = getPtrSubject()->getPtrSubejectIndex(findSubject(command));
		if (index == -1)
		{
			cout << "과목을 찾지 못했습니다." << endl;
		}

		else
			(*getPtrSubject()->getPtrFolderRoute())[index]->add(findElement(command));
	}

	// 옵션이 없다면(subject.txt에 추가)
	else
	{
		getPtrSubject()->add(findSubject(command));
	}
}

void Command::_delete(std::string command)
{
	// 옵션이 있다면(과목명.txt 정보를 보여준 후 index를 입력받아 해당 인덱스 경로 삭제)
	if (findOption(command))
	{
		int index = getPtrSubject()->getPtrSubejectIndex(findSubject(command));
		(*getPtrSubject()->getPtrFolderRoute())[index]->print();
		(*getPtrSubject()->getPtrFolderRoute())[index]->_delete(getUserIndex());
	}

	// 옵션이 없다면(subject.txt 정보를 보여준 후 index를 입력받아 해당 인덱스 과목명 삭제)
	else
	{
		getPtrSubject()->print();
		getPtrSubject()->_delete(getUserIndex());
	}
}

void Command::print(std::string command)
{
	// 옵션이 있다면(과목명.txt의 모든 경로를 출력)
	if (findOption(command))
	{
		int index = getPtrSubject()->getPtrSubejectIndex(findSubject(command));
		if (index == -1)
			cout << "과목을 찾지 못했습니다." << endl;
			
		else
			(*getPtrSubject()->getPtrFolderRoute())[index]->print();
	}

	// 옵션이 없다면(subject.txt의 모든 경로를 출력)
	else
	{
		getPtrSubject()->print();
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
			cout << "잘못된 값을 입력했습니다. 다시 입력해주세요" << endl;
			continue;
		}

		else
			break;
	}

	cin.clear();
	return index;
}

void Command::commandSystem()
{
	while (true)
	{
		cin.clear();
		string command;
		getline(cin, command);

		if (findAction(command) == "add")
			add(command);

		else if (findAction(command) == "delete")
			_delete(command);


		else if (findAction(command) == "print")
			print(command);

		else if (findAction(command) == "clear")
			clear();

		else if (findAction(command) == "exit")
			return;

		else
			cout << "잘못된 명령어 입니다. 다시 입력해 주세요" << endl;

	}
}

*/

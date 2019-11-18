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

	// �ɼ��� �ִٸ�
	if (findOption(command))
	{
		string subcommand(command.substr(pos + 1, command.length() - pos));
		pos = subcommand.find(" ");

		if(pos == subcommand.find_last_of(" "))
			return subcommand.substr(pos + 1, subcommand.length() - pos);

		return subcommand.substr(pos + 1, subcommand.find_last_of(" ") - pos);
	}

	// �ɼ��� ���ٸ�
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
	// �ɼ��� �ִٸ�(�����.txt�� �߰�)
	if (findOption(command))
	{
		int index = getPtrSubject()->getPtrSubejectIndex(findSubject(command));
		if (index == -1)
		{
			cout << "������ ã�� ���߽��ϴ�." << endl;
		}

		else
			(*getPtrSubject()->getPtrFolderRoute())[index]->add(findElement(command));
	}

	// �ɼ��� ���ٸ�(subject.txt�� �߰�)
	else
	{
		getPtrSubject()->add(findSubject(command));
	}
}

void Command::_delete(std::string command)
{
	// �ɼ��� �ִٸ�(�����.txt ������ ������ �� index�� �Է¹޾� �ش� �ε��� ��� ����)
	if (findOption(command))
	{
		int index = getPtrSubject()->getPtrSubejectIndex(findSubject(command));
		(*getPtrSubject()->getPtrFolderRoute())[index]->print();
		(*getPtrSubject()->getPtrFolderRoute())[index]->_delete(getUserIndex());
	}

	// �ɼ��� ���ٸ�(subject.txt ������ ������ �� index�� �Է¹޾� �ش� �ε��� ����� ����)
	else
	{
		getPtrSubject()->print();
		getPtrSubject()->_delete(getUserIndex());
	}
}

void Command::print(std::string command)
{
	// �ɼ��� �ִٸ�(�����.txt�� ��� ��θ� ���)
	if (findOption(command))
	{
		int index = getPtrSubject()->getPtrSubejectIndex(findSubject(command));
		if (index == -1)
			cout << "������ ã�� ���߽��ϴ�." << endl;
			
		else
			(*getPtrSubject()->getPtrFolderRoute())[index]->print();
	}

	// �ɼ��� ���ٸ�(subject.txt�� ��� ��θ� ���)
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
		cout << "0 ~ 10 ������ �ε����� �Է����ּ���" << endl;
		cout << "index : ";
		cin >> index;

		if (index > 10 || index < 0)
		{
			cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է����ּ���" << endl;
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
			cout << "�߸��� ��ɾ� �Դϴ�. �ٽ� �Է��� �ּ���" << endl;

	}
}

*/

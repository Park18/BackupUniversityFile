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
	// �ɼ��� �ִٸ�(�����.txt�� �߰�)
	if (findOption(command))
	{
		int index; // findSubject(command)�� �ش��ϴ� �ε����� ã�´�.
		(*getSubject()->getPtrFolderRoute())[index]->add(findElement(command));
	}

	// �ɼ��� ���ٸ�(subject.txt�� �߰�)
	else
	{
		getSubject()->add(findSubject(command));
	}
}

void Command::_delete(std::string command)
{
	// �ɼ��� �ִٸ�(�����.txt ������ ������ �� index�� �Է¹޾� �ش� �ε��� ��� ����)
	if (findOption(command))
	{
		int index; // findSubject(command)�� �ش��ϴ� �ε����� ã�´�.
		(*getSubject()->getPtrFolderRoute())[index]->print();
		(*getSubject()->getPtrFolderRoute())[index]->_delete(getUserIndex());
	}

	// �ɼ��� ���ٸ�(subject.txt ������ ������ �� index�� �Է¹޾� �ش� �ε��� ����� ����)
	else
	{
		getSubject()->print();
		getSubject()->_delete(getUserIndex());
	}
}

void Command::print(std::string command)
{
	// �ɼ��� �ִٸ�(�����.txt�� ��� ��θ� ���)
	if (findOption(command))
	{
		int index; // findSubject(command)�� �ش��ϴ� �ε����� ã�´�.
		(*getSubject()->getPtrFolderRoute())[index]->print();
	}

	// �ɼ��� ���ٸ�(subject.txt�� ��� ��θ� ���)
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
		cout << "0 ~ 10 ������ �ε����� �Է����ּ���" << endl;
		cout << "index : ";
		cin >> index;

		if (index > 10 || index < 0)
		{
			cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է����ּ���";
			continue;
		}

		else
			break;
	}

	return index;
}


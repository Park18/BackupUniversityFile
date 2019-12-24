#include "Command.hpp"

using namespace std;

std::string Command::command_action(const std::string command)
{
	int blank_index = command.find_first_of(" ");
	return command.substr(0, blank_index);
}

std::string Command::command_option(const std::string command)
{
	int option_index = command.find(" -");
	int blank_index = command.find(" ", option_index);
	
	return command.substr(option_index + 1, blank_index - (option_index + 1));
}

std::string Command::command_deirectory(const std::string command)
{
	int option_index = command.find(" -") + 2;
	int blank_index = command.find(" ", option_index);

	return command.substr(blank_index + 1, command.length() - blank_index);
}

bool Command::check_command(const std::string command)
{
	int blank_count = 0;

	string action;
	string option;
	string directory;

	for (int index = 0; index != -1;)
	{
		if (index == 0)
			index = command.find(" ", index);

		else
			index = command.find(" ", index + 1);

		if (index != -1)
			blank_count++;
		
	}

	switch (blank_count)
	{

	// action�� �ʿ��� ��ɾ�
	// �бⰡ ���� ��ɾ�
	case 0:
		action = command_action(command);

		if (command == action && (action == ACTION_BACKUP || action == ACTION_EXIT))
			return true;

		else
			return false;
		
	// action, option�� �ʿ��� ��ɾ�
	// �бⰡ �� ���� �ִ� ��ɾ�
	case 1:
		action = command_action(command);
		option = command_option(command);

		if (action == ACTION_DELETE || ACTION_PRINT)
		{
			if (option == OPTION_ROOT || option == OPTION_COPY)
				return true;

			else
				return false;

		}

		else
			return false;
		
	// action, option, directory�� �ʿ��� ��ɾ�
	// �бⰡ �� ���� �ִ� ��ɾ�
	case 2:
		action = command_action(command);
		option = command_option(command);
		directory = command_option(command);

		if (action == ACTION_ADD)
		{
			if (option == OPTION_ROOT || option == OPTION_COPY)
			{
				// �����ϴ� �������� Ȯ��
			}

			else
				return false;

		}

		else
			return false;

	// �бⰡ �� ���̻��� ��ɾ�
	default:
		return false;
	}

	return false;
}

void Command::add(std::string command)
{
	if (command_option(command) == OPTION_ROOT)
	{
		this->ptr_root_manager->add(command_deirectory(command));
	}

	else if(command_option(command) == OPTION_COPY)
	{
		this->ptr_copy_manager->add(command_deirectory(command));
	}
}

void Command::_delete(std::string command)
{
	if (command_option(command) == OPTION_ROOT)
	{
		cout << "[ROOT]" << endl;
		this->ptr_root_manager->_delete();
	}

	else if (command_option(command) == OPTION_COPY)
	{
		cout << "[COPY]" << endl;
		this->ptr_copy_manager->_delete();
	}
}

void Command::print(std::string command)
{
	if (command_option(command) == OPTION_ROOT)
	{
		this->ptr_root_manager->print();
	}

	else if (command_option(command) == OPTION_COPY)
	{
		this->ptr_copy_manager->print();
	}
}

void Command::backup()
{
}

void Command::help()
{
}

void Command::command_system()
{
	while (1)
	{
		string command;
		cout << "[��ɾ�] >> ";
		getline(cin, command);

		if (check_command(command))
			cout << "�ǹٸ� ��ɾ�" << endl;

		else
			cout << "�߸��� ��ɾ�" << endl;

		if (command_action(command) == "exit")
			return;
	}
}

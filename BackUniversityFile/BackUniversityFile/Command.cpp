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
	int blank_index = command.find(" ", option_index + 1);
	
	return command.substr(option_index + 1, blank_index - (option_index + 1));
}

std::string Command::command_directory(const std::string command)
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

	// action만 필요한 명령어
	// 분기가 없는 명령어
	case 0:
		action = command_action(command);

		if (command == action && (action == ACTION_BACKUP || action == ACTION_EXIT))
			return true;

		else
			return false;
		
	// action, option만 필요한 명령어
	// 분기가 한 개만 있는 명령어
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
		
	// action, option, directory만 필요한 명령어
	// 분기가 두 개만 있는 명령어
	case 2:
		action = command_action(command);
		option = command_option(command);
		directory = command_directory(command);

		if (action == ACTION_ADD)
		{
			if (option == OPTION_ROOT || option == OPTION_COPY)
			{
				boost::filesystem::path add_path(directory);

				// 존재하는 폴더인지 확인
				if (boost::filesystem::is_directory(add_path))
					return true;

				else
					return false;
			}

			else
				return false;
		}

		else
			return false;

	// 분기가 세 개이상인 명령어
	default:
		return false;
	}

	return false;
}

void Command::add(std::string command)
{
	if (command_option(command) == OPTION_ROOT)
	{
		this->ptr_root_manager->add(command_directory(command));
	}

	else if(command_option(command) == OPTION_COPY)
	{
		this->ptr_copy_manager->add(command_directory(command));
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
		cout << "[명령어] >> ";
		getline(cin, command);

		if (check_command(command))
		{
			string action = command_action(command);

			if (action == ACTION_ADD)
				add(command);

			else if (action == ACTION_DELETE)
				_delete(command);

			else if (action == ACTION_PRINT)
				print(command);

			else if (action == ACTION_BACKUP)
				backup();

			else if (action == ACTION_HELP)
				help();

			else if (action == ACTION_EXIT)
				return;	
		}

		else
			cout << "잘못된 명령어입니다." << endl;
	}
}

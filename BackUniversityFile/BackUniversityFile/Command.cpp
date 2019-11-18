#include "Command.hpp"

using namespace std;

std::string Command::find_action(const std::string command)
{
	int first_blank_pos = command.find_first_of(" ");
	return command.substr(0, first_blank_pos);
}

std::string Command::find_option(const std::string command)
{
	string copy_command = command.substr(command.find_first_of("-"));
	int option_start_pos = copy_command.find_first_of("-");
	int option_last_pos = copy_command.find_first_of(" ");

	if(option_start_pos <0 || option_start_pos > command.size())
		// -�� ���� �ɼǹ�, �߸��� ��ɾ� ���� �߻�

	return command.substr(option_start_pos, option_last_pos);
}

std::string Command::find_directory(const std::string command)
{
	int last_blank_pos = command.find_last_of(" ");
	return command.substr(last_blank_pos);
}

void Command::add(std::string command)
{
	if (find_option(command) == OPTION_ROOT)
		get_ptr_root_manager()->add(find_directory(command));
	
	
	else if (find_option(command) == OPTION_COPY)
		get_ptr_copy_manager()->add(find_directory(command));	

}

void Command::_delete(std::string command)
{
	if (find_option(command) == OPTION_ROOT)
		get_ptr_root_manager()->_delete();

	else if (find_option(command) == OPTION_COPY)
		get_ptr_copy_manager()->_delete();
}

void Command::print(std::string command)
{
	if (find_option(command) == OPTION_ROOT)
		get_ptr_root_manager()->print();

	else if (find_option(command) == OPTION_COPY)
		get_ptr_copy_manager()->print();
}

void Command::backup()
{
}

void Command::help()
{
	cout << "|---------------��ɾ� ����---------------|" << endl;
	cout << "	action -option directory" << endl;
	cout << "	action -option" << endl;
	cout << "	action" << endl;
	cout << "|---------------action ����---------------|" << endl;
	cout << "	add		: ���� �߰� (+ -option directory)" << endl;
	cout << "	delete	: ���� ���� (+ -option)" << endl;
	cout << "	print	: ���� ��� (+ -option)" << endl;
	cout << "	clear	: ȭ�� û��" << endl;
	cout << "	backup	: ��� ����" << endl;
	cout << "	help	: ���� ���" << endl;
	cout << "	exit	: ���α׷� ����" << endl;
	cout << "|---------------option ����---------------|" << endl;
	cout << "	root	: ���� ���� ���� �߰�" << endl;
	cout << "	copy	: ���� ī�Ǻ� ���� �߰�" << endl;
	cout << endl;
}

void Command::command_system()
{
	string command("");

	while (1)
	{
		getline(cin, command);
		string action = find_action(command);

		if (action == "add")
			add(command);

		else if (action == "delete")
			_delete(command);

		else if (action == "print")
			print(command);

		else if (action == "clear")
			CLEAR();

		else if (action == "backup")
			backup();

		else if (action == "help")
			help();

		else if (action == "exit")
			return;
	}
}




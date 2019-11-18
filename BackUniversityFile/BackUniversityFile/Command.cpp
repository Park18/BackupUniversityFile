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
		// -이 없는 옵션문, 잘못된 명령어 에러 발생

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
	cout << "|---------------명령어 형식---------------|" << endl;
	cout << "	action -option directory" << endl;
	cout << "	action -option" << endl;
	cout << "	action" << endl;
	cout << "|---------------action 모음---------------|" << endl;
	cout << "	add		: 폴더 추가 (+ -option directory)" << endl;
	cout << "	delete	: 폴더 삭제 (+ -option)" << endl;
	cout << "	print	: 폴더 출력 (+ -option)" << endl;
	cout << "	clear	: 화면 청소" << endl;
	cout << "	backup	: 백업 실행" << endl;
	cout << "	help	: 도움말 출력" << endl;
	cout << "	exit	: 프로그램 종료" << endl;
	cout << "|---------------option 모음---------------|" << endl;
	cout << "	root	: 복사 원본 폴더 추가" << endl;
	cout << "	copy	: 복사 카피본 폴더 추가" << endl;
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




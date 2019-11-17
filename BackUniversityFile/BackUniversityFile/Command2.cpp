#include "Command2.h"

using namespace std;

std::string Command2::find_action(const std::string command)
{
	int pos = command.find_first_of(" ");
	return command.substr(0,pos);
}

std::string Command2::find_option(const std::string command)
{
	string copy_command = command.substr(command.find_first_of("-"));
	int option_start_pos = copy_command.find_first_of("-");
	int option_last_pos = copy_command.find_first_of(" ");

	if(option_start_pos <0 || option_start_pos > command.size())
		// 에러 발생

	return command.substr(option_start_pos, option_last_pos);
}

std::string Command2::find_directory(const std::string command)
{


	return std::string();
}


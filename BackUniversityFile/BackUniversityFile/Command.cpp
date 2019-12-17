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
	
	return command.substr(option_index + 2, blank_index - (option_index + 2));
}

std::string Command::command_deirectory(const std::string command)
{
	int option_index = command.find(" -") + 2;
	int blank_index = command.find(" ", option_index);

	return command.substr(blank_index + 1, command.length() - blank_index);
}

bool Command::check_command(const std::string command)
{
	int blank_index = command.find(" ");
	if (blank_index != -1)
	return false;
}


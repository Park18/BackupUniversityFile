#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "Route.h"

using namespace std;

class Command
{
private:
	route::Subject* subject;

public:
	void setSubject() { this->subject = new route::Subject(); }
	route::Subject* getSubject() { return this->subject; }

	std::string findAction(std::string command);

	std::string findSubject(std::string command);

	std::string findElement(std::string command);

	bool findOption(std::string command);

	void clear();

	void _exit();

	void add(std::string command);

	void _delete(std::string command);

	void print(std::string command);

	int getUserIndex();
};


#endif // !COMMAND


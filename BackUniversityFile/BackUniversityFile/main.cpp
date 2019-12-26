// directory_test
//#include <boost\filesystem.hpp>
//#include <iostream>
//#include <string>
//#include <vector>

// Test.hpp
#include "Test.hpp"

#include <iostream>
#include <string>

#include "Directory_Manager.hpp"
#include "Command.hpp"


using namespace std;

void test1();
void command_test();
void directory_test();

int main()
{
	//directory_test();
	command_test();
	//test1();
}

void test1()
{	
	ofstream write_file("path\\test.txt");

	if (write_file.is_open())
	{
		write_file << "hello" << endl;
		write_file.close();
	}

	else
		cout << "파일 열기 실패" << endl;
}

void command_test()
{
	Command command;
	command.command_system();

}

void directory_test()
{
	string root_dir = "test1//";
	boost::filesystem::path p(root_dir);

	vector<boost::filesystem::path> dir;

	long dir_cnt = 0;

	if (boost::filesystem::is_directory(p))
	{
		cout << "디렉토리" << endl;
	}

	else
	{
		cout << "디렉토리 아님" << endl;
	}
}
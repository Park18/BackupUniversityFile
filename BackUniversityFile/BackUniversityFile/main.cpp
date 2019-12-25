//#include <boost\filesystem.hpp>
//#include <boost\foreach.hpp>
//#include <boost\filesystem\path.hpp>
//#include <boost/lexical_cast.hpp>

// directory_test
#include <boost\filesystem.hpp>
#include <iostream>
#include <string>
#include <vector>

//#include <iostream>
//#include <string>

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
}

void test1()
{	
	const boost::filesystem::path path("c:\\users");

	BOOST_FOREACH(const boost::filesystem::path & p,
		std::make_pair(boost::filesystem::recursive_directory_iterator(path),
		boost::filesystem::recursive_directory_iterator()))
	{
		if (!boost::filesystem::is_directory(p))
		{
			std::cout << p << std::endl;
		}
	}
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
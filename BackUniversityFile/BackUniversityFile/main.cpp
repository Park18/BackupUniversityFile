#include <boost\filesystem.hpp>
#include <boost\foreach.hpp>
#include <boost\filesystem\path.hpp>

#include <iostream>
#include <string>

#include "Directory_Manager.hpp"
#include "Command.hpp"


using namespace std;


int main()
{
	/*
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
	*/
	
	/*
	boost::filesystem::path my_dir("c:/library");
	cout << boost::filesystem::is_directory(my_dir) << endl;
	*/

	Command command;
	//cout<<  command.command_option("print -root");
	command.command_system();

}

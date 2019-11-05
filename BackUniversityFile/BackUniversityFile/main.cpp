#include "RootManager.h"

#include <boost\filesystem.hpp>
#include <boost\foreach.hpp>

using namespace std;

void rootTest();

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
	
	rootTest();
}

void rootTest()
{
	RootManager rootManager;

	rootManager.checkRoot();
}
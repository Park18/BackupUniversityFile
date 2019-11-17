#include "Directory_Manager.hpp"

using namespace std;

void Base_Directory_Manager::set_backup()
{
	ofstream write_file(ROOT_DIRECTORY_FILE);

	BOOST_FOREACH(string directory, (*get_ptr_directory()))
		write_file << directory << endl;

	write_file.close();
}

void Base_Directory_Manager::get_backup()
{
	ifstream read_file(ROOT_DIRECTORY_FILE);

	if (read_file.is_open())
	{
		string root_directory;
		while (read_file.peek() != EOF)
		{
			getline(read_file, root_directory);
			add(root_directory);
		}
	}

	else
	{
		cout << "lost root_directory" << endl;
		exit(0);
	}
}

void Base_Directory_Manager::add(std::string root_directory)
{
	if (IS_HAVE_DIRETORY(root_directory))
		get_ptr_directory()->push_back(root_directory);

	else
		cout << "error, not folder!" << endl;
}

void Base_Directory_Manager::_delete()
{
	cout << "********************delete********************" << endl;
	print();

	while (1)
	{
		int index = 0;
		cout << "input delte index : ";
		cin >> index;

		if (index < 0)
			cout << "pls enter the number bigger than 0" << endl;

		else if (index > get_directory_size())
			cout << "pls enther the number samller than " << get_directory_size() << endl;

		else
			break;
	}

	cout << "********************delete********************" << endl;
}

void Base_Directory_Manager::print()
{
	cout << "**************my root directory***************" << endl;

	for (int index = 0; index < get_directory_size(); index++)
		cout << "[" << index << "]" << (*get_ptr_directory())[index] << endl;

	cout << "**************my root directory***************" << endl;
}

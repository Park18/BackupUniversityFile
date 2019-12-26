#include "Directory_Manager.hpp"

using namespace std;

// Example set_backup()
/*
void Base_Directory_Manager::set_backup()
{
	ofstream write_file("exapmle.txt");

	BOOST_FOREACH(string directory, (*get_ptr_directory()))
		write_file << directory << endl;

	write_file.close();
}
*/

// Example get_backup()
/*
void Base_Directory_Manager::get_backup()
{
	ifstream read_file("example.txt");

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
*/


void Base_Directory_Manager::add(std::string root_directory)
{
	get_ptr_directory()->push_back(root_directory);
}

void Base_Directory_Manager::_delete()
{
	if (this->ptr_directory->empty())
	{
		cout << "[알림] : 비어있습니다." << endl << endl;
		return;
	}

	cout << "[삭제]" << endl;
	print();

	while (1)
	{
		int index = 0;
		cout << "[삭제할 번호] >> ";
		cin >> index;

		if (index < 0 || index > this->ptr_directory->size())
			cout << "[알림] : 잘못된 값이 입력됬습니다." << endl << endl;

		else
		{
			this->ptr_directory->erase(this->ptr_directory->begin() + index);
			
			// cin 버퍼 초기화
			// 초기화 이유 command_system의 버퍼가 남아서 잘못된 명령어로 인식됨
			cin.ignore();
			return;
		}
	}
}

void Base_Directory_Manager::print()
{
	if (ptr_directory->empty())
	{
		cout << "[알림] : 비어있습니다." << endl;
		return;
	}

	cout << "[출력]" << endl;

	for (int index = 0; index < get_directory_size(); index++)
		cout << "[" << index << "] : " << (*get_ptr_directory())[index] << endl;

	cout << endl;
}

void Copy_Directory_Manager::set_backup()
{
	ofstream write_file(COPY_DIRECTORY_FILE);

	BOOST_FOREACH(string directory, (*get_ptr_directory()))
		write_file << directory << endl;

	write_file.close();
}

void Copy_Directory_Manager::get_backup()
{
	ifstream read_file(COPY_DIRECTORY_FILE);

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
		cout << "[알림] : <Copy Directory> 백업된 파일을 찾을 수 없습니다. 파일을 재생성합니다." << endl;
		
		// 파일 재생성하는 코드
		boost::filesystem::path backup_directory("path");
		
		if (boost::filesystem::exists(backup_directory))
		{
			ofstream write_file(COPY_DIRECTORY_FILE);
			write_file.close();
		}

		else
		{
			boost::filesystem::create_directory(backup_directory);
			ofstream write_file(COPY_DIRECTORY_FILE);
			write_file.close();
		}

		//exit(0);
	}
}


void Root_Directory_Manager::set_backup()
{
	ofstream write_file(ROOT_DIRECTORY_FILE);

	BOOST_FOREACH(string directory, (*get_ptr_directory()))
		write_file << directory << endl;

	write_file.close();
}

void Root_Directory_Manager::get_backup()
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
		cout << "[알림] : <Root Directory> 백업된 파일을 찾을 수 없습니다. 파일을 재생성합니다." << endl;
		
		// 파일 재생성하는 코드
		boost::filesystem::path backup_directory("path");

		if (boost::filesystem::exists(backup_directory))
		{
			ofstream write_file(COPY_DIRECTORY_FILE);
			write_file.close();
		}

		else
		{
			boost::filesystem::create_directory(backup_directory);
			ofstream write_file(COPY_DIRECTORY_FILE);
			write_file.close();
		}

		//exit(0);
	}
}

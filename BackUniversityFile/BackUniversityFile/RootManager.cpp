#include "RootManager.h"

using namespace std;
namespace filesystem = boost::filesystem;

//*********************************************************************************
//  vector에 저장된 root 폴더를 txt 파일에 백업하는 메소드
//*********************************************************************************
void RootManager::setBackup()
{
	ofstream writeFile(BACKUPROOTFILE);

	for (int index = 0; index < getPtrRootManager()->size(); index++)
		writeFile << (*getPtrRootManager())[index] << endl;

	writeFile.close();
}

//*********************************************************************************
// txt 파일에 백업된 root 폴더를 vector에 저장하는 메소드
//*********************************************************************************
void RootManager::getBackup()
{
	ifstream readFile(BACKUPROOTFILE);

	if (readFile.is_open())
	{
		string root;
		while (readFile.peek() != EOF)
		{
			getline(readFile, root);
			add(root);
		}
	}

	else
	{
		cout << "파일을 열지 못했습니다." << endl;
		exit(0);
	}
}

//*********************************************************************************
// vector에 저장된 root 폴더가 실제 존재하는 폴더인지 확인하는 메소드
//
// - 19.11.05
// - 재귀적인 방법으로 모든 파일과 폴더를 확인하여 일치하는 항목이 있는지 검사한다.
// - 해당 메소드에선 디렉토리만 확인하면 되므로 비효율적이다.
// - 디렉토리만 찾는 boost 라이브러리를 찾아 바꿀것.
//*********************************************************************************
void RootManager::checkRoot()
{
	for (int index = 0; index < getPtrRootManager()->size(); index++)
	{
		string root = (*getPtrRootManager())[index];
		filesystem::path path(upperRoot(root));

		BOOST_FOREACH(const filesystem::path& folderName,
			std::make_pair(filesystem::recursive_directory_iterator(path),
				filesystem::recursive_directory_iterator()))
		{
			if (root == folderName)
			{
				cout << "일치 항목을 찾았습니다." << endl;
				cout << folderName << endl;
				break;
			}
		}
	}


}

//*********************************************************************************
// root 폴더의 상위 폴더를 반환하는 메소드
//*********************************************************************************
std::string RootManager::upperRoot(std::string root)
{
	string upperRoot(root.substr(0, root.find_last_of("\\")));

	if (upperRoot.find_first_of("\\") > upperRoot.length())
		upperRoot.append("\\");

	return upperRoot;
}

//*********************************************************************************
// root 폴더를 vector에 저장하는 메소드
//*********************************************************************************
void RootManager::add(std::string root)
{
	getPtrRootManager()->push_back(root);
}

//*********************************************************************************
// vector에 저장된 root 폴더를 삭제하는 메소드
//*********************************************************************************
void RootManager::_delete()
{
	print();

	int index;
	cout << "삭제 할 인덱스를 입력해주세요" << endl;
	cout << "index : ";
	cin >> index;

	getPtrRootManager()->erase(getPtrRootManager()->begin() + index);
}

//*********************************************************************************
// root 폴더를 출력하는 메소드
//*********************************************************************************
void RootManager::print()
{
	cout << "---------------------삭제----------------------" << endl;

	for (int index = 0; index < getPtrRootManager()->size(); index++)
		cout << index << " : " << (*getPtrRootManager())[index] << endl;

	cout << "-----------------------------------------------" << endl;
}

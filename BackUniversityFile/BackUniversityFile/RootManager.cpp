#include "RootManager.h"

using namespace std;

void RootManager::setBackup()
{
	ofstream writeFile(BACKUPROOTFILE);

	for (int index = 0; index < getPtrRootManager()->size(); index++)
		writeFile << (*getPtrRootManager())[index] << endl;

	writeFile.close();
}

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

void RootManager::add(std::string root)
{
	getPtrRootManager()->push_back(root);
}

void RootManager::_delete()
{
	print();

	int index;
	cout << "삭제 할 인덱스를 입력해주세요" << endl;
	cout << "index : ";
	cin >> index;

	getPtrRootManager()->erase(getPtrRootManager()->begin() + index);
}

void RootManager::print()
{
	cout << "---------------------삭제----------------------" << endl;

	for (int index = 0; index < getPtrRootManager()->size(); index++)
		cout << index << " : " << (*getPtrRootManager())[index] << endl;

	cout << "-----------------------------------------------" << endl;
}

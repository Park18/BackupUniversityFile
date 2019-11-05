#include "RootManager.h"

using namespace std;
namespace filesystem = boost::filesystem;

//*********************************************************************************
//  vector�� ����� root ������ txt ���Ͽ� ����ϴ� �޼ҵ�
//*********************************************************************************
void RootManager::setBackup()
{
	ofstream writeFile(BACKUPROOTFILE);

	for (int index = 0; index < getPtrRootManager()->size(); index++)
		writeFile << (*getPtrRootManager())[index] << endl;

	writeFile.close();
}

//*********************************************************************************
// txt ���Ͽ� ����� root ������ vector�� �����ϴ� �޼ҵ�
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
		cout << "������ ���� ���߽��ϴ�." << endl;
		exit(0);
	}
}

//*********************************************************************************
// vector�� ����� root ������ ���� �����ϴ� �������� Ȯ���ϴ� �޼ҵ�
//
// - 19.11.05
// - ������� ������� ��� ���ϰ� ������ Ȯ���Ͽ� ��ġ�ϴ� �׸��� �ִ��� �˻��Ѵ�.
// - �ش� �޼ҵ忡�� ���丮�� Ȯ���ϸ� �ǹǷ� ��ȿ�����̴�.
// - ���丮�� ã�� boost ���̺귯���� ã�� �ٲܰ�.
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
				cout << "��ġ �׸��� ã�ҽ��ϴ�." << endl;
				cout << folderName << endl;
				break;
			}
		}
	}


}

//*********************************************************************************
// root ������ ���� ������ ��ȯ�ϴ� �޼ҵ�
//*********************************************************************************
std::string RootManager::upperRoot(std::string root)
{
	string upperRoot(root.substr(0, root.find_last_of("\\")));

	if (upperRoot.find_first_of("\\") > upperRoot.length())
		upperRoot.append("\\");

	return upperRoot;
}

//*********************************************************************************
// root ������ vector�� �����ϴ� �޼ҵ�
//*********************************************************************************
void RootManager::add(std::string root)
{
	getPtrRootManager()->push_back(root);
}

//*********************************************************************************
// vector�� ����� root ������ �����ϴ� �޼ҵ�
//*********************************************************************************
void RootManager::_delete()
{
	print();

	int index;
	cout << "���� �� �ε����� �Է����ּ���" << endl;
	cout << "index : ";
	cin >> index;

	getPtrRootManager()->erase(getPtrRootManager()->begin() + index);
}

//*********************************************************************************
// root ������ ����ϴ� �޼ҵ�
//*********************************************************************************
void RootManager::print()
{
	cout << "---------------------����----------------------" << endl;

	for (int index = 0; index < getPtrRootManager()->size(); index++)
		cout << index << " : " << (*getPtrRootManager())[index] << endl;

	cout << "-----------------------------------------------" << endl;
}

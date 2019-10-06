#pragma once
#ifndef BACKUPUNIVERSITYFILE_H
#define BACKUPUNIVERSITYFILE_H

#include "Subject.h"
namespace phw
{

class BackupUniversityFile
{
private:
	phw::Subject* ptrSubject;
	std::string action;
	//int option;
	std::string mainAgent;
	std::string element;

public:
	void setPtrSubject() { this->ptrSubject = new phw::Subject(); }
	phw::Subject* getPtrSubject() { return ptrSubject; }

	/**
	 * �Է¹��� ��ɾ�� action�� ��ȯ�ϴ� �޼���
	 */
	std::string findAction(std::string command);

	/**
	 * �Է¹��� ��ɾ�� subject�� ��ȯ�ϴ� �޼���
	 */
	std::string findSubject(std::string command);

	/**
	 * �Է¹��� ��ɾ�� element�� ��ȯ�ϴ� �޼���
	 */
	std::string findElement(std::string command);

	/**
	 * ��ɾ� ��Ȱ �޼���
	 */
	void ramifyCommand(std::string command);

	/**
	 * �ɼ� Ȯ�� �޼���
	 */
	bool isOption(std::string command);

	/**
	 * �߰� ��ɾ� �޼���
	 */
	void add(bool option, std::string subject, std::string element);

	/**
	 * ���� ��ɾ� �޼���
	 */
	void _delete(bool option, std::string subject, int index);

	/**
	 * ��� ��ɾ� �޼���
	 */
	void print(bool option, std::string subject);

	/**
	 * ȭ�� û�� ��ɾ� �޼���
	 */
	void clear();

	/**
	 * main �޼���
	 */
	void backupUniversityFile();

	// test
	void testFolderRoute();
	void testSubject();
};

} // !namespace pwh

#endif // !BACKUPUNIVERSITYFILE_H
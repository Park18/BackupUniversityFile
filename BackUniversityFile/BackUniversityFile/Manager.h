#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include "Subject.h"

namespace phw
{

/***
 * ����ڿ��� ��ɾ �Է¹޾� ����/��θ� �����ϴ� Ŭ����
 */
class Manager
{
private:
	phw::Subject* ptrSubject;

public:
	Manager() { setPtrSubject(); }
	~Manager() { delete getPtrSubject(); }

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
	 * �ɼ� Ȯ�� �޼���
	 */
	bool isOption(std::string command);

	/**
	 * �߰� ��ɾ� �޼���
	 */
	void add(bool isOption, std::string subject, std::string element);

	/**
	 * ȭ�� û�� ��ɾ� �޼���
	 */
	void clear();
};

}// !namespace phw

#endif // !MANAGER_H
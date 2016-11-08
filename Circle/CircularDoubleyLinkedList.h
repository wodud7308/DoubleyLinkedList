#pragma once
#include "DoubleyLinkedList.h"
class CircularDoubleyLinkedList : public DoubleyLinkedList
{
public:

	virtual void SearchHead(int num);		//head���� num��° �����ͱ��� Ž��
	virtual void SearchTail(int num);		//tail���� num��° �����ͱ��� Ž��

	virtual void AddTail(int data);	//���κп� ��� ����
	virtual void AddHead(int data);	//ù�κп� ��� ����

	virtual void Delete(int num);		//num��° ������ ����
	virtual void Delete(int data, int num);		//data���� ���� ��带 num�� ����

	virtual void GetNode();		//��ü �տ��� ���� ������ ���
	virtual void GetNode(int num);	//num��° ������ ���
public:
	CircularDoubleyLinkedList() = default;
	~CircularDoubleyLinkedList();
};


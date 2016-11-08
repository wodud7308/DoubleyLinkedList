#pragma once
#include "Header.h"
class DoubleyLinkedList
{
protected:

	Node * _head;		//ù ���
	Node * _tail;		//������ ���
	Node * _end;			//���� �˷��ִ� ���(������ NULL, end->next = nulptr) 
	Node * _iter;		//������ ���
	int _size;

protected:
	
	Node * NewNode();	//�� ��� �Ҵ� �Լ�
	bool IsEmpty();		//��� ���� �Ǵ� �Լ�
	void DeleteData();
	void ResetHead(int data);	//head �ʱ�ȭ �Լ�

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
	void Delete(Node * node);	//node�� ���� ������ ����
	void SearchTail(Node * node);	//tail���� node�� ���� ������ Ž��
	void SearchHead(Node * node);	//head���� node�� ���� ������ Ž��
public:

	DoubleyLinkedList() = default;
	~DoubleyLinkedList();
};

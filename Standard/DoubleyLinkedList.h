#pragma once
#include "Header.h"
class DoubleyLinkedList
{
protected:

	Node * _head;		//첫 노드
	Node * _tail;		//마지막 노드
	Node * _end;			//끝을 알려주는 노드(데이터 NULL, end->next = nulptr) 
	Node * _iter;		//현재의 노드
	int _size;

protected:
	
	Node * NewNode();	//새 노드 할당 함수
	bool IsEmpty();		//노드 유무 판단 함수
	void DeleteData();
	void ResetHead(int data);	//head 초기화 함수

public:
	virtual void SearchHead(int num);		//head부터 num번째 데이터까지 탐색
	virtual void SearchTail(int num);		//tail부터 num번째 데이터까지 탐색

	virtual void AddTail(int data);	//끝부분에 노드 삽입
	virtual void AddHead(int data);	//첫부분에 노드 삽입

	virtual void Delete(int num);		//num번째 데이터 삭제
	virtual void Delete(int data, int num);		//data값이 같은 노드를 num개 삭제

	virtual void GetNode();		//전체 앞에서 부터 데이터 출력
	virtual void GetNode(int num);	//num번째 데이터 출력

public:
	void Delete(Node * node);	//node와 같은 데이터 삭제
	void SearchTail(Node * node);	//tail부터 node와 같은 데이터 탐색
	void SearchHead(Node * node);	//head부터 node와 같은 데이터 탐색
public:

	DoubleyLinkedList() = default;
	~DoubleyLinkedList();
};

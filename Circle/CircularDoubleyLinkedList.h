#pragma once
#include "DoubleyLinkedList.h"
class CircularDoubleyLinkedList : public DoubleyLinkedList
{
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
	CircularDoubleyLinkedList() = default;
	~CircularDoubleyLinkedList();
};


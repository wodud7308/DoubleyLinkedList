#include "Header.h"
#include "CircularDoubleyLinkedList.h"

void CircularDoubleyLinkedList::AddHead(int data)
{
	if (IsEmpty())
	{
		ResetHead(data);	//_head에 아무것도 없으면 초기화
	}
	else
	{
		Node * temp = _head;		//_head를 임시 변수에 저장
		_head = NewNode();		//_head에 새 노드 할당
		_head->set_data(data);	//_head 노드에 데이터 저장
		_head->set_next(temp);	//임시변수를 _head 뒤에 연결
		temp->set_prev(_head);	//연결한 노드의 앞에 _head 연결
		_head->set_prev(_tail);	//_head의 앞에 _tail노드 연결
		_tail->set_next( _head);	//_tail의 다음 _head를 갱신
	}
}

void CircularDoubleyLinkedList::AddTail(int data)
{
	if (IsEmpty())			//_head에 아무것도 없으면 초기화
	{
		ResetHead(data);
	}
	else
	{
		_tail->set_next(NewNode());	//_tail 노드의 다음에 새 노드 할당
		_tail->GetNext()-> set_prev( _tail);//새로 할당한 노드의 앞에 그 전 _tail 노드 연결
		_tail = _tail->GetNext();		//tail의 위치를 기존의 다음 노드로 갱신
		_tail-> set_data(data);		//갱신된 _tail노드에 데이터 할당
		_tail->set_next(_head);		//_tail의 다음 _head를 갱신
		_head->set_prev(_tail);		//_head의 앞에 _tail노드 연결
	}
}

void CircularDoubleyLinkedList::SearchHead(int num)
{
	_iter = _head;
	for (int repeat = 0; repeat < num - 1; repeat++)
	{
		_iter = _iter->GetNext();	//정해진 횟수 만큼 탐색해 현재 노드 위치 갱신
	}
}

void CircularDoubleyLinkedList::SearchTail(int num)
{
	_iter = _tail;
	for (int repeat = 0; repeat < num - 1; repeat++)
	{
		_iter = _iter->GetPrev();	//정해진 횟수 만큼 탐색
	}
}

void CircularDoubleyLinkedList::Delete(int num)
{
	if (IsEmpty())
	{
		return;		//지울 데이터가 없으면 종료
	}
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
	}
	else 
	{
		SearchHead(num);
		DeleteData();
	}
	_size--;					//지운 노드 개수만큼 _size 감소
}

void CircularDoubleyLinkedList::Delete(int data, int num)
{
	if (IsEmpty())
	{
		return;		//지울 데이터가 없으면 종료
	}
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_size--;
	}
	else {
		for (int repeat = 0; repeat < num; repeat++)//num횟수만큼 반복
		{
			_iter = _head;
			while (!(_iter->GetData() == data))
			{
				if (_iter->GetNext() == _head)
				{
					cout << repeat << "개 데이터 삭제, 같은 데이터 없음" << endl;
					return;
				}
				_iter = _iter->GetNext();
			}
			DeleteData();
			_size--;					//지운 노드 개수만큼 _size 감소
		}
	}
	cout << num << "개 데이터 삭제" << endl;
}

void CircularDoubleyLinkedList::GetNode() 
{
	if (IsEmpty())
	{
		cout << "데이터가 없습니다." << endl;
		return;
	}
	_iter = _head;
	do 	//처음을 제외하고 현재 노드의 앞이_tail노드(마지막)까지 반복
	{
		cout << _iter->GetData() << endl;
		_iter = _iter->GetNext();
	} while (_iter->GetPrev() != _tail);
}

void CircularDoubleyLinkedList::GetNode(int num)
{
	if(num > _size)
	{
		cout << "해당 번호보다 전체 데이터가 적습니다." << endl;
		return;
	}
	if (IsEmpty())
	{
		cout << "데이터가 없습니다." << endl;
		return;
	}
	if (_head == _tail)
	{
		cout << _head->GetData() << endl;
		return;
	}
	SearchHead(num);
	cout << _iter->GetData() << endl;
}

CircularDoubleyLinkedList::~CircularDoubleyLinkedList()
{
}

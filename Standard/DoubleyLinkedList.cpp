#include "DoubleyLinkedList.h"

Node * DoubleyLinkedList::NewNode()		//새 노드 할당
{
	Node * temp = new Node();	//임시 변수 temp에 새 노드 할당
	_size++;					//연결된 데이터의 개수 증가
	return temp;				//할당한 노드를 반환
}

bool DoubleyLinkedList::IsEmpty()	//노드의 유무 판단 함수
{
	if (_head == NULL)	//_head가 비어있으면 
		return true;	//true 반환
	else
		return false;	//비어있지 않으면 false 반환
}

void DoubleyLinkedList::ResetHead(int _data)	//_head 초기화 함수
{
	_head = NewNode();			//_head에 새 노드 할당
	_tail = _head;				//처음노드는 _head와 _tail이 같음
	_tail-> set_next(_end);			//_tail의 다음에 끝을 알려주는 _end 연결
	_head-> set_data(_data);			//_head의 데이터에 입력값 저장
}

void DoubleyLinkedList::SearchHead(Node * object)
{
	_iter = _head;
	while (!(_iter-> GetData() == object->GetData()))
	{
		if (_iter->GetNext() == _end)
		{
			return;
		}
		_iter = _iter->GetNext();	//그 노드의 데이터 비교후 위치 갱신
	}
}

void DoubleyLinkedList::SearchHead(int num)
{
	_iter = _head;
	for (int repeat = 0; repeat < num - 1; repeat++)
	{
		if (_iter->GetNext() == _end)
		{
			return;
		}
		_iter = _iter->GetNext();	//정해진 횟수 만큼 탐색해 현재 노드 위치 갱신
	}
}

void DoubleyLinkedList::SearchTail(Node * object)
{
	_iter = _tail;
	while (!(_iter->GetData() == object->GetData()))
	{
		if (_iter->GetNext() == _end)
		{
			return;
		}
		_iter = _iter->GetPrev();	//그 노드의 데이터 비교 후 위치 갱신
	}
}

void DoubleyLinkedList::SearchTail(int num)
{
	_iter = _tail;
	for (int repeat = 0; repeat < num - 1; repeat++)
	{
		if (_iter->GetNext() == _end)
		{
			return;
		}
		_iter = _iter->GetPrev();	//정해진 횟수 만큼 탐색
	}
}

void DoubleyLinkedList::AddHead(int data)
{
	if (IsEmpty())
	{
		ResetHead(data);	//_head에 아무것도 없으면 초기화
	}
	else
	{
		Node * temp = _head;	//기존 _head 노드 저장
		_head = NewNode();	//_head에 새 노드 할당
		_head-> set_data(data); //입력 받은 데이터를 저장
		_head-> set_next(temp);	//_head뒤에 저장된 노드 연결
		temp-> set_prev(_head);//_head의 다음 노드의 앞에 _head를 연결
	}
}
                                                                                                       
void DoubleyLinkedList::AddTail(int data)
{
	if (IsEmpty())
	{
		ResetHead(data);
	}
	else 
	{
		_tail-> set_next(NewNode());	//_tail 노드의 다음에 새 노드 할당
		_tail-> GetNext()->set_prev( _tail);//새로 할당한 노드의 앞에 그 전 _tail 노드 연결
		_tail = _tail->GetNext();		//tail의 위치를 기존의 다음 노드로 갱신
		_tail->set_data(data);		//갱신된 _tail노드에 데이터 할당
		_tail->set_next(_end);		//_tail노드 next에 끝을 알리는 _end 저장
	}
}

void DoubleyLinkedList::DeleteData()
{
	if (_iter == _head && _iter != _tail)//지울 노드가 _head이고 _tail이 아닐 때
	{
		_head = _iter->GetNext();	//_head의 다음 노드를 _head로 갱신
		_head->set_prev(_end);	//앞의 노드가 없다는 의미로 _end 저장
		delete _iter;
	}
	else if (_iter != _head && _iter == _tail)//지울 노드가 _tail이고 _head가 아닐 때
	{
		_tail = _iter->GetPrev();	//_tail의 이전 노드를 _tail로 갱신
		_tail->set_next(_end);	//뒤의 노드가 없다는 의미로 _end 저장
		delete _iter;
	}
	else if (!(_iter == _head && _iter == _tail)) //지울 노드가 중간에 있을 때
	{
		Node * temp = _iter->GetNext();	//iter의 next를 임시 변수로 지정
		temp->set_prev(_iter->GetPrev());	//임시변수의 prev에 현재 노드의 prev를 연결
		_iter->GetPrev()->set_next(temp);	//iter의 앞 노드의 next에 임시변수 연결
		delete _iter;				//현재 노드 삭제
		_iter = temp;				//지운 노드의 다음 노드를 현재로 갱신
	}
}

void DoubleyLinkedList::Delete(int num)
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

void DoubleyLinkedList::Delete(int data, int num)
{
	if (IsEmpty())
	{
		return;		//지울 데이터가 없으면 종료
	}

	if (num > _size)
	{
		cout << "해당 번호보다 전체 데이터가 적습니다." << endl;
		return;
	}
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_size--;
	}
	else
	{
		for (int repeat = 0; repeat < num; repeat++)//num횟수만큼 반복
		{
			_iter = _head;

			while (!(_iter->GetData() == data))
			{
				if (_iter->GetNext() == _end)
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

void DoubleyLinkedList::Delete(Node * object)
{
	if (IsEmpty())
	{
		return;			//지울 데이터가 없으면 종료
	}
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
	}
	else
	{
		SearchHead(object);
		DeleteData();
	}
	_size--;					//지운 노드 개수만큼 _size 감소
}

void DoubleyLinkedList::GetNode()
{
	if (IsEmpty())
	{
		cout << "데이터가 없습니다." << endl;
		return;
	}
	_iter = _head;
	while (_iter != _end)
	{
		cout << _iter->GetData() << endl;
		_iter = _iter->GetNext();
	}
}

void DoubleyLinkedList::GetNode(int num)
{
	if (num > _size)
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

DoubleyLinkedList::~DoubleyLinkedList()
{
}
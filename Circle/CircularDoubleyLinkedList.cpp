#include "Header.h"
#include "CircularDoubleyLinkedList.h"

void CircularDoubleyLinkedList::AddHead(int data)
{
	if (IsEmpty())
	{
		ResetHead(data);	//_head�� �ƹ��͵� ������ �ʱ�ȭ
	}
	else
	{
		Node * temp = _head;		//_head�� �ӽ� ������ ����
		_head = NewNode();		//_head�� �� ��� �Ҵ�
		_head->set_data(data);	//_head ��忡 ������ ����
		_head->set_next(temp);	//�ӽú����� _head �ڿ� ����
		temp->set_prev(_head);	//������ ����� �տ� _head ����
		_head->set_prev(_tail);	//_head�� �տ� _tail��� ����
		_tail->set_next( _head);	//_tail�� ���� _head�� ����
	}
}

void CircularDoubleyLinkedList::AddTail(int data)
{
	if (IsEmpty())			//_head�� �ƹ��͵� ������ �ʱ�ȭ
	{
		ResetHead(data);
	}
	else
	{
		_tail->set_next(NewNode());	//_tail ����� ������ �� ��� �Ҵ�
		_tail->GetNext()-> set_prev( _tail);//���� �Ҵ��� ����� �տ� �� �� _tail ��� ����
		_tail = _tail->GetNext();		//tail�� ��ġ�� ������ ���� ���� ����
		_tail-> set_data(data);		//���ŵ� _tail��忡 ������ �Ҵ�
		_tail->set_next(_head);		//_tail�� ���� _head�� ����
		_head->set_prev(_tail);		//_head�� �տ� _tail��� ����
	}
}

void CircularDoubleyLinkedList::SearchHead(int num)
{
	_iter = _head;
	for (int repeat = 0; repeat < num - 1; repeat++)
	{
		_iter = _iter->GetNext();	//������ Ƚ�� ��ŭ Ž���� ���� ��� ��ġ ����
	}
}

void CircularDoubleyLinkedList::SearchTail(int num)
{
	_iter = _tail;
	for (int repeat = 0; repeat < num - 1; repeat++)
	{
		_iter = _iter->GetPrev();	//������ Ƚ�� ��ŭ Ž��
	}
}

void CircularDoubleyLinkedList::Delete(int num)
{
	if (IsEmpty())
	{
		return;		//���� �����Ͱ� ������ ����
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
	_size--;					//���� ��� ������ŭ _size ����
}

void CircularDoubleyLinkedList::Delete(int data, int num)
{
	if (IsEmpty())
	{
		return;		//���� �����Ͱ� ������ ����
	}
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_size--;
	}
	else {
		for (int repeat = 0; repeat < num; repeat++)//numȽ����ŭ �ݺ�
		{
			_iter = _head;
			while (!(_iter->GetData() == data))
			{
				if (_iter->GetNext() == _head)
				{
					cout << repeat << "�� ������ ����, ���� ������ ����" << endl;
					return;
				}
				_iter = _iter->GetNext();
			}
			DeleteData();
			_size--;					//���� ��� ������ŭ _size ����
		}
	}
	cout << num << "�� ������ ����" << endl;
}

void CircularDoubleyLinkedList::GetNode() 
{
	if (IsEmpty())
	{
		cout << "�����Ͱ� �����ϴ�." << endl;
		return;
	}
	_iter = _head;
	do 	//ó���� �����ϰ� ���� ����� ����_tail���(������)���� �ݺ�
	{
		cout << _iter->GetData() << endl;
		_iter = _iter->GetNext();
	} while (_iter->GetPrev() != _tail);
}

void CircularDoubleyLinkedList::GetNode(int num)
{
	if(num > _size)
	{
		cout << "�ش� ��ȣ���� ��ü �����Ͱ� �����ϴ�." << endl;
		return;
	}
	if (IsEmpty())
	{
		cout << "�����Ͱ� �����ϴ�." << endl;
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

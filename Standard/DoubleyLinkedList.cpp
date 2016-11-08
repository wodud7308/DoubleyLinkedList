#include "DoubleyLinkedList.h"

Node * DoubleyLinkedList::NewNode()		//�� ��� �Ҵ�
{
	Node * temp = new Node();	//�ӽ� ���� temp�� �� ��� �Ҵ�
	_size++;					//����� �������� ���� ����
	return temp;				//�Ҵ��� ��带 ��ȯ
}

bool DoubleyLinkedList::IsEmpty()	//����� ���� �Ǵ� �Լ�
{
	if (_head == NULL)	//_head�� ��������� 
		return true;	//true ��ȯ
	else
		return false;	//������� ������ false ��ȯ
}

void DoubleyLinkedList::ResetHead(int _data)	//_head �ʱ�ȭ �Լ�
{
	_head = NewNode();			//_head�� �� ��� �Ҵ�
	_tail = _head;				//ó������ _head�� _tail�� ����
	_tail-> set_next(_end);			//_tail�� ������ ���� �˷��ִ� _end ����
	_head-> set_data(_data);			//_head�� �����Ϳ� �Է°� ����
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
		_iter = _iter->GetNext();	//�� ����� ������ ���� ��ġ ����
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
		_iter = _iter->GetNext();	//������ Ƚ�� ��ŭ Ž���� ���� ��� ��ġ ����
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
		_iter = _iter->GetPrev();	//�� ����� ������ �� �� ��ġ ����
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
		_iter = _iter->GetPrev();	//������ Ƚ�� ��ŭ Ž��
	}
}

void DoubleyLinkedList::AddHead(int data)
{
	if (IsEmpty())
	{
		ResetHead(data);	//_head�� �ƹ��͵� ������ �ʱ�ȭ
	}
	else
	{
		Node * temp = _head;	//���� _head ��� ����
		_head = NewNode();	//_head�� �� ��� �Ҵ�
		_head-> set_data(data); //�Է� ���� �����͸� ����
		_head-> set_next(temp);	//_head�ڿ� ����� ��� ����
		temp-> set_prev(_head);//_head�� ���� ����� �տ� _head�� ����
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
		_tail-> set_next(NewNode());	//_tail ����� ������ �� ��� �Ҵ�
		_tail-> GetNext()->set_prev( _tail);//���� �Ҵ��� ����� �տ� �� �� _tail ��� ����
		_tail = _tail->GetNext();		//tail�� ��ġ�� ������ ���� ���� ����
		_tail->set_data(data);		//���ŵ� _tail��忡 ������ �Ҵ�
		_tail->set_next(_end);		//_tail��� next�� ���� �˸��� _end ����
	}
}

void DoubleyLinkedList::DeleteData()
{
	if (_iter == _head && _iter != _tail)//���� ��尡 _head�̰� _tail�� �ƴ� ��
	{
		_head = _iter->GetNext();	//_head�� ���� ��带 _head�� ����
		_head->set_prev(_end);	//���� ��尡 ���ٴ� �ǹ̷� _end ����
		delete _iter;
	}
	else if (_iter != _head && _iter == _tail)//���� ��尡 _tail�̰� _head�� �ƴ� ��
	{
		_tail = _iter->GetPrev();	//_tail�� ���� ��带 _tail�� ����
		_tail->set_next(_end);	//���� ��尡 ���ٴ� �ǹ̷� _end ����
		delete _iter;
	}
	else if (!(_iter == _head && _iter == _tail)) //���� ��尡 �߰��� ���� ��
	{
		Node * temp = _iter->GetNext();	//iter�� next�� �ӽ� ������ ����
		temp->set_prev(_iter->GetPrev());	//�ӽú����� prev�� ���� ����� prev�� ����
		_iter->GetPrev()->set_next(temp);	//iter�� �� ����� next�� �ӽú��� ����
		delete _iter;				//���� ��� ����
		_iter = temp;				//���� ����� ���� ��带 ����� ����
	}
}

void DoubleyLinkedList::Delete(int num)
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

void DoubleyLinkedList::Delete(int data, int num)
{
	if (IsEmpty())
	{
		return;		//���� �����Ͱ� ������ ����
	}

	if (num > _size)
	{
		cout << "�ش� ��ȣ���� ��ü �����Ͱ� �����ϴ�." << endl;
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
		for (int repeat = 0; repeat < num; repeat++)//numȽ����ŭ �ݺ�
		{
			_iter = _head;

			while (!(_iter->GetData() == data))
			{
				if (_iter->GetNext() == _end)
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

void DoubleyLinkedList::Delete(Node * object)
{
	if (IsEmpty())
	{
		return;			//���� �����Ͱ� ������ ����
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
	_size--;					//���� ��� ������ŭ _size ����
}

void DoubleyLinkedList::GetNode()
{
	if (IsEmpty())
	{
		cout << "�����Ͱ� �����ϴ�." << endl;
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

DoubleyLinkedList::~DoubleyLinkedList()
{
}
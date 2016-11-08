#pragma once

class Node
{
private:
	Node * _prev;
	Node * _next;
	int  _data;

public:
	Node()
	{
		_prev = nullptr;
		_next = nullptr;
		_data = 0;
	}
public:
	inline Node * GetPrev()
	{
		return _prev;
	}
	inline void set_prev(Node * object)
	{
		_prev = object;
	}
	inline Node * GetNext()
	{
		return _next;
	}
	inline void set_next(Node * object)
	{
		_next = object;
	}
	inline int GetData()
	{
		return _data;
	}
	inline void set_data(int data)
	{
		_data = data;
	}

};
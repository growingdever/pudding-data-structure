
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

#include "util.h"

template<typename T>
class HongQueue
{
private:
	T* _items;
	int _size;
	int _rear;

public:
	HongQueue(int size)
		:_size(size), _rear(0)
	{
		_items = new T[size];
	}
	~HongQueue()
	{
		if( _items )
			delete[] _items;
	}

	void push( T v )
	{
		if( _rear + 1 > _size )
		{
			std::cout<<"Queue overflow."<<std::endl;
			return;
		}

		_items[ _rear++ ] = v;
	}
	T pop()
	{
		T v = _items[0];
		
		int i;
		for( i=1; i<_rear; i++ )
			_items[i-1] = _items[i];
		
		_rear--;

		return v;
	}
	void clear()
	{
		while( _rear > 0 )
		{
			_items[ _rear-- ] = 0;
		}
	}
	void resize( int size )
	{
		T* items = new T[size];

		int des = myMin( size - 1, _rear );
		int i;
		for( i=0; i<des; i++ )
		{
			items[i] = _items[i];
		}

		delete[] _items;
		_items = items;
		_size = size;
		_rear = des;
	}

	void PrintLeftToRight()
	{
		int i;
		for( i=0; i<_rear; i++ )
		{
			std::cout<<_items[i]<<" ";
		}
		std::cout<<std::endl;
	}
	void PrintRightToLeft()
	{
		int i;
		for( i=_rear; i>=_0; i-- )
		{
			std::cout<<_items[i]<<" ";
		}
		std::cout<<std::endl;
	}
};

#endif
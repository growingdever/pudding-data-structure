
#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <stack>

template <typename T>
class HongStack
{
private:
	T* _items;
	int _size;
	int _rear;

public:
	HongStack(int size)
		:_size(size), _rear(0)
	{
		_items = new T[size+1];
	};
	~HongStack()
	{
		if( _items )
			delete[] _items;
	};

	void push( T n ) 
	{
		if( _rear + 1 > _size )
		{
			std::cout<<"Stack overflow."<<std::endl;
			return;
		}

		_items[ _rear++ ] = n;
	};
	T pop()
	{
		if( _rear - 1 < 0 )
		{
			std::cout<<"Stack underflow."<<std::endl;
			return 0;
		}

		_rear--;
		T t = _items[ _rear ];
		_items[ _rear ] = 0;

		return t;
	};
	void clear()
	{
		while( _rear > 0 )
		{
			_items[ --_rear ] = 0;
		}
	};
	void resize( int size )
	{
		T* items = new T[size];

		int des = myMin( size, _rear );
		int i;
		for( i=0; i<des; i++ )
			items[i] = _items[i];

		delete[] _items;

		_items = items;
		_size = size;
		_rear = i;
	};

	void PrintTopToBottm()
	{
		int i;
		for( i=_rear-1; i>=0; i-- )
			std::cout<<_items[i]<<" ";
		std::cout<<std::endl;
	};
	void PrintBottmToTop()
	{
		int i;
		for( i=0; i<_rear; i++ )
			std::cout<<_items[i]<<" ";
		std::cout<<std::endl;
	};
};

#endif
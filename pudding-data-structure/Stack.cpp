
#include "Stack.h"

template <typename T>
void HongStack<T>::push( int n )
{
	if( _rear + 1 > _size )
	{
		printf("Stack over flow.\n");
		return;
	}

	_items[ _rear++ ] = n;
}

template <typename T>
T HongStack<T>::pop()
{
	if( _rear - 1 < 0 )
	{
		printf("Stack under flow.\n");
		return 0;
	}

	T* t = _items[ _rear ];
	_items[ _rear ] =0;
	_rear--;

	return t;
}


template <typename T>
void HongStack<T>::clear()
{
	while( _rear != 0 )
	{
		delete _items[ _rear-- ];
	}
}
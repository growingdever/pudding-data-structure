
#include "Stack.h"

#include <stdio.h>

HongStack::HongStack(int size)
	:_size(size),
	_rear(0)
{
	_items = new int[size+1];
	_items[size] = 0;
}

HongStack::~HongStack()
{
	if( _items )
		delete _items;
}

void HongStack::push( int n )
{
	if( _rear + 1 > _size )
	{
		printf("Stack over flow.\n");
		return;
	}

	_items[ _rear++ ] = n;
}

void HongStack::pop()
{
	if( _rear - 1 < 0 )
	{
		printf("Stack under flow.\n");
		return;
	}

	_items[ _rear-- ] = 0;
}

void HongStack::Print()
{
	int i;
	for( i=0; i<_rear; i++ )
	{
		printf("%d ", _items[i]);
	}
	printf("\n");
}

void HongStack::clear()
{
	while( _rear != 0 )
	{
		_items[ _rear-- ] = 0;
	}
}
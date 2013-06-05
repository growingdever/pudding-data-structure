
#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include "util.h"

void insertionsort( int arr[], int size, int value, bool increase )
{
	// Increasement sorting
	if( increase )
	{
		int i;
		for( i=0; i<size; i++ )
		{
			if( arr[i] > value )
			{
				insert( arr, size, i, value );
				break;
			}
		}
	}
	// Decreasement sorting
	else
	{
		int i;
		for( i=0; i<size; i++ )
		{
			if( arr[i] < value )
			{
				insert( arr, size, i, value );
				break;
			}
		}
	}
}

#endif

#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include "util.h"

void insertionsort( int arr[10], int size )
{
	int* tmparr = new int[size];
	init( tmparr, size, 0 );

	tmparr[0] = arr[0];

	// Increasement sorting
	int i, j;
	for( i=1; i<size; i++ )
	{
		for( j=0; j<i; j++ )
		{
			if( tmparr[j] < arr[i] )
				break;
		}
		
		insert( tmparr, size, j, arr[i]);
	}

	mymemcpy( arr, tmparr, size );

	delete[] tmparr;
}

#endif
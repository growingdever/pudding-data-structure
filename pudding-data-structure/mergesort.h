
#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "util.h"
#include "insertionsort.h"

void merge( int arr[], int left, int mid, int right )
{
	int* tmp = new int[right - left + 1];
	init( tmp, right - left + 1, 0 );
	printf( "left : %d\t right : %d\n", left, right );

	int i = left;
	int j = mid+1;
	int cnt = 0;

	while( i <= mid && j <= right )
	{
		if( arr[i] > arr[j] )
			tmp[cnt++] = arr[i++];
		else
			tmp[cnt++] = arr[j++];
	}

	while( i <= mid)
		tmp[cnt++] = arr[i++];

	while( j <= right )
		tmp[cnt++] = arr[j++];

	int k=0;
	cnt = 0;
	for( k=left; k<=right; k++ )
		arr[k] = tmp[cnt++];

	print( tmp, right - left + 1 );
	print( arr, 10 );
	printf("\n\n");

	delete[] tmp;
}

void mergesort( int arr[], int left, int right )
{
	if( left >= right )
		return ;

	int mid = (left + right) / 2; // floor

	mergesort( arr, left, mid );
	mergesort( arr, mid+1, right );
	merge( arr, left, mid, right );
}

#endif

#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "util.h"
#include "insertionsort.h"


template <typename T, typename C>
void merge( T arr[], int leftstart, int leftend, int rightstart, int rightend, C (*fp)(int,int) )
{
	T* tmp = new T[ rightend - leftstart + 1];
	init( tmp, rightend - leftstart + 1, 0 );

	int i = leftstart;
	int j = rightstart;
	int cnt = 0;

	while( i <= leftend && j <= rightend )
	{
		if( fp(arr[i], arr[j]) )
			tmp[cnt++] = arr[i++];
		else
			tmp[cnt++] = arr[j++];
	}

	while( i <= leftend )
		tmp[cnt++] = arr[i++];

	while( j <= rightend )
		tmp[cnt++] = arr[j++];

	int k;
	int cnt2 = 0;
	for( k = leftstart; k <= rightend; k++ )
		arr[k] = tmp[cnt2++];

	delete[] tmp;
}


template <typename T, typename C>
void mergesort( T arr[], int left, int right, C (*fp)(int,int) )
{
	if( left >= right )
		return;

	int mid = ( left + right ) / 2;
	
	mergesort( arr, left, mid, fp );
	mergesort( arr, mid+1, right, fp );
	merge( arr, left, mid, mid+1, right, fp );

}

template <typename T, typename C>
void mergesort_without_recursion( T arr[], int left, int right, C (*fp)(int,int) )
{
	int step = 2;
	int i = 1;
	int length = right - left + 1;
	int tmp;

	int l = left, r;

	while( l < right )
	{
		merge( arr, l, l, l+1, l+1, fp );
		l+=2;
	}

	for( step = 2; step < length; step *= 2 )
	{
		l = left;
		r = l + step;
		merge( arr, l, l+step-1, r, r+step-1, fp );

		while( 1 )
		{
			l += step*2;
			r = l + step;

			if( r > right )
				break;

			merge( arr, l, l+step-1, r, r+step-1, fp );
		}
	}

}


#endif

#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include "util.h"
#include "insertionsort.h"

template <typename T, typename C>
void qsort( T arr[], int left, int right, C (*fp)(int,int) )
{
	if( left > right )
		return;

	int size = right - left + 1;
	int pivot = arr[left];
	int i;

	T* leftarr = new T[size];
	T* rightarr = new T[size];

	int cnt = 0;

	// left array : less than or equal pivot
	// right array : over than pivot
	int leftcnt = 0;
	int rightcnt = 0;
	for( i=left+1; i<=right; i++ )
	{
		if( fp(arr[i], pivot) )
			rightarr[ rightcnt++ ] = arr[i];
		else
			leftarr[ leftcnt++ ] = arr[i];
	}

	// Re-fill array
	cnt = 0;
	for( i=0; i<leftcnt; i++ )
		arr[left + cnt++] = leftarr[i];
	arr[left + cnt++] = pivot;
	for( i=0; i<rightcnt; i++ )
		arr[left + cnt++] = rightarr[i];

	qsort( arr, left, left + leftcnt - 1, fp );
	qsort( arr, left + leftcnt + 1, right, fp );

	delete[] leftarr;
	delete[] rightarr;
}

template <typename T, typename C>
void quicksort( T arr[], int size, C (*fp)(int,int) )
{
	qsort( arr, 0, size-1, fp );

}


#endif
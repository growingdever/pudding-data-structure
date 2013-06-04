
#include <stdio.h>

#include "Stack.h"
#include "mergesort.h"

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int i;

	for( i=0; i<10; i++ )
		printf("%d ", arr[i]);
	printf("\n");

	mergesort( arr, 0, 9 );

	for( i=0; i<10; i++ )
		printf("%d ", arr[i]);
	printf("\n");
}
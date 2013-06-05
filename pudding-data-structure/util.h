
#ifndef _UTIL_H_
#define _UTIL_H_

void print( int arr[], int size )
{
	int i;
	for( i=0; i<size; i++ )
		printf("%4d", arr[i]);
	printf("\n");
}

void init( int arr[], int size, int value )
{
	int i;
	for( i=0; i<size; i++ )
		arr[i] = value;
}

void insert( int arr[], int size, int index, int value )
{
	int i;
	for( i=size-2; i>=index; i-- )
		arr[i+1] = arr[i];
	arr[index] = value;
}

void swap( int& a, int& b )
{
	int tmp = a;
	a = b;
	b = tmp;
}

#endif
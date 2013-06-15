
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

void mymemcpy( int* des, int* src, int size )
{
	int i;
	for( i=0; i<size; i++ )
		des[i] = src[i];
}

void insert( int arr[], int size, int index, int value )
{
	int* tmparr = new int[size];
	int i, cnt=0;

	for( i=0; i<index; i++ )
		tmparr[cnt++] = arr[i];
	tmparr[cnt++] = value;
	for( ; i<size-1; i++ )
		tmparr[cnt++] = arr[i];

	mymemcpy( arr, tmparr, size );

	delete[] tmparr;
}

void swap( int& a, int& b )
{
	int tmp = a;
	a = b;
	b = tmp;
}

#endif
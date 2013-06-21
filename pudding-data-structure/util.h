
#ifndef _UTIL_H_
#define _UTIL_H_

inline void print( int arr[], int size )
{
	int i;
	for( i=0; i<size; i++ )
		printf("%4d", arr[i]);
	printf("\n");
}

inline void init( int arr[], int size, int value )
{
	int i;
	for( i=0; i<size; i++ )
		arr[i] = value;
}

inline void mymemcpy( int* des, int* src, int size )
{
	int i;
	for( i=0; i<size; i++ )
		des[i] = src[i];
}

inline void insert( int arr[], int size, int index, int value )
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

inline void swap( int& a, int& b )
{
	int tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T myMax( T a, T b )
{
	if( a > b )
		return a;
	else
		return b;
}

template <typename T>
T myMin( T a, T b )
{
	if( a < b )
		return a;
	else
		return b;
}

#endif
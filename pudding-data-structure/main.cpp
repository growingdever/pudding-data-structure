
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <Windows.h>
#include <stdio.h>
#include <time.h>

#include "Stack.h"
#include "mergesort.h"
#include "insertionsort.h"


int comp( int a, int b )
{
	if( a > b )
		return true;
	else 
		return false;
}

int main()
{
	// Check memory leak
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	_CrtDumpMemoryLeaks();

	srand( (unsigned)time(NULL) );

	FILE* fp = fopen( "input.txt", "r");

	int size = rand()%17;
	int n;

	LARGE_INTEGER freq, t1, t2;
	QueryPerformanceFrequency(&freq);


	fscanf(fp, "%d", &n);

	int* arr = new int[n];
	int i;
	for( i=0; i<n; i++ )
		fscanf(fp, "%d", &arr[i]);


	QueryPerformanceCounter(&t1);
	printf("--Pre sorting--\nTime : %lld\n\n", t1.QuadPart);

	mergesort( arr, 0, n, comp );
	//mergesort_without_recursion( arr, 0, n, comp );
	
	QueryPerformanceCounter(&t2);
	printf("--Sorted--\nTime : %lld\n\n", t2.QuadPart);

	printf("Time diff = %lld\n\n", (t2.QuadPart - t1.QuadPart) );


	FILE* out = fopen( "output.txt", "w" );
	fprintf(out, "%d\n", n);
	for( i=0; i<n; i++ )
		fprintf(out, "%d\n", arr[i]);

	delete[] arr;
}
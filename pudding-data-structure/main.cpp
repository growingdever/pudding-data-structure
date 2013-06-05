
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>

#include "Stack.h"
#include "mergesort.h"
#include "insertionsort.h"


int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	_CrtDumpMemoryLeaks();

	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	int arr2[] = { 1, 2, 3, 4, 5 };

	print( arr, 10 );
	printf("\n\n");

	mergesort( arr, 0, 9 );
	print( arr, 10 );
	printf("\n\n");
}

#include <stdio.h>

#include "Stack.h"

int main()
{
	HongStack stack(5);

	int i;
	for( i=0; i<3; i++ )
		stack.push(i);
	stack.push(0);
	for( i=0; i<3; i++ )
		stack.push(i);

	stack.Print();

	stack.clear();

	for( i=0; i<3; i++ )
		stack.pop();
	stack.pop();

	return 0;
}
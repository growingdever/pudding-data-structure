
#ifndef _STACK_H_
#define _STACK_H_

class HongStack
{
private:
	int* _items;
	int _size;
	int _rear;

public:
	HongStack(int size);
	~HongStack();

	void push( int n );
	void pop();
	void Print();
	void clear();
};

#endif
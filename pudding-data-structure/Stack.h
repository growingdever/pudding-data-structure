
#ifndef _STACK_H_
#define _STACK_H_

template <typename T>
class HongStack
{
private:
	T* _items;
	int _size;
	int _rear;

public:
	HongStack(int size);
	~HongStack();

	void push( int n );
	T pop();
	void clear();
};


template <typename T>
HongStack<T>::HongStack(int size)
	:_size(size),
	_rear(0)
{
	_items = new T[size+1];
}

template <typename T>
HongStack<T>::~HongStack()
{
	if( _items )
		delete[] _items;
}


#endif
#include "Queue_Array.h"

template <class T>
bool Queue_Array<T>::isEmpty()
{
	if (length == 0)
		return true;
	return false;
}

template <class T>
bool Queue_Array<T>::isFull()
{
	if (tail == size)
		return true;
	return false;
}

template <class T>
int Queue_Array<T>::queSize()
{
	return length;
}

template<class T>
void Queue_Array<T>::resize()
{
	T* temp = new T [length * 2];
	
	int i;
	for (i = 0; head < tail; ++i)
	{
		temp[i] = q[head++];
	}

	tail = i;
	head = 0;
	delete q;
	q = temp;
}

template<class T>
void Queue_Array <T>::push(T data)
{
	if (isFull())
		resize();
	q[tail++] = data;
	length++;
}

template<class T>
void Queue_Array<T>::pop()
{
	if (isEmpty())
		return;
	head++;
	length--;
}

template<class T>
T Queue_Array<T>::top()
{
	if (isEmpty())
		throw logic_error("Queue is empty. There is no value in queue to run top().");
	return q[head];
}

template<class T>
void Queue_Array<T>::clear()
{
	head = 0;
	tail = 0;
	length = 0;
}

template<class T>
void Queue_Array<T>::print()
{
	cout << "Queue contains: { ";
	for (int i = head; i < tail; ++i)
	{
		cout << q[i] << " ";
	}
	cout << "}\n";
}
#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <iostream>
#include <exception>

using namespace std;

template<class T>
class Queue_Array
{
private:
	T *q;
	int length;
	int head;	//index to top()
	int tail;	//index to push()
	int size;

	void resize();
	bool isFull();

public:

	Queue_Array()
	{
		size = 2;
		q = new T [size];
		length = 0;
		head = 0;
		tail = 0;
	}

	~Queue_Array()
	{
		delete q;
	}

	void clear();
	bool isEmpty();
	int	queSize();
	void push(T data);
	void pop();
	T top();
	void	print();



};

#endif
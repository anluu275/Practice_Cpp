#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <iostream>
#include <exception>

using namespace std;

template<class T>
class Node
{
public:

	T val;
	Node<T>* next;

	Node(const T &d = T(), Node<T>* p = nullptr)
	{
		val = d;
		next = p;
	}
};

template <class T>
class Queue_Linked_List
{
private:
	Node<T>* headptr;
	Node<T>* tailptr;
	int length;

public:

	Queue_Linked_List()
	{
		headptr = nullptr;
		tailptr = nullptr;
		length = 0;
	}

	Queue_Linked_List(const Queue_Linked_List& other)
	{
		if (other.isEmpty())
			headptr = tailptr = nullptr;
		else
		{
			headptr = new Node<T>(other.headptr->data);
			Node<T>* otherCurrent = other.headptr->next;
			Node<T>* pre = headptr;
			while (otherCurrent != nullptr) {
				pre->next = new Node<T>(otherCurrent->data);
				pre = pre->next;
				otherCurrent = otherCurrent->next;
			}
		}
	}

	~Queue_Linked_List()
	{
		clear();
	}

	void	clear();
	void	push(T data);
	void	pop();
	void	print();
	bool	isEmpty();
	T	top();
	int	queSize();
};
#endif // !QUEUE_LINKED_LIST_H
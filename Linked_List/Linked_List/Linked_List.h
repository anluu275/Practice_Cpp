#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>

using namespace std;

template <class T>
class Node
{
public:
	T val;
	Node<T>* next;

	Node(const T& d = T(), Node<T>* p = nullptr)
	{
		val = d;
		next = p;
	}
};

template <class T>
class Linked_List
{
private:
	Node<T>* head;
	int length;

public:
	Linked_List()
	{
		head = nullptr;
		length = 0;
	}

	~Linked_List()
	{
		clear();
	}

	void	insertFront		(const T& data);
	void	insertBack		(const T& data);
	void	removeFirst		();
	void	removeAtIndex	(int i);
	void	clear			();
	void	printList		() const;
	int		getLength		()	const;
	bool	isEmpty			() const;
	T		getFirst		() const;

};

#endif


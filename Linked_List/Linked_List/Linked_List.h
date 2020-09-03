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

	int		getLength		()	const;
	T		getFirst		() const;
	T		getAtIndex		(int i) const;

	void	insertFront		(const T& data);
	void	insertAtIndex	(const T& data, int i);
	void	insertBack		(const T& data);

	void	removeFirst		();
	void	removeAtIndex	(int i);

	void	clear			();
	bool	isEmpty			() const;
	void	printList		() const;



};

#endif


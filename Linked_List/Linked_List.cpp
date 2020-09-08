#include "Linked_List.h"

template<class T>
int Linked_List<T>::getLength() const
{
	return length;
}

template<class T>
T	Linked_List<T>::getFirst() const
{

	if (isEmpty())
		throw logic_error("No items in Linked List to getFirst");
	return head->val;
}

template<class T>
T	Linked_List<T>::getAtIndex(int i) const
{
	if (isEmpty())
		throw logic_error("No items in Linked List to getAtIndex");
	if (i >= length || i < 0)
		throw logic_error("Index is out of range of LinkedList");
	
	Node<T>* temp = head;
	for (int j = 0; j < i; ++j)
		temp = temp->next;
	return temp->val;
}

template<class T>
void Linked_List<T>::insertFront(const T& data)
{
	if (isEmpty())
		head = new Node<T>(data);
	else
	{
		Node<T>* temp = new Node<T>(data, head);
		head = temp;
	}
	length++;
}

template<class T>
void Linked_List<T>::insertAtIndex(const T& data, int i)
{
	if (0 == i)
		insertFront(data);
	else if (i < 0 || i > length)
	{
		cout << "Index given was out of range of LinkedList. \n" << 
			" Please choose a index within you currents Linked List range of 0 to " << getLength() << endl;
		return;
	}
	else
	{
		Node<T>* curptr = head;
		Node<T>* prevptr = head;

		for (int j = 0; j < i; ++j)
		{
			prevptr = curptr;
			curptr = curptr->next;
		}

		Node<T>* newNode = new Node<T>(data, curptr);
		prevptr->next = newNode;
		length++;
	}
}

template<class T>
void Linked_List<T>::insertBack(const T& data)
{
	if (isEmpty())
		insertFront(data);
	else
	{
		Node<T>* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = new Node<T>(data);
		length++;
	}
}

template<class T>
void Linked_List<T>::removeFirst()
{
	if (isEmpty())
		return;
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	length--;
}

template<class T>
void Linked_List<T>::removeAtIndex(int i)
{
	if (0 == i)
		removeFirst();
	else if (isEmpty())
		return;
	else if (i < 0 || i > length)
	{
		cout << "Index given was out of range of LinkedList. \n" <<
			" Please choose a index within you currents Linked List range of 0 to " << getLength() - 1 << endl;
		return;
	}
	else
	{
		Node<T>* curptr = head;
		Node<T>* prevptr = head;

		for (int j = 0; j < i; ++j)
		{
			prevptr = curptr;
			curptr = curptr->next;
		}

		prevptr->next = curptr->next;
		delete curptr;
		length--;
	}
}

template<class T>
bool Linked_List<T>::isEmpty() const
{
	return (length <= 0) ? true : false;
}

template<class T>
void Linked_List<T>::clear()
{
	while (!isEmpty())
		removeFirst();
}

template<class T>
void Linked_List<T>::printList() const
{
	if (isEmpty())
	{
		cout << "Linked List is Empty" << endl;
		return;
	}
	cout << "\nContent in Linked List: " << endl;
	cout << "INDEX     VALUE" << endl;

	Node<T>* temp = head;
	for (int i = 0; i < length; ++i)
	{
		cout << "  " << i << "         " << temp->val << endl;
		temp = temp->next;
	}
}

template<class T>
void Linked_List<T>::reverseList()
{
	//recursiveReverse(head);
	iterativeReverse(head);
}

template<class T>
Node<T>* Linked_List<T>::recursiveReverse(Node<T>* temp)
{
	if (temp == nullptr)
		return nullptr;
	if (temp->next == nullptr)
	{
		head = temp;
		return temp;
	}
	Node<T>* nxt = reverse(temp->next);
	nxt->next = temp;
	return temp;
}

template<class T>
void Linked_List<T>::iterativeReverse(Node<T>* temp)
{
	if (isEmpty() || length == 1) //Empty or single node list doesnt need to be reversed
		return;

	Node<T>* curNode = temp;
	Node<T>* prevNode = nullptr;

	while (curNode != nullptr)
	{
		Node<T>* nextNode = curNode->next;
		curNode->next = prevNode;
		prevNode = curNode;
		curNode = nextNode;
	}
	head = prevNode;
}
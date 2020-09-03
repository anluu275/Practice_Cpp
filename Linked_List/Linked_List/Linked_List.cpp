#include "Linked_List.h"

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
void Linked_List<T>::insertBack(const T& data)
{
	if (isEmpty())
		head = new Node<T>(data);
	else
	{
		Node<T>* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = new Node<T>(data);
	}
	length++;
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
	return;
}

template<class T>
int Linked_List<T>::getLength() const
{
	return length;
}

template<class T>
T Linked_List<T>::getFirst() const
{
	try
	{
		if (isEmpty())
			throw logic_error("No items in Linked List to getFirst");
		return head->val;
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
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

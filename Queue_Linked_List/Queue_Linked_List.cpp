#include "Queue_Linked_List.h"

template<class T>
void	Queue_Linked_List<T>::clear()
{
	while (!isEmpty())
		pop();
}

template<class T>
void	Queue_Linked_List<T>::pop() // FIFO
{
	if (length == 0)
		return;
	Node<T>* temp = headptr;
	headptr = headptr->next;
	delete temp;
	length--;
	if (headptr == nullptr)
		tailptr = nullptr;
}

template<class T>
bool	Queue_Linked_List<T>::isEmpty()
{
	if (length == 0)
		return true;
	return false;
}

template<class T>
void	Queue_Linked_List<T>::push(T data)
{
	if (isEmpty())
	{
		headptr = new Node<T>(data);
		tailptr = headptr;
	}
	else {
		Node<T>* temp = new Node<T>(data);
		tailptr->next = temp;
		tailptr = tailptr->next;
	}
	length++;
}

template <class T>
int	Queue_Linked_List<T>::queSize()
{
	return length;
}

template <class T>
void	Queue_Linked_List<T>::print()
{
	Node<T>* temp = headptr;

	cout << "Content in Current Queue : FRONT { ";
	while (temp != nullptr)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << "} BACK\n";
}

template <class T>
T	Queue_Linked_List<T>::top()
{
	if (isEmpty())
		throw logic_error("Queue is empty. Top() function was not performed.");
	return headptr->val;
}
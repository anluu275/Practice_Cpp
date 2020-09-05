#include <iostream>
#include <exception>
#include "Linked_List.cpp"

using namespace std;

void linkedint()
{
	Linked_List<int> intlist;

	cout << "Value at Index 0: " << intlist.getFirst() << endl;
	cout << "Current Length:" << intlist.getLength() << endl;
	intlist.insertFront(6);
	intlist.insertFront(5);
	intlist.insertAtIndex(4,3); //out of range
	intlist.insertAtIndex(4,1);
	intlist.insertAtIndex(7,3);
	cout << "Value at Index 0: " << intlist.getFirst() << endl;
	cout << "Value at Index 1: " << intlist.getAtIndex(1)	<< endl;
	cout << "Value at Index 2: " << intlist.getAtIndex(2)	<< endl;
	intlist.printList();
	intlist.insertBack(4);
	intlist.removeFirst();
	intlist.printList();
}

void reverseIntList()
{
	Linked_List<int> reverseintlist;
	reverseintlist.insertFront(6);
	reverseintlist.insertFront(5);
	reverseintlist.insertFront(4);
	reverseintlist.insertFront(3);
	reverseintlist.insertFront(2);
	reverseintlist.insertFront(1);
	reverseintlist.insertFront(0);
	reverseintlist.printList();
	reverseintlist.reverseList();
	reverseintlist.printList();
}

int main()
{
	//linkedint();
	reverseIntList();
	
}
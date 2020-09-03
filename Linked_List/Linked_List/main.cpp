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

int main()
{
	linkedint();
	
}
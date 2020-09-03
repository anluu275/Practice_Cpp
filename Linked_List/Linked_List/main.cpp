#include <iostream>
#include <exception>
#include "Linked_List.cpp"

using namespace std;

void linkedint()
{
	Linked_List<int> intlist;

	intlist.getFirst();
	cout << intlist.getLength();
	intlist.insertFront(6);
	intlist.insertFront(5);
	cout << "\n" << intlist.getFirst();
	intlist.printList();
	intlist.insertBack(4);
	intlist.removeFirst();
	intlist.printList();

}

int main()
{
	linkedint();
	
}
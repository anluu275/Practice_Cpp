#include "Queue_Linked_List.cpp"




void Queue_Linked_ListTest()
{
	Queue_Linked_List<int> que;

	try {que.top();} catch (exception ex) {cout << ex.what() << endl;}

	cout << que.queSize() << endl;
	que.push(10);
	que.print();
	que.push(100);
	que.push(9);
	que.push(72);
	cout << que.queSize() << endl;

	try { cout << que.top() << endl;} catch (exception ex) {cout << ex.what() << endl;}

	que.pop();
	que.print();
	que.clear();
	que.print();
	cout << que.queSize();
}

int main()
{
	Queue_Linked_ListTest();
}
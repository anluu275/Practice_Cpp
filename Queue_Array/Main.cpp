#include "Queue_Array.cpp"

void queueArrayTest()
{
	Queue_Array<int> que;

	que.queSize();
	try {
		cout << que.top() << endl;
	}
	catch (logic_error ex)
	{
		cout << ex.what() << endl;
	}
	que.push(2);
	try {
		cout << que.top() << endl;
	}
	catch (logic_error ex)
	{
		cout << ex.what() << endl;
	}
	que.push(10);
	que.pop();
	que.push(100);
	que.push(20);
	que.push(10);
	que.print();
}


int main()
{
	queueArrayTest();

}
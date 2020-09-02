#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
template<class T>
class MaxPQ
{
public:
	const int SIZE = 2;

private:
	T *q[];
	int tail = -1;	//iterator value of queue within q

	bool isfull()
	{
		return (q.size() == qSize()) ? true : false;
	}

	void resize()
	{
		T* temp[] = new arr[qSize * 2];

		for (int x = 0; x < tail; ++x)
		{
			temp[x] = q[x];
		}
		delete q;
		q = temp;
	}

public:

	MaxPQ()
	{
		q = new T arr[SIZE];
	}

	~MaxPQ()
	{
		clean();
	}

	void isEmpty()
	{
		return (tail < 0) ? true : false;
	}

	int qSize()
	{
		return tail;
	}

	void push(T value)
	{
		if (isFull())
			resize();
		q[++tail] = value;
	}

	void pop()
	{
		if (isEmpty())
			return;
		tail--;
	}

	T top()
	{
		if (isEmpty())
			throw logic_error("Queue is empty");
		return q[0];

	}
	void clean()
	{

	}

};

#endif
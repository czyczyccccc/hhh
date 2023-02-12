#include<iostream>
using namespace std;
class Heap
{
protected:
	int* arr;
	int capacity;
	int size;
	bool isfull()
	{
		return(size == capacity);
	}
	bool isempty()
	{
		return(size == 0);
	}
	void percolateup()
	{
		int x = arr[size];
		int i;
		for (i = size; i > 1 && (x < arr[i / 2]); i = i / 2)
		{
			arr[i] = arr[i / 2];
		}
		arr[i] = x;
	}
	void percolatedown()
	{
		int x = arr[1];
		int i,child;
		for (i = 1; i * 2 <= size; i=child)
		{
			child = i * 2;
			if (child < size)
			{
				if (arr[child] > arr[child + 1])
				{
					child++;
				}
			}
			if (x > arr[child])
			{
				arr[i] = arr[child];
			}
			else
			{
				break;
			}
		}
		arr[i] = x;
	}
public:
	Heap(int n)
	{
		arr = new int[n];
		capacity = n;
		size = 0;
	}
	~Heap()
	{
		delete[]arr;
	}
	void printheap()
	{
		for (int i = 1; i <= size; i++)
		{
			cout << arr[i] << ' ';
		}
	}
	void inesrt(int x)
	{
		if (!isfull())
		{
			size++;
			arr[size] = x;
			percolateup();
		}
	}
	void remove(int &x)
	{
		if (!isempty())
		{
			x = arr[1];
			arr[1] = arr[size];
			size--;
			percolatedown();
		}
	}

};
int main()
{
	Heap h(100);
	h.inesrt(20);
	h.inesrt(10);
	h.inesrt(5);
	h.inesrt(15);
	h.inesrt(30);
	h.inesrt(18);
	int x;
	h.remove(x);
	cout << x << endl;
	h.printheap();

	return 0;
}
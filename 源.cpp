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
	void percolateup(int t)
	{
		int x = arr[t];
		int i;
		for (i = t; i > 1 && (x < arr[i / 2]); i = i / 2)
		{
			arr[i] = arr[i / 2];
		}
		arr[i] = x;
	}
	void percolatedown(int t)
	{
		int x = arr[t];
		int i,child;
		for (i = t; i * 2 <= size; i=child)
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
	Heap(int *p ,int m,int n);
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
			percolateup(size);
		}
	}
	void remove(int &x)
	{
		if (!isempty())
		{
			x = arr[1];
			arr[1] = arr[size];
			size--;
			percolatedown(1);
		}
	}

};
Heap::Heap(int *p,int m,int n)
{
	arr = new int[n];
	capacity = n;
	size = m;
	for (int i = 1; i <= size; i++)
	{
		arr[i] = p[i - 1];
	}
	for (int i = size / 2; i > 0; i--)
	{
		percolatedown(i);
	}
}
int main()
{
	int arr[] = { 10,50,60,5,30,20 };
	
	Heap h(arr, 6, 10);
	h.printheap();

	return 0;
}
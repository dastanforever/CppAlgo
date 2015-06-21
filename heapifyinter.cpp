#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector< int > heap;

int parent(int node)
{
	return int(node/2);
}

int left(int node)
{
	return 2*node;
}

int right(int node)
{
	return (2*node + 1);
}

int heapify(int parent)
{
	int i = 0,res = 1;
	while (i != 1)
	{
		int l = left(parent);
		int r = right(parent);
		int largest = parent;
		if (heap[l] > heap[parent] && l < heap.size())
			largest = l;
		else
			largest = parent;
		if (heap[r] > heap[largest] && r < heap.size())
		{
			largest = r;
		}
		if (largest != parent)
		{
			int temp = heap[parent];
			heap[parent] = heap[largest];
			heap[largest] = temp;
			i = 0;
			parent = largest;
			res = 0;
		}
		else
			i = 1;
	}
	return res;
}

int main(void)
{
	int num_ele,i,ele,res;
	cin>>num_ele;
	heap.push_back(0);
	while(num_ele--)
	{
		cin>>ele;
		heap.push_back(ele);
	}
	for (i = (heap.size()+1)/2; i >= 1; --i)
	{
		res = heapify(i);
		
	}
	for (i = 1; i < heap.size(); ++i)
	{
		cout<<heap[i]<<" ";
	}
	return 0;
}

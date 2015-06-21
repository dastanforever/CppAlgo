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

void heapify(int parent)
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
		heapify(largest);
	}
}

int main(void)
{
	int num_ele,i,ele;
	cin>>num_ele;
	heap.push_back(0);
	while(num_ele--)
	{
		cin>>ele;
		heap.push_back(ele);
	}
	heapify(1);
	for (i = 1; i < heap.size(); ++i)
	{
		cout<<heap[i]<<" ";
	}
	return 0;
}

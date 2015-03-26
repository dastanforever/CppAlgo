#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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

void heapify(vector<int> heap, int parent)
{
	int l = left(parent);
	int r = right(parent);
	int largest = parent;
	if (heap[l] > heap[parent])
		largest = l;
	else
		largest = parent;
	if (heap[r] > heap[largest])
	{
		largest = r;
	}
	if (largest != parent)
	{
		int temp = heap[parent];
		heap[parent] = heap[largest];
		heap[largest] = temp;
		heapify(heap, largest);
	}
}

int main(void)
{
	vector< int > heap;
	int num_ele,i,ele;
	cin>>num_ele;
	heap.push_back(0);
	while(num_ele--)
	{
		cin>>ele;
		heap.push_back(ele);
	}
	//heapify(heap, 1);
	for (i = 0; i < num_ele; ++i)
	{
		cout<<heap[i]<<" ";
	}
	return 0;
}

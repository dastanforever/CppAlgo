#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void  merge(vector < int > &v1, int p,int q,int r)
{
	cout<<"p : "<<p<<"q : "<<q<<"r : "<<r<<endl;
	vector < int > v1sam,v2sam;
	int i = 0,j = 0;
	for (i = p; i <= q; ++i)
	{
		v1sam.push_back(v1[i]);
	}
		for (i = q; i <= r; ++i)
	{
        
		v2sam.push_back(v1[i]);
	}
	i = 0;
	j = 0;
	int k;
	for (k = p; k < r; ++k)
	{
		if (v1sam[i] < v2sam[j])
			v1[k] = v1sam[i++];
		else 
			v1[k] = v2sam[j++];
		if (i >= v1sam.size() || j >= v2sam.size())
			break;
	}
	if (i < v1sam.size())
		while(i < v1sam.size())
			v1[k++] = v1sam[i++];
	if (j < v2sam.size())
		while(j < v2sam.size())
			v1[k++] = v1sam[j++];
}

void mergesort(vector < int > &vec, int start, int end)
{
	if (end - start > 2)
	{
		mergesort(vec,start,(start+end)/2);
		mergesort(vec,(start+end)/2,end);
	}
	else 
		merge(vec,start,(int)((start+end)/2),end);
}

int main(int argc, char const *argv[])
{
	int n,i,ele;
	vector < int > v1;
	cin>>n;
	for (i = 0; i < n; ++i)
	{
		cin>>ele;
		v1.push_back(ele);
	}
	mergesort(v1,0,v1.size());
	for (i = 0; i < v1.size(); ++i)
	{
		cout<<v1[i]<<" ";
	}
	return 0;
}
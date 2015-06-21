#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;


struct Data
{
	// All the data
	// To store.
	int val;
};

struct Node
{
	Data key;
	Node * left;
	Node * right;
};

struct Tree
{

	Node * root;

	// Functions for the tree.
	// eg. insert, delete, 
	//all else.






	Node * getnewnode(Data data)
	{
		Node * newnode = new Node;
		newnode->key = data;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}

	// Since its a binary tree
	// Insert the node using
	// bfs and search for the
	// first null.
	bool insert(Data data)
	{
		queue < Node * > nodes;
		nodes.push(root);
		Node * ele = new Node;
		while(!nodes.empty())
		{
			ele = nodes.front();
			nodes.pop();
			if(ele == NULL || ele->left == NULL || ele->right == NULL) break;
			nodes.push(ele->left);
			nodes.push(ele->right);
		}
		Node * newnode = getnewnode(data);
		if(ele == NULL) { ele = new Node; ele = newnode;root = ele;}
		else if (ele->left == NULL) ele->left = newnode;
		else ele->right = newnode;
		return true;
	}

	void printdata(Node * ele)
	{
		Data dt = ele->key;
		printf("%d\n", dt.val);
	}


	void printbinaryrec(Node * ele)
	{
		if(ele->left == NULL && ele->right == NULL) { printdata(ele); return; }
		if(ele->left!= NULL) printbinaryrec(ele->left);
		if(ele->right!= NULL) printbinaryrec(ele->right);
		printdata(ele);
	}


	// Printing from stack as
	// Auxiliary data Storage.

	void printbinarystack()
	{
		stack < Node * > nodes;
		nodes.push(root);
		Node * ele = new Node;
		while(nodes.size())
		{
			ele = nodes.top();
			nodes.pop();
			if(ele == NULL) continue;
			nodes.push(ele->left);
			nodes.push(ele->right);
			printdata(ele);
		}
	}


	// Printing using BFS.
	// Queue STL.

	void printbinary()
	{
		queue < Node * > nodes;
		nodes.push(root);
		Node * ele = new Node;
		while(!nodes.empty())
		{
			ele = nodes.front();
			nodes.pop();
			if(ele == NULL) continue;
			nodes.push(ele->left);
			nodes.push(ele->right);
			printdata(ele);
		}
	}
};

int main(void)
{
	Tree Extree;
	Data dta;
	int i;
	Extree.root = NULL;
	for (i = 0; i < 10; ++i)
	{
		dta.val = i;
		Extree.insert(dta);
	}
	printf("BFS\n");
	Extree.printbinary();
	printf("Recursive\n");
	Extree.printbinaryrec(Extree.root);
	printf("Stack\n");
	Extree.printbinarystack();
	return 0;
}
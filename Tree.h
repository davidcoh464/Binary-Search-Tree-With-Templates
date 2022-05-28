#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

template <class T>
class Tree
{
protected:
	//inner class
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val)
			: value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r)
			: value(val), left(l), right(r) {}
	}; //end of Node class 
	Node* root;
public:
	Tree() { root = NULL; } // initialize tree
	virtual ~Tree();
	bool isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	int leaves() { return(leaves(root)); }
	int height() { return(height(root)); }
	void reflect() { reflect(root); }
	int onlyLeftSon() { return(onlyLeftSon(root)); }
	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;
protected:
	void reflect(Node* current);
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);
	int   leaves(Node* current);
	int height(Node* current);
	int onlyLeftSon(Node* current);
};
template <class T>
int Tree<T>::leaves(Node* current)
{
	if (!current)
		return 0;
	if (!current->left && !current->right)//if the current its leave
		return 1;
	else {
		return leaves(current->left) + leaves(current->right);//return the sum of leaves 
	}

}
template <class T>
int Tree<T>::height(Node* current)
{
	if (!current)
		return 0;
	int L = height(current->left);
	int R = height(current->right);
	return(max(L, R) + 1);//reaurn the max between the right and left
}
template <class T>
void Tree<T>::reflect(Node* current)
{
	if (!current)
		return;
	reflect(current->left);
	reflect(current->right);
	//swap the pointers in this node
	typename Tree<T>::Node* temp = current->left;
	current->left = current->right;
	current->right = temp;
}
template <class T>
int Tree<T>::onlyLeftSon(Node* current)
{
	if (!current)
		return 0;
	if (current->left && !current->right)//if this node have only left son
		return onlyLeftSon(current->left) + 1;//add one and continue to the left node
	else {
		return onlyLeftSon(current->left) + onlyLeftSon(current->right);//return the sum of the only left sons
	}
}
///////////////////////////////////////////
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}


template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
bool Tree<T>::isEmpty() const
{
	return  root == NULL;
}
// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}
// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}
// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}



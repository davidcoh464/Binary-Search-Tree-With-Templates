#pragma once
#include "Tree.h"
template <class T>
class SearchTree : public Tree<T>
{
public:
	// protocol for search trees
	void add(T value);
	bool  search(T value)
	{
		return search(this->root, value);
	}
	void remove(T value)
	{
		if (search(this->root, value))
		{
			if (this->root->value == value)//if the root equal to the value
			{
				typename Tree<T>::Node* current = this->root;
				typename Tree<T>::Node* temp = this->root->right;
				if (temp)
				{
					while (temp->left)//moves temp untill the end of the left
						temp = temp->left;
					temp->left = this->root->left;// add the left son of root into the left of temp
					this->root = this->root->right;//promote root to the right
				}
				else // if there isnt right  son to root
					this->root = this->root->left;//promote root into the left
				delete current;//delete root
				current = NULL;
				return;
			}
			remove(this->root, value);
		}
	}

	int level(T value)
	{
		return(level(this->root, value, 0));
	}
private:
	void process(T val) { cout << val << " "; }
	void add(class Tree<T>::Node* current, T val);
	bool  search(class Tree<T>::Node* current, T val);
	void  remove(class Tree<T>::Node*& current, T val);
	int level(class Tree<T>::Node* current, T value, int count);
};

template < class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree
	if (!this->root)
	{
		this->root = new typename Tree<T>::Node(val);
		return;
	}
	add(this->root, val);
}

template < class T>
bool SearchTree<T>::search(class Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false; // not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}
///////////////////////////////////////////////////////////////////////////////
template < class T>
void SearchTree<T>::add(class Tree<T>::Node* current, T val)
{
	if (current->value <= val)// add to right subtree
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	// add to left subtree
	else if (!current->left)
	{
		current->left = new typename Tree<T>::Node(val);
		return;
	}
	else add(current->left, val);
}
/////////////////////////////////////////////////////////////////////////////////
template < class T>
void SearchTree<T>::remove(class Tree<T>::Node*& current, T val)
{
	if (!current)
		return;
	if (!current->left && !current->right)//if the cureent it's  a leave
		return;
	if (current->left)
	{
		if (current->left->value == val)
		{
			//creating two temporary variables that equal to the node that need to remove
			typename Tree<T>::Node* temp = current->left;
			typename Tree<T>::Node* temp2 = current->left;
			if (temp->right)
			{
				temp = temp2->right;
				while (temp->left)//move temp untill the end of the left
					temp = temp->left;
				temp->left = temp2->left;//add to temp the left node that need to remove
				current->left = temp2->right; //connects the father with the right side of the node
			}
			else//if it dosnt have a right son
				current->left = temp2->left;
			delete temp2;
			temp2 = NULL;
			return;
		}
	}
	if (current->right)
	{
		if (current->right->value == val)
		{
			//creating two temporary variables that equal to the node that need to remove
			typename Tree<T>::Node* temp = current->right;
			typename Tree<T>::Node* temp2 = current->right;
			if (temp->right)
			{
				temp = temp2->right;//temp equal to the right son of the one that need to remove
				while (temp->left)//move temp untill the of the left
					temp = temp->left;
				temp->left = temp2->left;//add the left of the node that need to remove to the left of temp
				current->right = temp2->right;//connects the father with the right side of the node
			}
			else//if it's dosnt have a right son
				current->right = temp2->left;
			delete temp2;
			temp2 = NULL;
			return;
		}
	}
	////////////////////////////////////////////////
	if (val < current->value)
	{
		remove(current->left, val);
	}
	if (val > current->value)
	{
		remove(current->right, val);
	}
}
//////////////////////////////////////////////////////////////////////////////
template < class T>
int SearchTree<T>::level(class Tree<T>::Node* current, T val, int count)
{
	if (!current)
		return -1; 
	if (current->value == val)
		return count++;
	if (current->value < val)
	{
		return  level(current->right, val, ++count);
	}
	else
	{
		return level(current->left, val, ++count);
	}
}

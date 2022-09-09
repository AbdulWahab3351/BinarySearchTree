#include "BST.h"
#include<iostream>
using namespace std;

template <typename T>
BST<T>::BST()
{
	root = nullptr;
}
template<typename T>
bool BST<T>:: search(T key)
{
	if (!root)
		return false;
	BTNode<T>* ptr = root;
	do
	{
		if (ptr->info == key)
			return true;
		else if (key > ptr->info)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	} while (ptr);
	return false;
}
template <typename T>
void BST<T>:: insert(T val)
{
	if (!root)
	{
		root = new BTNode<T>(val);
		return;
	}
	BTNode<T>* ptr;
	BTNode<T>* prev = root;
	ptr = (val >= root->info ? root->right : root->left);
	while (ptr)
	{
		prev = ptr;
		ptr = (val >= ptr->info ? ptr->right : ptr->left);
	} 
	if (!prev->left && !prev->right)
	{
		if(val>=prev->info)
			prev->right = new BTNode<T>(val);
		else
			prev->left = new BTNode<T>(val);
	}
	else if(!prev->left)
		prev->left = new BTNode<T>(val);
	else
		prev->right = new BTNode<T>(val);
}
template <typename T>
void BST<T>::preOrder()
{
	if (!root)
		return;
	cout << root->info << ' ';
	if (root->left)
		descendantsDisplay(root->left);
	if (root->right)
		descendantsDisplay(root->right);
}
template <typename T>
void BST<T>::descendantsDisplay(BTNode<T>* ptr)
{
	cout << ptr->info << ' ';
	if (ptr->left)
		descendantsDisplay(ptr->left);
	if (ptr->right)
		descendantsDisplay(ptr->right);
}
template <typename T>
void BST<T>:: remove(T val)
{
	if (!root)
		return;
	if (root->info == val)
	{
		if (!root->left && !root->right)
			root = nullptr;
		else if (!root->left)
			root = root->right;
		else if (!root->right)
			root = root->left;
		else
			root->info = removeDegree2Node(root);
		return;
	}
	removeElem(val);
}
template <typename T>
void BST<T>:: removeElem(T key)
{
	if (!root->left && !root->right)
		return;
	BTNode<T>* ptr = (key >= root->info ? root->right : root->left);
	BTNode<T>* prev = root;
	while (ptr)
	{
		if (key == ptr->info)
		{
			if (!ptr->left && !ptr->right)
			{
				if (prev->left == ptr)
					prev->left = nullptr;
				else
					prev->right = nullptr;
				delete ptr;
			}
			else if (!ptr->right && ptr->left)
			{
				if (prev->left == ptr)
					prev->left = ptr->left;
				else
					prev->right = ptr->right;
				delete ptr;
			}
			else if (!ptr->left && ptr->right)
			{
				if (prev->left == ptr)
					prev->left = ptr->right;
				else
					prev->right = ptr->right;
				delete ptr;
			}
			else
				ptr->info = removeDegree2Node(ptr);
			return;
		}
		else if (key > ptr->info)
		{
			prev = ptr;
			ptr = ptr->right;
		}
		else
		{
			prev = ptr;
			ptr = ptr->left;
		}
	}
}
template <typename T>
T BST<T>::removeDegree2Node(BTNode<T>* ptr)
{
	BTNode<T>* prev = ptr;
	ptr = ptr->right;
	while (ptr->left)
	{
		prev = ptr;
		ptr = ptr->left;
	}
	if (prev->right == ptr)
		prev->right = ptr->right;
	else
		prev->left = ptr->right;
	T temp = ptr->info;
	delete ptr;
	return temp;
}
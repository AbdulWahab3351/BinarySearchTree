#ifndef BST_H
#define BST_H
#include "BTNode.h"
template <typename T>
class BST
{
	BTNode<T>* root;

	void removeElem(T key);
	void descendantsDisplay(BTNode<T>* ptr);
	T removeDegree2Node(BTNode<T>* ptr);
public:
	BST();
	void insert(T val);
	void remove(T val);
	bool search(T val);

	void preOrder();
};
#endif // !BST_H



#include<iostream>
using namespace std;
#include"BST.h"

int main()
{
	BST<int> b;
	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(3);
	b.insert(6);
	b.insert(15);
	b.insert(35);
	b.insert(5);
	b.insert(9);
	b.insert(16);
	
	b.insert(37);
	b.preOrder();
	b.remove(6);
	cout << '\n';
	b.preOrder();
	return 0;
}
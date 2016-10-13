#include "stdafx.h"
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree bst;
	BinarySearchTree bst2 = bst;

	bst.insert_integer (2);
	bst.insert_integer (7);
	bst.insert_integer (6);

	cout << bst.search_tree (11) << bst.search_tree (7) << endl;

	system ("pause");

    return 0;
}
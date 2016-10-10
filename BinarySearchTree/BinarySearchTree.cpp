// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct node {
	int value;
	struct node* left;
	struct node* right;
};

struct node* root = nullptr;

void insert_integer (struct node** tree, int value)
{
	if (*tree == nullptr)
	{
		*tree = new node;
		(*tree)->value = value;
		(*tree)->left = nullptr;
		(*tree)->right = nullptr;
	}
	else
	{
		if (value > (*tree)->value)
		{
			if ((*tree)->right != nullptr)
			{
				insert_integer (&((*tree)->right), value);
			}
			else
			{
				(*tree)->right = new node;
				(*tree)->right->value = value;
				(*tree)->right->left = nullptr;
				(*tree)->right->right = nullptr;
			}
		}
		else if (value < (*tree)->value)
		{
			if ((*tree)->left != nullptr)
			{
				insert_integer (&((*tree)->left), value);
			}
			else
			{
				(*tree)->left = new node;
				(*tree)->left->value = value;
				(*tree)->left->left = nullptr;
				(*tree)->left->right = nullptr;
			}
		}
		else if (value == (*tree)->value)
		{
			cout << "The tree has already had a node of the same value: " << (*tree)->value << endl;
		}
	}
}

void print_tree (struct node* tree) 
{
	if (tree)
	{
		if (tree->left)
			print_tree (tree->left);

		cout << tree->value << endl;

		if (tree->right)
			print_tree (tree->right);
	}
	else
	{
		cout << "The tree is empty!" << endl;
	}
}

void terminate_tree (struct node** tree)
{
	if (*tree)
	{
		if ((*tree)->left)
			terminate_tree (&((*tree)->left));

		if ((*tree)->right)
			terminate_tree (&((*tree)->right));

		delete (*tree);
		*tree = nullptr;
	}
	else
	{
		cout << "The tree is empty!" << endl;
	}
}

int main()
{
	insert_integer (&root, 2);
	insert_integer (&root, 9);
	insert_integer (&root, 3);

	print_tree (root);

	terminate_tree (&root);

	system ("pause");

    return 0;
}
// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree () : root (nullptr) {}
BinarySearchTree::~BinarySearchTree () {

	if (root)
	{
		_terminate_tree (&root);
	}
}

void BinarySearchTree::insert_integer (int value)
{
	_insert_integer (&root, value);
}

void BinarySearchTree::print_tree ()
{
	_print_tree (root);
}

void BinarySearchTree::terminate_tree ()
{
	_terminate_tree (&root);
}

bool BinarySearchTree::search_tree (int value) {
	return _search_tree (root, value);
}

void BinarySearchTree::_insert_integer (struct node** tree, int value)
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
			_insert_integer (&((*tree)->right), value);
		}
		else if (value < (*tree)->value)
		{
			_insert_integer (&((*tree)->left), value);
		}
		else if (value == (*tree)->value)
		{
			cout << "The tree has already had a node of the same value: " << (*tree)->value << endl;
		}
	}
}

void BinarySearchTree::_print_tree (struct node* tree) 
{
	if (tree)
	{
		if (tree->left)
			_print_tree (tree->left);

		cout << tree->value << endl;

		if (tree->right)
			_print_tree (tree->right);
	}
	else
	{
		cout << "The tree is empty!" << endl;
	}
}

void BinarySearchTree::_terminate_tree (struct node** tree)
{
	if (*tree)
	{
		if ((*tree)->left)
			_terminate_tree (&((*tree)->left));

		if ((*tree)->right)
			_terminate_tree (&((*tree)->right));

		delete (*tree);
		*tree = nullptr;
	}
	else
	{
		cout << "The tree is empty!" << endl;
	}
}

bool BinarySearchTree::_search_tree (struct node* tree, int value) {
	
	if (tree)
	{
		if (tree->value	== value)
			return true;
		else if (tree->value > value)
			return _search_tree (tree->left, value);
		else
			return _search_tree (tree->right, value);
	}

	return false;
}
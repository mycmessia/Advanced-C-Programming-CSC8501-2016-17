#pragma once

#ifndef BINARY_SERACH_TREE
#define BINARY_SERACH_TREE

struct node {
	int value;
	struct node* left;
	struct node* right;
};

class BinarySearchTree
{
public:
	BinarySearchTree ();
	~BinarySearchTree ();

	void insert_integer (int value);
	void print_tree ();
	void terminate_tree ();
	bool search_tree (int value);

private:
	struct node* root;

	void _insert_integer (struct node** tree, int value);
	void _print_tree (struct node* tree);
	void _terminate_tree (struct node** tree);
	bool _search_tree (struct node* tree, int value);
};

#endif
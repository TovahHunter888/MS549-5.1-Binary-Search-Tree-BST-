#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include "BST.h"
#include <vector>
#include <climits>
using namespace std;

// Code in this file are referenced from Geek for Geek website

// Function to perform inorder tree traversal 
void inorder(Node* root)
{
	if (root != NULL) //Check if root is not NULL
	{
		inorder(root->left); //Traverse left subtree
		cout << root->key << " " << root->count << " "; //Visit current node
		inorder(root->right); //Travers right subtree
	}
}

//Function to insert a new node with a given key in the BST
Node* insert(Node* node, int key)
{
	if (node == NULL) // if tree is empty, return a new node
	{
		return new Node(key);
	}

	if (key == node->key) // if key exists in BST,increment count and return
	{
		node->count++;
		return node;
	}

	if (key < node->key) // otherwise, recur down the tree
	{
		node->left = insert(node->left, key);
	}
	else
	{
		node->right = insert(node->right, key);
	}
	return node; // Unchanges node pointer is returned
};


// A non- empty BST return the node with minimum key value found in that tree. The entire tree does not have to get searched.
Node* minValueNode(Node* node)
{
	Node* currrent = node;

	// loop down to find the leftmose leaf
	while (currrent->left != NULL)
	{
		currrent = currrent->left;
	}
	return currrent;
}

// A BST and a key. FUnction to delete a given key and return root of modified tree
Node* deleteNode(Node* root, int key)
{
	//Base case
	if (root == NULL)
	{
		return root;
	}
	// If the key to be deleted is smaller than the root key, put it in the left subtree
	if (key < root->key)
	{
		root->left = deleteNode(root->left, key);
	}
	// If the key to be deleted is greater than the root key, put it in the right subtree
	else if (key > root->key)
	{
		root->right = deleteNode(root->right, key);
	}
	// If the key is the same as root key
	else
	{
		// If key is duplicate, decrement count and return
		if (root->count > 1)
		{
			root->count--;
			return root;
		}

		// else delte the node with only one child or no child
		if (root->left == NULL)
		{
			Node* curr = root->right;
			delete root;
			return curr;
		}
		else if (root->right == NULL)
		{
			Node* curr = root->left;
			delete root;
			return curr;
		}

		// node with two children get the inorder successor (smallest into the right tree
		Node* nm = minValueNode(root->right);

		//copy the inorder successor content to this node
		root->key = nm->key;
		root->count = nm->count;

		//Make sure successor gets deleted by delete node call, set count to 0
		nm->count = 0;

		//delete inorder successor
		root->right = deleteNode(root->right, nm->key);
	}
	return root;
}
	// Function to find the node with maximun value. This will be the rightmost leaf node
	//code referenced from Geek for Geek and rathbhupendra
int findMax(Node * root)
{
	Node* current = root;
	// Traverse to the rightmost node, which will have the maximum key
	while (current->right != NULL)
	{
		current = current->right;
	}
	return current->key; // Reeturn the key of the rightmost (maxium) node
}
// Find the node with data passed
//Function to search a key in a BST
Node* search(Node* root, int key)
{
	// Case for if root is null or key ia present at the root
	if (root == NULL || root->key == key )
	{
		return root;
	}


	// Key is greater than root key
	if (root->key < key)
	{
		return search(root->right, key);
	}

	// Key is smaller than root key
	return search(root->left, key);
}

// Function to find all the leaf nodes in the BST
vector<Node*> findLeafNodes(Node* root)
{
	vector<Node*> leafNodes;
	if (root == NULL)
	{
		return leafNodes;
	}
	if(root->left == NULL && root->right == NULL)
	{
		leafNodes.push_back(root); // Add leaf node to the list
	}

	// Recursively find leaf node in the left and right subtrees
	vector<Node*> leftLeafs = findLeafNodes(root->left);
	vector<Node*> rightLeafs = findLeafNodes(root->right);

	// append the results from the left and right subtrees
	leafNodes.insert(leafNodes.end(), leftLeafs.begin(), leftLeafs.end());
	leafNodes.insert(leafNodes.end(), rightLeafs.begin(), rightLeafs.end());

	return leafNodes;
}

//Function to find the nodes with one child
vector<Node*> findNodesOneChild(Node* root)
{
	vector<Node*> nodesOneChild;
	if (root == NULL)
	{
		return nodesOneChild;
	}
	// if node has exactly one child (either left or riht but not both)
	if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right))
	{
		nodesOneChild.push_back(root); 
	}

	// Recursively find nodes with one child in the left and right subtrees
	vector<Node*> leftNodes =  findNodesOneChild(root->left);
	vector<Node*> rightNodes = findNodesOneChild(root->right);

	// Append the results from the left and right subtrees
	nodesOneChild.insert(nodesOneChild.end(), leftNodes.begin(), leftNodes.end());
	nodesOneChild.insert(nodesOneChild.end(), rightNodes.begin(), rightNodes.end()); 

	return nodesOneChild;
}

//Function to find the nodes with Two children
vector<Node*> findNodesTwoChildren(Node* root)
{
	vector<Node*> nodesTwoChildren;
	if (root == NULL)
	{
		return nodesTwoChildren;
	}

	// if the node has exactly two children (both left and right)
	if (root->left != NULL && root->right != NULL)
	{
		nodesTwoChildren.push_back(root);
	}

	//Recursively find nodes with two children in the left and right subtrees
	vector<Node*> leftNodes = findNodesTwoChildren(root->left);
	vector<Node*> rightNodes = findNodesTwoChildren(root->right);

	//Append the results from the left and right subtrees
	nodesTwoChildren.insert(nodesTwoChildren.end(), leftNodes.begin(), leftNodes.end());
	nodesTwoChildren.insert(nodesTwoChildren.end(), rightNodes.begin(), rightNodes.end());

	return nodesTwoChildren;
}

// Function to test deletion on an empty tree
void testDeletion(Node*& root)
{
	// Dalete all nodes, attempting to delete nodes from an empty BST
	if (root == NULL)
	{
		cout << "Tree is empty, procedd with deletion attempt" << endl;
	}

	//Attempt to delete a random node 
	int randomKey = rand() % 100000; // Random delete attempt from an empty tree
	cout << "Attempting to delete key: " << randomKey << endl;
	root = deleteNode(root,randomKey); // Delete the node

	//Check the final tree using inorder reversal
	cout << "Final tree (should be empty): ";
	inorder(root); // Should print nothing because tree is empty
	cout << endl;
	
}


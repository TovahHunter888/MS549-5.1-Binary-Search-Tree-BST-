#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;

// The code in this header file are referenced from Geeks for Geeks website

// Node class declaration
class Node
{
public:
	int data;
	int key; // key values of the node
	int count; // count value to track occurrances
	Node* left; // Leftchild pointer
	Node* right; //Rightchild pointer
	Node* node;
	Node* root; 

	//Constructor to intialize the node with a given value;;
		Node(int x)
		{
			key = x;
			count = 1;
			left = NULL;
			right = NULL;
		}
	
};



// Function prototypes go here
Node* insert(Node* node, int key);
void inorder(Node* root);
Node* minValueNode(Node* node);
Node* deleteNode(Node* root, int key);
int findMax(Node* root);
Node* search(Node* root, int key);
vector< Node*> findLeafNodes(Node* root); // function to find all leaf nodes
vector<Node*> findNodesOneChild(Node* root); // function to find nodes with one child
vector<Node*> findNodesTwoChildren(Node* root); // function to find nodes with two children
void testDeletion(Node*& root); // Function to delete node from an empty tree

//Files class declaration
class Files
{
public:
	 // Root node of the tree
	//root = NULL;
	//constructor intialize Files object
	//Files(); // Constructor declaration

	
};


#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include "BST.h"
#include <vector>
#include <climits>
using namespace std;

// code referenced from  rathbhupendra on Geek for Geek website
int main()
{
	srand(time(0)); // set seed for random number generator
	// Create an empty BST Tree
	Node* root = NULL;

	//Measure time for adding 100 random nodes and measure the time for insertion  
	auto start = std::chrono::high_resolution_clock::now();  // start the timer

	for (int i = 0; i < 100; i++)
	{
		root = insert(root, rand() % 1000); // insert random numbers between 0 and 999
	}
	// Measure the elapsed time
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast <std::chrono::milliseconds>(end - start);
	std::cout << "Inserting 100 elements took" << duration.count() << "  milliseconds ";



	//Measure time for adding 1000 random nodes and measure the time for insertion  
	start = std::chrono::high_resolution_clock::now();  // start the timer

	for (int i = 0; i < 1000; i++)
	{
		root = insert(root, rand() % 1000);
	}
	// Measure the elapsed time
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast <std::chrono::milliseconds>(end - start);
	std::cout << "Inserting 1000 elements took " << duration.count() << " milliseconds ";

	//Measure time for adding 10000 random nodes and measure the time for insertion  
	start = std::chrono::high_resolution_clock::now();  // start the timer

	for (int i = 0; i < 10000; i++)
	{
		root = insert(root, rand() % 10000);
	}
	// Measure the elapsed time
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast <std::chrono::milliseconds>(end - start);
	std::cout << "Inserting 10000 elements took " << duration.count() << "milliseconds ";

	//Measure time for adding 100000 random nodes and measure the time for insertion  
	start = std::chrono::high_resolution_clock::now();  // start the timer

	for (int i = 0; i < 100000; i++)
	{
		root = insert(root, rand() % 100000);
	}
	// Measure the elapsed time
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast <std::chrono::milliseconds>(end - start);
	std::cout << "Inserting 100000 elements took " << duration.count() << " milliseconds ";


	//Print  the BST using inorder traversal before the deletion
	cout << "BST after random insertions:" << endl;
	if (root == NULL)
	{
		cout << "BST is empty " << endl;
	}
	else
	{
		inorder(root); // output the tree structure using inorder traversal
	}
	cout << endl;



	// Delete a node with no children
	vector<Node*> leafNodes = findLeafNodes(root);
	if (!leafNodes.empty())
	{
		// Randomly select a leaf node to delete
		Node* leafToDelete = leafNodes[rand() % leafNodes.size()];

		//Delete the leaf node
		cout << "Deleting node with key " << leafToDelete->key << " ";
		root = deleteNode(root, leafToDelete->key);
		//cout << "BST after deleting leaf node with no child " << leafToDelete->key << " ";
		//inorder(root);
		cout << endl;
	}


	//Find the nodes with exactly one child to delete it
	//Delete a node with (one child)
	vector<Node*> nodesOneChild = findNodesOneChild(root);
	if (!nodesOneChild.empty())
	{
		//Randomly select node with one child
		Node* nodeToDelete = nodesOneChild[rand() % nodesOneChild.size()];

		//Delete the randomly selected node with on child
		cout << "Deleting node with key " << nodeToDelete->key << " one child";
		root = deleteNode(root, nodeToDelete->key);

		/*//Print the BST tree after deletion
		cout << "BST after deleting node with one child: " << endl;
		inorder(root);
		cout << endl;
	}
	else
	{
		cout << "No nodes with one child found. " << endl;
	}
	*/

	//Delete a node (two children)
	//Find nodes exactly two children
		vector<Node*> nodesTwoChildren = findNodesTwoChildren(root);
		if (!nodesTwoChildren.empty())
		{
			//Randomely se;ect a node with two children
			Node* nodeToDelete = nodesTwoChildren[rand() % nodesTwoChildren.size()];

			//Delete the randomly selected node with two children
			cout << "Deleting node with key " << nodeToDelete->key << " two children: ";
			root = deleteNode(root, nodeToDelete->key);

			/*//Print the BST after deletiion
			cout << "BST after deleting node with two children: " << endl;
			inorder(root);
			cout << endl;*/
		}


		//Delete a node (duplicate)
		//Insert a duplicate node
		int duplicateValue = rand() % 100; // Random value to insert
		cout << " Inserting duplicate value: " << duplicateValue << endl;
		root = insert(root, duplicateValue); // Insert the same value again to test duplicate deletion

		//Print tree structure after inserting the duplicate
		cout << "BST after inserting duplicate value:" << endl;
		inorder(root);
		cout << endl;

		//Delete the duplicate node (after decrementing count)
		cout << "Deleting duplicate value: " << duplicateValue << endl;
		root = deleteNode(root, duplicateValue);

		//Print the tree structure after deletion
		cout << "BST after deleting duplicate value: " << endl;
		inorder(root);
		cout << endl;

		//Test the deletion on an empty tree
		testDeletion(root);



		//call function to find maximum 
		cout << "Maximum elemet is " << findMax(root) << endl;

		return 0;
	}
}

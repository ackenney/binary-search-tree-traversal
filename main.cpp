// This program traverses a Binary Search Tree in-order, pre-order,and post-order

#include<iostream>
#include<fstream>

using std::ofstream;
using std::ifstream;
using std::cout;



class BinarySearchTree
{

private:
	ofstream outFile;
	struct node
	{
		int data;
		node* leftSubTree;
		node* rightSubTree;

	};// End of struct

	node* root;// root pointer

public:
	void insert(int x);
	BinarySearchTree();
};



int main()
{
	// Declaring file variables
	ifstream inFile;
	ofstream outFile;
	int temp = 0;

	// Opening i/o file
	inFile.open("input.txt");
	outFile.open("output.txt");
	
	//checking if i/o files opened
	if (!inFile.good() || !outFile.good())
	{
		cout << "Error opening file:\n";
		outFile << "Error opening file:\n";
	}

	// Closing i/o files files
	inFile.close();
	outFile.close();
	return 0;
}


BinarySearchTree::BinarySearchTree() // constructor
{
	root = NULL;
	outFile.open("output");

} // End of constructor


void BinarySearchTree::insert(int x)
{
	// Declaring pointers and setting them to null
	node* tree = new node;
	node* parent;
	tree->data = x;
	tree->leftSubTree = NULL;
	tree->rightSubTree = NULL;
	parent = NULL;

	// Checking if it is creating a new tree
	if (root == NULL) // 
	{
		root = tree;
	}
	else
	{
		// Creating a local pointer and setting it to the root node
		node* locPtr;
		locPtr = root;

		while (locPtr != NULL)
		{
			parent = locPtr;
			if (tree->data >= locPtr->data)
			{
				locPtr = locPtr->rightSubTree;
			}
			else
			{
				locPtr = locPtr->leftSubTree; // L < r
			}
		}

		if (tree->data <= parent->data)
		{

			parent->leftSubTree = tree; // r < R
		}
		else
		{
			parent->rightSubTree = tree; //L < r
		}
	}


}// End of insert function
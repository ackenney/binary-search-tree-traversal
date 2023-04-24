// This program traverses a Binary Search Tree in-order, pre-order,and post-order

#include<iostream>
#include<fstream>

using std::ofstream;
using std::ifstream;
using std::cout;
using std::endl;



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
	void search(int x);
	void inOrder(node* x);
	void preOrder(node* x);
	void postOrder(node* x);
	void print();
	BinarySearchTree();
};



int main()
{
	// Declaring file variables
	ifstream inFile;
	ofstream outFile;
	std::string fileName;
	int temp = 0;

	// Opening i/o file
	std::cout << "Enter file name: "; std::cin >> fileName;
	inFile.open("input.txt");
	outFile.open("output.txt");
	
	//checking if i/o files opened
	if (!inFile.good() || !outFile.good())
	{
		cout << "Error opening file:\n";
		outFile << "Error opening file:\n";
	}


	BinarySearchTree BinarySearchTreeObj;

	//insert data into bst
	while (inFile >> temp)
	{
		BinarySearchTreeObj.insert(temp);

	}

	// Printing each order
	BinarySearchTreeObj.print();

	// Testing the search function with two hardcoded known values, one in the data set given and one not.
	// In the program guide it did not say anything about testing this, but I still included it. 
	BinarySearchTreeObj.search(15);
	BinarySearchTreeObj.search(2);

	// Closing i/o files files
	inFile.close();
	outFile.close();
	return 0;
}


BinarySearchTree::BinarySearchTree() // constructor
{
	root = NULL;
	outFile.open("output.txt");

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

void BinarySearchTree::search(int x)
{

	node* locPtr = root;
	bool foundFlag = false;

	while (locPtr != NULL)
	{

		if (locPtr->data == x)
		{
			cout << endl << x << " is in the tree\n\n";
			outFile << endl << x << " is in the tree\n\n";


			return;
		}

		if (x < locPtr->data)
		{
			locPtr = locPtr->leftSubTree;
		}
		else
		{
			locPtr = locPtr->rightSubTree;
		}


	}
	cout << endl << x << " is not the tree\n\n";
	outFile << endl << x << " is not the tree\n\n";
	return;
}

void BinarySearchTree::inOrder(node* x)
{
	// In-order: LrR
	node* tempPtr = x;

	if (tempPtr != NULL) // Declaring temp pointer
	{
		inOrder(tempPtr->leftSubTree);  // L
		cout << tempPtr->data << " ";	// r (output to console)
		outFile << tempPtr->data << " ";// r (output to file)
		inOrder(tempPtr->rightSubTree); // R

	}
}

void BinarySearchTree::preOrder(node* x)
{
	// Pre-order: rLR

	node* tempPtr = x; // Declaring temp pointer

	if (tempPtr != NULL)
	{
		cout << tempPtr->data << " ";	 // r (output to console)
		outFile << tempPtr->data << " ";	 // r (output to console)
		preOrder(tempPtr->leftSubTree);  // L
		preOrder(tempPtr->rightSubTree); // R
	}

} // End of pre-order function

void BinarySearchTree::postOrder(node* x)
{
	// Post-Order: LRr
	node* tempPtr = x; // Declaring temp pointer

	if (tempPtr != NULL)
	{

		postOrder(tempPtr->leftSubTree);  // L
		postOrder(tempPtr->rightSubTree); // R
		cout << tempPtr->data << " ";	  // r (output to console)
		outFile << tempPtr->data << " ";  // r (output to file)
	}

} // End of post-order function

void BinarySearchTree::print()
{
	cout << "Post-order\n"; // output to console
	outFile << "Post-order\n"; // output to file
	postOrder(root);
	cout << endl << endl;
	outFile << endl << endl;

	cout << "In-order\n"; // output to console
	outFile << "In-order\n"; // output to file
	inOrder(root);
	cout << endl << endl;
	outFile << endl << endl;

	cout << "Pre-order\n"; // output to console
	outFile << "Pre-order\n"; // output to file
	preOrder(root);
	cout << endl << endl;
	outFile << endl << endl;
}



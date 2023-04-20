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
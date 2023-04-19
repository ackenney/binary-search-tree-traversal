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
	return 0;
}
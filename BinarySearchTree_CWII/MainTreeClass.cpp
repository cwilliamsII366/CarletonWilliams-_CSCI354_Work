//Name: Carleton Williams II
//StudentID: 03028817
//Class: CSCI-354 Com-Sci III
#include <iostream>
#include "TreeNode.h"
using namespace std;


int main() {
	//Root Node
	TreeNode tree;
	TreeNode::Node* root = tree.newNodeAppending(0);
	//Array of Nodes to be inserted
	int arr[] = { 0,1,3,6,-1,2,5,7,-3,10,-2,-100,-9,20,8 };
	//Display numbers to be inserted
	cout << "Numbers to be inserted into tree: ";
	for (int i = 0; i < sizeof(arr) / sizeof(arr[i]); i++) {
		tree.insertToTree(root, arr[i]);
		cout << arr[i] << " ";
	}
	//Display all orders of tree
	cout << "\nPreOrder" << endl;
	tree.preOrder(root);
	cout << "\nInorder" << endl;
	tree.inOrder(root);
	cout << "\nPostOrder" << endl;
	tree.postOrder(root);


	//Check to see BST is empty
	cout << "\nThe following below is true (1) or false (0):" << endl;
	cout << "Is BST Tree Empty? ";
	cout << tree.isEmpty(root) << endl;

	//Check to see if it is a full BST
	cout << "Is it a Full BST Tree? ";
	cout << tree.isFull(root) << endl;

	//Check to see if 7 in tree. 1 is true, 0 is false
	cout << "Is 7 in the tree? " << tree.isFound(root, 7) << endl;

	//Check to see if -100 is in tree. 1 is true, 0 is false
	cout << "Is -100 in the tree? " << tree.isFound(root, -100) << endl;

	//Check to see if 10000 is in tree. 1 is true, 0 is false
	cout << "Is 10000 in the tree? " << tree.isFound(root, 10000) << endl;

	//Delete the node that contains 6
	cout << "\nDelete 6 from the tree: ";
	tree.Deletion(root, 6);

	//Display new tree without 6
	cout << "\nNew Tree" << endl;
	cout << "Pre Order" << endl;
	tree.preOrder(root);
	cout << "\nIn Order" << endl;
	tree.inOrder(root);
	cout << "\nPost Order" << endl;
	tree.postOrder(root);

	//Delete the root node
	cout << "\nDelete the root (0) from the tree: ";
	tree.Deletion(root, root->data);

	//Display new tree without the original root node '0'
	cout << "\nNew Tree" << endl;
	cout << "Pre Order" << endl;
	tree.preOrder(root);
	cout << "\nIn Order" << endl;
	tree.inOrder(root);
	cout << "\nPost Order" << endl;
	tree.postOrder(root);

	//Delete the node that contains -100
	cout << "\nDelete -100 from the tree: " << endl;
	tree.Deletion(root, -100);
	//Display new tree without -100
	cout << "New Tree" << endl;
	cout << "Pre Order" << endl;
	tree.preOrder(root);
	cout << "\nIn Order" << endl;
	tree.inOrder(root);
	cout << "\nPost Order" << endl;
	tree.postOrder(root);
	return 0;
}




// Name: Carleton Williams II
//StudentID: 03028817	
//Class: CSCI-354 Com-Sci III
#include "TreeNode.h"
#include <iostream>
using namespace std;

/// <summary>
/// Inserts the newly added node within to BST. 
/// </summary>
/// <param name="root"></param> Current node of the BST
/// <param name="key"></param> Data of the node to be inserted
/// <returns></returns> Newly added node in the BST
TreeNode::Node* TreeNode::insertToTree(Node* root, int key) {
	//If the key is greater than the current node's data. 
	//And there is no right child. Insert it to the right of the current node
	if (root->data < key && !root->right) {
		Node* node = new Node();
		node->data = key;
		node->left = nullptr;
		node->right = nullptr;
		root->right = node;
	}
	//If the key is less than the current node's data. 
	//And there is nol left child. Insert it to the left of the current node
	else if (root->data > key && !root->left) {
		Node* node = new Node();
		node->data = key;
		node->left = nullptr;
		node->right = nullptr;
		root->left = node;
	}//If the key is greater than the current node's data.
	//But the node already has a right child. Traverse to the right of the current node
	else if (root->data < key && root->right) {
		insertToTree(root->right, key);
	}
	//If the key is less than the current node's data.
	//But the node already has a right child. Traverse to the left of the current node
	else if (root->data > key && root->left) {
		insertToTree(root->left, key);
	}
	return NULL;
}
/// <summary>
/// Prints the BST in the PreOrder style
/// </summary>
/// <param name="node"></param> Current node of the BST
void TreeNode::preOrder(Node* node) {
	if (!node) {
		return;
	}
	else {
		cout << node->data << endl;
		preOrder(node->left);
		preOrder(node->right);
	}
	return;
}
/// <summary>
/// Prints the BST in the Inorder style
/// </summary>
/// <param name="node"></param> Current node of BST
void TreeNode::inOrder(Node* node) {
	if (!node) {
		return;
	}
	else {
		inOrder(node->left);
		cout << node->data << endl;
		inOrder(node->right);
	}
	return;
}
/// <summary>
/// Prints the BST in the PostOrder style
/// </summary>
/// <param name="node"></param> Current node of the BST
void TreeNode::postOrder(Node* node) {
	if (!node) {
		return;
	}
	else {
		postOrder(node->left);
		postOrder(node->right);
		cout << node->data << endl;
	}
	return;
}
/// <summary>
/// Checks if the BST is empty or not
/// </summary>
/// <param name="root"></param> Root of the BST
/// <returns></returns> True if the tree is empty. False otherwise
bool TreeNode::isEmpty(Node* root) {
	if (!root) {
		return true;
	}
	else {
		return false;
	}
}
/// <summary>
/// Checks if the BST is a Full BST. 
/// </summary>
/// <param name="node"></param> Current Node of the BST
/// <returns></returns> True if the BST is a full BST. False otherwise
bool TreeNode::isFull(Node* node) {
	//If the current node is NULL or if it doesn't have any chidren.
	//Then is it is a FULL BST
	if (!node || (!node->left && !node->right)) {
		return true;
	}// If the current node does have children, check to see if the children have
	// 0 or 2 children specifically
	else if (node->left && node->right) {
		return (isFull(node->left) && isFull(node->right));
	}
	else {
		return false;
	}
}
/// <summary>
/// Searches the BST for the specified node/key data
/// </summary>
/// <param name="node"></param> The current Node of the BST
/// <param name="key"></param> The key to be found in the BST
/// <returns></returns> True if the node/key was found. False otherwise
bool TreeNode::isFound(Node* node, int key) {

	if (!node) {
		return NULL;
	}
	else if (node->data == key) {
		return node;
	}
	else if (node->data < key) {
		isFound(node->right, key);
	}
	else if (node->data > key) {
		isFound(node->left, key);
	}
	else {
		cout << "No!" << endl;
		return NULL;
	}
}
/*
* Deletes a specified node and replace the node with either its children
* or NULL
* */
TreeNode::Node* TreeNode::Deletion(Node* node, int key) {
	//Base Case #1
	if (!node) {
		return NULL;
	}//Move to the left part of tree if key is less than the current
	//node's key
	else if (node->data > key) {
		node->left = Deletion(node->left, key);
	}
	//Move to the right part of tree if key is greater than the current
	//node's key
	else if (node->data < key) {
		node->right = Deletion(node->right, key);
	}
	else {
		//If the node doesn't have any children
		if (!node->left && !node->right) {
			Node* temp = node;
			delete temp;
			node = NULL;
		}//If the node has only a right child
		else if (!node->left && node->right) {
			Node* temp = node;
			node = node->right;
			delete temp;
		}//If the node only has a left child
		else if (node->left && !node->right) {
			Node* temp = node;
			node = node->left;
			delete temp;
			return node;
		}
		else {
			//Otherwise if the node has both children, move to the right
			//copy the child's data, assign it to the parent's node and 
			//do the same for the exceeding children of the right node's path
			Node* temp = node->right;
			node->data = temp->data;
			node->right = Deletion(node->right, node->right->data);
		}
	}
	//Return the node
	return node;
}


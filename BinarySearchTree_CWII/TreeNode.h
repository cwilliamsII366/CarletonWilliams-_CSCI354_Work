#pragma once
// Name: Carleton Williams II
//StudentID: 03028817	
//Class: CSCI-354 Com-Sci III
class TreeNode {
public:
	/// <summary>
	/// Structure of a node
	/// </summary>
	struct Node {
		int data;
		Node* left, * right;
	};
	//Appends the root
	Node* newNodeAppending(int key) {
		Node* node = new Node();
		node->data = key;
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}
	//Protoypes for the TreeClass
	Node* insertToTree(Node* root, int key);
	void preOrder(Node* root);
	void inOrder(Node* root);
	void postOrder(Node* root);
	bool isFull(Node* node);
	bool isEmpty(Node* root);
	bool isFound(Node* root, int key);
	Node* Deletion(Node* node, int key);
};
#include <iostream>
#include "Node.h"
#include "BST.h"
void BST::addNode(int val) {
	Node* node = new Node();
	Node* tmpRoot = nullptr;
	node->val = val;
	if (root == nullptr)
		root = node;
	else {
		Node* ptr = root;
		while (ptr != nullptr) {
			tmpRoot = ptr;
			if (node->val < ptr->val)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		if (node->val < tmpRoot->val)
			tmpRoot->left = node;
		else
			tmpRoot->right = node;
	}
}

Node* BST::removeSequence(Node* node, int _val) {
	if (node == nullptr) return node;
	else if (node->val > _val)
		node->left = removeSequence(node->left, _val);
	else if (node->val < _val)
		node->right = removeSequence(node->right, _val);
	else {
		Node* ptr = node;
		if (node->right == nullptr && node->left == nullptr) {
			delete node;
			node = nullptr;
		}
		else if (node->right == nullptr) {
			node = node->left;
			delete ptr;
		}
		else if (node->left == nullptr) {
			node = node->right;
			delete ptr;
		}
		else {
			ptr = searchMaxNode(node->left);
			node->val = ptr->val;
			node->left = removeSequence(node->left, ptr->val);
		}
	}
	return node;
}
void BST::removeNode(int val) {
	Node* ptr = root;
	removeSequence(ptr, val);
}

bool BST::searchValue(int val) {
	Node* ptr = root;
	Node* tmpRoot = nullptr;
	while (ptr != nullptr) {
		if (ptr->val == val) {
			cout << val << endl;
			return true;
		}
		else if (ptr->val > val)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	return false;
}
void BST::show() {
	inOrder(root);
	cout << endl;
}

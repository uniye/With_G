#include <iostream>
#include "Node.h"
#ifndef BISETR
#define BISETR

using namespace std;

class BST {
private:
	Node* root;
	Node* tail;
	void inOrder(Node* current) {
		if (current != nullptr) {
			inOrder(current->left);
			cout << current->val << "  ";
			inOrder(current->right);
		}
	}
	Node* searchMaxNode(Node* node) {
		if (node == NULL)
			return NULL;
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
	}
	Node* removeSequence(Node*, int);
public:
	BST() : root(nullptr) {};
	~BST() {};
	void addNode(int);
	bool searchValue(int);
	void removeNode(int);
	void show();
};
#endif

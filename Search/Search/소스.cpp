#include <iostream>
#include "Node.h"
#include "BST.h"

int main() {
	BST *bst = new BST;
	bst->addNode(10);
	bst->addNode(1);
	bst->addNode(4);
	bst->addNode(6);
	bst->addNode(5);
	bst->addNode(13);
	bst->addNode(7);
	bst->addNode(3);
	bst->show();

	bst->removeNode(13);
	bst->show();

	return 0;
}
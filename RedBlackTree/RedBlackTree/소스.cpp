#include <iostream>
#include <string>
using namespace std;

namespace Color{
	const enum NODE_COLOR : bool { BLACK = false, RED = true };
}


class Node{
private:
	int key;	// 노드의 unique한 key값
	bool color;	// 노드의 색깔
	Node* parent, * left, * right;	// 부모노드, 왼쪽 자식노드, 오른쪽 자식노드를 가리킨다.
	friend class RedblackTree;		// 레드블랙트리 클래스를 friend로 지정.
public:
	explicit Node(const int& paramKey = NULL, const bool paramColor = Color::BLACK,
		Node* paramParent = nullptr, Node* paramLeft = nullptr, Node* paramRight = nullptr)
		: key(paramKey), color(paramColor), parent(paramParent), left(paramLeft), right(paramRight) {}
};


class RedblackTree{
private:	
	int numOfElement;	
	Node* nil;	

private:	
	Node* getGrandNode(Node*);	
	Node* getUncleNode(Node*);	
	void leftRotate(Node*);		
	void rightRotate(Node*);	
	void insertFix(Node*);		
	void insertNode(Node*, const int& );
	void preOrderTraverse(Node*, std::string* , std::string ,const std::string& , const bool) const;
	std::string showTree(Node* ) const;	

public:	
	explicit RedblackTree() : numOfElement(0), nil(new Node(-1, Color::BLACK)) {
		nil->left = nil->right = nil->parent = nil;
	}
	void insertNode(const int& data) { insertNode(nil, data); }
	std::string showTree() const { return showTree(nil->right); }
};


Node* RedblackTree::getGrandNode(Node* cur){
	if (cur == nullptr || cur->parent == nullptr) return nullptr;
	return cur->parent->parent;
}

Node* RedblackTree::getUncleNode(Node* cur){
	Node* tempGrand(getGrandNode(cur));
	if (tempGrand == nullptr) return nullptr;
	if (cur->parent == tempGrand->left) return tempGrand->right;
	else return tempGrand->left;
}


void RedblackTree::leftRotate(Node* cur){
	Node* temp = cur->right;
	cur->right = temp->left;
	if (temp->left != nil) temp->left->parent = cur;
	temp->parent = cur->parent;
	if (cur->parent == nil) nil->right = temp;
	else if (cur == cur->parent->left) cur->parent->left = temp;
	else cur->parent->right = temp;
	temp->left = cur;
	cur->parent = temp;
}


void RedblackTree::rightRotate(Node* cur){
	Node* temp = cur->left;
	cur->left = temp->right;
	if (temp->right != nil) temp->right->parent = cur;
	temp->parent = cur->parent;
	if (cur->parent == nil) nil->right = temp;
	else if (cur == cur->parent->left) cur->parent->left = temp;
	else cur->parent->right = temp;
	temp->right = cur;
	cur->parent = temp;
}

void RedblackTree::insertFix(Node* cur){
	while (cur->parent->color == Color::RED){
		Node* grandNode(getGrandNode(cur));		
		Node* uncleNode(getUncleNode(cur));		
		if (cur->parent == grandNode->left){	
			if (uncleNode->color == Color::RED){	
				cur->parent->color = uncleNode->color = Color::BLACK;
				grandNode->color = Color::RED;
				cur = grandNode;	
			}
			else{
				if (cur == cur->parent->right){
					cur = cur->parent;	
					leftRotate(cur);	
				}
				cur->parent->color = !cur->parent->color;	
				grandNode->color = !grandNode->color;		
				rightRotate(grandNode);	
			}
		}
		else{
			if (uncleNode->color == Color::RED){
				cur->parent->color = uncleNode->color = Color::BLACK;
				grandNode->color = Color::RED;
				cur = grandNode;
			}
			else{
				if (cur == cur->parent->left){
					cur = cur->parent;
					leftRotate(cur);
				}
				cur->parent->color = !cur->parent->color;
				grandNode->color = !grandNode->color;
				rightRotate(grandNode);
			}
		}
	}
	nil->right->color = Color::BLACK;
}

void RedblackTree::insertNode(Node* root, const int& data){
	Node* parent, * tail;
	parent = nil;				
	tail = nil->right;		
	while (tail != nil){
		parent = tail;			
		int var = tail->key;
		if (data == var){
			cout << "[ERROR] Duplicated input value!" << endl;
			return;
		}
		else if (data < var) tail = tail->left;
		else tail = tail->right;
	}
	tail = new Node(data, Color::RED, parent, nil, nil);
	if (parent == nil){
		parent->right = tail;	
		tail->color = Color::BLACK;	
	}
	else if (data < parent->key) parent->left = tail;
	else parent->right = tail;

	this->numOfElement++;		
	insertFix(tail);		
}

void RedblackTree::preOrderTraverse(Node* root, std::string* stringBuilder, std::string padding, const std::string& pointer, const bool hasRightChild) const{
	std::string* paddingBuilder;
	if (root == nil) return;
	else{
		paddingBuilder = new std::string(padding);
		stringBuilder->append("\n").append(padding).append(pointer);
		if (root->color == Color::BLACK) stringBuilder->append("B");
		else stringBuilder->append("R");
		stringBuilder->append(to_string(root->key));

		if (hasRightChild) paddingBuilder->append("│  ");
		else paddingBuilder->append("   ");
	}

	preOrderTraverse(root->left, stringBuilder, *paddingBuilder, "├──", root->right != nullptr);
	preOrderTraverse(root->right, stringBuilder, *paddingBuilder, "└──", false);
	delete paddingBuilder;	
}

std::string RedblackTree::showTree(Node* root) const{
	if (this->numOfElement == 0){
		cout << "[ERROR] Can't perform 'show' function on empty tree!" << endl;
		return "";
	}

	std::string* str = new std::string();	
	if (root->color == Color::BLACK) str->append("B");
	else str->append("R");
	str->append(to_string(root->key));	

	preOrderTraverse(root->left, str, "", "├──", root->right != nullptr);
	preOrderTraverse(root->right, str, "", "└──", false);

	std::string returnStr = *str;	
	delete str;						
	return returnStr;				
}

int main(void){
	RedblackTree* myTree = new RedblackTree();
	if (myTree == nullptr){
		cout << "[ERROR] Tree memory allocation problem" << endl;
		return -1;
	}

	cout << "-------------------------------------" << endl;
	cout << "Commands:" << endl;
	cout << "   '+Key': Insert element" << endl;
	cout << "      'Q': Quit the test program" << endl;
	cout << "--------------------------------------" << endl;
	cout << "※ In tree draw, '├──key' is left child, '└──key' is right child ※" << endl;

	std::string userStr;

	while (true){
		cout << myTree->showTree() << endl;		

		cout << "Command: ";
		cin >> userStr;

		char userOption = userStr[0];		
		userStr.erase(0, 1);				
		int userVar = std::atoi(userStr.c_str());	
		if (userOption != '+' && userOption != 'Q' && userOption != 'q'){
			cout << "[ERROR] Wrong command! Input command again please" << endl;
			continue;
		}
		
		switch (userOption){
		case '+':
			myTree->insertNode(userVar);
			break;
		case 'Q': case 'q':
			cout << "Quit program!" << endl;
			delete myTree;
			return 0;
		}
	}
}
//출처] [자료구조] 레드블랙트리(Red black tree) C++ implementation 삽입연산 구현하기 | 작성자 임베디드쥰 :: 코드 너무 좋아서 여러번 보자.(나는 구현을 왜 못하는가...)


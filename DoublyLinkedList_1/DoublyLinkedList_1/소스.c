
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct Node {
	char* data[10];
	struct Node* next;
	struct Node* prev;
};
typedef struct Node Node;

int add_node(Node* head, char* item, char* fdata);
Node* findnode(Node* head, char* findw);
int strcmp_ptr(const char* ptr1, const char* ptr2);
Node* add_first(Node* head, char* item);
void printnode(Node* node);
int del(Node* head, char* fdata);

main() {
	Node* head = malloc(sizeof(struct Node));
	char list[10][10] = { "a","b","c","dd","e","f","g","h" };
	strcpy(head->data, list[0]);
	Node* h = head;
	int a = 1;
	for (; h != NULL; h = h->next) {
		Node* node = malloc(sizeof(struct Node));
		strcpy(node->data, list[a]);
		node->prev = h;
		h->next = node;
		if (a ==5){
			node->next = NULL;
			break;
		}
		a++;
	}
	Node* h1 = head;
	Node* h2 = add_first(h1,"ad");
	printnode(h2);
	del(h2,"dd");
	printnode(h2);
}

void printnode(Node* node) {
	for (; node != NULL; node = node->next) {
		printf("%s", node->data);
	}
	printf("\n");
}

Node* findnode(Node* head, char* fdata) {
	Node* findn = malloc(sizeof(struct Node));
	for (; head != NULL; head = head->next) {
		if (strcmp_ptr(head->data, fdata) == 1)
			findn = head;
	}
	return findn;
}

int strcmp_ptr(const char* ptr1, const char* ptr2) {
	for (int i = 0; ptr1[i] != '\0' || ptr2[i] != '\0'; ++i) {
		if (ptr1[i] != ptr2[i])
			return 0;
	}
	return 1;
}

int add_node(Node* head, char* item, char* fdata) {
	if (&head == NULL)
		return 0;
	else {
		Node* fd = findnode(head, fdata);
		Node* newnode = malloc(sizeof(struct Node));
		strcpy(newnode->data, item);
		newnode->next = fd->next;
		newnode->prev = head;
		fd->next->prev = newnode;
		fd->next = newnode;
		return 0;
	}
}

Node* add_first(Node* head, char* item) {
	Node* newnode = malloc(sizeof(struct Node));
	strcpy(newnode->data, item);
	newnode->prev = NULL;
	newnode->next = head;
	head->prev = newnode;
	return newnode;
}

int del(Node* head, char* fdata) {
	Node* fd = findnode(head, fdata);
	fd->prev->next = fd->next;
	fd->next->prev = fd->prev;
}
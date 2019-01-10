//============================================================================
// Name        : tree.cpp
// Author      : Nikhil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node {
	int data;
	node *l, *r;
};

class Tree {
	node *root;
public:
	Tree() {
		root = NULL;
	}
	node* createNN();
	void create();
	void display();
	void inorder(node *parent);
};

node* Tree::createNN() {

	node *nn = new node;
	cout << "\nEnter the data: ";
	cin >> nn->data;
	nn->l = nn->r = NULL;
	return nn;

}
void Tree::create() {
	node *nn, *temp;
	int num;

	cout << "\nEnter the number of nodes in Tree: ";
	cin >> num;

	for (int i = 0; i < num; i++) {

		nn = createNN();

		if (root == NULL)
			root = nn;
		else {
			temp = root;
			while (true) {
				if (nn->data < temp->data) {
					if (temp->l == NULL) {
						temp->l = nn;
						break;
					} else
						temp = temp->l;
				} else {
					if (temp->r == NULL) {
						temp->r = nn;
						break;
					} else
						temp = temp->r;
				}
			}
		}

	}
}

void Tree::inorder(node *parent) {

	if (parent == NULL)
		return;
	else {
		inorder(parent->l);
		cout << parent->data << " ";
		inorder(parent->r);
	}

}

void Tree::display() {
	cout << "\nTree in Inorder Traversal format: ";
	inorder(root);
	cout << endl;
}

int main() {

	Tree obj;

	int choice;

	do {
		cout << "\nEnter 1 to Create Tree\nEnter 2 to display Tree\nInput : ";
		cin >> choice;
		switch (choice) {
		case 1:
			obj.create();
			break;
		case 2:
			obj.display();
			break;
		default:
			break;
		}
	} while (choice < 2);

	return 0;
}

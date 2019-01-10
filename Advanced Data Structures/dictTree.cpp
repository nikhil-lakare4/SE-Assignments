//============================================================================
// Name        : tree.cpp
// Author      : Nikhil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

struct node {
	string keyword;
	string meaning;
	node *l, *r;
};

class Tree {
	node *root;
public:
	Tree() {
		root = NULL;
	}

	node* createNN();
	void addNN();
	void create();
	node* searchN(string key);
	void ModifyN(string key);
	void deleteN(string key);
	void display();
	void inorder(node *parent);
	void preorder(node *parent);
	void postorder(node *parent);
	void breadthfirst(node *parent);
};

node* Tree::createNN() {

	node *nn = new node;

	cout << "\nEnter the keyword: ";
	cin >> nn->keyword;
	cout << "Enter it's meaning: ";
	cin >> nn->meaning;
	nn->l = nn->r = NULL;
	return nn;

}

void Tree::addNN() {

	node *nn, *temp;

	nn = createNN();
	temp = root;

	while (true) {
		if (nn->keyword < temp->keyword) {
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

void Tree::create() {

	node *nn;
	int num;

	cout << "\nEnter the number of keywords to be added: ";
	cin >> num;
	for (int i = 0; i < num; i++) {

		if (root == NULL) {
			nn = createNN();
			root = nn;
		} else
			addNN();
	}
}
node* Tree::searchN(string key) {

	node *temp = root;

	while (temp != NULL) {
		if (key == temp->keyword) {
			cout << "\nKeyword Found!" << "\nMeaning: " << temp->meaning
					<< endl;
			return temp;
		} else if (key < temp->keyword) {
			temp = temp->l;
		} else {
			temp = temp->r;
		}
	}
	cout << "\nKeyword not found!";
	return NULL;
}

void Tree::inorder(node *parent) {

	if (parent == NULL)
		return;
	else {
		inorder(parent->l);
		cout << parent->keyword << " ";
		inorder(parent->r);
	}

}
void Tree::preorder(node *parent) {

	if (parent == NULL)
		return;
	else {
		cout << parent->keyword << " ";
		inorder(parent->l);
		inorder(parent->r);
	}

}
void Tree::postorder(node *parent) {

	if (parent == NULL)
		return;
	else {
		inorder(parent->l);
		inorder(parent->r);
		cout << parent->keyword << " ";
	}

}

void Tree::breadthfirst(node *parent) {

	queue<node*> Q;
	node *cn = parent;

	Q.push(cn);
	while (!Q.empty()) {

		cn = Q.front();
		cout << cn->keyword << " ";
		Q.pop();

		if (cn->l != NULL)
			Q.push(cn->l);
		if (cn->r != NULL)
			Q.push(cn->r);
	}

}

void Tree::deleteN(string key) {

	node *parent, *child, *temp, *tempparent;

	parent = child = root;
	temp = tempparent = NULL;

	while (child != NULL) {
		if (key == child->keyword) {

			if (child->l == NULL && child->r == NULL) {

				if (child == root) {
					delete (child);
					root = NULL;
					cout << "\nKeyword Found and Deleted! No tree exists now!"
							<< endl;
					return;
				} else if (parent->l == child) {
					parent->l = NULL;
					delete (child);
					cout << "\nKeyword Found and Deleted!" << endl;
					return;
				} else {
					parent->r = NULL;
					delete (child);
					cout << "\nKeyword Found and Deleted!" << endl;
					return;
				}

			} else if (child->l == NULL && child->r != NULL) {

				if (child == root) {
					root = child->r;
					delete (child);
					cout << "\nKeyword Found and Deleted!" << endl;
					return;
				} else if (parent->l == child) {
					parent->l = child->r;
					delete (child);
					cout << "\nKeyword Found and Deleted!" << endl;
					return;
				} else {
					parent->r = child->r;
					delete (child);
					cout << "\nKeyword Found and Deleted!" << endl;
					return;
				}

			} else if (child->l != NULL && child->r == NULL) {

				if (child == root) {
					root = child->l;
					delete (child);
					cout << "\nKeyword Found and Deleted!" << endl;
					return;
				} else if (parent->l == child) {
					parent->l = child->l;
					delete (child);
					cout << "\nKeyword Found and Deleted!" << endl;
					return;
				} else {
					parent->r = child->l;
					delete (child);
					cout << "\nKeyword Found and Deleted!" << endl;
					return;
				}

			} else {

				temp = child->r;
				tempparent = child;

				while (temp->l != NULL) {
					tempparent = temp;
					temp = temp->l;
				}

				child->keyword = temp->keyword;
				child->meaning = temp->meaning;

				if (tempparent->r == temp) {
					if (temp->r != NULL)
						tempparent->r = temp->r;
					else
						tempparent->r = NULL;
				} else {
					if (temp->r != NULL)
						tempparent->l = temp->r;
					else
						tempparent->l = NULL;
				}

				delete (temp);
				cout << "\nKeyword Found and Deleted!" << endl;
				return;

			}

		} else if (key < child->keyword) {
			parent = child;
			child = child->l;
		} else {
			parent = child;
			child = child->r;
		}
	}

	cout << "\nCannot Delete! Keyword not found!";

}

void Tree::ModifyN(string key) {

	node *cn = searchN(key);

	if (cn != NULL) {
		cout << "Enter it's New meaning: ";
		cin >> cn->meaning;
		cout << "\nKeyword Modified Successfully!";
	} else
		cout << "\nCannot Modify!";

}

void Tree::display() {

	cout << "\nTree in Inorder Traversal format:		";
	inorder(root);
	cout << endl;
	cout << "\nTree in Preorder Traversal format:		";
	preorder(root);
	cout << endl;
	cout << "\nTree in Postorder Traversal format: 		";
	postorder(root);
	cout << endl;
	cout << "\nTree in Breadth First Traversal format: 	";
	breadthfirst(root);
	cout << endl;

}

int main() {

	Tree obj;

	string key;

	int choice;

	do {
		cout << "\n-------------------------------------------"
				<< "\n-------------------------------------------"
				<< "\n               DICTIONARY                  "
				<< "\n-------------------------------------------"
				<< "\n-------------------------------------------\n"
				<< "\nEnter 1 to Create Dictionary\nEnter 2 to Add New Keyword\nEnter 3 to Search Keyword\nEnter 4 to Modify Keywordn\nEnter 5 to Delete node\nEnter 6 to Display Dictionary\nEnter 7 to exit\nInput : ";
		cin >> choice;
		switch (choice) {
		case 1:
			obj.create();
			cout << "\nDictionary of keywords created successfully!";
			break;
		case 2:
			obj.addNN();
			cout << "\nNew keyword added successfully!";
			break;
		case 3:
			cout << "\nEnter the keyword to be Searched: ";
			cin >> key;
			obj.searchN(key);
			break;
		case 4:
			cout << "\nEnter the keyword to be Modified: ";
			cin >> key;
			obj.ModifyN(key);
			break;
		case 5:
			cout << "\nEnter the keyword to be Deleted: ";
			cin >> key;
			obj.deleteN(key);
			break;
		case 6:
			obj.display();
			break;
		default:
			break;
		}
	} while (choice <= 6);

	return 0;
}

//============================================================================
// Name        : AS2.cpp
// Author      : Nikhil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

struct node {
	char data;
	node *l, *r;
};

class Tree {
	node *root;
	stack<node*> S1;
	stack<node*> S2;
	stack<node*> Stack, postStack;

public:
	Tree() {
		root = NULL;
	}
	node* createNN(char x);
	void inorder(node* parent);
	void preorder(node* parent);
	void postorder(node* parent);
	int priority(char x);
	void BuildTree(string S);

};

node* Tree::createNN(char x) {

	node *nn = new node;
	nn->data = x;
	nn->l = nn->r = NULL;
	return nn;
}

void Tree::inorder(node* parent) {

	node *cn = parent;

	while(cn != NULL || !Stack.empty()) {
		Stack.push(cn);
		cn = cn->l;
		while(cn == NULL && !Stack.empty()) {
			cn = Stack.top();
			Stack.pop();
			cout << cn->data << " ";
			cn = cn->r;
		}
	}


}

void Tree::preorder(node* parent) {

	node *cn = parent;
	Stack.push(cn);
	while(!Stack.empty()) {
		cn = Stack.top();
		Stack.pop();
		cout << cn->data << " ";
		if (cn->r != NULL)
			Stack.push(cn->r);
		if (cn->l != NULL)
			Stack.push(cn->l);
	}


}

void Tree::postorder(node* parent) {

	node *cn = parent;
	Stack.push(cn);
	while(!Stack.empty()) {
		cn = Stack.top();
		Stack.pop();
		postStack.push(cn);

		if (cn->l != NULL)
			Stack.push(cn->l);
		if (cn->r != NULL)
			Stack.push(cn->r);
	}

	while (!postStack.empty()) {
		cn = postStack.top();
		postStack.pop();
		cout << cn->data << " ";
	}

	cout << endl;


}

int Tree::priority(char x) {

	if (x == '^')
		return 3;
	else if (x == '*' || x == '/')
		return 2;
	else if (x == '+' || x == '-')
		return 1;
	else
		return 0;
}

void Tree::BuildTree(string S) {

	node *cn, *temp;
	temp = NULL;
	int length = S.size();

	for (int i = 0; i < length; i++) {
		cn = createNN(S[i]);
		if (S[i] == '^' || S[i] == '*' || S[i] == '/' || S[i] == '+'
				|| S[i] == '-') {
			if (S1.empty()) {
				S1.push(cn);
			} else if (priority(S1.top()->data) < priority(S[i])) {
				S1.push(cn);
			} else {
				while (!S1.empty()
						&& (priority(S1.top()->data) >= priority(S[i]))) {
					temp = S1.top();
					S1.pop();
					temp->r = S2.top();
					S2.pop();
					temp->l = S2.top();
					S2.pop();
					S2.push(temp);
				}
				S1.push(cn);
			}
		} else
			S2.push(cn);
	}
	while (!S1.empty()) {
		temp = S1.top();
		S1.pop();
		temp->r = S2.top();
		S2.pop();
		temp->l = S2.top();
		S2.pop();
		S2.push(temp);
	}

	root = temp;

	cout << "\nTree Built Successfully! ;)" << endl;
	cout << "\nTree in Inorder traversal format:	";
	inorder(root);
	cout << endl;
	cout << "\nTree in Preorder traversal format:	";
	preorder(root);
	cout << endl;
	cout << "\nTree in Postorder traversal format:	";
	postorder(root);
	cout << endl;
}

int main() {
	Tree T;
	string exp;

	cout << "Enter the expression: ";
	cin >> exp;

	T.BuildTree(exp);


}

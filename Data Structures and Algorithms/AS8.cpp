//============================================================================
// Name        : AS8.cpp
// Author      : Nikhil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

struct stack {
	char data[20];
	int top;
};

class bracks {
	stack s;
public:
	bracks() {
		s.top = -1;
	}
	void display();
	int isEmpty();
	int isFull();
	void Push(char x);
	void Pop();
	int compare(char, char);
	void isBalanced(char *exp);
};

void bracks::display() {
	cout << "Current stack is : ";
	for (int i = 0; i <= s.top; i++)
		cout << s.data[i];
	cout << endl;
}

int bracks::isEmpty() {
	if (s.top == -1)
		return 1;
	else
		return 0;
}

int bracks::isFull() {
	if (s.top == 20 - 1)
		return 1;
	else
		return 0;
}

void bracks::Push(char x) {
	s.top++;
	s.data[s.top] = x;
}

void bracks::Pop() {
	s.top--;
}

int bracks::compare(char a, char b) {
	if (a == '(' && b == ')')
		return 1;
	else if (a == '[' && b == ']')
		return 1;
	else if (a == '{' && b == '}')
		return 1;
	else
		return 0;
}

void bracks::isBalanced(char *exp) {
	int length = strlen(exp);
	for (int i = 0; i < length; i++) {
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
			if (!isFull())
				Push(exp[i]);
			else
				cout << "Error" << endl;
		}
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
			if(!isEmpty()) {
				if (compare(s.data[s.top], exp[i]))
					Pop();
				else
					cout << "Error" << endl;
			}
			else {
				cout << "Couldn't find opening bracket! Expression is Unbalanced :(" << endl;
				return;
			}
		}
	}

	if (isEmpty()) {
		cout << "Stack is Empty! Expression is Balanced :)" << endl;
	} else {
		cout << "Expression is Unbalanced :(" << endl;
		display();
	}
}

int main() {

	char *ex = new char[20];

	cout << "Enter the expression : ";
	cin >> ex;

	bracks B;
	B.isBalanced(ex);

	return 0;
}

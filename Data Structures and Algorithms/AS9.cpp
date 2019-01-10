//============================================================================
// Name        : AS9.cpp
// Author      : Nikhil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 20

struct stack {
	char data[MAX];
	int top;
};

struct intstack {
	int data[MAX];
	int top;
};

class postfix {
	stack S;
	intstack I;
	int count;
	char post[MAX];
	int values[3];
public:
	postfix() {
		S.top = -1;
		count = 0;
	}
	void display();
	int isEmptyS();
	int isFullS();
	void PushS(char x);
	void PopS();
	int isEmptyI();
	int isFullI();
	void PushI(char x);
	int PopI();
	int precedence(char);
	void operation(char *exp);
	void evaluate();
};

void postfix::display() {
	cout << "Postfix Expression is : ";
	for (int i = 0; i <= count; i++) {
		cout << post[i];
	}
	cout << endl;
}

int postfix::isEmptyS() {
	if (S.top == -1)
		return 1;
	else
		return 0;
}

int postfix::isEmptyI() {
	if (I.top == -1)
		return 1;
	else
		return 0;
}

int postfix::isFullS() {
	if (S.top == MAX - 1)
		return 1;
	else
		return 0;
}

int postfix::isFullI() {
	if (I.top == MAX - 1)
		return 1;
	else
		return 0;
}

void postfix::PushS(char x) {
	S.top++;
	S.data[S.top] = x;
}

void postfix::PushI(char x) {
	I.top++;
	I.data[I.top] = x;
}

void postfix::PopS() {
	S.top--;
}

int postfix::PopI() {
	I.top--;
	return I.data[I.top + 1];
}

int postfix::precedence(char a) {
	if (a == '+' || a == '-')
		return 1;
	else if (a == '*' || a == '/')
		return 2;
	else if (a == '^')
		return 3;
	else
		return 0;
}

void postfix::operation(char *exp) {
	int length = strlen(exp);

	cout << "Input" << "\t\t\t\t" << "Output" << "\t\t\t\t" << "Stack" << endl;

	for (int i = 0; i < length; i++) {
		if (exp[i] == '(' || exp[i] == ')' || exp[i] == '^' || exp[i] == '*'
				|| exp[i] == '/' || exp[i] == '+' || exp[i] == '-') {
			if (isEmptyS() || exp[i] == '(')
				PushS(exp[i]);
			else if (exp[i] == ')') {
				while (S.data[S.top] != '(') {
					post[count] = S.data[S.top];
					count++;
					PopS();
				}
				PopS();
			} else if (precedence(S.data[S.top]) >= precedence(exp[i])) {
				while (!isEmptyS() && S.data[S.top] != '(') {
					post[count] = S.data[S.top];
					count++;
					PopS();
				}
				PushS(exp[i]);
			} else {
				PushS(exp[i]);
			}
		} else {
			post[count] = exp[i];
			count++;
		}

		cout << exp[i] << "\t\t\t\t";
		for(int i = 0; i < count; i++)
			cout << post[i];
		cout << "\t\t\t\t" << S.data[S.top] << endl;
	}
	cout << "NULL" << "\t\t\t\t";
			for(int i = 0; i < count; i++)
				cout << post[i];
			cout << "\t\t\t\t" << "NULL" << endl;

	while (!isEmptyS()) {
		post[count] = S.data[S.top];
		count++;
		PopS();
		cout << "NULL" << "\t\t\t\t";
		for(int i = 0; i < count; i++)
			cout << post[i];
		cout << "\t\t\t\t" << "NULL" << endl;
	}
}

void postfix::evaluate() {
	int length = strlen(post);

	int a, b;

	cout << "Enter the value of A : ";
	cin >> values[0];
	cout << "Enter the value of B : ";
	cin >> values[1];
	cout << "Enter the value of C : ";
	cin >> values[2];

	for (int i = 0; i < length; i++) {

		if (post[i] == 'A' || post[i] == 'a')
			PushI(values[0]);
		else if (post[i] == 'B' || post[i] == 'b')
			PushI(values[1]);
		else if (post[i] == 'C' || post[i] == 'c')
			PushI(values[2]);
		else if (post[i] == '^') {
			b = PopI();
			a = PopI();
			PushI(a ^ b);
		} else if (post[i] == '*') {
			b = PopI();
			a = PopI();
			PushI(a * b);
		} else if (post[i] == '/') {
			b = PopI();
			a = PopI();
			PushI(a / b);
		} else if (post[i] == '+') {
			b = PopI();
			a = PopI();
			PushI(a + b);
		} else if (post[i] == '-') {
			b = PopI();
			a = PopI();
			PushI(a - b);
		}
	}

	cout << "Evaluated value of expression is : " << I.data[I.top] << endl;

}

int main() {

	char *ex = new char[MAX];

	cout << "Enter Infix Expression : ";
	cin >> ex;

	postfix B;
	B.operation(ex);
	B.display();
	B.evaluate();

	return 0;
}

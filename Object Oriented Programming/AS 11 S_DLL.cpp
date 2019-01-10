//============================================================================
// Name        : AS 11 STL_S_LL.cpp
// Author      : Nikhil Lakare SECOB205
// Version     :
// Copyright   : Your copyright notice
// Description : 11. Write C++ program using STL for implementation of Stack using SLL.
//============================================================================

/*
 * C++ Program to Implement Stack in STL using DLL
 */
#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;
class Stack {
	list<int> l;
public:
	void push() {
		int val;
		cout << "Enter value : ";
		cin >> val;
		l.push_back(val);
	}
	void pop() {
		l.pop_back();
	}
	int top() {
		return (l.back());
	}
	int size() {
		return (l.size());
	}

	void display() {
		list<int>::iterator itr;
		cout << "\t Stack : ";
		if (l.size() == 0) {
			cout << "EMPTY!!!";
		} else {
			for (itr = l.begin(); itr != l.end(); itr++) {
				cout << *itr << "  ";
			}
		}
		cout << endl;
	}
};
int main() {
	Stack s;
	int choice, item;

	while (1) {
		cout << "\n---------------------" << endl;
		cout << "Stack implementation in STL using DLL" << endl;
		cout << "---------------------" << endl;
		cout << "1.Push Element \t";
		cout << "2.Pop Element \t\t";
		cout << "3.Size \t" << endl;
		cout << "4.Top Element \t";
		cout << "5.Display Stack \t";
		cout << "Exit on Wrong choice";
		cout << "\nEnter your Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			s.push();
			break;
		case 2:
			item = s.top();
			s.pop();
			cout << "Element " << item << " Deleted from Stack" << endl;
			break;
		case 3:
			cout << "Size of the Stack: ";
			cout << s.size() << endl;
			break;

		case 4:
			cout << "Top Element of the Stack: ";
			cout << s.top() << endl;
			break;
		case 5:
			s.display();
			break;
		default:
			cout << "\nExit from Program..." << endl;
			exit(0);
		} //switch
	} //while
	return 0;
}


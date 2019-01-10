//============================================================================
// Name        : AS 11 STL_Q_LL
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
// Description : Write C++ program using STL for implementation of Queue using SLL.
//============================================================================

/*
 * C++ Program to Implement Queue in STL using DLL
 */
#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;
class Queue {
	list<int> l;
public:
	void insert() {
		int val;
		cout << "Enter value : ";
		cin >> val;
		l.push_back(val);
	}
	void del() {
		l.pop_front();
	}
	int front() {
		return (l.front());
	}
	int back() {
		return (l.back());
	}

	int size() {
		return (l.size());
	}

	void display() {
		list<int>::iterator itr;
		cout << "\nQueue : ";
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
	Queue q;
	int choice, item;

	while (1) {
		cout << "\n---------------------" << endl;
		cout << "Queue implementation in STL using DLL";
		cout << "\n---------------------" << endl;
		cout << "1.Insert Element \t";
		cout << "2.Delete Element \t";
		cout << "3.Size " << endl;
		cout << "4.Top Element \t\t";
		cout << "5.Display Queue \t";
		cout << "Exit on Wrong choice";
		cout << "\nEnter your Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			q.insert();
			break;
		case 2:
			item = q.front();
			q.del();
			cout << "Element " << item << " Deleted from Queue" << endl;
			break;
		case 3:
			cout << "Size of the Queue: ";
			cout << q.size() << endl;
			break;

		case 4:
			cout << "Top Elements of the Queue: " << endl;
			cout << "Queue front = " << q.front() << endl;
			cout << "Queue back  = " << q.back() << endl;
			break;
		case 5:
			q.display();
			break;
		default:
			cout << "\nExit from Program..." << endl;
			exit(0);
		} //switch
	} //while
	return 0;
}


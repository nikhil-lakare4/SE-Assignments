//============================================================================
// Name        :  AS 13 STL_DQueue
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
// Description : Write C++ program using STL for Deque
//============================================================================

/*
 * Write C++ program using STL for DQueue (Double ended queue)
 */

#include<iostream>
#include<deque>
#include<cstdlib>
using namespace std;
int main() {
	int choice, element;
	deque<int> dq;
	deque<int>::iterator ditr;
	while (1) {
		cout << "\n---------------------" << endl;
		cout << "DQueue implementation in STL" << endl;
		cout << "---------------------";
		cout << "\n1.Insert element at front\t2.Insert element at rear";
		cout << "\n3.Delete front element\t\t4.Delete rear element";
		cout << "\n5.Display front element\t\t6.Display rear element";
		cout << "\n7.Display DQeque\t\tExit on Wrong choice";
		cout << "\nEnter your Choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "\nEnter Element to insert at front";
			cin >> element;
			dq.push_front(element);
			break;

		case 2:
			cout << "\nEnter Element to insert at rear";
			cin >> element;
			dq.push_back(element);
			break;

		case 3:
			cout << "Front element ";
			dq.front();
			cout << " of DQueue is deleted";
			dq.pop_front();
			break;

		case 4:
			dq.pop_back();
			cout << "Back element ";
			dq.back();
			cout << " of DQueue is deleted";
			break;

		case 5:
			cout << "\nFront Element:";
			cout << dq.front();
			break;

		case 6:
			cout << "\nRear Element:";
			cout << dq.back();
			break;

		case 7:
			if (dq.empty())
				cout << "\nQueue is empty!";
			else {
				for (ditr = dq.begin(); ditr < dq.end(); ditr++)
					cout << *ditr << "\t";
			}
			cout << endl;
			break;

		default:
			cout << "\nExit from Program..." << endl;
			exit(0);
		} //switch
	} //while
	return 0;
} //main


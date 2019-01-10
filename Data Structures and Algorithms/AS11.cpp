//============================================================================
// Name        : AS11.cpp
// Author      : Nikhil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 10

struct Queue {
	int q[MAX];
	int front;
	int rear;
};

class Dequeue {
	Queue Q;
public:
	Dequeue() {
		Q.front = -1;
		Q.rear = -1;
	}

	int isEmpty();
	int isFull();
	void addfromfront(int x);
	void addfromrear(int x);
	void deletefromfront();
	void deletefromrear();
	void display();
};

int Dequeue::isEmpty() {
	if (Q.front == -1 && Q.rear == -1)
		return 1;
	else
		return 0;
}

int Dequeue::isFull() {
	if (Q.rear == MAX - 1 || Q.front > Q.rear)
		return 1;
	else
		return 0;
}

void Dequeue::addfromfront(int x) {
	if (isEmpty()) {
		Q.q[++Q.front] = x;
		Q.rear++;
		cout << "Element added at front!" << endl;
	}
	else if (isFull()) {
		cout << "Cannot add at front! Queue is full!" << endl;
	}
	else if (Q.front == Q.rear)
	{
		Q.q[Q.rear + 1] = Q.q[Q.rear];
		Q.rear++;
		Q.q[Q.front] = x;
	}
	else {
		for (int i = Q.rear; i != Q.front - 1; i--) {
			Q.q[i + 1] = Q.q[i];
		}
		Q.q[Q.front] = x;
		Q.rear++;
		cout << "Element added at front!" << endl;
	}
}

void Dequeue::addfromrear(int x) {
	if (isEmpty()) {
		Q.q[++Q.front] = x;
		Q.rear++;
		cout << "Element added at rear!" << endl;
	} else if (isFull())
		cout << "Cannot add at rear! Queue is full!" << endl;
	else {
		Q.q[++Q.rear] = x;
		cout << "Element added at rear!" << endl;
	}

}

void Dequeue::deletefromfront() {
	if (isEmpty())
		cout << "Cannot delete from front! Queue is empty!" << endl;
	else if (Q.front == Q.rear) {
		cout << Q.q[Q.front] << " deleted from front!" << endl;
		Q.front = Q.rear = -1;
	}
	else
		cout << Q.q[Q.front++] << " deleted from front!" << endl;



}

void Dequeue::deletefromrear() {
	if (isEmpty())
		cout << "Cannot delete from rear! Queue is empty!" << endl;
	else if (Q.front == Q.rear) {
		cout << Q.q[Q.rear] << " deleted from front!" << endl;
		Q.front = Q.rear = -1;
	}
	else
		cout << Q.q[Q.rear--] << " deleted from rear!" << endl;
}

void Dequeue::display() {
	cout << "Current queue is : ";
	for (int i = Q.front; i <= Q.rear; i++) {
		cout << Q.q[i] << " ";
	}
	cout << endl;
}

int main() {

	int ch;
	int num;
	Dequeue D;

	while (true) {
		cout << "Enter 1 to add element from front\nEnter 2 to add element from rear\nEnter 3 to delete element from front\nEnter 4 to deleter element from rear\nEnter any other to exit\nInput: ";
		cin >> ch;
		switch (ch) {
		case 1:
			cout << "Element: ";
			cin >> num;
			D.addfromfront(num);
			D.display();
			break;
		case 2:
			cout << "Element: ";
			cin >> num;
			D.addfromrear(num);
			D.display();
			break;
		case 3:
			D.deletefromfront();
			D.display();
			break;
		case 4:
			D.deletefromrear();
			D.display();
			break;
		default:
			return 0;
		}
	}
}

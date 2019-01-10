//============================================================================
// Name        : AS10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 5


struct Queue
{
	int q[MAX];
	int front;
	int rear;
	int count;
};

class Pizza
{
	Queue Q;
	int num;

public:
	Pizza()
	{
		for(int i = 0; i < MAX; i++)
			Q.q[i] = 0;

		Q.front = -1;
		Q.rear = -1;
		Q.count = 0;
		num = 0;

	}

	int isEmpty();
	int isFull();
	void Enqueue();
	void Dequeue();
};

int Pizza :: isEmpty()
{
	if((Q.front == -1 && Q.rear == -1) || Q.count == 0)
		return 1;
	else
		return 0;
}

int Pizza :: isFull()
{
	if(Q.rear == MAX - 1 || Q.count == MAX || Q.front > Q.rear)
		return 1;
	else
		return 0;
}

void Pizza :: Enqueue()
{
	if(isFull())
	{
		Q.front = (Q.front + 1) % MAX;
		Q.rear = (Q.rear + 1) % MAX;
	}

	do
	{
		cout << "Enter the total number of orders to be enqueued: ";
		cin >> num;

		if(num > MAX)
			cout << "Order limit exceeds! Retry!" << endl;

	}while(num > MAX - Q.count);

	Q.front++;
	for(int i = 0; i < num; i++)
	{
		Q.q[i] = 1;
		Q.rear++;
		Q.count++;
	}

	cout << "Queue has " << Q.count << " orders!" << endl;
}

void Pizza :: Dequeue()
{
	if(isEmpty())
	{
		cout << "Queue is Empty!" << endl;
		return;
	}

	int num;

	do
	{
	cout << "Enter the number of orders to be dequeued: ";
	cin >> num;

	if(num > Q.count)
		cout << "Can't perform operation! Retry!" << endl;

	}while(num > Q.count);


	for(int i = 0; i < num; i++)
	{
		Q.q[i] = 0;
		Q.front++;
		Q.count--;
	}

	cout << "Queue has " << Q.count << " orders!" << endl;

}



int main() {

	char ch;

	Pizza P;
	do
	{
		P.Enqueue();
		P.Dequeue();

		cout << "Do you want to continue?(Y)" << endl;
		cin >> ch;
	}while(ch == 'Y');

	return 0;
}

//============================================================================
// Name        : AS1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//Node Structure
struct node {
	int x;
	node *next;
};

//Class for integer
class integer {
	node *head;
	int count;
	head = NULL;
public:
	integer() {
		head = NULL;
		count = 0;
	}
	node* createNN();
	void create();
	void addNew();
	void deleteN();
	void display();
};

//Function to create a single node
node* integer::createNN() {
	node* nn;
	nn = new node;
	cout << "\nEnter the element : ";
	cin >> nn->x;
	nn->next = NULL;
	count++;
	return nn;
}

//Function to create complete list
void integer::create() {

	node *nn, *cn;
	char choice;

	do {
		nn = createNN();
		if (head == NULL) {
			head = nn;
			cn = nn;
		} else {
			cn->next = nn;
			cn = nn;
		}

		cout << "\nDo you want to add another node? (y/n)";
		cin >> choice;

	} while (choice == 'y');
}

//Function to add a new node
void integer::addNew() {

	node *nn, *cn, *temp;
	int P;
	cout << "\nEnter the position where you want to add new node : ";
	cin >> P;

	cn = head;

	if (P == 1) {
		nn = createNN();
		nn->next = head;
		head = nn;
		cout << "\nNode Added!\n";
	} else if (P > 1 || P < count) {
		nn = createNN();
		for (int i = 0; i < P - 1; i++) {
			temp = cn;
			cn = cn->next;
		}
		temp->next = nn;
		nn->next = cn;
		cout << "\nNode Added!\n";
	} else if (P == count) {
		nn = createNN();
		while (cn->next != NULL) {
			cn = cn->next;
		}
		cn->next = nn;
		cout << "\nNode Added!\n";
	}
}

//Function to delete a node
void integer::deleteN() {

	node *nn, *cn, *temp;

	int P;
	cout << "\nEnter the position of node which is to be deleted : ";
	cin >> P;

	cn = head;

	if (P == 1) {
		nn = head;
		head = head->next;
		delete (nn);
		count--;
		cout << "\nNode deleted!\n";
	} else if (P > 1 || P < count) {
		for (int i = 0; i < P - 1; i++) {
			temp = cn;
			cn = cn->next;
		}
		temp->next = cn->next;
		delete (cn);
		count--;
		cout << "\nNode deleted!\n";
	} else if (P == count) {
		while (cn->next != NULL) {
			temp = cn;
			cn = cn->next;
		}
		temp->next = NULL;
		delete (cn);
		count--;
		cout << "\nNode deleted!\n";
	}

}

//Function to display complete list
void integer::display() {
	node *cn = head;
	cout << "\nThe linked list is : ";
	while (cn != NULL) {
		cout << cn->x << " ";
		cn = cn->next;
	}
	cout << endl;
}

int main() {

	integer I;
	int choice;

	while (choice <= 4) {

		cout
				<< "\n\nEnter 1 to create list\nEnter 2 add new node\nEnter 3 to delete node\nEnter 4 to display list\nEnter any other to exit\nInput : ";
		cin >> choice;

		switch (choice) {
		case 1:
			I.create();
			break;
		case 2:
			I.addNew();
			break;
		case 3:
			I.deleteN();
			break;
		case 4:
			I.display();
			break;
		default:
			break;
		}
	}
	return 0;
}

//============================================================================
// Name        : AS7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int MAX = 10;

struct client {
	long num;
	string name;
};

class phoneBook {
	int n;
	client P[10];
public:
	phoneBook() {
		n = 0;
		for (int i = 0; i < MAX; i++) {
			P[i].num = -1;
			P[i].name = "NULL";
		}
	}

	void createTable();
	int hashValue(long key);
	void searchKey();
	void display();
};

int phoneBook::hashValue(long key) {
	return (key % MAX);
}

void phoneBook::createTable() {

	int hash;
	long key;
	string keyword;

	do {
		cout << "\nEnter the number of entries to be entered(MAX 10): ";
		cin >> n;

		if (n > MAX)
			cout << "\nLimit Exceeded! Retry!";
	} while (n > MAX);

	for (int i = 0; i < n; i++) {
		cout << "\nEnter Phone Number: ";
		cin >> key;
		hash = hashValue(key);
		if (P[hash].num == -1) {
			P[hash].num = key;
			cout << "Enter Name: ";
			cin >> keyword;
			P[hash].name = keyword;
		} else {
			while (P[hash].num != -1) {
				hash = (hash + 1) % MAX;
				if (P[hash].num == -1) {
					P[hash].num = key;
					cout << "Enter Name: ";
					cin >> keyword;
					P[hash].name = keyword;
					break;
				}
			}
		}

	}

}

void phoneBook::display() {
	cout << "\nHash Table is: ";


	for (int i = 0; i < MAX; i++) {
		cout << "\n" << i << "   " << P[i].num << "   " << P[i].name << endl;
	}
}

void phoneBook::searchKey() {
	long key;
	int hash;

	cout << "\nEnter the key to be searched: ";
	cin >> key;

	hash = hashValue(key);

	if (P[hash].num == key) {
		cout << "\nFound! Phone Number belongs to: " << P[hash].name;
		return;
	}
	else {
		while(P[hash].num != key) {
			hash = (hash + 1) % MAX;
			if(P[hash].num == key)
		}
	}

}

int main() {
	phoneBook P;
	P.createTable();
	P.display();
	P.searchKey();
	return 0;
}

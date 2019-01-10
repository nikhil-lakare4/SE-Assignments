//============================================================================
// Name        : AS12.cpp
// Author      : Nikhil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
const int MAX = 10;


class pgm {
	int stud[MAX];
	int n;
public:
	void getdata();
	void bubblesort();
	void linearsearch(int);
	void binarysearch(int);
	void sentinalsearch(int);
	void fibonaccisearch(int);
};

void pgm::getdata() {
	cout << "Enter the total number of student who attended training program (MAX " << MAX << "): ";
	cin >> n;
	cout << endl;
	cout << "Enter Roll Numbers of student who attended training program in random order: " << endl;
	for(int i = 0; i < n; i++) {
		cin >> stud[i];
	}
	cout << endl;
}

void pgm::bubblesort() {

	cout << "Sorting with Bubble Sort.........." << endl << endl;
	int swap = 0, temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1 ; j++) {
			if (stud[j] > stud [j+1]) {
				temp = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = temp;
				swap++;
			}
		}
		if (swap == 0)
			break;
	}
	cout << "Sorted :)" << endl << endl;
}

void pgm::linearsearch(int key) {

	cout << "In Linear Search........" << endl << endl;

	int flag = 0;

	for (int i = 0; i < n; i++) {
		if (stud[i] == key) {
			cout << "Roll Number " << key << " attended training program :)" << endl << endl;
			flag++;
			break;
		}
	}
	if (flag == 0)
		cout << "Roll Number " << key << " did not attend training program :(" << endl << endl;

}

void pgm::binarysearch(int key) {

	cout << "In Binary Search......" << endl << endl;

	int start = 0, end = n - 1, middle;

	while (start <= end) {

		middle = (start + end) / 2;

		if (stud[middle] == key) {
			cout << "Roll Number " << key << " attended training program :)" << endl << endl;
			break;
		}
		else if (stud[middle] < key)
			start = middle + 1;
		else
			end = middle - 1;
	}

	if (start > end)
		cout << "Roll Number " << key << " did not attend training program :(" << endl << endl;

}

void pgm::sentinalsearch(int key) {
	cout << "In Sentinal Search......" << endl << endl;

	int last = stud[n - 1];
	stud[n - 1] = key;
	int i = 0;
	while(stud[i] != key)
	{
	    i++;
	}
	stud[n - 1] = last;
	if( (i < n - 1) || (key == stud[n - 1]) )
		cout << "Roll Number " << key << " attended training program :)" << endl << endl;
	else
		cout << "Roll Number " << key << " did not attend training program :(" << endl << endl;
}

void pgm::fibonaccisearch(int key) {
	cout << "In Fibonacci Search......." << endl << endl;

	int fibo = 0;
	int fibonext = 1;
	int fibonextnext = fibo + fibonext;
	while (n > fibonextnext) {
		fibo = fibonext;
		fibonext = fibonextnext;
		fibonextnext = fibo + fibonext;
	}

	if (fibonextnext >= n) {
		fibonextnext = fibonext;
		fibonext = fibo;
		fibo = fibonext - fibo;
	}

	int f = n - 1;
	int b = fibonextnext;
	int a = fibonext;
	int temp;

	while ( f >= 0) {
		if (key < stud[f]) {
			f = f - a;
			temp = b -a;
			b = a;
			a = temp;
		}
		else if (key > stud[f]) {
			f = f + a;
			b = b - a;
			a = a - b;
		}
		else {
			cout << "Roll Number " << key << " attended training program :)" << endl << endl;
			return;
		}
	}

	cout << "Roll Number " << key << " did not attend training program :(" << endl << endl;

}

int main() {
	pgm P;
	P.getdata();
	int choice, key;
	char ch;

	do {
		cout << "Enter the Roll Number to be searched: ";
		cin >> key;
		cout << endl << "Enter 1 to use Linear Search\nEnter 2 to use Binary Search\nEnter 3 to use Sentinal Search\nEnter 4 to use Fibonacci Search\nEnter any other to exit\nInput: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			P.linearsearch(key);
			break;
		case 2:
			P.bubblesort();
			P.binarysearch(key);
			break;
		case 3:
			P.sentinalsearch(key);
			break;
		case 4:
			P.bubblesort();
			P.fibonaccisearch(key);
			break;
		default:
			cout << "Exited" << endl;
			return 0;
		}

		cout << "Wanna search again? (Y/y) : ";
		cin >> ch;
		cout << endl;
	} while (ch == 'Y' || ch == 'y');
	cout << "Exited" << endl;
	return 0;
}

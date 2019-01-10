//============================================================================
// Name        : AS14.cpp
// Author      : NIKHIL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const int MAX = 20;

class FE {
	float stud[MAX];
	float temp;
public:
	int n;
	FE() {
		temp = 0;
		n = 0;
	}
	void getdata();
	int partition(int, int);
	void quicksort(int, int);
	void display();
};

void FE::getdata() {
	cout << "Enter total number of students (MIN 5 & MAX " << MAX << "): ";
	cin >> n;
	cout << endl;
	cout << "Enter First Year Percentage of students in random order: " << endl;
	for(int i = 0; i < n; i++) {
		cin >> stud[i];
	}
	cout << endl;
}

void FE:: display() {
	cout << "First Year Percentages in ascending order are: " << endl;
	for (int i = 0; i < n; i++)
		cout << stud[i] << " ";
	cout << endl << endl;

	cout << "Top five scores are: " << endl;
	for(int i = n - 1; i > n - 1 - 5; i--) {
		cout << stud[i] << " ";
	}
	cout << endl << endl;
}

int FE::partition(int low, int high) {

	int pivot = low;

	int i = low + 1;
	int j = high;

	while (true) {
	while(stud[pivot] > stud[i])
		i++;
	while (stud[pivot] < stud[j])
		j--;

	if (i < j) {
		temp = stud[i];
		stud[i] = stud[j];
		stud[j] = temp;
	}
	else {
		temp = stud[j];
		stud[j] = stud[pivot];
		stud[pivot] = temp;
		break;
	}
	}
	return j;
}

void FE::quicksort(int low, int high) {

	if (low < high) {
		int pi = partition(low, high);
		quicksort(low, pi - 1);
		quicksort(pi + 1, high);
	}
	else
		return;
}

int main() {
	FE P;
	P.getdata();
	cout << "Sorting with QuickSort.........." << endl << endl;
	P.quicksort(0, P.n - 1);
	cout << "Sorted :)" << endl << endl;
	P.display();
	return 0;
}

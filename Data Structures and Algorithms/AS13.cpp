//============================================================================
// Name        : AS13.cpp
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
	void selectionsort();
	void bubblesort();
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

void FE::selectionsort() {

	cout << "Sorting with Selection Sort.........." << endl << endl;
	int min, temp, j;

	for (int i = 0; i < n; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (stud[j] < stud[min])
				min = j;
		}

		temp = stud[i];
		stud[i] = stud[min];
		stud[min] = temp;
	}
	cout << "Sorted :)" << endl << endl;
}

void FE::bubblesort() {

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

int main() {
	FE P;
	int choice;
	P.getdata();
	cout << "Enter 1 to use Selection Sort\nEnter 2 to use Bubble sort\nEnter any other to exit\nInput: ";
	cin >> choice;
	cout << endl;
	switch(choice) {
	case 1:
		P.selectionsort();
		P.display();
		break;
	case 2:
		P.bubblesort();
		P.display();
		break;
	default:
		return 0;
	}

	return 0;
}

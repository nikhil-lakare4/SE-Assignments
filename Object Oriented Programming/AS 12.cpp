//============================================================================
// Name        : AS 12 STL_S_Binary
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
// Description : Write C++ program using STL to add binary numbers (assume one bit as one number); use STL stack
//============================================================================

#include <iostream>
#include<stack>
#include<list>
using namespace std;

int main() {
	stack<int> n1, n2;
	list<int> add;
	int n, i, m;
	cout << "\n Number of bits in binary no. : ";
	cin >> n;
	cout << "\nEnter first binary number (space separated) : ";
	for (i = 0; i < n; i++) {
		cin >> m;
		n1.push(m);
	}
	cout << "\nEnter second binary number (space separated) : ";
	for (i = 0; i < n; i++) {
		cin >> m;
		n2.push(m);
	}
	cout << "\nAddition is : ";
	int c = 0, s;
	for (i = 0; i < n; i++) {
		s = c + n1.top() + n2.top();
		n1.pop();
		n2.pop();

		int sum = s % 2;
		c = s / 2;

		add.push_back(sum);
	}
	add.push_back(c);
	list<int>::reverse_iterator iter;

	for (iter = add.rbegin(); iter != add.rend(); iter++) {
		cout << *iter;
	}
	return 0;

}


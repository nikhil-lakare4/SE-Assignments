//============================================================================
// Name        : AS 6
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
/* Description : Write a function template selection Sort. Write a program that
inputs, sorts and outputs an integer array and a float array.
*/
//============================================================================

#include <iostream>
using namespace std;

template <class T>
class sort_array
{
	int n;
	T a[20];
public:
	void getArray();
	void displayArray();
	void sortArray();
};

template <class T>
void sort_array <T>:: getArray()
{
	cin >> n;
	cout << "Enter the numbers : " << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

template <class T>
void sort_array <T>:: sortArray()
{
	int swap = -1;
	T temp = 0;
	for(int i = 0; i < n -1; i++)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			swap = 0;
			if(a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				swap++;
			}
		}
		if(swap == 0)
		{
			cout << "Array is already sorted" << endl;
			break;
		}
	}

}

template <class T>
void sort_array <T>:: displayArray()
{
	cout << "Sorted array is : " << endl;
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}

int main() {

	sort_array <int> A1;
	cout << "Enter the number of integers : ";
	A1.getArray();
	A1.sortArray();
	A1.displayArray();

	sort_array <float> A2;
	cout << "Enter the number of floats : ";
	A2.getArray();
	A2.sortArray();
	A2.displayArray();

	return 0;
}

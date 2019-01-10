//============================================================================
// Name        : AS 7
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
/* Description : Create a class template to represent a generic vector. Include
following member functions:
 To create the vector.
 To modify the value of a given element
 To multiply by a scalar value
 To display the vector in the form (10,20,30,...)
*/
//============================================================================

#include <iostream>
using namespace std;

template <class T>
class vector
{
	T v[10];
	int n;
public :
	void create();
	void modify();
	void scalar();
	void display();
};

template <class T>
void vector <T>:: create()
{
	cout << "Enter Vector Elements (Max 10) :";
	cin >> n;
	cout << "Enter "<< n <<" Vector Elements: ";
	for(int i = 0; i<n ;i++)
	{
		cin >> v[i];
	}
	cout << endl;
}

template <class T>
void vector <T>:: modify()
{

	int m;
	cout << "\nEnter index of element is to be modify :";
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		if(m == i)
		{
		cout << "Enter Value: ";
		cin >> v[i];
		break;
		}
	}
}

template <class T>
void vector <T>::scalar()
{
	T s;
	cout << "\nEnter scalar value for multiplication: ";
	cin >> s;
	for (int i=0; i<n; i++)
	{
		v[i] = v[i]*s;
	}
}

template <class T>
void vector <T>::display()
{
	cout << "Your vector : ( ";
		for (int i = 0; i<n ;i++)
		{
			if(i != n-1)
				cout << v[i] << " , ";
			else
				cout<< v[i] << " )" << endl;
		}
}

int main() {
	char k;
	vector <int>v;
	cout <<"*****************Vector Creation*****************"<< endl <<endl;

	v.create();
	v.display();
	int ch;
	do
	{
		cout << endl << "*****************Vector operations*****************" << endl << endl;
	cout << "\nEnter choice \n1. Modify\n2. scalar multiplication\n";
	cin >> ch;
	switch (ch)
	{
	case 1:
		v.modify();
		v.display();
		break;
	case 2:
		v.scalar();
		v.display();
		break;
	}
	cout<<"Do you want to continue ?(y/n)";
	cin >> k;
	}while (k == 'y' || k == 'Y');

	cout<< endl << "EXIT :-)";
	return 0;
}

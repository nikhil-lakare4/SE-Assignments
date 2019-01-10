//============================================================================
// Name        : AS5
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
/* Description : Create employee bio-data using following classes i) Personal
record ii))Professional record iii) Academic record. Assume
appropriate data members and member function to accept
required data & print bio-data. Create bio-data using multiple
inheritance using C++.
*/
//============================================================================

#include <iostream>
using namespace std;

class Personal
{
	string name;
	string addr;
	long telno;
public:
	void getDetails();
	void showDetails();
};

void Personal :: getDetails()
{
	cout << "Enter Name : ";
	cin >> name;
	cout << "Enter Address : ";
	cin >> addr;
	cout << "Enter Telephone No : ";
	cin >> telno;
}

void Personal :: showDetails()
{
	cout << "Name :" << name << endl;
	cout << "Address :" << addr << endl;
	cout << "Telephone No : " << telno << endl;
}

class Professional
{
	string org;
	string id;
public:
	void getDetails();
	void showDetails();
};

void Professional :: getDetails()
{
	cout << "Enter Organization : ";
	cin >> org;
	cout << "Enter ID No : ";
	cin >> id;
}

void Professional :: showDetails()
{
	cout << "Organization :" << org << endl;
	cout << "ID No : " << id << endl;
}

class Academic
{
	string qual;
	int marks;
public:
	void getDetails();
	void showDetails();
};

void Academic :: getDetails()
{
	cout << "Enter Qualification : ";
	cin >> qual;
	cout << "Enter Marks : ";
	cin >> marks;
}

void Academic :: showDetails()
{
	cout << "Qualification :" << qual << endl;
	cout << "Marks :" << marks << endl;
}

class Employee : Personal, Professional, Academic
{
public:
	void getDetails();
	void showDetails();
};

void Employee :: getDetails()
{
	Personal :: getDetails();
	Professional :: getDetails();
	Academic :: getDetails();
}

void Employee :: showDetails()
{
	Personal :: showDetails();
	Professional :: showDetails();
	Academic :: showDetails();
}

int main() {

	Employee E;
	E.getDetails();
	cout << endl << "Entered Details are....." << endl;
	E.showDetails();
	return 0;
}

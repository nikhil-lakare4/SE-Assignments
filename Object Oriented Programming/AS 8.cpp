//============================================================================
// Name        : AS 8
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
/* Description : Crete User defined exception to check the following conditions and
throw the exception if the criterion does not meet.
a. User has age between 18 and 55
b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per
month
c. User stays in Pune/ Mumbai/ Bangalore / Chennai
d. User has 4-wheeler
Accept age, Income, City, Vehicle from the user and check for the
conditions mentioned above. If any of the condition not met then
throw the exception.
*/
//============================================================================

#include <iostream>
using namespace std;
#include <string>

class Error
{
public:
	Error(int x){}
	Error(float x){}
	Error(string x){}

	void errAge(int x)
	{
		cout << "ERROR! Age " << x << " is invalid!" << endl;
	}

	void errSalary(float x)
	{
		cout << "ERROR! Salary " << x << " is invalid!" << endl;
	}

	void errCity(string x)
	{
		cout << "ERROR! City " << x << " is invalid!" << endl;
	}

	void errVehicle(int x)
	{
		cout << "ERROR! Vehicle " << x << " Wheeler is invalid!" << endl;
	}
};
int main() {
	int age, vehicle;
	float salary;
	string city;

	cout << "Enter Age (18 to 55): ";
	cin >> age;

	try
	{
		if(age < 18 || age > 55)
			throw Error(age);
		else
			cout << "Age is: " << age << endl;
	}
	catch(Error &e)
	{
		e.errAge(age);
	}

	cout << "Enter Salary (50000 to 100000): ";
	cin >> salary;

	try
	{
		if(salary < 50000 || salary > 100000)
			throw Error(salary);
		else
			cout << "Salary is: " << salary << endl;
	}
	catch(Error &e)
	{
		e.errSalary(salary);
	}

	cout << "Enter City (Pune/Mumbai/Banglore/Chennai): ";
	cin >> city;

	try
	{
		if(!(city == "Pune" || city == "Mumbai" || city == "Banglore" || city == "Chennai"))
			throw Error(city);
		else
			cout << "City is: " << city << endl;
	}
	catch(Error &e)
	{
		e.errCity(city);
	}

	cout << "Enter Vehicle Info (2 Wheeler / 4 Wheeler): ";
	cin >> vehicle;

	try
	{
		if(!(vehicle == 2 || vehicle == 4))
			throw Error(vehicle);
		else
			cout << "Vehicle is: " << vehicle << " Wheeler" << endl;
	}
	catch(Error &e)
	{
		e.errVehicle(vehicle);
	}

	return 0;
}

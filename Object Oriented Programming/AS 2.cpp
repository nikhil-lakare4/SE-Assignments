//============================================================================
// Name        : AS2
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
/* Description : Write a C++ program create a calculator for an arithmetic operator
(+, -, *, /). The program should take two operands from user and
performs the operation on those two operands depending upon the
operator entered by user. Use a switch statement to select the
operation. Finally, display the result.
*/
//============================================================================

#include <iostream>
using namespace std;

class Calculator
{
	int num1, num2;
	public:
	void getdata();
	void add();
	void subtract();
	void mult();
	void div();
	void mod();
};

void Calculator :: getdata()
{
	cout << "Enter the the two numbers:\n";
	cin >> num1 >> num2;
}
 void Calculator :: add()
 {
	 cout << endl << "Addition is : " << num1 + num2 << endl;
 }

 void Calculator :: subtract()
 {
	 cout << endl << "Subtraction is : " << num1 - num2 << endl;
 }

 void Calculator :: mult()
 {
	 cout << endl <<"Multiplication is : " << num1 * num2 << endl;
 }

 void Calculator :: div()
 {
	 cout << endl << "Division is : " <<  (float)num1/num2 << endl;
 }

 void Calculator :: mod()
 {
	 cout << endl << "Modulo is :  " << num1 % num2 << endl;
 }


int main()
{
	int choice;
	char per;

	Calculator c;

	do
	{
		c.getdata();

		cout << endl << "Enter 1 for addition\nEnter 2 for subtraction\nEnter 3 for multiplication\nEnter 4 for division\nEnter 5 for modulo\n" << endl;

		cin >> choice;

		switch(choice)
		{
		case 1:
			c.add();
			break;
		case 2:
			c.subtract();
			break;
		case 3:
			c.mult();
			break;
		case 4:
			c.div();
			break;
		case 5:
			c.mod();
			break;
		default:
			cout << "Invalid input";
		}

		cout << endl << "Do you want to continue ? (y) : \n";

		cin >> per;
	} while (per == 'y');

	cout << endl << "Exiting program..." << endl;

	return 0;
}

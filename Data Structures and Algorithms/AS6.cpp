//============================================================================
// Name        : AS6.cpp
// Author      : Nikhil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
struct node
{
	int bit;
	node *prev, *next;
};

class binary
{
	int num;
	node *header, *header1, *tail, *tail1, *temp;
public:
	binary()
	{
		num = 0;
		header = NULL;
		header1 = NULL;
		tail = NULL;
		tail1 = NULL;
		temp = NULL;
	}
	void create();
	void comp1();
	void comp2();
	void addition();
	void display();
};

void binary :: create()
{
	cout << "Enter the number of bits to work with: ";
	cin >> num;
	cout << endl;

	node *nn = new node;
	header = nn;
	nn -> prev = NULL;

	cout << "Enter bits of binary number (From LSB): " << endl;
	cin >> nn -> bit;
	for(int i = 0; i < num - 1; i++)
	{
		temp = nn;
		nn -> next = new node;
		nn = nn -> next;
		nn -> prev = temp;
		cin >> nn -> bit;
	}
	tail = nn;
	nn -> next = NULL;

	cout << endl;
}

void binary :: comp1()
{
	node *cn;
	cn = header;
	while(cn != NULL)
	{
		if(cn -> bit == 0)
			cn -> bit = 1;
		else
			cn -> bit = 0;

		cn = cn -> next;
	}

}

void binary :: comp2()
{
	node *cn = header;
	for(int i = 0; i < num; i++)
	{
		if(cn -> bit == 1)
		{
			cn = cn -> next;
			break;
		}
		else
			cn = cn -> next;
	}

	while(cn != NULL)
	{
		if(cn -> bit == 0)
			cn -> bit = 1;
		else
			cn -> bit = 0;

		cn = cn -> next;
	}
}

void binary :: addition()
{
	node *nn = new node;
	header1 = nn;
	nn -> prev = NULL;

	cout << "Enter bits of binary number which is to be added (From LSB) : " << endl;
	cin >> nn -> bit;
	for(int i = 0; i < num - 1; i++)
	{
		temp = nn;
		nn -> next = new node;
		nn = nn -> next;
		nn -> prev = temp;
		cin >> nn -> bit;
	}
	tail1 = nn;
	nn -> next = NULL;

	nn = header1;
	node *cn = header;

	int carry = 0;

	if(cn -> bit == 0 && nn -> bit == 0 && carry == 0)
	{
		cn -> bit = 0;
		carry = 0;
	}
	else if (cn -> bit == 0 && nn -> bit == 1 && carry == 0)
	{
		cn -> bit = 1;
		carry = 0;
	}
	else if (cn -> bit == 1 && nn -> bit == 0 && carry == 0)
	{
		cn -> bit = 1;
		carry = 0;
	}
	else if(cn -> bit == 1 && nn -> bit == 1 && carry == 0)
	{
		cn -> bit = 0;
		carry = 1;
	}

	cn = cn -> next;
	nn = nn -> next;

	for(int i = 0; i < num - 1; i++)
	{
		if(cn -> bit == 0 && nn -> bit == 0 && carry == 0)
		{
			cn -> bit = 0;
			carry = 0;
		}
		else if (cn -> bit == 0 && nn -> bit == 0 && carry == 1)
		{
			cn -> bit = 1;
			carry = 0;
		}
		else if (cn -> bit == 0 && nn -> bit == 1 && carry == 0)
		{
			cn -> bit = 1;
			carry = 0;
		}
		else if (cn -> bit == 0 && nn -> bit == 1 && carry == 1)
		{
			cn -> bit = 0;
			carry = 1;
		}
		else if (cn -> bit == 1 && nn -> bit == 0 && carry == 0)
		{
			cn -> bit = 1;
			carry = 0;
		}
		else if (cn -> bit == 1 && nn -> bit == 0 && carry == 1)
		{
			cn -> bit = 0;
			carry = 1;
		}
		else if(cn -> bit == 1 && nn -> bit == 1 && carry == 0)
		{
			cn -> bit = 0;
			carry = 1;
		}
		else if (cn -> bit == 1 && nn -> bit == 1 && carry == 1)
		{
			cn -> bit = 1;
			carry = 1;
		}


		if(cn -> next != NULL && nn -> next != NULL)
		{
			cn = cn -> next;
			nn = nn -> next;
		}
	}

	if (carry == 1)
	{
		cn -> next = new node;
		temp = cn;
		cn = cn -> next;
		cn -> prev = temp;
		cn -> bit = 1;
		cn -> next = NULL;
		tail = cn;
	}

	cout << endl;
}

void binary :: display()
{
	node *cn;
	cn = tail;
	while(cn != NULL)
	{
		cout << cn -> bit;
		cn = cn -> prev;
	}

	cout << endl;
}

int main() {

	binary B;
	B.create();
	B.comp1();
	cout << "1's complement is : ";
	B.display();
	cout << endl;
	B.comp1();
	B.comp2();
	cout << "2's complement is : ";
	B.display();
	cout << endl;
	B.comp2();
	B.addition();
	cout << "Addition Result is : ";
	B.display();
	cout << endl;

	return 0;
}

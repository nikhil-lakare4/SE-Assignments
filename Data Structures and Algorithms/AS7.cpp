//============================================================================
// Name        : AS7.cpp
// Author      : Nikhil
// Version     :
// Copyright   : Your copyright notice
// Description : Ticket Booking, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int seatno;
	char rowno;
	char stat;
	node *prev;
	node *next;
};

class movie
{
	node *header, *temp;
public:
	movie()
	{
		temp = NULL;
		header = NULL;
	}
	void create();
	void display();
	void book();
	void cancel();
};

void movie :: create()
{
	int seat = 1;
	char row = 'A';
	node *cn = new node;
	header = cn;
	for(int i = 0; i < 70; i++)
	{
		cn -> prev = temp;
		cn -> seatno = seat;
		seat++;
		cn -> rowno = row;
		cn -> stat = 'a';
		cn -> next = new node;

		if(seat > 7)
		{
			seat = 1;
			row++;
		}
		temp = cn;
		cn = cn -> next;
	}

	cn -> next = header;
}

void movie :: display()
{
	node *cn = header;

	for(int i = 0; i < 10; i++)
	{	for(int j = 0; j < 7; j++)
		{
			if(cn -> stat == 'b')
				cout << "BOOKED" << "\t" << "\t";
			else
				cout << cn -> rowno << cn -> seatno << "\t" << "\t";

			cn = cn -> next;
		}
	cout << endl << endl;
	}
}

void movie :: book()
{
	int n;
	cout << "Enter the numbers of tickets you want to buy : ";
	cin >> n;

	char ch[n];
	int s[n];

	for(int i = 0; i < n; i++)
	{
		cout << endl << "Enter Row Number for seat " << i + 1 << " :";
		cin >> ch[i];
		cout << "Enter Seat Number for seat " << i + 1 << " :";
		cin >> s[i];
	}
	cout << endl;

	node *cn = header;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 70; j++)
		{
			if(cn -> rowno == ch[i] && cn -> seatno == s[i])
			{
				if(cn -> stat == 'b')
				{
					cout << "Can't book " << ch[i] << s[i] << "! Already booked!" << endl;
					break;
				}
				else
				{
					cn -> stat = 'b';
					cout << "Seat " << ch[i] << s[i] << " booked!" << endl;
					break;
				}
			}
			 cn = cn -> next;
		}
	}
	cout << endl;
}

void movie :: cancel()
{
	char ch;
	int s;

	cout << endl << "Enter Seat number for Cancellation: " << endl;

    cout << "Enter Row Number for seat :";
	cin >> ch;
	cout << "Enter Seat Number for seat :";
	cin >> s;
	cout << endl;


	node *cn = header;

	for(int j = 0; j < 70; j++)
	{
		if(cn -> rowno == ch && cn -> seatno == s)
		{
			if(cn -> stat == 'a')
			{
				cout << "Can't cancel! Seat " << ch << s << " is not booked!" << endl;
				break;
			}
			else
			{
				cn -> stat = 'a';
				cout << "Seat " << ch << s << " Canceled!\n" << endl;
				break;
			}
		}
		 cn = cn -> next;
	}
	cout << endl;
}

int main() {
	movie m;
	m.create();

	int choice;

	while (true)
	{
		cout << "Enter 1 to Display seats\nEnter 2 to Book seat(s)\nEnter 3 to Cancel seat\nEnter 4 to Exit portal\nInput : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			m.display();
			break;
		case 2:
			m.book();
			break;
		case 3:
			m.cancel();
			break;
		case 4:
			return 0;
		default:
			cout << "Invalid Input!\n\n";
		}
	}
}

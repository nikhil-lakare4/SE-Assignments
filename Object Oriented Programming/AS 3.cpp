//============================================================================
// Name        : AS3
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
/*Description : Develop an object oriented program in C++ to create a database of
student information system containing the following information:
Name, Roll number, Class, division, Date of Birth, Blood group,
Contact address, telephone number, driving license no. etc
Construct the database with suitable member functions for
initializing and destroying the data viz constructor, default
constructor, Copy constructor, destructor, static member functions,
friend class, this pointer, inline code and dynamic memory
allocation operators-new and delete.
*/
//============================================================================

#include<iostream>
#include<string.h>
using namespace std;

class student
{

        string Name, Cls, Div, DOB, BG, Addr, Licno;
        int Rollno;
        long Tellno;
        static int count;
        public:
				student()
				{
						Rollno = 0;
						Name = "NA";
						Cls = "SE";
						Div = "B";
						DOB = "NA";
						BG = "NA";
						Addr = "NA";
						Licno = "NA";
						Tellno = 0;

				}
				student(string Name,string Cls, string Div, string DOB, string BG, string Addr, string Licno, long Tellno)
				{
						cout << "Inside parameterized constructor...........\n";
						Rollno = ++count;
						this->Name = Name;
						this->Cls = Cls;
						this->Div = Div;
						this->DOB = DOB;
						this->BG = BG;
						this->Addr = Addr;
						this->Licno = Licno;
						this->Tellno = Tellno;

				}

				student (student &s)
				{
						cout << Inside Copy constructor...........\n";
						Rollno = ++count;
						this->Name = s.Name;
						this->Cls = s.Cls;
						this->Div = s.Div;
						this->DOB = s.DOB;
						this->BG = s.BG;
						this->Addr = s.Addr;
						this->Licno = s.Licno;
						this->Tellno = s.Tellno;

				}
				~student()
				{
					cout << "Destructor is called......." << student :: count-- << endl << endl;
				}
                void getdata();
                inline void displaydata();
                static void noofstud();
};

void student :: noofstud()
{
	cout << "Database has " << count << " student\n\n";
}

int student :: count = 0;

void student :: getdata()
{
		count++;
		Rollno = count;
        cout << "Enter the details of " << Rollno << "nd student" << endl << endl;
        cout << "Name: ";
        cin >> Name;
        cout << "Class: ";
        cin >> Cls;
        cout << "Division: ";
        cin >> Div;
        cout << "Date of Birth: ";
        cin >> DOB;
        cout << "Blood Group: ";
        cin >> BG;
        cout << "Contact address: ";
        cin >> Addr;
        cout << "Telephone number: ";
        cin >> Tellno;
        cout << "Driving license number: ";
        cin >> Licno;
        cout << endl;
}

inline void student :: displaydata()
{
        cout << endl << "Roll number: " << Rollno << endl << "Name: " << Name << endl << "Class: " << Cls << endl << "Division: " << Div << endl << "Date of Birth: " << DOB << endl << "Blood Group: " << BG << endl << "Contact address: " << Addr << endl << "Telephone number: " << Tellno << endl << "Drivng licence number: " << Licno << endl << endl;
}

int main()
{
		int n;
		cout << "Enter the number of student\n\n";
		cin >> n;
        student *S = new student[n];
        for(int i = 0; i < n; i++)
        	S[i].getdata();

         cout << "You have entered following details" << endl;

        for(int i = 0; i < n; i++)
        	S[i].displaydata();

        student s1("Student_Name", "SE", "B", "DOB", "Blood_Group", "PCCOE,Pune", "Licence_No.", 12345);
        s1.displaydata();

        student s2(s1);
        s2.displaydata();

        student :: noofstud();

        delete [] S;

        return 0;
}

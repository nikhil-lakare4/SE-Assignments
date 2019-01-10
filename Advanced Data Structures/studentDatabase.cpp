//============================================================================
// studentName        :
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
/* Description :
 */
//============================================================================
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

class Person {
	int rollNo;
	char studentName[30];
	char DOB[10];
	char ADDR[50];
public:
	void setData() {
		cout << "\nEnter the Name of Student: ";
		cin >> studentName;
		cout << "Enter Roll No of Student: ";
		cin >> rollNo;
		cout << "Enter DOB of Student: ";
		cin >> DOB;
		cout << "Enter ADDR of Student: ";
		cin >> ADDR;
	}

	void showData() {
		cout << "\nName of Student : " << studentName;
		cout << "\tRoll No. : " << rollNo;
		cout << "\tDOB. : " << DOB;
		cout << "\tADDR. : " << ADDR;
	}

	int retrollNo() {
		return rollNo;
	}
	char* retstudentName() {
		return studentName;
	}

	char* retDOB() {
		return DOB;
	}
	char* retADDR() {
		return ADDR;
	}
};

/*
 * function to write in a binary file.
 */

void write_record() {
	ofstream outFile;
	outFile.open("student.txt", ios::binary | ios::app);

	Person obj;
	obj.setData();

	outFile.write((char*) &obj, sizeof(obj));

	outFile.close();
}

/*
 * function to display records of file
 */

void display() {
	ifstream inFile;
	inFile.open("student.txt", ios::binary);

	Person obj;

	while (inFile.read((char*) &obj, sizeof(obj))) {
		obj.showData();
	}

	inFile.close();
}

/*
 * function to search and display from binary file
 */

void search(int n) {
	ifstream inFile;
	inFile.open("student.txt", ios::binary);

	Person obj;

	int flag = 0;

	while (inFile.read((char*) &obj, sizeof(obj))) {
		if (obj.retrollNo() == n) {
			obj.showData();
			flag++;
		}
	}

	if (flag == 0)
		cout << "\nDetails not found! :(\n";

	inFile.close();
}
void search(char n[]) {
	ifstream inFile;
	inFile.open("student.txt", ios::binary);

	Person obj;

	int flag = 0;

	while (inFile.read((char*) &obj, sizeof(obj))) {
		if (!strcmp(obj.retstudentName(), n)) {
			obj.showData();
		}
	}

	if (flag == 0)
		cout << "\nDetails not found! :(\n";

	inFile.close();
}
/*
 * function to modify a record
 */

void modify_record(char n[]) {

	fstream file;
	file.open("student.txt", ios::in | ios::out | ios::binary);

	Person obj;

	while (file.read((char*) &obj, sizeof(obj))) {
		if (!strcmp(obj.retstudentName(), n)) {
			cout << "\nEnter the new details of Person";
			obj.setData();

			int pos = -1 * sizeof(obj);
			file.seekp(pos, ios::cur);

			file.write((char*) &obj, sizeof(obj));
		}
	}

	file.close();
}

void delete_record(char n[]) {

	fstream file, tempfile;
	file.open("student.txt", ios::in | ios::out | ios::binary);
	tempfile.open("temp.txt", ios::out | ios::binary);

	Person obj;

	while (file.read((char*) &obj, sizeof(obj))) {
		if (strcmp(obj.retstudentName(), n)) {
			tempfile.write((char*) &obj, sizeof(obj));
		}
	}

	file.close();
	remove("student.txt");
	tempfile.close();
	rename("temp.txt", "student.txt");
}

int main() {
	int ch;
	int no1;
	char studentName1[50];

	do {
		cout
				<< "\n\n1.Create\n2.Display\n3.Find Student\n4.Find Roll No\n5.Update Roll No\n6.Delete Roll No\n7.Exit\nEnter your choice : ";
		cin >> ch;
		switch (ch) {
		case 1:
			write_record();
			break;

		case 2:
			cout << "\nList of records";
			display();
			break;

		case 3:
			//Search studentName
			cout << "\nEnter Roll No : ";
			cin >> no1;
			search(no1);
			break;

		case 4:
			//Search phone no
			cout << "\nEnter Name of Student: ";
			cin >> studentName1;
			search(studentName1);
			break;

		case 5:
			//Modify record
			cout << "To update, Enter the Name of Student: ";
			cin >> studentName1;
			modify_record(studentName1);
			break;
		case 6:
			//Delete record
			cout << "To delete, Enter the Name of Student: ";
			cin >> studentName1;
			delete_record(studentName1);
			break;
		default:
			cout << "\nExit from program...";
			exit(0);
		}
	} while (1);

	return 0;
}

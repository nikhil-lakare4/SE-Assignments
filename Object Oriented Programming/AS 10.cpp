//============================================================================
// Name        : AS 10
// Author      :
// Version     :
// Copyright   : Your copyright notice
/* Description : Write a C++ program that creates an output file, writes information
to it, closes the file and open it again as an input file and read the
information from the file.
*/
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
#define filename "abc.txt"

int main() {
	ofstream fout;
	fout.open(filename);

	if(!fout)
	{
		cout << "Error in opening file!";
		return 0;
	}

	fout << "Hello World!!!";
	fout.close();

	ifstream fin;
	fin.open(filename);
	if(!fin)
	{
		cout <<"Error in reading the file!";
		return 0;
	}

	char ch;

	while(!fin.get(ch))
	{
		cout << ch;
	}

	fin.close();

	return 0;
}

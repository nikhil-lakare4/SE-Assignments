#include<iostream>
#include<list>
using namespace std;

class setOperations {
	list<int> A;
	list<int> B;
	list<int> U;
	list<int> I;
	list<int> DA;
	list<int> DB;
	list<int> SS;
public:
	void createSets();
	void checkSize();
	void addElementA();
	void addElementB();
	void deleteElementA();
	void deleteElementB();
	void Union();
	void Intersection();
	void Difference();
	void Subset();
	void displaySets();
};

void setOperations::createSets() {

	int data;
	int numA, numB;

	cout << "\nEnter the number of elements to insert in set A: ";
	cin >> numA;
	cout << "\nEnter the elements of Set A: \n";
	for (int i = 0; i < numA; i++) {
		cin >> data;
		A.push_back(data);
	}

	cout << "\nEnter the number of elements to insert in set B: ";
	cin >> numB;
	cout << "\nEnter the elements of Set B: \n";
	for (int i = 0; i < numB; i++) {
		cin >> data;
		B.push_back(data);
	}

}

void setOperations::checkSize() {

	list<int>::iterator iterator;

	cout << "\nSize of Set A is : ";
	cout << A.size() << endl;

	cout << "\nSize of Set B is : ";
	cout << B.size() << endl;


}

void setOperations::addElementA() {

	int data;
	cout << "\nEnter the element to be added in Set A: ";
	cin >> data;
	A.push_back(data);
	cout << "\nThe element added successfully in Set A!\n";

}

void setOperations::addElementB() {

	int data;
	cout << "\nEnter the element to be added in Set B: ";
	cin >> data;
	B.push_back(data);
	cout << "\nThe element added successfully in Set B!\n";\
}

void setOperations::deleteElementA() {

	int data;
	cout << "\nEnter the element to which is to be deleted: ";
	cin >> data;

	A.remove(data);

	cout << "\nThe element deleted successfully!!";

}

void setOperations::deleteElementB() {

	int data;
	cout << "\nEnter the element to which is to be deleted: ";
	cin >> data;

	B.remove(data);

	cout << "\nThe element deleted successfully!!";

}

void setOperations::Union() {

	int flag;

	list<int>::iterator iteratorA;
	list<int>::iterator iteratorB;
	list<int>::iterator iteratorU;
	for (iteratorA = A.begin(); iteratorA!=A.end();iteratorA++) {
		U.push_back(*iteratorA);
	}

	for (iteratorB=B.begin();iteratorB!=B.end(); iteratorB++) {
		flag = 0;
		for ( iteratorU=U.begin(); iteratorU!=U.end(); iteratorU++) {
			if (*iteratorB == *iteratorU) {
				flag++;
			}
		}

		if (flag == 0) {
			U.push_back(*iteratorB);
		}
	}

	cout << "\nUnion of Set A & Set B = { ";

		iteratorU = U.begin();
		while (true) {
			cout << *iteratorU;
			iteratorU++;
			if (iteratorU == U.end())
				break;
			else
				cout << ", ";
		}
	cout << " }\n" << endl;
};

void setOperations::Intersection() {

	int flag;

	list<int>::iterator iteratorA;
	list<int>::iterator iteratorB;
	list<int>::iterator iteratorI;

	for (iteratorA=A.begin(); iteratorA!=A.end(); iteratorA++) {
		flag = 0;
		for ( iteratorB=B.begin(); iteratorB!=B.end(); iteratorB++) {
			if (*iteratorA == *iteratorB) {
				flag++;
			}
		}

		if (flag != 0) {
			I.push_back(*iteratorA);
		}
	}

	cout << "\nIntersection of Set A & Set B = { ";

		iteratorI = I.begin();
		while (true) {
			cout << *iteratorI;
			iteratorI++;
			if (iteratorI == I.end())
				break;
			else
				cout << ", ";
		}
	cout << " }\n" << endl;
};

void setOperations::Difference() {

	int flag;

	list<int>::iterator iteratorA;
	list<int>::iterator iteratorB;
	list<int>::iterator iteratorDA;
	list<int>::iterator iteratorDB;

	for (iteratorA=A.begin(); iteratorA!=A.end(); iteratorA++) {
		flag = 0;
		for ( iteratorB=B.begin(); iteratorB!=B.end(); iteratorB++) {
			if (*iteratorA == *iteratorB) {
				flag++;
			}
		}

		if (flag == 0) {
			DA.push_back(*iteratorA);
		}
	}

	cout << "\nDifference of Set A & Set B (A - B) = { ";

		iteratorDA = DA.begin();
		while (true) {
			cout << *iteratorDA;
			iteratorDA++;
			if (iteratorDA == DA.end())
				break;
			else
				cout << ", ";
		}
	cout << " }\n" << endl;

	for (iteratorB=B.begin(); iteratorB!=B.end(); iteratorB++) {
			flag = 0;
			for ( iteratorA=A.begin(); iteratorA!=A.end(); iteratorA++) {
				if (*iteratorB == *iteratorA) {
					flag++;
				}
			}

			if (flag == 0) {
				DB.push_back(*iteratorB);
			}
		}

		cout << "\nDifference of Set B & Set A (B - A) = { ";

			iteratorDB = DB.begin();
			while (true) {
				cout << *iteratorDB;
				iteratorDB++;
				if (iteratorDB == DB.end())
					break;
				else
					cout << ", ";
			}
		cout << " }\n" << endl;
};

void setOperations::Subset() {

	int flag;

	list<int>::iterator iteratorA;
	list<int>::iterator iteratorB;
	list<int>::iterator iteratorSS;
	
	int data;
	int num;

	cout << "\nEnter the number of elements to insert in subset: ";
	cin >> num;
	cout << "\nEnter the elements of subset: \n";
	for (int i = 0; i < num; i++) {
		cin >> data;
		SS.push_back(data);
	}

	flag = 0;
	for (iteratorSS=SS.begin(); iteratorSS!=SS.end(); iteratorSS++) {
		for ( iteratorA=A.begin(); iteratorA!=A.end(); iteratorA++) {
			if (*iteratorSS == *iteratorA) {
				flag++;
			}
		}	
	}
	if (flag == num) 
		cout << "\nGiven set is subset of A :)\n";
	else
		cout << "\nGiven set is not subset of A :(\n";
	
	flag = 0;
	for (iteratorSS=SS.begin(); iteratorSS!=SS.end(); iteratorSS++) {
		for ( iteratorB=B.begin(); iteratorB!=B.end(); iteratorB++) {
			if (*iteratorSS == *iteratorB) {
				flag++;
			}
		}	
	}
	if (flag == num) 
		cout << "\nGiven set is subset of B :)\n";
	else
		cout << "\nGiven set is not subset of B :(\n";

};

void setOperations::displaySets() {

	list<int>::iterator iterator;

	cout << "\nSet A is : { ";
	iterator = A.begin();
	while (true) {
		cout << *iterator;
		iterator++;
		if (iterator == A.end())
			break;
		else
			cout << ", ";
	}
	cout << " }\n";

	cout << "\nSet B is : { ";
	iterator = B.begin();
	while (true) {
		cout << *iterator;
		iterator++;
		if (iterator == B.end())
			break;
		else
			cout << ", ";
	}
	cout << " }\n";

}

int main(void) {

	setOperations S;

	int choice;

	do {

		cout << "\nEnter 1 to create Set A & Set B"
				"\nEnter 2 to check size of Set A & Set B"
				"\nEnter 3 to add element in set A"
				"\nEnter 4 to add element in Set B"
				"\nEnter 5 to delete element of Set A"
				"\nEnter 6 to delete element of set of B"
				"\nEnter 7 to create union of Sets"
				"\nEnter 8 to create intersection of sets"
				"\nEnter 9 to create difference of sets"
				"\nEnter 10 to check subset of A & B"
				"\nEnter 11 to display set A & set B"
				"\nEnter 12 to exit"
				"\nInput:";

		cin >> choice;

		switch (choice) {
		case 1:
			S.createSets();
			break;
		case 2:
			S.checkSize();
			break;
		case 3:
			S.addElementA();
			break;
		case 4:
			S.addElementB();
			break;
		case 5:
			S.deleteElementA();
			break;
		case 6:
			S.deleteElementB();
			break;
		case 7:
			S.Union();
			break;
		case 8:
			S.Intersection();
			break;
		case 9:
			S.Difference();
			break;
		case 10:
			S.Subset();
			break;
		case 11:
			S.displaySets();
			break;
		case 12:
			break;
		}
	} while (choice != 12);

	return 0;
}

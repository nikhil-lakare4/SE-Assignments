#include<iostream>
using namespace std;

const int MAX = 10;

class sparse {
public:
	int A[MAX][MAX], ATP[MAX*MAX][3];
	int rows, cols;
	void getmat();
	void converttotupple();
	void converttosimple();
	void simpletranspose();
	void fasttranspose();
};

void sparse::getmat() {
	cout << "\nEnter number of rows of matrix: ";
	cin >> rows;
	cout << "\nEnter number of columns of matrix: ";
	cin >> cols;

	cout << "\nEnter the elements of matrix (row by row): " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> A[i][j];
		}
		cout << endl;
	}

	cout << "\nEntered Matrix is " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}

void sparse::converttotupple() {
	ATP[0][0] = rows;
	ATP[0][1] = cols;

	int k = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (A[i][j] != 0) {
				ATP[k][0] = i;
				ATP[k][1] = j;
				ATP[k][2] = A[i][j];
				k++;
			}
		}
	}
	ATP[0][2] = k - 1;

	cout << "\nThree tupple matrix representation is :" << endl;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ATP[i][j] << "\t";
		}
		cout << endl;
	}

}

void sparse::converttosimple() {
	int ASP[rows][cols];

	int k = 1;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (ATP[k][0] == i && ATP[k][1] == j && k <= ATP[0][2]) {
				ASP[i][j] = ATP[k][2];
				k++;
			} else
				ASP[i][j] = 0;
		}
	}

	cout << "\nSimple matrix of three tupple is " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << ASP[i][j] << "\t";
		}
		cout << endl;
	}

}

void sparse::simpletranspose() {

	int ATR[ATP[0][2] + 1][3];

	ATR[0][0] = ATP[0][1];
	ATR[0][1] = ATP[0][0];
	ATR[0][2] = ATP[0][2];

	int k = 1;

	for (int i = 0; i < ATP[0][2]; i++) {
		for (int j = 1; j <= ATP[0][2]; j++) {
			if (ATP[j][1] == i) {
				ATR[k][0] = ATP[j][1];
				ATR[k][1] = ATP[j][0];
				ATR[k][2] = ATP[j][2];
				k++;
			}
		}
	}

	cout << "\nSimple Transpose of three tupple matrix is " << endl;
	for (int i = 0; i <= ATR[0][2]; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ATR[i][j] << "\t";
		}
		cout << endl;
	}
}
void sparse::fasttranspose() {

	//Fast transpose
	int ATF[ATP[0][2] + 1][3];

	int terms[cols];
	int rpos[cols];

	for (int i = 0; i < cols; i++) {
		terms[i] = 0;
	}

	for (int i = 1; i <= ATP[0][2]; i++) {
		terms[ATP[i][1]]++;
	}

	rpos[0] = 1;

	for (int i = 1; i < cols; i++) {
		rpos[i] = rpos[i - 1] + terms[i - 1];
	}

	for (int i = 1; i <= ATP[0][2]; i++) {
		int j;
		j = rpos[ATP[i][1]];
		ATF[j][0] = ATP[i][1];
		ATF[j][1] = ATP[i][0];
		ATF[j][2] = ATP[i][2];
		rpos[ATP[i][1]] = j + 1;
	}
	ATF[0][0] = cols;
	ATF[0][1] = rows;
	ATF[0][2] = ATP[0][2];
	//	Displaying the fast transpose
	cout << "\nFast Transpose of three tupple matrix is:" << endl;
	for (int i = 0; i <= ATP[0][2]; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ATF[i][j] << "\t";
		}
		cout << endl;
	}
}

void addition(sparse x, sparse y) {

	if (x.rows != y.rows || x.cols != y.cols) {
		cout << "\nAddition is not possible!\n";
		return;
	}

	int max;

	x.ATP[0][2] > y.ATP[0][2] ? max = x.ATP[0][2] : max = y.ATP[0][2];

	int ADD[max + 1][3];

	ADD[0][0] = x.rows;
	ADD[0][1] = x.cols;

	int i = 1, j = 1, k = 1;
	while (i <= x.ATP[0][2] && j <= y.ATP[0][2]) {
		cout << "In while";
		if (x.ATP[i][0] == y.ATP[j][0]) {
			if (x.ATP[i][1] == y.ATP[j][1]) {
				ADD[k][0] = x.ATP[i][0];
				ADD[k][1] = x.ATP[i][1];
				ADD[k][2] = x.ATP[i][2] + y.ATP[j][2];
				i++;
				j++;
				k++;
			} else {
				if (x.ATP[i][1] > y.ATP[j][1]) {
					ADD[k][0] = y.ATP[j][0];
					ADD[k][1] = y.ATP[j][1];
					ADD[k][2] = y.ATP[j][2];
					j++;
					k++;
				} else {

					ADD[k][0] = x.ATP[i][0];
					ADD[k][1] = x.ATP[i][1];
					ADD[k][2] = x.ATP[i][2];
					i++;
					k++;
				}
			}
		} else {
			if (x.ATP[i][0] > y.ATP[j][0]) {
				ADD[k][0] = y.ATP[j][0];
				ADD[k][1] = y.ATP[j][1];
				ADD[k][2] = y.ATP[j][2];
				j++;
				k++;
			} else {
				ADD[k][0] = x.ATP[i][0];
				ADD[k][1] = x.ATP[i][1];
				ADD[k][2] = x.ATP[i][2];
				i++;
				k++;
			}
		}
	}
	ADD[0][2] = k - 1;
	cout << "\nAddition of the two 3 tupple matrices is:\n";
	for (i = 0; i <= ADD[0][2]; i++) {
		for (j = 0; j < 3; j++) {
			cout << ADD[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {
	sparse S1, S2;
	int ch;
	do {
		cout << "\n1. Enter the sparse matrix";
		cout
				<< "\n2. Convert the entered sparse matrix to three tupple representation";
		cout << "\n3. Simple transpose of entered three tupple matrix";
		cout << "\n4. Fast transpose of entered three tupple matrix";
		cout << "\n5. Addition of the two three tupple matrices";
		cout << "\n6. EXIT";
		cout << "\nInput: ";
		cin >> ch;
		cout << endl;

		switch (ch) {
		case 1:
			cout << "\nEnter the first matrix:" << endl;
			S1.getmat();
			break;
		case 2:
			S1.converttotupple();
			break;
		case 3:
			S1.simpletranspose();
			break;
		case 4:
			S1.fasttranspose();
			break;
		case 5:
			cout << "\nEnter the second matrix:" << endl;
			S2.getmat();
			S2.converttotupple();
			addition(S1, S2);
			break;
		}

	} while (ch <= 5);

	return 0;
}


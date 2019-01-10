//============================================================================
// Name        : AS4
// Author      : Nikhil Lakare SECOB205 B1
// Version     :
// Copyright   : Your copyright notice
/*Description : Implement a class Complex which represents the Complex
Number data type. Implement the following operations:
1. Constructor (including a default constructor which creates the
complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers.
*/
//============================================================================

#include <iostream>
using namespace std;

class Complex
{
private:
	int real;
	int imag;
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex (int x, int y)
	{
		real = x;
		imag = y;
	}

	friend istream &operator >>(istream &mycin, Complex &C);

	Complex operator +(Complex &C)
	{
		Complex temp;
		temp.real = real + C.real;
		temp.imag = imag + C.imag;
		return temp;
	}

	Complex operator *(Complex &C)
	{
		Complex temp;
        temp.real = (real * C.real) - (imag * C.imag);
        temp.imag = (real * C.imag) + (imag * C.real);
        return temp;
	}

	friend ostream &operator <<(ostream &mycout, Complex &C);
};

istream &operator >>(istream &mycin, Complex &C)
{
	cout << "Enter real part : ";
	mycin >> C.real;
	cout << "Enter real imaginary : ";
	mycin >> C.imag;
	return mycin;
}

ostream &operator <<(ostream &mycout, Complex &C)
{
	mycout << C.real << "+" << C.imag << "i" << endl;
	return mycout;
}

int main() {

	Complex C1;
	Complex C2(2, 3);
	Complex C3;
	cin >> C3;

	Complex C4 = C2 + C3;
	Complex C5 = C2 * C3;

	cout << C1;
	cout << C2;
	cout << C3;
	cout << C4;
	cout << C5;

	return 0;
}

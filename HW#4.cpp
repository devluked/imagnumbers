#include<iostream>
#include<iomanip>
using namespace std;

class Complex
{
	friend ostream &operator<<(ostream&, const Complex&);
	friend istream &operator >> (istream&, Complex&);

public:
	Complex(float = 0, float = 0);
	Complex operator+ (Complex);
	Complex operator- (Complex);
	Complex operator* (Complex);
	Complex& operator++();
	Complex operator++(int);
	bool operator == (const Complex &) const;
	bool operator != (const Complex &) const;

private:
	float real, imag;
};

Complex::Complex(float a, float b)
{
	real = a;
	imag = b;
}

Complex Complex::operator+(Complex one)
{
	Complex two;
	two.real = real + one.real;
	two.imag = imag + one.imag;
	return(two);
}

Complex Complex::operator-(Complex one)
{
	Complex two;
	two.real = real - one.real;
	two.imag = imag - one.imag;
	return(two);
}

Complex Complex::operator*(Complex one)
{
	Complex two;
	two.real = (real * one.real) + (imag * one.imag * (-1));
	two.imag = (real * one.imag) - (one.real * imag);
	return(two);
}
Complex& Complex::operator ++()
{
    float real1 = real;
	real = (real1 * real1 * real1) + (3 * real1) * (imag * imag * (-1));
    imag = 3 * (real1 * real1)*imag + (imag * imag *imag * (-1));
    return *this;
}

Complex Complex::operator ++(int)
{
    Complex temp = *this;
    float real1 = real;
	real = (real1 * real1 * real1) + (3 * real1) * (imag * imag * (-1));
    imag = 3 * (real1 * real1)*imag + (imag * imag *imag * (-1));
    return temp;
}

//Insertion Operator
ostream &operator<<(ostream &output, const Complex &one)
{
	output << one.real << "+" << one.imag << "i" << endl;
	return output;
}

//Extraction Operator
istream &operator >> (istream &input, Complex &one)
{
	input >> one.real >> one.imag;
	return input;
}

bool Complex::operator==(const Complex &one) const
{
	if (one.real == real && one.imag == imag)
		return true;
	else
		return false;
}

bool Complex::operator!=(const Complex &one) const
{
	if (one.real != real || one.imag != imag)
		return true;
	else
		return false;
}

//Write stream insertion and extraction operators

int main()
{
	Complex c1, c2, c3, sum, diff, prod;
	cout << "Enter first complex number: ";
	cin >> c1;
	cout << "Enter second complex number: ";
	cin >> c2;
	cout << "The first complex number is: " << c1;
	cout << "The second complex number is: " << c2;
	sum = c1 + c2;
	cout << "The sum is: " << sum;
	diff = c1 - c2;
	cout << "The difference is: " << diff;
	prod = c1*c2;
	cout << "The product is: " << prod << endl;
	if (c1 == c2)
		cout << "Equal" << endl;
	if (c1!=c2)
		cout <<"Not equal" << endl;
	cout << endl;
	//Cube function is the ++ operator
	cout << "Preincrement: " << endl << ++c1 << ++c2 << endl;
    cout << "Postincrement: " << endl << c1++ << c2++ << endl;
	cout << "After post increment: " << endl << c1 <<  c2 << endl;

	return 0;
}

/*Enter first complex number: 1 2
Enter second complex number: 1 2
The first complex number is: 1+2i
The second complex number is: 1+2i
The sum is: 2+4i
The difference is: 0+0i
The product is: -3+0i

Equal

Preincrement:
-11+-2i
-11+-2i

Postincrement:
-11+-2i
-11+-2i

After post increment:
-1199+-718i
-1199+-718i


Process returned 0 (0x0)   execution time : 1.739 s
Press any key to continue.*/

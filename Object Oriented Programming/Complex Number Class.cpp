#include <iostream>
#include <cmath>
using namespace std;

class Complex {
	friend ostream& operator <<(ostream&, Complex&);
	friend istream& operator >>(istream&, Complex&);

public:
	Complex(double = 0, double = 0);
	void setComplex(double, double);

	Complex operator +(Complex);
	Complex operator -(Complex);
	Complex operator *(Complex);
	Complex operator /(Complex);

	bool operator <(Complex);
	bool operator <=(Complex);
	bool operator >(Complex);
	bool operator >=(Complex);
	bool operator ==(Complex);
	bool operator !=(Complex);

private:
	double real_n;
	double imaginary_n;
};

Complex::Complex(double a, double b) {
	setComplex(a, b);
}

void Complex::setComplex(double a, double b) {
	real_n = a;
	imaginary_n = b;
}

Complex Complex::operator+(Complex n) {
	Complex sum;
	sum.real_n = real_n + n.real_n;
	sum.imaginary_n = imaginary_n + n.imaginary_n;
	return sum;
}

Complex Complex::operator-(Complex n) {
	Complex difference;
	difference.real_n = real_n - n.real_n;
	difference.imaginary_n = imaginary_n - n.imaginary_n;
	return difference;
}

Complex Complex::operator*(Complex n) {
	Complex product;
	product.real_n = real_n * n.real_n - (imaginary_n * n.imaginary_n);
	product.imaginary_n = real_n * n.imaginary_n + n.real_n * imaginary_n;
	return product;
}

Complex Complex::operator/(Complex n) {
	Complex quotient;
	Complex conjugate = n;
	conjugate.imaginary_n *= -1;

	quotient = *this * conjugate;

	quotient.real_n /= (pow(n.real_n, 2) + pow(n.imaginary_n, 2));
	quotient.imaginary_n /= (pow(n.real_n, 2) + pow(n.imaginary_n, 2));
	return quotient;
}

bool Complex::operator <(Complex n) {
	return sqrt(pow(real_n, 2) + pow(imaginary_n, 2)) < sqrt(pow(n.real_n, 2) + pow(n.imaginary_n, 2));
}
bool Complex::operator <=(Complex n) {
	return sqrt(pow(real_n, 2) + pow(imaginary_n, 2)) <= sqrt(pow(n.real_n, 2) + pow(n.imaginary_n, 2));
}
bool Complex::operator >(Complex n) {
	return sqrt(pow(real_n, 2) + pow(imaginary_n, 2)) > sqrt(pow(n.real_n, 2) + pow(n.imaginary_n, 2));
}
bool Complex::operator >=(Complex n) {
	return sqrt(pow(real_n, 2) + pow(imaginary_n, 2)) >= sqrt(pow(n.real_n, 2) + pow(n.imaginary_n, 2));
}
bool Complex::operator ==(Complex n) {
	return sqrt(pow(real_n, 2) + pow(imaginary_n, 2)) == sqrt(pow(n.real_n, 2) + pow(n.imaginary_n, 2));
}
bool Complex::operator !=(Complex n) {
	return sqrt(pow(real_n, 2) + pow(imaginary_n, 2)) != sqrt(pow(n.real_n, 2) + pow(n.imaginary_n, 2));
}

ostream& operator <<(ostream& output, Complex& n) {
	if (n.imaginary_n < 0) {
		output << n.real_n << "-" << n.imaginary_n * -1<<"i";
	}
	else if (n.imaginary_n > 0) {
		output << n.real_n << "+" << n.imaginary_n<<"i";
	}
	else {
		output << n.real_n;
	}

	return output;
}
istream& operator >>(istream& input, Complex& n) {
	input >> n.real_n >> n.imaginary_n;
	return input;
}

int main() {

	Complex n, m;

	cout << "Enter n" << endl;
	cin >> n;
	cout << "Enter m" << endl;
	cin >> m;

	Complex result;

	result = n + m;
	cout << "Sum: " << result << endl;

	result = n - m;
	cout << "Difference: " << result << endl;

	result = n * m;
	cout << "Product: " << result << endl;

	result = n / m;
	cout << "Quotient: " << result << endl;

	cout << "Distance from Origin wise" << endl;
	cout << n << " < " << m << " is " << ((n < m) ? "True" : "False") << endl;
	cout << n << " <= " << m << " is " << ((n <= m) ? "True" : "False") << endl;
	cout << n << " > " << m << " is " << ((n > m) ? "True" : "False") << endl;
	cout << n << " >= " << m << " is " << ((n >= m) ? "True" : "False") << endl;
	cout << n << " == " << m << " is " << ((n == m) ? "True" : "False") << endl;
	cout << n << " != " << m << " is " << ((n != m) ? "True" : "False") << endl;
}

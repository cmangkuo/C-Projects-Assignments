#pragma once
#include <iostream>
using namespace std;
class Fraction
{
	
private:
	int numerator;
	int denominator;
	void simplify();
public:
	Fraction() {
		numerator = 0; denominator = 1;
	}
	Fraction(int num, int den);
	int greatestCommonFactor(int, int);
	int leastCommonMultiple(int, int);
	Fraction operator+ (Fraction);
	Fraction operator- (Fraction);
	Fraction operator* (Fraction);
	Fraction operator/ (Fraction);
	bool operator> (const Fraction& a) const;
	bool operator< (const Fraction& a) const;
	bool operator== (const Fraction& a) const;

	// Insertion operator
	friend ostream& operator << (ostream& out, const Fraction& a)
	{
		if (a.numerator == 0)
		{
			out << "0";
		}
		else if (a.denominator == 1)
		{
			out << a.numerator;
		}
		else
		{
			out << a.numerator << "/" << a.denominator;
		}
		return out;
	};

	// Extractor operator
	friend istream& operator >> (istream& in, Fraction& a)
	{
		char c;
		cout << "Enter fraction: ";
		in >> a.numerator >> c >> a.denominator;
		a.simplify();
		return in;

	};

};

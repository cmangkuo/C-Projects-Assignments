#include "stdafx.h"
#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Simplification
void Fraction::simplify()
{
	// Divide by greatest common factor
	int GCD = greatestCommonFactor(numerator, denominator);
	numerator /= GCD;
	denominator /= GCD;

	// If denominator is negative, switch signs on numerator/denominator
	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
			
	
}

// Paramaterized constructor
Fraction::Fraction(int num, int den)
{
	numerator = num;
	while ((!den) || (den == 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Denominator invalid, re-enter: ";
		cin >> den;
		cin.ignore();	
	}
	denominator = den;

}


// Find greatest common denominator
int Fraction::greatestCommonFactor(int numerator, int denominator)
{
	bool valid = true;
	int temp1, temp2, temp3;
	int factor;

	// Exit function if numerator is zero
	if (numerator == 0)
	{
		factor = 1;
		valid = false;
	}

	// Find GCD via Euclidean Algorithm
	if (valid)
	{
		if (numerator >= denominator)
		{
			temp1 = numerator;
			temp2 = denominator;
		}
		else 
		{
			temp1 = denominator;
			temp2 = numerator;
		}
		while (temp1 % temp2 != 0)
		{
			temp3 = temp2;
			temp2 = temp1 % temp2;
			temp1 = temp3;
		}
		factor = temp2;
	}
	return factor;
}

// Find least common multiple
int Fraction::leastCommonMultiple(int den1, int den2)
{
	int factor, multiple;
	// Find GCD
	factor = greatestCommonFactor(den1, den2);
	// LCM = (A x B) / GCD
	multiple = (den1 * den2) / factor;
	return multiple;

}
// Addition operator
Fraction Fraction::operator+(Fraction a)
{
	Fraction temp;
	// Convert to common denominator, scale numerator by equal amount
	int mult1, mult2;
	// Find LCM
	int LCM = leastCommonMultiple(denominator, a.denominator);

	// Find respective common multipliers
	mult1 = LCM / denominator;
	mult2 = LCM / a.denominator;

	// Multiply numerator/denominator by their respective multipliers
	numerator *= mult1;
	denominator *= mult1;

	a.numerator *= mult2;
	a.denominator *= mult2;

	// Add numerators
	temp.numerator = numerator + a.numerator;
	temp.denominator = a.denominator;
	temp.simplify();
	return (temp);


}

// Subtraction operator
Fraction Fraction::operator-(Fraction a)
{
	Fraction temp;
	// Convert to common denominator, scale numerator by equal amount
	int mult1, mult2;
	// Find LCM
	int LCM = leastCommonMultiple(denominator, a.denominator);

	// Find respective common multipliers
	mult1 = LCM / denominator;
	mult2 = LCM / a.denominator;

	// Multiply numerator/denominator by their respective multipliers
	numerator *= mult1;
	denominator *= mult1;

	a.numerator *= mult2;
	a.denominator *= mult2;

	// Subtract numerators
	temp.numerator = numerator - a.numerator;
	temp.denominator = a.denominator;
	temp.simplify();
	return (temp);

}

// Multiplication operator
Fraction Fraction::operator*(Fraction a)
{
	Fraction temp;
	temp.numerator = numerator * a.numerator;
	temp.denominator = denominator * a.denominator;
	temp.simplify();
	return (temp);

}

// Division operator
Fraction Fraction::operator/(Fraction a)
{
	Fraction temp;
	temp.numerator = numerator * a.denominator;
	temp.denominator = denominator * a.numerator;
	temp.simplify();
	return (temp);

}

// Greater than operator
bool Fraction::operator>(const Fraction& a) const
{
	double frac1, frac2;
	frac1 = double(numerator) / double(denominator);
	frac2 = double(a.numerator) / double(a.denominator);
	return (frac1 > frac2);
}

// Less than operator
bool Fraction::operator<(const Fraction & a) const
{
	double frac1, frac2;
	frac1 = double(numerator) / double(denominator);
	frac2 = double(a.numerator) / double(a.denominator);
	return (frac1 < frac2);
}

// Equal to operator
bool Fraction::operator==(const Fraction & a) const
{
	double frac1, frac2;
	frac1 = double(numerator) / double(denominator);
	frac2 = double(a.numerator) / double(a.denominator);
	return (frac1 == frac2);
}


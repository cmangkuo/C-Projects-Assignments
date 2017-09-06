// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// SOLUTION

// Constant for array size
const int SIZE = 80;

// Function prototypes
void upper(char[]);
void lower(char[]);
void reverse(char[]);

int main()
{
	// Three character arrays
	char str1[SIZE], str2[SIZE], str3[SIZE];

	// Get a string
	cout << "Enter a string: ";
	cin.getline(str1, SIZE);

	// Copy the string to str2 and str3.
	strcpy_s(str2, str1);
	strcpy_s(str3, str1);

	// Change str1 to uppercase.
	cout << "After a call to Upper: ";
	upper(str1);
	cout << str1 << endl;

	// Change str2 to lowercase.
	cout << "After a call to Lower: ";
	lower(str2);
	cout << str2 << endl;

	// Reverse the case in str3.
	cout << "After a call to Reverse: ";
	reverse(str3);
	cout << str3 << endl;
	return 0;
}

//***********************************************
// Function upper *
// this function converts each character in the *
// str parameter array to uppercase. *
//***********************************************

void upper(char str[])
{

	// TODO


}

//***********************************************
// Function lower *
// this function converts each character in the *
// str parameter array to lowercase. *
//***********************************************

void lower(char str[])
{

	// TODO

}

//***********************************************
// Function reverse *
// This function steps through each character *
// in the str parameter array, converting each *
// uppercase character to lowercase, and each *
// lowercase character to uppercase. *
//***********************************************

void reverse(char str[])
{

	// TODO

}
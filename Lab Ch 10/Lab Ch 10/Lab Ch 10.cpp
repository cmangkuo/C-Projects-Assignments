// Lab Ch 10.cpp
// Author: Chris Mangkuorahardjo
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// SOLUTION

// Constant for array size
const int SIZE = 80;
int stringsize = 0;
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
	stringsize = strlen(str1);
	

	// Copy the string to str2 and str3.
	strcpy_s(str2, str1);
	strcpy_s(str3, str1);


	// Change str1 to uppercase.
	cout << "After a call to Upper: ";
	upper(str1);
	

	// Change str2 to lowercase.
	cout << "After a call to Lower: ";
	lower(str2);
	

	// Reverse the case in str3.
	cout << "After a call to Reverse: ";
	reverse(str3);
	
	cin.ignore();
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
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = toupper(str[i]);
		
	}
	cout << str << endl;
	

}

//***********************************************
// Function lower *
// this function converts each character in the *
// str parameter array to lowercase. *
//***********************************************

void lower(char str[])
{

	// TODO
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = tolower(str[i]);

	}
	cout << str << endl;
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

	
	for (int i = 0; i < stringsize; i++)
	{
		
		if (isspace(str[i] == true))
		{
			continue;
		}

		else if (isupper(str[i]) == true)
		{
			str[i] = tolower(str[i]);
			cout << str[i];
		}
		else
		{
			str[i] = toupper(str[i]);
			cout << str[i];
		}
		

	}
	
}

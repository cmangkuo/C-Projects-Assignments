// CS116Lab2Part1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototype
// Accepts an integer array a of size b and reverses it
int* ReverseArray(int a[], int b);

int main()
{
	// Modify the test array here
	int testArray[] = {10,20,30,40,50,60,70,80,90,100};

	int size = sizeof(testArray) / sizeof(*testArray);
	cout << "Test Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << testArray[i];
		if (i < size-1)
		{
			cout << ", ";
		}
	}
	cout << "." << endl;


	int *reversedArray = new int[size];
	reversedArray = ReverseArray(testArray, size);
	cout << "Reversed Array: ";
	for (int i = 1; i < size+1; i++)
	{
		cout << reversedArray[i];
		if (i < size)
		{
			cout << ", ";
		}
	}
	cout << "." << endl;
	cin.ignore();
    return 0;
}



// Function Definition
// Takes an input array, and its size. Returns a pointer array whose contents are reversed from the input array
int* ReverseArray(int a[], int b)
{
	// Create pointer array
	int* newArray;
	newArray = new int[b];
	
	// Populate temporary array in reverse
	for (int i = 0; i <= b; i++)
	{
		*(newArray + i) = a[b - i];
	}

	int* pointer = newArray;
	return pointer;
	delete[] newArray;
	
}



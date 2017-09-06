

// Author: Chris Mangkuorahardjo

#include <iostream>
#include <iomanip>
using namespace std;

// Constants for the array sizes
const int ROWS = 4;
const int COLS = 5;

// Function prototypes
int getTotal(int[][COLS], int, int);
double getAverage(int[][COLS], int, int);
int getRowTotal(int[][COLS], int, int);
int getColumnTotal(int[][COLS], int, int);
int getHighestInRow(int[][COLS], int, int);
int getLowestInRow(int[][COLS], int, int);

int main()
{
	// Array with test data
	int testArray[ROWS][COLS] = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 },
		{ 16, 17, 18, 19, 20 }
	};

	cout << "Your array is: " << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << testArray[i][j] << ", ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------------------" << endl;

	// Display the total of the array elements.
	int total = getTotal(testArray, ROWS, COLS);
	cout << "The total sum of array elements is: " << total << endl;
	cout << "------------------------------------------------------------" << endl;
	
	// Display the average of the array elements.
	double average = getAverage(testArray, ROWS, COLS);
	cout << "The average of the array elements is: " << average << endl;
	cout << "------------------------------------------------------------" << endl;
	

	// Display the total of row 0 to row 3 (4 rows in total).
	int rowTotal = 0;
	for (int i = 0; i < ROWS; i++)
	{
		rowTotal = getRowTotal(testArray, i, COLS);
		cout << "The total for row " << i + 1 << " is: " << rowTotal << endl;

	}
	cout << "------------------------------------------------------------" << endl;
	
	
	

	// Display the total of column 0 to column 5 (each row has 5 columns).
	int colTotal = 0;
	for (int i = 0; i < COLS; i++)
	{
		colTotal = getColumnTotal(testArray, ROWS, i);
		cout << "The total for column " << i + 1 << " is: " << colTotal << endl;

	}
	cout << "------------------------------------------------------------" << endl;
	

	
	
	// Display the highest value in each row.
	int highestInRow = 0;
	for (int i = 0; i < ROWS; i++)
	{
		highestInRow = getHighestInRow(testArray, i, COLS);
		cout << "The highest value in row " << i + 1 << " is: " << highestInRow << endl;
	
	}
	cout << "------------------------------------------------------------" << endl;


	// Display the lowest value in each row.
	int lowestInRow = 0;
	for (int i = 0; i < ROWS; i++)
	{
		lowestInRow = getLowestInRow(testArray, i, COLS);
		cout << "The lowest value in row " << i + 1 << " is: " << lowestInRow << endl;
		
	}
	cout << "------------------------------------------------------------" << endl;



	cin.ignore();

	return 0;
}

// ********************************************************
// The getTotal function returns the total of all *
// the elements in the array. *
// ********************************************************
int getTotal(int array[][COLS], int rows, int cols)
{
	int total = 0;
	int i, j = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			total += array[i][j];
		}
	}

	// TODO

	return total;
}

// ********************************************************
// The getAverage function returns the averave value *
// of the elements in the array. *
// ********************************************************
double getAverage(int array[][COLS], int rows, int cols)
	{
		// Calculate the number of elements in the array.
		// Use a double so we can avoid integer division
		// later.
		double numElements = rows * cols;
		double total = 0;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				total += array[i][j];
			}
		}

		// TODO: Get the average of the elements.
		double average = total / numElements;

		// Return the average.
		return average;
	}

// ********************************************************
// The getRowTotal function returns the total of the *
// the elements in the specified row of the array. *
// ********************************************************
int getRowTotal(int array[][COLS], int rowToTotal, int cols)
{
	int total = 0;
	for (int i = 0; i < cols; i++)
	{
		total += array[rowToTotal][i];
	}
	// TODO

	return total;
}

// ********************************************************
// The getColTotal function returns the total of the *
// the elements in the specified column of the array. *
// ********************************************************
int getColumnTotal(int array[][COLS], int rows, int colToTotal)
{
	int total = 0;

	// TODO
	for (int i = 0; i < rows; i++)
	{
		total += array[i][colToTotal];
	}

	return total;
}

// ********************************************************
// The getHighestInRow function returns the highest *
// value in the specified row. *
// ********************************************************
int getHighestInRow(int array[][COLS], int rowToSearch, int cols)
{
	int highest = array[rowToSearch][0];

	// TODO
	for (int i = 0; i < cols; i++)
	{
		if (array[rowToSearch][i] > highest)
		{
			highest = array[rowToSearch][i];
		}
	}
	return highest;
}

// ********************************************************
// The getLowestInRow function returns the lowest *
// value in the specified row. *
// ********************************************************
int getLowestInRow(int array[][COLS], int rowToSearch, int cols)
{
	int lowest = array[rowToSearch][0];

	// TODO
	for (int i = 0; i < cols; i++)
	{
		if (array[rowToSearch][i] < lowest)
		{
			lowest = array[rowToSearch][i];
		}
	}

	return lowest;
}

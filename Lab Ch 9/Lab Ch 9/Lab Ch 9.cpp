

#include <iostream>
#include <iomanip>
using namespace std;

// Author: Chris Mangkuorahardjo

// Function prototypes
void sort(double*, int);
double averageDropLowest(double*, int);

int main()
{
	int numTestScores = 0; // To hold the number of test scores
	double *pointer = nullptr; // To point to the dynamically allocated array
	double testAverage = 0; // To hold the test score average
	double score = 0; // Temporary variable to hold user input for test scores
	// Get the number of test scores and validate the number of scores
	cout << "How many test scores will you enter? ";
	cin >> numTestScores;

	// Allocate an array to hold the test scores.
	pointer = new double[numTestScores];
	// Get the test scores (i.e user enters numTestScores into pointer)
	for (int i = 0; i < numTestScores; i++)
	{
		cout << "Enter test score " << i+1 << "." << endl;
		cin >> score;
		while ((score < 0) || (score > 100))
		{
			cout << "Please enter a valid score." << endl;
			cin >> score;
		}
		pointer[i] = score;
	}
	cout << "-------------------------------------" << endl;
	// Sort the test scores.
	sort(pointer, numTestScores);
	
	// Get the average of the test scores.
	testAverage = averageDropLowest(pointer, numTestScores);

	// Display the resulting data and average score
	cout << "Original Test Scores: ";
	for (int i = 0; i < numTestScores; i++)
	{
		cout << pointer[i];
		if (i+1 < numTestScores)
		{
			cout << ", ";
		}
	}
	cout << "." << endl;
	cout << "-------------------------------------" << endl;

	cout << "After dropping lowest score: ";
		for(int i = 1; i < numTestScores; i++)
		{
			cout << pointer[i];
			if (i+1 < numTestScores)
			{
				cout << ", ";
			}
		}
	cout << "." << endl;
	cout << "-------------------------------------" << endl;

	cout << "Average Score: " << testAverage << "." << endl;
	
	// Free the dynamically-allocated memory.
	delete [] pointer;
	pointer = nullptr;
	cout << "-------------------------------------" << endl;
	cout << "Press any key to exit." << endl;
	cin.ignore();
	cin.ignore();
	return 0;
}

// ********************************************************
// The sort function performs a selection sort on the *
// array pointed to by the score parameter into ascending *
// order. The size parameter holds the number of elements.*
// ********************************************************
void sort(double* score, int size)
{
	// Selection sort of score
	double least;
	double temp = 0;
	int x = 0;
	for (int i = 0; i < size; i++)
	{
		least = score[i];
		for (int j = i + 1; j < size; j++)
		{
			if (score[j] < least)
			{
				least = score[j];
				x = j;
			}
			temp = score[i];
			score[i] = least;
			score[x] = temp;
		}


		
	}

}

// ********************************************************
// The averageDropLowest function calculates and returns *
// the average of the values stored in the array passed *
// into the scores parameter, with the lowest score *
// dropped. Because the array must already be sorted in *
// ascending order, the first element is not included in *
// the calculations. The parameter numScores holds the *
// number of elements in the array. *
// ********************************************************
double averageDropLowest(double* score, int numScores)
{
	double average = 0;

	// calculate and return the average of the values
	for (int i = 1; i < numScores; i++)
	{
		average += score[i];
	}
	average /= numScores-1;
	return average; // Remember that you dropped one.
}
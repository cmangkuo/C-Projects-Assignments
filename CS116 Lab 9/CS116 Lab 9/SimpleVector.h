#pragma once
template <class T>  //T is my datatype
class SimpleVector
{
protected:
	int maxsize;  //number of elements allocated
	int numElements;  //current number of elements
					  //need a pointer to represent the array
	T* list;

public:
	SimpleVector();  //default constructor
	SimpleVector(int);
	~SimpleVector();  //destructor
	void insert(T);
	T& getItemAt(int);
	int size() { return numElements; }
	bool isFull();
	bool isEmpty();
	void print();
	bool isValidSubscript(int s)
	{
		return (s >= 0 && s < numElements);
	}

	void selectionSort();
	int search(T);
	class BadSubscript
	{
	private:
		int sub;
	public:
		BadSubscript() { sub = 0; }
		BadSubscript(int s) { sub = s; }
		int getSub() { return sub; }

	};
};

//all function definitions for a template MUST BE IN
//header file.  NO .cpp file!

template <class T>
void SimpleVector<T>::print()
{
	for (int i = 0; i < numElements; i++)
	{
		cout << list[i];
		if (i == numElements - 1)
		{
			cout << endl;
		}
		else
		{
			cout << ", ";
		}
	}
}

template <class T>
bool SimpleVector<T>::isFull()
{
	return (numElements == maxsize);
}

template <class T>
bool SimpleVector<T>::isEmpty()
{
	return (numElements == 0);
}

template <class T>
SimpleVector<T>::SimpleVector()
{
	//let's set a default size for this vector
	maxsize = 50;
	//allocate the array list
	list = new T[maxsize];
	numElements = 0;
}

template <class T>
SimpleVector<T>::SimpleVector(int nelems)
{
	//let's set a default size for this vector
	maxsize = nelems;
	//allocate the array list
	list = new T[maxsize];
	numElements = 0;
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
	//release memory 
	delete[]list;
}


template <class T>
void SimpleVector<T>::insert(T newItem)
{
	if (!isFull())
	{
		//add this object T to the list at next empty postion
		list[numElements] = newItem;
		//increment counter
		numElements++;
	}
}


template <class T>
T& SimpleVector<T>::getItemAt(int pos)
{
	//make sure pos is valid
	if (pos >= 0 && pos < numElements)
	{
		return list[pos];
	}
	else
		throw (BadSubscript(pos));
}

template <class T>
void SimpleVector<T>::selectionSort()
{

	bool minimumfound;
	int sortedElements = 0;
	int minimum, swapValue;
	int sub1, sub2;
	for (int i = sortedElements; i < numElements; i++)
	{
		// Set initial minimum value as first unsorted element
		minimum = swapValue = list[sortedElements];
		sub1 = sortedElements;
		minimumfound = false;
		// Find smallest, unsorted element left in list
		for (int i = sortedElements + 1; i < numElements; i++)
		{
			
			// Find minimum value in list
			if (list[i] < swapValue)
			{
				sub2 = i;
				swapValue = list[i];
				minimumfound = true;
			}
		}
		// Swap values
		if (minimumfound)
		{
			list[sub1] = swapValue;
			list[sub2] = minimum;
		}
		sortedElements++;
	}
}

template <class T>
int SimpleVector<T>::search(T value)
{
	bool valuefound = false;
	int location;
	
	for (int i = 0; i < numElements; i++)
	{
		if (list[i] == value)
		{
			valuefound = true;
			location = i;
		}
	}

	if (valuefound)
	{
		return location;
	}
	else
	{
		return -1;
	}

	
}
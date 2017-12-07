#pragma once
#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
protected:
	struct Node
	{
		T data;
		Node* next;
	};
	
	Node* current;
	Node* head;

public:
	LinkedList()
	{
		head = NULL;
	}
	~LinkedList()
	{
		Node* deleter = head;
		Node* temp;

		while (deleter != NULL)
		{
			temp = deleter;
			deleter = deleter->next;
			delete temp;
		}
	}
	void appendNode(T); // Append a node of value T
	void insertNode(T, int); // Insert node of T value at chosen position
	void deleteNode(int); // Delete node at chosen position
	T getNodeAt(int); // Get node at some position
	void displayList() const;
	

};

template <class T>
void LinkedList<T>::appendNode(T value)
{
	Node* temp;

	// Create new node if head is NULL
	if (head == NULL)
	{
		head = current = temp = new Node;
		current->data = value;
		

	}
	else
	{
		temp = new Node;
		temp->data = value;
		current->next = temp;
		current = current->next;
	}

	// Set end of list to null
	current->next = NULL;

}

template <class T>
void LinkedList<T>::insertNode(T value, int position)
{
	Node* targetPrevious; // Node before target
	Node* target = head; // Node we want to insert, set to head by default
	Node* targetNext; // Node after target
	Node* checker = head; // Pointer for checking size
	int size = 0;

	// Determine if node exists
	while (checker != NULL)
	{
		checker = checker->next;
		size++;
	}

	// Send error message if inappropriate position
	if ((position > size + 1) || (position < 1))
	{
		cout << "Invalid position." << endl;
	}
	// Find the insertion position of the new node otherwise
	else
	{
		// Create new node
		target = new Node;

		// Assign the value 
		target->data = value;

		// Special case: user wants to insert at first position
		if (position == 1)
		{
			// Point this node towards the 1st node
			target->next = head;

			// Reassign head node to point at the new 1st node
			head = target;
		}
		// User wants to insert elsewhere
		else
		{
			targetPrevious = head;
			// Iterate to the node previous
			for (int i = 0; i < position - 2; i++)
			{
				targetPrevious = targetPrevious->next;
			}
			// Set the next node
			targetNext = targetPrevious->next;

			// Insert new node
			targetPrevious->next = target;
			target->next = targetNext;
		}
	}
}

template <class T>
void LinkedList<T>::deleteNode(int position)
{
	Node* targetPrevious; // Node before target
	Node* target = head; // Node we want to delete, set to head by default
	Node* targetNext; // Node after target
	Node* checker = head; // Pointer for checking size
	int size = 0;


	// Determine if node exists
	while (checker != NULL)
	{
		checker = checker->next;
		size++;
	}

	// Send error message if inappropriate position
	if ((position > size) || (position < 1))
	{
		cout << "Node does not exist." << endl;
	}

	// Find the specified node otherwise
	else
	{
		// Special Case: Target node is first node
		if (position == 1)
		{
			// 
			// Move head pointer to 2nd node
			head = head->next;
			// Delete target node
			delete target;
		}
		// Target is not first node
		else
		{
			//Iterate to target's previous node
			for (int i = 0; i < position - 2; i++)
			{
				target = target->next; // Now points to target's previous node
			}

			targetPrevious = target; // Points to node previous to target
			target = targetPrevious->next; // Now points to node we want to delete
			
			// Check if targeted node is the last node in the list
			if (target->next == NULL)
			{
				// Set end of list to NULL
				targetPrevious->next = NULL;
			}
			else
			{	
				// Points to node after the target
				targetNext = target->next; 

				// Link previous node to next node
				targetPrevious->next = targetNext;
			}

			// delete target node
			delete target;
			

			
		}
	}
}

template <class T>
T LinkedList<T>::getNodeAt(int)
{
	Node* walker = head;
	Node* target = head;
	
	return Node();
}

template <class T>
void LinkedList<T>::displayList() const
{
	Node* walker;
	walker = head;
	int counter = 1;
	while (walker != NULL)
	{	
		if (walker != NULL)
		{
			cout << walker->data;
		}
		walker = walker->next;
	}
	cout << endl;

}




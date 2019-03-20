// Chapter 9, Programming Challenge 1: Array Allocator
#include <iostream>
using namespace std;

// Function Prototype
int* arrayAllocator(int);

int main()
{
	int numElements;			// To hold the number of elements to allocate
	int *pointer = nullptr;     // A pointer to the array
	int i;            			// A loop counter

	// Get the array size.
	cout << "\nEnter an array size: ";
	cin >> numElements;
   
	// Allocate the array.
	pointer = arrayAllocator(numElements);

	// Fill the array with values.
	for (i = 0; i < numElements; i++)
		pointer[i] = i;

	// Display the values.
	cout << "Here are the values in the array:\n";
	for (i = 0; i < numElements; i++)
		cout << "Element " << i << " has the value " 
		     << pointer[i] << endl;

	// Deallocate the array.
	delete [] pointer;
	pointer = nullptr;

	return 0;
}

// ********************************************************
// The arrayAllocator function dynamically allocates an   *
// array of ints. The number of elements is passed as an  *
// argument into the parameter num. The function returns  *
// a pointer to the array.                                *
// ********************************************************
int* arrayAllocator(int num)
{
	int *arrPtr = nullptr;
   
	// Allocate space for the array.
	arrPtr = new int[num];
   
	// Return the address of the allocated memory.
	return arrPtr;
}
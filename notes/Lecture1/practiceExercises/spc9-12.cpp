// Chapter 9, Programming Challenge 12: Element Shifter
#include <iostream>
using namespace std;

// Prototype
int *shift(int[], int);
void showArray(int[], int);

int main()
{
	const int SIZE = 5;
	int values[SIZE] = { 1, 2, 3, 4, 5 };

	// Display the contents of the array.
	cout << "The contents of the original array are:\n";
	showArray(values, SIZE);

	// Call the shift function to make a copy of
	// the array, with the elements shifted one
	// position toward the end if the array.
	int *arrCopy = shift(values, SIZE);

	// Display the contents of the new array.
	cout << "The contents of the new array are:\n";
	showArray(arrCopy, SIZE+1);

	return 0;
}

// ********************************************************
// The shift function accepts an int array and an int     *
// indicating the array's size. The function returns a    *
// pointer to an array that is one element larger than    *
// the array that was passed as an argument. The elements *
// of the argument array are copied to the new array,     *
// shifted one position toward the end of the array.      *
// ********************************************************
int *shift(int arr[], int size)
{
	int *copy = nullptr;

    // Make sure the new array size is greater than zero.
	if (size > 0)
	{
		// Allocate an array one element larger
		// than the array that was passed as
		// an argument.
		copy = new int[size + 1];

		// Set the first element of the new
		// array to 0.
		copy[0] = 0;

		// Copy arr's elements to the new array,
		// shifted one position toward the end
		// of the array.
		for (int index = 0; index < size; index++)
		{
			copy[index + 1] = arr[index];
		}
	}
   
    // Return a pointer to the new array.
    return copy;
}

// ********************************************************
// The showArray function displays the contents of an int *
// array.                                                 *
// ********************************************************
void showArray(int arr[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << arr[index] << " ";
	}
		
	cout << endl << endl;
}
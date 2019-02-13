#include <iostream>

int main()
{
    const int SIZE = 8;
    int set[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};
    int *numPtr = nullptr;

    // Make numPtr point to the set array
    numPtr = set;

    // Use the pointer to display the array contents
    std::cout << "The numbers in the set are:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << *numPtr << " ";
        numPtr++;
    }

    // Display the array contents in reverse order
    std::cout << "\nThe numbers in the set backward are:\n";
    for (int i = 0; i < SIZE; i++) {
        numPtr--;
        std::cout << *numPtr << " ";
    }

    return 0;
}
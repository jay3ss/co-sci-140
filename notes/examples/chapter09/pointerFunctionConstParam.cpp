#include <iostream>

void displayValues(const int *, int);

int main()
{
    const int SIZE = 6;

    const int array1[SIZE] = { 1, 2, 3, 4, 5, 6 };
    int array2[SIZE] = { 2, 4, 6, 8, 10, 12 };

    // Display the contents of each array
    displayValues(array1, SIZE);
    displayValues(array2, SIZE);

    return 0;
}

void displayValues(const int *numbers, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << *(numbers + i) << " ";
    }
    std::cout << std::endl;
}
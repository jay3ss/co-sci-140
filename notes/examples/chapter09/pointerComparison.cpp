#include <iostream>

int main()
{
    int set[8] = {5, 10, 15, 20, 25, 30, 35, 40};
    int *nums = set;    // Make nums point to set

    // Display the numbers in the array
    std::cout << "The numbers in set are:\n";
    std::cout << *nums << " ";  // Display the first element

    while (nums < &set[7]) {
        // Advance nums to point to the next element
        nums++;
        // Display the value point to by nums
        std::cout << *nums << " ";
    }

    //  Display the numbers in reverse order
    std::cout << "\nThe numbers in set backward are:\n";
    std::cout << *nums << " ";  // Display the last element first

    while (nums > set) {
        // Move backward to the previous element
        nums--;
        // Display the value poin to by nums
        std::cout << *nums << " ";
    }

    return 0;
}
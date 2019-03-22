#include <iostream>

int main()
{
    const int NUM_COINS = 5;
    double coins[NUM_COINS] = {0.05, 0.1, 0.25, 0.5, 1.0};
    double *doublePtr = nullptr;

    // Use the pointer to display the values in the array
    std::cout << "Here are the values in the coins array:\n";
    for (int i = 0; i < NUM_COINS; i++) {
        // Get the address of an array element
        doublePtr = &coins[i];

        // Display the contents of the element
        std::cout << *doublePtr << " ";
    }

    std::cout << std::endl;
    return 0;
}
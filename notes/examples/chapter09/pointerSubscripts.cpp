#include <iostream>

int main()
{
    const int NUM_COINS = 5;
    double coins[NUM_COINS] = {0.5, 0.1, 0.25, 0.5, 1.0};
    double *doublePtr;      // Pointer to a double
    
    // Assign the address of the coins array to doublePtr
    doublePtr = coins;

    // Display the contents of the coins array. Use subscripts
    // with the pointer!
    std::cout << "Here are the values in the coins array:\n";
    for (int i = 0; i < NUM_COINS; i++) {
        std::cout << doublePtr[i] << " ";
    }

    // Display the contents of the array again, but this time
    // use pointer notation with the array name!
    std::cout << "\nAnd here they are again:\n";
    for (int i = 0; i < NUM_COINS; i++) {
        std::cout << *(coins + i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
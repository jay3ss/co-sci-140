#include <iostream>

int main()
{
    const int SIZE = 5;
    int numbers[SIZE];
    
    // Get values to store in the array
    // Use pinter notation instead of subscripts
    std::cout << "Enter " << SIZE << " numbers: ";
    
    for (int count = 0; count < SIZE; count++) {
        std::cin >> *(numbers + count);
    }
    
    // Display the values in the array
    // Use pointer notation instead of subscripts
    std::cout << "Here are the numbers you entered:\n";
    for (int count = 0; count < SIZE; count++) {
        std::cout << *(numbers + count) << " ";
    }
    std::cout << std::endl;
    return 0;
}
#include <iostream>

int main()
{
    int x = 25, y = 50, z = 75; // Three int variables
    int *ptr = nullptr;         // Initialize the pointer to NULL
    
    std::cout << "Here are the values of x, y, and z:\n"
              << x << " " << y << " " << z << std::endl;
    
    // Use the pointer to manipulate x, y, and z
    ptr = &x;       // Store the address of x in ptr
    *ptr += 100;    // Add 100 to the current value of x
    
    ptr = &y;       // Store the address of y in ptr
    *ptr += 100;    // Add 100 to the current value of y
    
    ptr = &z;       // Store the address of z in ptr
    *ptr += 100;    // Add 100 to the current value of z
    
    // Display the contents of x, y, and z
    std::cout << "Once again, here are the values of x, y, and z:\n"
              << x << " " << y << " " << z << std::endl;
    
    return 0;
}
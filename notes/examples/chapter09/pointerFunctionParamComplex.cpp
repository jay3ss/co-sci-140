#include <iostream>

// Function prototypes
void getNumber(int*);
void doubleValue(int *);

int main()
{
    int number;

    // Call getNumber and pass the address of number
    getNumber(&number);

    // Call doubleValue and pass the address of number
    doubleValue(&number);

    // Display the value in number
    std::cout << "That value doubled is " << number << std::endl;
    return 0;
}

//******************************************************
// Definition of getNumber. The parameter, input is a
// pointer. This function asks the user for a number.
// The value entered is stored in the variable pointed
// to by input.
//******************************************************

void getNumber(int* input) {
    std::cout << "Enter an integer number: ";
    // Use the indirection (*) operator! If you don't then
    // you'll be changing the address of input and there
    // will be undefined behavior
    std::cin >> *input;
}

//******************************************************
// Definition of doubleValue. The parameter, val, is a
// pointer. This function multiplies the variable
// pointed to by valy by two.
//******************************************************

void doubleValue(int *val)
{
    *val *= 2;
}

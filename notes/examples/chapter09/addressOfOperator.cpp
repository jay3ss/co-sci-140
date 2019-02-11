#include <iostream>

int main()
{
    int myInteger = 12345;
    std::cout << "myInteger is " << myInteger
              << " and is at memory location x" << &myInteger;
    
    return 0;
}
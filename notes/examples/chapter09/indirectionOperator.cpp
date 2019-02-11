#include <iostream>

int main()
{
    int x = 25;
    int *ptr = nullptr;
    
    ptr = &x;
    
    std::cout << "Here is the value in x, printed twice:\n"
              << x << std::endl
              << *ptr << std::endl;
    
    *ptr = 100;
    
    std::cout << "Once again, here is the value in x:\n"
              << x << std::endl
              << *ptr << std::endl;
              
    return 0;
}
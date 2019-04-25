// This program demonstrates a static member variable and function
#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    // Define three Tree objects
    Tree oak;
    Tree elm;
    Tree pine;

    // Display the number of Tree objects we have.
    cout << "We have " << Tree::getObjectCount()
         << " trees in our program!\n";
    // system("pause"); // Only for Visual Studio
    
    return 0;
}
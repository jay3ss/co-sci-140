// Define the function
void doubleValue(int *val)
{
    // Dereference the variable to access the data
    *val *= 2;
}

// Call the function with the address of the variable
doubleValue(&number);
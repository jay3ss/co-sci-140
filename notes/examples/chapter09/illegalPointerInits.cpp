// Pointers must point to a variable of the same data type
float myFloat;
int *pint = &myFloat;

// Pointers must be initialzed to the address of an object
// that has already been defined
int *pint = &myValue;
int myValue;
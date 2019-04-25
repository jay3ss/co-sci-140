#include <iostream>
#include <iomanip>

// Function prototypes
void getSales(double *, int);
double totalSales(double *, int);

int main()
{
    const int QTRS = 4;
    double sales[QTRS];

    // Get the sales data for all quarters
    getSales(sales, QTRS);

    // Set the numeric output formatting
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    // Display the total sales for the year
    std::cout << "The total sales for the year are $" 
              << totalSales(sales, QTRS) << std::endl;
    
    return 0;
}

//*******************************************************
// Definition of getSales. This function uses a pointer
// to accept the address of an array of doubles. The
// function asks the user to enter sales figures and
// stores them in the array.
//*******************************************************
void getSales(double *arr, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the sales figure for quarter "
                  << (i + 1) << ": ";
        std::cin >> arr[i];
    }
}

//*******************************************************
// Definition of totalSales. This function uses a
// pointer to accept the address of an array. The
// function returns the total of the elements in the
// array.
//*******************************************************
double totalSales(double *arr, int size)
{
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += *arr;
        arr++;
    }

    return sum;
}
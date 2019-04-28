#include <iostream>
#include <iomanip>

int main()
{
    double *sales = nullptr,
            total = 0.0,
            average;
    int numDays,
        count;

    // Get the number of days of sales
    std::cout << "How many days of sales figures do you wish "
              << "to process? ";
    std::cin >> numDays;

    // Dynamically allocate an array large enough to hold
    // that many days of sale amounts
    sales = new double[numDays];

    // Get the sales figures for each day
    for (int i = 0; i < numDays; i++)
    {
        std::cout << "Day " << (i + 1) << ": ";
        std::cin >> *(sales + i);
    }

    // Calculate the total sales
    for (int i = 0; i < numDays; i++)
    {
        total += *(sales + i);
    }

    average = total / numDays;

    // Display the results
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "\n\nTotal sales: $" << total << std::endl
              << "Average sales: $" << average << std::endl;

    // Free dynamically allocated memory
    delete [] sales;
    sales = nullptr;

    return 0;
}
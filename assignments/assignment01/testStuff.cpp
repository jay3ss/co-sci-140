#include <iostream>

void sortAscending(double *, int);

int main()
{
    double *scores;
    int numScores;

    std::cout << "Enter the number of scores: ";
    std::cin >> numScores;
    std::cin.ignore();

    scores = new double[numScores];
    int count = 0;

    while (count < numScores)
    {
        *(scores + count) = numScores - count;
        count++;
    }

    std::cout << "The contents of the unsorted scores array are ";
    count = 0;

    while (count < numScores)
    {
        std::cout << *(scores + count) << " ";
        count++;
    }

    std::cout << "\nThe contents of the sorted (ascending) scores array are ";
    count = 0;

    sortAscending(scores, numScores);

    while (count < numScores)
    {
        std::cout << *(scores + count) << " ";
        count++;
    }

    return 0;
}

void sortAscending(double *arr, int size)
{
    // Implements the selection sort algorithm to sort
    // arr in ascending order (chapter 8, section 3)
    int startScan, minIndex, minValue;

    for (int startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = *(arr + startScan);
        for (int index = startScan + 1; index < size; index++)
        {
            if (*(arr + index) < minValue)
            {
                minValue = *(arr + index);
                minIndex = index;
            }
        }
        *(arr + minIndex) = *(arr + startScan);
        *(arr + startScan) = minValue;
    }
}
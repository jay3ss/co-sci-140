// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 01
// Due February 17, 2019
// Prompt:
// Write a program that dynamically allocates an array large enough to hold a
// user-defined number of test scores. Once all the scores are entered, the
// array should be passed to a function that sorts them in ascending order.
// Another function should be called that calculates the average score.The
// program should display the sorted list of scores and averages with appropriate
// headings. Use pointer notation rather than array notation whenever possible.
// 
// Input Validation: Do not accept negative numbers for test scores.

#include <iostream>

// Function prototypes
double averageScore(const double *, int);
void displayResults(const double *, int, double);
void sortAscending(double *, int);
bool validateScore(double);

int main()
{
    double *scores = nullptr;
    int numScores = -1;

    std::cout << "How many test scores will you enter? ";
    while (numScores < 0)
    {
        std::cin >> numScores;

        if (numScores < 0)
        {
            std::cout << "The number cannot be negative.\nEnter another number: ";
        }
    }
    
    int scoresCount = 0;
    scores = new double[numScores];


    while (scoresCount < numScores)
    {

        scoresCount++;
    }

    return 0;
}

double averageScore(const double *arr, int size)
{}

void displayResults(const double *arr, int size, double average)
{}

void sortAscending(double *arr, int size)
{
    // Implements the selection sort algorithm to sort
    // arr in ascending order (chapter 8)
    int startScan, minIndex, minValue;

    for (int startScan = 0; startScan < (size - 1); startScan)
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

bool validateScore(double score)
{
    // Returns true if score is greater than or equal to zero.
    // Returns false otherwise
    return score >= 0;
}
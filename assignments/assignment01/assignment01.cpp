// Joshua Saunders
// CO SCI 140 (Section 15029) - Assignment 01
// Due February 17, 2019
// Prompt:
// Write a program that dynamically allocates an array large enough to hold a
// user - defined number of test scores. Once all the scores are entered, the
// array should be passed to a function that sorts them in ascending order.
// Another function should be called that calculates the average score.The
// program should display the sorted list of scores and averages with appropriate
// headings. Use pointer notation rather than array notation whenever possible.
// 
// Input Validation: Do not accept negative numbers for test scores.

#include <iostream>

// Function prototypes
void sortScores(double *, int);
double averageScore(const double *, int);
void displayResults(const double *, int, double);
bool validateScore(double);

int main()
{
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
    // double scores[numScores];

    while (scoresCount < numScores)
    {

        scoresCount++;
    }

    return 0;
}
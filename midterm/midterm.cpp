// Joshua Saunders
// CO SCI 140 (Section 15029) - Midterm
// Due April 14
//
// Write a program that uses a structure to store the following data:
//
// Member Name         | Description
//------------------------------------
// Name                | Idnum
// Tests               | Average
// Grade               | Student name
// Student ID number   | Pointer to an array of test scores
// Average test score  | Course grade
//
// The program should keep a list of test scores for a group of students. It
// should ask the user how many test scores there are to be and how many
// students there are. It should then dynamically allocate an array of
// structures. Each structure’s Tests member should point to a dynamically
// allocated array that will hold the test scores.

// After the arrays have been dynamically allocated, the program should ask for
// the ID number and all the test scores for each student. The average test
// score should be calculated and stored in the average member of each
// structure. The course grade should be computed on the basis of the following
// grading scale:
//
// Average Test Grage | Course Grade
//------------------------------------
// 91-100             | A
// 81-90              | B
// 71-80              | C
// 61-70              | D
// 60 or below        | F
//
// The course grade should then be stored in the Grade member of each
// structure. Once all this data is calculated, a table should be displayed
// on the screen listing each student’s name, ID number, average test score,
// and course grade.

// Input Validation: Be sure all the data for each student is entered. Do not
// accept negative numbers for any test score.
#include <iostream>
#include <string>

using namespace std;

// Structure for holding information about a student
struct Student
{
    string name;            // Student name
    unsigned int idNum;     // Student ID number
    double* tests;          // Pointer to an array of test scores
    double average;         // Average test score
    char grade;             // Course grade
};

// Enum for the lowest criteria for grades
enum class Grade { A = 91, B = 81, C =  71, D = 61};

int main()
{
    int numStudents, numTestScores;

    cout << "How many students do you have? ";
    cin >> numStudents;

    cout << "\nHow many test scores do you have per student? ";
    cin >> numTestScores;

    // Create the Student array
    Student* students = nullptr;
    students = new Student[numStudents];

    // Populate the data for the students array
    for (int i = 0; i < numStudents; i++)
    {
        cout << "\nEnter student " << (i + 1) << "'s name: ";
        cin >> students[i].name;

        cout << "\nEnter student " << (i + 1) << "'s ID number: ";
        cin >> students[i].idNum;

        // Dynamically allocate the test scores array for the ith student
        students[i].tests = new double[numTestScores];

        // Enter the test scores for the ith student
        double tempAverage = 0;
        for (int j = 0; j < numTestScores; j++)
        {
            double tempScore;
            cout << "\nEnter test score number " << (j + 1);
            cin >> tempScore;
            students[i].tests[j] = tempScore;
            tempAverage += tempScore;
        }

        // Calculate the grade of the student
        if (students[i].average >= 91)
        {
            students[i].grade = 'A';
        }
        else if (students[i].average >= 81)
        {
            students[i].grade = 'B';
        }
        else if (students[i].average >= 71)
        {
            students[i].grade = 'C';
        }
        else if (students[i].average >= 61)
        {
            students[i].grade = 'D';
        }
        else
        {
            students[i].grade = 'F';
        }
    }

    return 0;
}
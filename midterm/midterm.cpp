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
#include <iomanip>
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

// Function prototypes
void getStudentData(Student&, int);
char letterGrade(double);
void setGrades(Student&, int);
void displayStudents(Student[], int);
void deallocateTests(Student[], int);

// Enum for the lowest criteria for grades
enum class Grade { A = 91, B = 81, C =  71, D = 61};

int main()
{
    int numStudents, numTestScores;

    cout << "How many students? ";
    cin >> numStudents;

    cout << "How many tests per student? ";
    cin >> numTestScores;

    // Create the Student array
    Student* students = nullptr;
    students = new Student[numStudents];

    // Populate the data for the students array
    for (int i = 0; i < numStudents; i++)
    {
        getStudentData(students[i], numTestScores);
    }

    // Display the data in the students array
    displayStudents(students, numStudents);

    // Deallocate dynamically created memory
    deallocateTests(students, numStudents);

    delete [] students;
    students = nullptr;

    system("pause");
    return 0;
}

void getStudentData(Student &student, int numTests)
{
    cout << "\nStudent name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "ID number: ";
    cin >> student.idNum;

    // Dynamically allocate the test scores array for the ith student
    student.tests = new double[numTests];

    // Enter the test scores for the ith student
    setGrades(student, numTests);

    // Calculate the grade of the student
    student.grade = letterGrade(student.average);
}

void setGrades(Student& student, int numTests)
{
    student.average = 0;
    for (int i = 0; i < numTests; i++)
    {
        cout << "\tTest # " << (i + 1) << ": ";
        cin >> student.tests[i];
        student.average += student.tests[i];
    }
    student.average /= numTests;
}

char letterGrade(double numGrade)
{
    char letGrade;
    if (numGrade >= 91)
    {
        letGrade = 'A';
    }
    else if (numGrade >= 81)
    {
        letGrade = 'B';
    }
    else if (numGrade >= 71)
    {
        letGrade = 'C';
    }
    else if (numGrade >= 61)
    {
        letGrade = 'D';
    }
    else
    {
        letGrade = 'F';
    }

    return letGrade;
}

void displayStudents(Student students[], int numStudents)
{
    cout << setprecision(3);
    for (int i = 0; i < numStudents; i++)
    {
        cout << "\n\nStudent name: " << students[i].name;
        cout << "\nID number: " << students[i].idNum;
        cout << "\nAverage test score: " << students[i].average;
        cout << "\nGrade: " << students[i].grade;
    }
}

void deallocateTests(Student students[], int numStudents)
{
    for (int i = 0; i < numStudents; i++)
    {
        delete [] students[i].tests;
        students[i].tests = nullptr;
    }
}
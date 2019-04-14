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
// Average Test Grade | Course Grade
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
// Prompts the user to enter validated data for a Student struct
void getStudentData(Student&, int);
// Prompts the user to enter test grades for the tests array and validates it.
// Then, the average of the tests is calculated and saved in the average
// attribute.
void setGrades(Student&, int);
// Converts a numerical grade to a letter grade using the following conversion
char letterGrade(double);
// Displays the data in a Student array. The data is displayed in the following
// format
void displayStudents(Student[], int);
// Deallocates the tests pointer for each Student struct in the students
void deallocateTests(Student[], int);
// Determines if a string is empty. If the string is empty, it returns
// true and false otherwise
bool isEmpty(string);
// Determines if a number is non-negative. If the number isn't non-negative
// it returns true and false otherwise
bool isValid(int);
// Determines if a number is non-negative. If the number isn't non-negative
// it returns true and false otherwise
bool isValid(double);
// Gets a string from the user then validates the string.
string getValidString(string);
// Gets a int from the user then validates the int
int getValidInt(string);
// Gets an unsigned int from the user then validates the int
unsigned int getValidUnsignedInt(string);
// Gets a double from the user then validates the int
double getValidDouble(string);

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

// getStudentData
// Prompts the user to enter validated data for a Student struct
//
// @param student: reference to a Student struct
// @return Nothing
void getStudentData(Student &student, int numTests)
{
    cin.ignore();
    cout << "\nStudent name: ";
    student.name = getValidString("Please enter a name: ");

    cout << "ID number: ";
    student.idNum = getValidUnsignedInt("Enter 0 or greater: ");

    // Dynamically allocate the test scores array for the ith student
    student.tests = new double[numTests];

    // Enter the test scores for the ith student
    setGrades(student, numTests);

    // Calculate the grade of the student
    student.grade = letterGrade(student.average);
}

// setGrades
// Prompts the user to enter test grades for the tests array and validates it.
// Then, the average of the tests is calculated and saved in the average
// attribute.
//
// @param student: reference to a Student struct
// @return Nothing
void setGrades(Student& student, int numTests)
{
    student.average = 0;
    // Go through each element in the tests array and prompt the user to enter
    // a test score. Validate the test score and save it. Add each test score
    // to the average and then divide it by the number of tests (numTests)
    for (int i = 0; i < numTests; i++)
    {
        cout << "\tTest # " << (i + 1) << ": ";
        student.tests[i] = getValidDouble("Enter 0 or greater: ");
        student.average += student.tests[i];
    }
    student.average /= numTests;
}

// letterGrade
// Converts a numerical grade to a letter grade using the following conversion
//
// Test Grade | Course Grade
//------------------------------------
// 91-100             | A
// 81-90              | B
// 71-80              | C
// 61-70              | D
// 60 or below        | F
//
// @param numGrade: a non-negative number that corresponds to a test score
// @return ltrGrade: A letter grade that is in the set
//                   {'A', 'B', 'C', 'D', 'F'}
char letterGrade(double numGrade)
{
    char ltrGrade;
    if (numGrade >= 91)
    {
        ltrGrade = 'A';
    }
    else if (numGrade >= 81)
    {
        ltrGrade = 'B';
    }
    else if (numGrade >= 71)
    {
        ltrGrade = 'C';
    }
    else if (numGrade >= 61)
    {
        ltrGrade = 'D';
    }
    else
    {
        ltrGrade = 'F';
    }

    return ltrGrade;
}

// displayStudents
// Displays the data in a Student array. The data is displayed in the following
// format
//
// Student name:  Bob
// ID number: 123
// Average test score: 88.00
// Grade: B
//
// Student name:  Tina
// ID number: 234
// Average test score: 88.00
// Grade: B
void displayStudents(Student students[], int numStudents)
{
    cout << setprecision(2) << fixed;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "\n\nStudent name: " << students[i].name;
        cout << "\nID number: " << students[i].idNum;
        cout << "\nAverage test score: " << students[i].average;
        cout << "\nGrade: " << students[i].grade;
    }
}

// deallocateTests
// Deallocates the tests pointer for each Student struct in the students
//
// @param students: an array of Student structs
// @param numStudents: the number of elements in the students parameter
// @return Nothing
//
// Side effects: the tests pointer in every element of the students array
//               will be deallocated and point to NULL
void deallocateTests(Student students[], int numStudents)
{
    for (int i = 0; i < numStudents; i++)
    {
        delete [] students[i].tests;
        students[i].tests = nullptr;
    }
}

// isEmpty
// Determines if a string is empty. If the string is empty, it returns
// true and false otherwise
//
// @param str: string to be examined
// @return True if str is empty, false otherwise
bool isEmpty(string str)
{
    return str == "";
}

// isValid
// Determines if a number is non-negative. If the number isn't non-negative
// it returns true and false otherwise
//
// @param num: number to be examined
// @return True if num isn't non-negative, false otherwise
bool isValid(int num)
{
    return num >= 0;
}

// isValid
// Determines if a number is non-negative. If the number isn't non-negative
// it returns true and false otherwise
//
// @param num: number to be examined
// @return True if num isn't non-negative, false otherwise
bool isValid(double num)
{
    return num >= 0;
}

// getValidString
// Gets a string from the user then validates the string.
//
// @param errMsg: The error message to be printed to the screen when an invalid
//                (empty) string is entered by the user
// @return str: a validated (non-empty) string
string getValidString(string errMsg)
{
    string str;

    getline(cin, str);

    while (isEmpty(str))
    {
        cout << errMsg;
        getline(cin, str);
    }

    return str;
}

// getValidInt
// Gets a int from the user then validates the int.
//
// @param errMsg: The error message to be printed to the screen when an invalid
//                int is entered by the user
// @return num: a validated (non-negative) int
int getValidInt(string errMsg)
{
    int num;
    cin >> num;

    while (!isValid(num))
    {
        cout << errMsg;
        cin >> num;
    }

    return num;
}

// getValidUnsignedInt
// Gets an unsigned int from the user then validates the int.
//
// @param errMsg: The error message to be printed to the screen when an invalid
//                int is entered by the user
// @return num: a validated (non-negative) unisigned int
unsigned int getValidUnsignedInt(string errMsg)
{
    int num = getValidInt(errMsg);
    return static_cast<unsigned int>(num);
}

// getValidDouble
// Gets a double from the user then validates the int.
//
// @param errMsg: The error message to be printed to the screen when an invalid
//                double is entered by the user
// @return num: a validated (non-negative) double
double getValidDouble(string errMsg)
{
    double num;
    cin >> num;

    while (!isValid(num))
    {
        cout << errMsg;
        cin >> num;
    }

    return num;
}
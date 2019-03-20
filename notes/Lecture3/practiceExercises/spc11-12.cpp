// Chapter 11, Programming Challenge 12: Course Grade
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Declaration of Student structure
struct Student
{
   string name;		// Student name
   int idNum;       // Student ID number
   int *tests;      // Pointer to array of test scores
   double average;  // Average test score
   char grade;      // Course grade
};

// Function prototypes
Student *initArrays(int, int);
void getInfo(Student [], int, int);
void showInfo(Student [], int, int);

int main()
{
   int numStudents;			// Number of students
   int numTests;			// Number of tests
   Student *list = nullptr; // Pointer to Student array

   // Get the number of students.
   cout << "How many students? ";
   cin >> numStudents;
   
   // Get the number of tests per student.
   cout << "How many tests per student? ";
   cin >> numTests;
   
   // Create an array of Students
   list = initArrays(numStudents, numTests);
   
   // Populate the array with data.
   getInfo(list, numStudents, numTests);
   
   // Display the data.
   showInfo(list, numStudents, numTests);

   return 0;
}

//**************************************************
// Function initArrays                             *
// This function dynamically allocates an array    *
// of Student structures and for each element in   *
// the array, allocates an array of ints to hold   *
// tests scors. The parameter s is the number of   *
// element to allocate for the array of structures *
// and the parameter t is the number of elements   *
// allocate for each array of ints.                *
//**************************************************
Student *initArrays(int s, int t)
{
   Student *ptr = nullptr;

   // Allocate the array of Student structures.
   ptr = new Student[s];

   // Allocate an array of ints (to hold test scores)
   // for each element of the array of Student structures.
   for (int count = 0; count < s; count++)
   {
      ptr[count].tests = new int[t];
   }

   // Return a pointer to the array of structures.
   return ptr;
}

//*****************************************************
// Function getInfo                                   *
// This function populates the Student array s with   *
// data entered by the user. The paramater ns is the  *
// number of students and nt is the number of tests.  *
//*****************************************************

void getInfo(Student s[], int ns, int nt)
{
   int total;

   // Get the data for each student.
   for (int index = 0; index < ns; index++)
   {
      // Get the name.
      cin.get();
      cout << "Student name: ";
      getline(cin, s[index].name);
      while (s[index].name.empty())
      {
         cout << "Please enter a name: ";
         getline(cin, s[index].name);
      }

      // Get the ID number.
      cout << "ID Number: ";
      cin >> s[index].idNum;
      while (s[index].idNum == 0)
      {
         cout << "Please enter an ID number other than 0: ";
         cin >> s[index].idNum;
      }

      // Get the test scores and accumulate a total.
      total = 0;
      for (int t = 0; t < nt; t++)
      {
         cout << "\tTest # " << (t+1) << ": ";
         do
         {
            cin >> s[index].tests[t];
            if (s[index].tests[t] < 0)
               cout << "Enter 0 or greater.\n";
         } while(s[index].tests[t] < 0);
         total += s[index].tests[t];
      }

      // Calculate the average score.
      s[index].average = static_cast<double>(total) / nt;

      // Assign a letter grade.
      if (s[index].average >= 91)
         s[index].grade = 'A';
      else if (s[index].average >= 81 && s[index].average <= 90)
         s[index].grade = 'B';
      else if (s[index].average >= 71 && s[index].average <= 80)
         s[index].grade = 'C';
      else if (s[index].average >= 61 && s[index].average <= 70)
         s[index].grade = 'D';
      else
         s[index].grade = 'F';
   }
}

//*****************************************************
// Function showInfo                                  *
// This function displays all of the data in the      *
// array s. The paramater ns is the number of         *
// students and nt is the number of tests.            *
//*****************************************************
void showInfo(Student s[], int ns, int nt)
{
   cout << fixed << showpoint << setprecision(1);
   for (int std = 0; std < ns; std++)
   {
      cout << "Student name: " << s[std].name << endl;
      cout << "ID number: " << s[std].idNum << endl;
      cout << "Average test score: " << s[std].average
           << endl;
      cout << "Grade: " << s[std].grade << endl << endl;
   }
}
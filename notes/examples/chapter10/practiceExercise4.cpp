// Write a function named replaceSubstring. The function should accept three
// C-string or string object arguments. Let's call them string1, string2, and
// string3. It should search search string1 for all occurrences of string2.
// When it finds an occurrence of string2, it should replace it with string3.
// For example, suppose the three arguments have the following values:
// 
// string1:     "the dog jumped over the fence"
// string2:     "the"
// string3:     "that"
// 
// With these three arguments, the function would return a string object with
// the value "that dog jumped over that fence." Demonstrate the function in a
// complete program.
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

// Searches the first string and replaces occurences of the second string with
// the third string.
void replaceSubstring(char *, char *, char *);

// Just playing around with substrings
void getSubstring(char [], char [], char []);
void printCstring(char []);

int main()
{
    const int SIZE = 128;
    char base[SIZE] = "Testing printing of a C-string\n\0";
    // char toReplace[SIZE];
    // char replaceWith[SIZE];

    // base = "Testing printing of a C-string";
    printCstring(base);

    system("pause");
    return 0;
}

// Searches string1 and replaces occurences of string2 with string3.
// For example, suppose the three arguments have the following values:
//
// string1:     "the dog jumped over the fence"
// string2:     "the"
// string3:     "that"
//
// With these three arguments, the function would return a string object with
// the value "that dog jumped over that fence."
// void replaceSubstring(char string1[], char string2[], char string3[])
// {
//     if (strcmp(string2, string3))
//     {
//         return;
//     }
//     bool substrFound = false;
//     char* strPtr = nullptr;
//     int size = strlen(string1);
//     int strLen = 1;

//     for (int i = 0; i < size; i++)
//     {
//         strLen = size - i + 1;
//         char* tempStr = new char[strLen];
//         strncpy(tempStr, string1+i, strLen);
//         tempStr[strLen] = '\0';
//         strPtr = strstr(string1, string2);
//         if (strPtr != nullptr) {

//         }
//         delete [] tempStr;
//         tempStr = nullptr;
//     }
    
// }

void getSubstring(char string1[], char string2[], char string3[])
{

}

void printCstring(char str[])
{
    int size = strlen(str);
    for (int i = 0; i < size; i++)
    {
        cout << str[i];
    }
}
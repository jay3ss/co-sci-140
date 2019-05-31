// Joshua Saunders
// CO SCI 140 (Section 15029) - Final Exam
// Due May 31, 2019
//
// Write a program with three functions: upper, lower, and reverse. The upper
// function should accept a pointer to a C-string as an argument. It should
// step through each character in the string, converting it to uppercase. The
// lower function, too, should accept a pointer to a C-string as an argument.
// It should step through each character in the string, converting it to
// lowercase. Like upper and lower, the reverse function should also accept a
// pointer to a C-string. As it steps through the string, it should test each
// character to determine whether it is uppercase or lowercase. If a character
// is uppercase, it should be converted to lowercase. Likewise, if a character
// is lowercase, it should be converted to uppercase.
//
// Test the functions by asking for a string in function main, then passing it
// to them in the following order: reverse, lower, and upper.
#include <cstring>
#include <iostream>
#include "CharInput.hpp"
#include "CaseModifier.h"

using namespace std;

int main()
{
	cout << "Enter a string: ";
	char *input = CharInput::getline();

	CaseModifier cm(input);

	cout << "After a call to Reverse: " << cm.reverse() << endl
		 << "After a call to Lower: "   << cm.lower()   << endl
		 << "After a call to Upper: "   << cm.upper()   << endl;

	system("pause");
    return 0;
}

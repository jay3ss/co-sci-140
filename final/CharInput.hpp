/** Class to get a C-string of unspecified size including spaces. Adapted from
	the code given in the Chapter 10 Weekly WrapUp:
	https://ilearn.laccd.edu/courses/70544/discussion_topics/690677 */
#ifndef _CHAR_INPUT_HPP_
#define _CHAR_INPUT_HPP_

#include <iostream>

class CharInput
{
public:
	/** Reads input from the user, including spaces, until the ENTER key ('\n')
		is pressed and returns the C-string
	@return A C-string (with null terminator) input by the user*/
    static char *getline()
    {
        char ch = std::cin.get();

        char *input = new char[2] {ch, '\0'};
		std::cin.get(ch);

        // Continue getting input until ENTER ('\n') is pressed
        while (ch != '\n')
        {
            append(ch, &input);
            std::cin.get(ch);
        }

        return input;
    }
private:
	/** Appends a character to the end of a C-string and appends the null
		terminator
	@post cstring will have the character found in ch appended to it along with
		the null terminator
	@param ch The character to be appended
	@param cstring The C-string that will have ch appended to it */
    static void append(char ch, char **cstring)
    {
        // Get the length of the string (including null terminator)
        unsigned int length = strlen(*cstring) + 1;

        // Make a copy of the current string
        char *buffer = new char[length];
        strcpy_s(buffer, length, *cstring);

        // Recreate the string from the buffer with a size increase of 1
        delete[] * cstring;
        *cstring = new char[length + 1];
		// To copy the null terminator, add 1 to the length and free up
		// the buffer
        strncpy_s(*cstring, length + 1, buffer, length + 1);
        delete[] buffer;
		buffer = nullptr;

        // Put the next character into the string and add the null terminator
        *(*cstring + length - 1) = ch;
        *(*cstring + length) = '\0';
    }
};

#endif // _CHAR_INPUT_HPP_

#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

/** Determines if a character is an uppercase alphabetic character
@param c The character to check
@return True if the character is an uppercase alphabetic character, false
	othwerwise */
bool isUpper(char c)
{
	if (isalpha(c))
	{
		return c == toupper(c);
	}

	// Not an alphabetic character
	return false;
}

/** Determines if a character is an lowercase alphabetic character
@param c The character to check
@return True if the character is an lowercase alphabetic character, false
	othwerwise */
bool isLower(char c)
{
	if (isalpha(c))
	{
		return c == tolower(c);
	}

	// Not an alphabetic character
	return false;
}

void lower(char* cstr)
{
    int length = strlen(cstr);
	for (int i = 0; i < length; i++)
	{
		if (isUpper(cstr[i]))
		{
			cstr[i] = static_cast<char>(tolower(cstr[i]));
		}
	}
}

void upper(char* cstr)
{
	int length = strlen(cstr);
	for (int i = 0; i < length; i++)
	{
		if (isLower(cstr[i]))
		{
			cstr[i] = static_cast<char>(toupper(cstr[i]));
		}
	}
}

void reverse(char* cstr)
{
	int length = strlen(cstr);
	for (int i = 0; i < length; i++)
	{
		if (isUpper(cstr[i]))
		{
			cstr[i] = static_cast<char>(tolower(cstr[i]));
		}
		else
		{
			cstr[i] = static_cast<char>(toupper(cstr[i]));
		}
	}
}

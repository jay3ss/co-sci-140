// Joshua Saunders
// CO SCI 140 (Section 15029) - Final Exam
// Due May 31, 2019
/** @file CaseModifier.cpp Implements a class that modifies the capitalization
	of a C-string */
#include "CaseModifier.h"

/** Constructor */
CaseModifier::CaseModifier(char* cstr)
{
	init(cstr);
}

/** Destructor */
CaseModifier::~CaseModifier()
{
	// Delete the dynamically allocated memory and return it to the system
	freeAllPointers();
}

/** Returns the base_ C-string as a constant */
const char* CaseModifier::base() const
{
	return base_;
}

/** Returns the reverse_ C-string as a constant */
const char* CaseModifier::reverse() const
{
	return reverse_;
}

/** Returns the lower_ C-string as a constant */
const char* CaseModifier::lower() const
{
	return lower_;
}

/** Returns the upper_ C-string as a constant */
const char* CaseModifier::upper() const
{
	return upper_;
}

/** Sets the base string and modified strings */
void CaseModifier::base(char* b)
{
	if (base_ != nullptr)
	{
		freeAllPointers();
	}
	init(b);
}

/** Initializes the C-string pointers */
void CaseModifier::init(char* cstr)
{
	if (cstr != nullptr)
	{
		length_ = strlen(cstr);

		// Copy the new base
		base_ = copyFrom(cstr);
		reverse_ = copyFrom(cstr);
		lower_ = copyFrom(cstr);
		upper_ = copyFrom(cstr);

		// Modify the case
		modifyCase();
	}
}

void CaseModifier::modifyCase()
{
	for (int i = 0; i < length_; i++)
	{
		// Check for both lowercase and uppercase because both check if the
		// character is alphabeti
		if (isUpper(base_[i]))
		{
			char low = static_cast<char>(tolower(base_[i]));
			reverse_[i] = low;
			lower_[i] = low;
		}
		else if (isLower(base_[i]))
		{
			char up = static_cast<char>(toupper(base_[i]));
			reverse_[i] = up;
			upper_[i] = up;
		}
	}
}

/** Determines if a character is an uppercase alphabetic character */
bool CaseModifier::isUpper(char c)
{
	if (isalpha(c))
	{
		return c == toupper(c);
	}

	// Not an alphabetic character
	return false;
}

/** Determines if a character is an lowercase alphabetic character */
bool CaseModifier::isLower(char c)
{
	if (isalpha(c))
	{
		return c == tolower(c);
	}

	// Not an alphabetic character
	return false;
}

/** Returns dynamically allocated memory back to the system */
void CaseModifier::freePointer(char* &pointer)
{
	delete[] pointer;
	pointer = nullptr;
}

/** Returns dynamically allocated memory back to the system */
void CaseModifier::freeAllPointers()
{
	freePointer(base_);
	freePointer(reverse_);
	freePointer(upper_);
	freePointer(lower_);
}

/** Returns a copy of the data pointed to by a character pointer */
char* CaseModifier::copyFrom(char* cstringPtr)
{
	int length = length_ + 1;
	char* toCstringPtr = new char[length];
	strncpy_s(toCstringPtr, length, cstringPtr, length);
	return toCstringPtr;
}

// Joshua Saunders
// CO SCI 140 (Section 15029) - Final Exam
// Due May 31, 2019
/** @file CaseModifier.h Defines a class that modifies the capitalization of
	a C-string */
#ifndef _CASE_MODIFIER_H_
#define _CASE_MODIFIER_H_

#include <cctype>
#include <cstring>

class CaseModifier
{
public:
	/** Constructor
	@param cstr The base string to modify */
	CaseModifier(char* cstr=nullptr);

	/** Destructor
	@post Returns all dynamically allowcated memory back to the system */
	~CaseModifier();

	// Getters
	/** Returns the base_ C-string as a constant */
	const char* base() const;

	/** Returns the reverse_ C-string as a constant */
	const char* reverse() const;

	/** Returns the lower_ C-string as a constant */
	const char* lower() const;

	/** Returns the upper_ C-string as a constant */
	const char* upper() const;

	// Setter
	/** Sets the base string and modified strings
	@post base_ will store the new base string (b)
		  reverse_ will store the new base string will all uppercase and
		  lowercase alphabetic characters inverted
		  upper_ will store the new base string will all alphabetic characters
		  uppercase
		  lower_ will store the new base string will all alphabetic characters
		  lowercase
	@param b The new base string */
	void base(char* b);
private:
	char* base_;	// The base string (i.e., what's being modified)
	char* reverse_;	// The base string with reversed capitalization
	char* lower_;	// The base string with all letters lowercase
	char* upper_;	// The base string with all letters uppercase
	int length_;	// Holds the length of the string excluding null terminator

	/** Initializes the C-string pointers
	@post The length_ member will hold the length of cstr, base_ will hold a copy
		of cstr, reverse_ will hold the inverted capitalization of cstr, lower_
		will hold the lowercase version of cstr, & upper will hold the uppercase
		version of cstr
	@param cstr Pointer to the string that will be the base string */
	void init(char* cstr);

	// Case modifier method
	/** Modifies the case of the base string and stores the	modifications
	@post
	    reverse_ will store the new base string with all uppercase and
			lowercase alphabetic characters inverted
		upper_ will store the new base string with all alphabetic characters
		    uppercase
		lower_ will store the new base string with all alphabetic characters
		    lowercase */
	void modifyCase();

	/** Determines if a character is an uppercase alphabetic character
	@param c The character to check
	@return True if the character is an uppercase alphabetic character, false
		othwerwise */
	bool isUpper(char c);

	// Check type of alphabetic characters
	/** Determines if a character is an lowercase alphabetic character
	@param c The character to check
	@return True if the character is an lowercase alphabetic character, false
		othwerwise */
	bool isLower(char c);

	// Functions for working with the pointers
	/** Returns dynamically allocated memory back to the system
	@pre The pointer should be a pointer to dynamically allocated memory
	@post The memory will be returned to the system and the pointer will be
		the nullptr
	@param pointer Reference to the pointer to the memory that is going to be
		returned to the system */
	void freePointer(char* &pointer);

	/** Returns dynamically allocated memory back to the system
	@pre The pointers (base_, reverse_, lower_, upper_) should be pointers to
		dynamically allocated memory
	@post The memory will be returned to the system and the pointer will be
		the nullptr
	@param pointer The pointer to the memory that will be returned to the
		system */
	void freeAllPointers();

	/** Returns a copy of the data pointed to by a character pointer
	@post A block of dynamically allocated memory will be created and returned.
		Make sure that this is deleted and not left dangling by using
		freePointer
	@param cstringPtr Pointer to the string that will be copied
	@return A pointer to a block of dynamically allocated memory */
	char* copyFrom(char* cstringPtr);
};

#endif // _CASE_MODIFIER_H_

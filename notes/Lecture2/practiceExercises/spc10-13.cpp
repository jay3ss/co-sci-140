// Chapter 10, Programming Challenge 13: Date Printer
#include <iostream>
#include <string>
using namespace std;

// Prototype
string format(string);

int main()
{
    // The following string will hold the user's input.
    string userDate;

    // The following string will hold the formatted date.
    string formattedDate;

    // Get a date from the user.
    cout << "Enter a date in the form mm/dd/yyyy: ";
    cin >> userDate;

    // Format the date.
    formattedDate = format(userDate);

    // Display the formatted date.
    cout << "You entered " << formattedDate << endl;

    return 0;
}

// The format function accepts a date in the form mm/dd/yyyy
// as a string, and returns the date in the form March 12, 2014.
string format(string date)
{
    int month;			// To hold the numeric month
    string temp;		// Temporary storage
    string result;		// To hold the formatted date

    // The following string array holds the names of
    // the months.
    string months[] = {"January", "February", "March",
                       "April",   "May",      "June",
                       "July",    "August",   "September",
                       "October", "November", "December"
                       };

    // Test the length of date. If it is in the correct
    // format, it should be 10 characters long.
    if (date.size() != 10)
    {
        cout << "Invalid date format!\n";
        return date;
    }
    
    // Get the month part, which starts at character 0
    // and is 2 characters long.
    temp = date.substr(0, 2);

    // Convert that to an int.
    month = atoi(temp.c_str());

    // Validate the month.
    if (month < 1 || month > 12)
    {
        cout << "Invalid month!\n";
        return date;
    }

    // Construct a formatted date. First, get the name
    // of the month.
    result = months[month-1] + " ";

    // Next, append the day, which starts at character 3
    // of the argument string and is 2 characters long.
    // (If the first character of the day is '0' then we
    // will leave it out.)
    if (date[3] == '0')
        result += date.substr(4, 1);
    else
        result += date.substr(3, 2);

    // Next, append a comma followed by a space.
    result += ", ";

    // Next append the year,which starts at character 6
    // of the argument date and is 4 characters long.
    result += date.substr(6, 4);

    // Return the formatted result.
    return result;
}
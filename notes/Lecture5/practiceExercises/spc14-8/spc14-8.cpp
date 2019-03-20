//  Chapter 14, Programming Challenge 8: Date Class Modification
#include <iostream>
#include <string>
using namespace std;

class Date;    // Forward declaration
ostream &operator <<(ostream &, Date &);
istream &operator >>(istream &, Date &);

// Constants
const int NUM_MONTHS = 12;

// Declaration of the Date class
class Date
{
private:
   int month;  // To hold the month
   int day;    // To hold the day
   int year;   // To hold the year
   
   // An array of strings to hold
   // the names of the months
   string names[NUM_MONTHS];
   
   // An array to hold the number of days
   // that each month has.
   int numDays[NUM_MONTHS];
   
   // Private member function to assign
   // the month names to the names array
   void setNames();
   
   // Private member function to assign
   // the numbers of days to the numDaus array
   void setDays();
   
public:
   // Constructors
   Date();
   Date(int, int, int);
   
   // Mutators
   void setMonth(int m);
   void setDay(int d);
   void setYear(int y);
   
   // Other member functions
   void showDate1();
   void showDate2();
   void showDate3();
   bool isLeapYear(int);
   
   // Overloaded operators
   Date operator ++();				// Prefix ++
   Date operator ++(int);			// Postfix ++
   Date operator --();				// Prefix --
   Date operator --(int);			// Postfix --
   bool operator >(const Date &);   // Greater-than operator
   int operator -(const Date &);	// Subtraction operator
   bool operator <(const Date &);   // Greater-than operator
   friend ostream &operator <<(ostream &, Date &); // Overloaded << operator
   friend istream &operator >>(istream &, Date &); // Overloaded >> operator
};

//**********************************
// Default constructor             *
//**********************************

Date::Date()
{
   setNames();
   setDays();
}

//**********************************
// Overloaded constructor          *
//**********************************

Date::Date(int m, int d, int y)
{
   setMonth(m);
   setDay(d);
   setYear(y);
   setNames();
   setDays();
}

//**********************************
// Member function setNames        *
//**********************************

void Date::setNames()
{
   names[0] = "January";
   names[1] = "Febraury";
   names[2] = "March";
   names[3] = "April";
   names[4] = "May";
   names[5] = "June";
   names[6] = "July";
   names[7] = "August";
   names[8] = "September";
   names[9] = "October";
   names[10] = "November";
   names[11] = "December";
}

//**********************************
// Member function setDays         *
//**********************************

void Date::setDays()
{
   numDays[0] = 31;
   numDays[1] = 28;
   numDays[2] = 31;
   numDays[3] = 30;
   numDays[4] = 31;
   numDays[5] = 30;
   numDays[6] = 31;
   numDays[7] = 31;
   numDays[8] = 30;
   numDays[9] = 31;
   numDays[10] = 30;
   numDays[11] = 31;
}

//**********************************
// Member function setMonth        *
//**********************************

void Date::setMonth(int m)
{
   if (m >= 1 && m <= 12)
      month = m;
   else
   {
      cout << m << " is not a valid value for the month.\n";
      exit(EXIT_FAILURE);
   }
}

//**********************************
// Member function setDay          *
//**********************************

void Date::setDay(int d)
{
   if (d >= 1 && d <= 31)
      day = d;
   else
   {
      cout << d << " is not a valid value for the day.\n";
      exit(EXIT_FAILURE);
   }
}

//**********************************
// Member function setYear         *
//**********************************

void Date::setYear(int y)
{
   if (y < 1900)
   {
      cout << "Enter a 4 digit year of 1900 or greater.\n";
      exit(EXIT_FAILURE);
   }
   else
      year = y;
}

//**********************************
// Member function showDate1       *
// Displays the date in the form   *
// MM/DD/YY                        *
// Example: 12/25/2014               *
//**********************************

void Date::showDate1()
{

   cout << month << "/" << day << "/" << year;
}

//*************************************
// Member function showDate2          *
// Displays the date in the following *
// form: December 25, 2014            *
//*************************************

void Date::showDate2()
{
   cout << names[month+1] << " " << day << ", ";
   cout << year << endl;
}

//*************************************
// Member function showDate2          *
// Displays the date in the following *
// form: 25 December, 2014            *
//*************************************

void Date::showDate3()
{
   cout << day << " " << names[month+1] << " " << year << endl;
}

//***************************************
// Prefix ++ operator                   *
//***************************************

Date Date::operator ++()
{
   if (day == numDays[month - 1])
   {
      if (month == 12)
      {
         month = 1;
         day = 1;
         year++;
      }
      else
      {
         month++;
         day = 1;
      }
   }
   else
   {
      day++;
   }

   return *this;
}

//***************************************
// Prostfix ++ operator                 *
//***************************************

Date Date::operator ++(int)
{
   Date temp(month, day, year);

   if (day == numDays[month - 1])
   {
      if (month == 12)
      {
         month = 1;
         day = 1;
         year++;
      }
      else
      {
         month++;
         day = 1;
      }
   }
   else
   {
      day++;
   }

   return temp;
}

//***************************************
// Prefix -- operator                   *
//***************************************

Date Date::operator --()
{
   if (day == 1)
   {
      if (month == 1)
      {
         month = 12;
         day = 31;
         year--;
      }
      else
      {
         month--;
         day = numDays[month - 1];
      }
   }
   else
   {
      day--;
   }

   return *this;
}

//***************************************
// Prostfix -- operator                 *
//***************************************

Date Date::operator --(int)
{
   Date temp(month, day, year);

   if (day == 1)
   {
      if (month == 1)
      {
         month = 12;
         day = 31;
         year--;
      }
      else
      {
         month--;
         day = numDays[month - 1];
      }
   }
   else
   {
      day--;
   }

   return temp;
}

//***************************************
// Overloaded > operator                *
//***************************************

bool Date::operator >(const Date &obj)
{
   bool status;

   if (year > obj.year)
      status = true;
   else if (year == obj.year && month > obj.month)
      status = true;
   else if (year == obj.year && month == obj.month && day > obj.day)
      status = true;
   else
      status = false;

   return status;
}

//***************************************
// isLeapYear function                  *
//***************************************

bool Date::isLeapYear(int year) 
{
   if (year % 4 == 0)
      return true;
   else return false;
}

//***************************************
// Overloaded - operator                *
//***************************************

int Date::operator -(const Date &obj)
{
   Date greater, lesser;
   bool inverted = false;
   int i;
   int numberOfDays = 0;

   if (*this > obj)
   {
      greater.day = day; greater.month = month; greater.year = year;
      lesser.day = obj.day; lesser.month = obj.month; lesser.year = obj.year;
   }
   else
   {
      greater.day = obj.day; greater.month = obj.month; greater.year = obj.year;
      lesser.day = day; lesser.month = month; lesser.year = year;
      inverted = true;
   }

   // If the lesser date is from an earlier year than the greater date,
   // add up the days from the lesser date to the end of its year.
   if (lesser.year < greater.year)
   {
      int tempDays = numDays[lesser.month - 1] - lesser.day;
      for (i = lesser.month + 1; i <= 12; i++)
         tempDays += numDays[i - 1];
      numberOfDays += tempDays;
   }

   // Add up the days in the years between the lesser to the greater.
   for (i = lesser.year + 1; i < greater.year; i++)
   {
      if (isLeapYear(i))
         numberOfDays += 366;
      else
         numberOfDays += 365;
   }
 
   // Add up the days from the beginning of the greater year until
   // the start of the month held by the greater year.
   for (i = 1; i < greater.month; i++)
   {
      numberOfDays += numDays[i - 1];
      if (i == 2 && isLeapYear(greater.year))
         numberOfDays++;
   }

   // Add up the days from the start of the greater date's month
   // through that date's current day.
   numberOfDays += greater.day;

   // Check to see if the difference should be negative.
   if (inverted)
      numberOfDays = -numberOfDays;

   // Return the number of days.
   return numberOfDays;
}

//*************************************
// Overloaded << operator             *
//*************************************

ostream &operator <<(ostream &strm, Date &obj)
{
   obj.showDate1();
   return strm;
}

//*************************************
// Overloaded >> operator             *
//*************************************

istream &operator >>(istream &strm, Date &obj)
{
   cout << "Enter the day: ";
   cin >> obj.day;
   cout << "Enter the month: ";
   cin >> obj.month;
   cout << "Enter the year: ";
   cin >> obj.year;

   return strm;
}


//*************************************
// Function main                      *
//*************************************

int main()
{
   // Demonstrate the overloaded - and << operators. 
   Date d1(2, 2, 2006); 
   Date d2(11, 10, 2003);
   int days = d1 - d2;
   cout << d1 << " minus " << d2 << " equals " << days << " days\n\n";

   // Demonstrate the overloaded ++ operators.
   cout << ++d1 << endl;
   cout << d1++ << endl;
   cout << d1 << endl;

   d1.setDay(31);
   d1.setMonth(12);
   cout << ++d1 << endl << endl;

   // Demonstrate the overloaded -- operators.
   d1.setDay(10);
   d1.setMonth(7);
   d1.setYear(2003);
   cout << --d1 << endl;
   cout << d1-- << endl;
   cout << d1 << endl;

   d1.setDay(1);
   d1.setMonth(1);
   d1.setYear(2004);
   cout << --d1 << endl;

   // Demonstrate the overloaded >> operator.
   cin >> d1;
   cout << "You entered " << d1 << endl;

   return 0;
}
// Chapter 14, Programming Challenge 4: NumDays Class
#include <iostream>
#include "numdays.h"
using namespace std;

int main()
{
   NumDays one(25), 
           two(15), 
           three, 
           four;

   // Display one and two.
   cout << "One: " << one.getDays() << endl;
   cout << "Two: " << two.getDays() << endl;
   
   // Add one and two, assign result to three.
   three = one + two;
   
   // Display three.
   cout << "Three: " << three.getDays() << endl;
   
   // Postfix increment...
   four = three++;
   cout << "Four = Three++: " << four.getDays() << endl;
   
   // Prefix increment...
   four = ++three;
   cout << "Four = ++Three: " << four.getDays() << endl;
   
   // Postfix decrement...
   four = three--;
   cout << "Four = Three--: " << four.getDays() << endl;
   
   // Prefix increment...
   four = --three;
   cout << "Four = --Three: " << four.getDays() << endl; 

   return 0;
}
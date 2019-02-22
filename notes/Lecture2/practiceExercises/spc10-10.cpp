// Chapter 10, Programming Challenge 10: replaceSubstring Function
#include <iostream>
#include <string>
using namespace std;

// Function prototype
void replaceSubstring(string &, string, string);

int main()
{
   // Create three string objects.
   string str1 = "the dog jumped over the fence";
   string str2 = "the";
   string str3 = "that";
   
   // Display str1 before we change it.
   cout << str1 << endl;
   
   // Test the function. This function call
   // should replace "the" with "that".
   replaceSubstring(str1, str2, str3);
   
   // Display the string.
   cout << str1 << endl;
   return 0;
}

void replaceSubstring(string &string1, string string2, string string3)
{
   // First, make sure string2 and string3 aren't the same.
   if (string2 == string3)
      return;
   
   // Find the first occurrence of string3.
   int index = string1.find(string2, 0);
      
   while (index >= 0)
   {
      // Replace this occurrence of the substring.
      string1.replace(index, string2.length(), string3);
         
      // Find the next occurrence of string3.
      index = string1.find(string2, index);
   }
}
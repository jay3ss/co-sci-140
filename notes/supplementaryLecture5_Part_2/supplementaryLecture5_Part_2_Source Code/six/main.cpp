//http://www.cplusplus.com/reference/cctype/
//#include <climits>// limits of named constants, see page 1284
//#include <cmath> //math library
#include <cctype> // library for strings and other useful validations
#include <iomanip> // library for manipulating output
#include <fstream> // library to direct output to files and get input from files
//#include <cstdlib> // library for the rand and srand functions
#include <ctime> // library to work with time
#include <string> //string library
#include <cstring> //to be able to use strlen
#include "Circle.h" 
#include <iostream>

using namespace std;

int main() 
{
	char continu = 'y';
	Circle myCircle;
	Circle yourCircle;
	double radius;

	cout << "y/Y to continue, any other char to exit" << endl;
	cin >> continu;
	system ("cls");
	while (continu == 'y' || continu =='Y')
	{
		cout << fixed << showpoint <<setprecision(2);
		cout << "enter the radius of circle 1" << endl;
		cin >> radius;
		myCircle.setRadius(radius);
		//=============
		cout << "enter the radius of circle 2" << endl;
		cin >> radius;
		yourCircle.setRadius(radius);

		//============
		if(myCircle.getRadius()==yourCircle.getRadius())
		{
			cout << "the two circles have equal radii\n";
		}
		else
		{
			cout << "the two circles have unequal radii\n";
		}
		//==============================
		if (myCircle.compareCircles(yourCircle))
		{
			cout << "the radius of my circle is equal to the radius of your circle" << endl;
		}
		else
		{
			cout << "the radius of my circle is not equal to the radius of your circle" << endl;
		}

		cout << "y/Y to continue, any other char to exit" << endl;
		cin >> continu;
		system ("cls");
	
	}
	return 0;
}
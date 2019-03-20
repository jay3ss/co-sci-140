//http://www.cplusplus.com/reference/cctype/
//#include <climits>// limits of named constants, see page 1284
//#include <cmath> //math library
//#include <cctype> // library for strings and other useful validations
//#include <iomanip> // library for manipulating output
//#include <fstream> // library to direct output to files and get input from files
//#include <cstdlib> // library for the rand and srand functions
//#include <ctime> // library to work with time
//#include <string> //string library
//#include <cstring> //to be able to use strlen
#include "Circle.h" 
#include "Triangle.h" 
#include "Square.h" 
#include <iostream>

using namespace std;
void menu(int&);
void implementUserChoice(char&, int, Circle, Triangle, Square);
int main()
{
	Circle userCircle;
	Triangle userTriangle;
	Square userSquare;
	char continu = 'y';
	int userChoice;

	do
	{
	cout << "Classes and Shapes\n" << endl;
	menu(userChoice);
	implementUserChoice(continu, userChoice, userCircle, userTriangle, userSquare);
	system("pause");
	system ("cls");
	}while (continu == 'y' || continu =='Y');
    return 0;
}
void menu(int& userChoice)
{
	cout << "1. Circle" << endl;
	cout << "2. Square" << endl;
	cout << "3. Triangle" << endl;
	cout << "4. Quit" << endl;
	cin >> userChoice;
}
void implementUserChoice(char& continu, int userChoice, Circle userCircle, Triangle userTriangle, Square userSquare)
{
	switch (userChoice)
	{
	case 1:
		cout << "enter radius\n";
		cin >> userChoice;
		userCircle.setRadius( userChoice);
		cout << "the radius is " << userCircle.getRadius() << endl;
		cout << "the area is " << userCircle.getArea() << endl;
		cout << "the circumference is " << userCircle.getCirumference() << endl;
		break;
	case 2:
		cout << "enter length of side\n";
		cin >> userChoice;
		userSquare.setLength(userChoice);
		cout << "the length of a side is " << userSquare.getLength() << endl;
		cout << "the area is " << userSquare.getArea() << endl;
		cout << "the perimeter is " << userSquare.getPerimeter() << endl;
		break;
	case 3:
		cout << "enter length of base\n";
		cin >> userChoice;
		userTriangle.setBase(userChoice);
		cout << "enter heigth\n";
		cin >> userChoice;
		userTriangle.setHeigth(userChoice);
		cout << "the base is " << userTriangle.getBase() << 
			 ", the height is " << userTriangle.getHeight() <<endl;
		cout << "the area is " << userTriangle.getArea() << endl;
		break;
	case 4:
		cout << "Good-bye\n";
		continu = 'n';
		break;
	default:
		cout << "invalid" << endl;
		break;
	}
}
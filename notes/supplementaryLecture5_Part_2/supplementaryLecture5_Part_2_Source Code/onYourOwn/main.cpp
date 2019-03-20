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
 
#include "Triangle.h" 
#include <iostream>

using namespace std;
void askForLengthOfSides(double triangleSides[], int length);
void setLengthOfSides(Triangle& triangle, double triangleSides[]);
//void displayLengthOfSides(double triangleSides[], int length);
int main()
{

	Triangle triangle1;
	Triangle triangle2;
	const int length = 3;
	double triangleSides[length];
	char continu = 'y';
	int userChoice;
	double someSide;

	do
	{
	cout << "Similar Right Triangles\n" << endl;

	askForLengthOfSides(triangleSides, length);
	setLengthOfSides(triangle1, triangleSides);

	//====================
	askForLengthOfSides(triangleSides, length);
	setLengthOfSides(triangle2, triangleSides);

	if(triangle1.isSimilar(triangle2))
		cout << "The triangles are right and similar\n";
	else
		cout << "The triangles are not similar because at least one of them is not right\n";

	cout << "Continue? (y/n)\n";
	cin >> continu;
	system ("cls");
	}while (continu == 'y' || continu =='Y');
    return 0;
}
void askForLengthOfSides(double triangleSides[], int length)
{
	for (int x = 0; x < 3; x++)
	{
		cout << "Enter length of side " << x+1 << endl;
		cin >> triangleSides[x];
		//cout << triangleSides[x] << endl;
	}
}
void setLengthOfSides(Triangle& triangle, double triangleSides[])
{
		triangle.setSide1(triangleSides[0]);
		triangle.setSide2(triangleSides[1]);
		triangle.setSide3(triangleSides[2]);
}
//void displayLengthOfSides(double triangleSides[], int length)
//{
//	for (int x = 0; x < 3; x++)
//	{
//		cout << "triangleSides " << x << " = " << triangleSides[x] << endl;
//	}
//}
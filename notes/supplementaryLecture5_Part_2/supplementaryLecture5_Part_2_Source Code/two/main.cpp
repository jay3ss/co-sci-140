//http://www.cplusplus.com/reference/cctype/
//#include <climits>// limits of named constants, see page 1284
//#include <cmath> //math library
//#include <cctype> // library for strings and other useful validations
#include <iomanip> // library for manipulating output
////#include <fstream> // library to direct output to files and get input from files
//#include <cstdlib> // library for the rand and srand functions
//#include <ctime> // library to work with time
#include <string> //string library
//#include <cstring> //to be able to use strlen
//#include <assert.h> 
#include "Addition.h" 
#include <iostream>

using namespace std;

int main() 
{
	char continu = ' ';
	int num1, num2, userResponse;
	Addition addProblem;
	num1 = addProblem.generateOperand();
	num2 = addProblem.generateOperand();

	cout << "y/Y to continue, any other char to exit" << endl;
	cin >> continu;

	system ("cls");

	while (continu == 'y' || continu =='Y')
	{
	cout << "Problem " << addProblem.getProblemCount() << endl;
	cout << num1 << " + " << num2<< " = ?" << endl;
	cin >> userResponse;

	addProblem.checkUserResponse(userResponse, num1 + num2);
	addProblem.updateStats(userResponse, num1 + num2);
	addProblem.displayStats();

	cout << "y/Y to continue, any other char to exit" << endl;
	cin >> continu;

	num1 = addProblem.generateOperand();
	num2 = addProblem.generateOperand();
	system("cls");
	}


	return 0;
}

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
	Addition addProblem(num1, num2);

	cout << "y/Y to continue, any other char to exit" << endl;
	cin >> continu;

	system ("cls");

	while (continu == 'y' || continu =='Y')
	{

	cout << num1 << " + " << num2 << " = ?" << endl;
	cin >> userResponse;
	if(userResponse == addProblem.getSum())
	{
			cout << "correct!\n";
	}
	else
	{
			cout << "incorrect!\n";
	}
	addProblem.checkUserResponse(userResponse);
	addProblem.displayStats();

	cout << "y/Y to continue, any other char to exit" << endl;
	cin >> continu;
	addProblem.randomize(num1, num2);
	}


	return 0;
}

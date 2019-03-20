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
#include "Subtraction.h" 
#include <iostream>

using namespace std;
void menu();
void validateUserEntry(char&);
void displayProblem(char&);
void displayAdditionProblem();
void displaySubtractionProblem();

int main() 
{
	char continu = 'y';

	while (continu == 'y' || continu =='Y')
	{
		menu();
		cin >> continu;
		validateUserEntry(continu);
		displayProblem(continu);
	}

	return 0;
}

void menu()
{
	system("cls");
	cout << "1. Add\n";
	cout << "2. Subtract\n";
	cout << "Quit--> q or Q\n";
}

void validateUserEntry(char& continu)
{
		while(continu != '1' && continu != '2' && continu != 'q' && continu != 'Q')
		{
			cout << "invalid option\n";
			cin.ignore(1000000,'\n');
			cin >> continu;
		}
}
void displayProblem(char& continu)
{
	switch (continu)
		{
		case '1':
			displayAdditionProblem();
			continu = 'y';
			break;
		case '2':
			displaySubtractionProblem();
			continu = 'y';
			break;
		case 'q':
		case 'Q':
			cout <<"bye!\n";
			continu = 'n';
			break;
		 default:
			 //but you know this will never happen!
			 cout << "invalid option\n";
		}

		system("pause");
}
void displayAdditionProblem()
{
	int num1, num2, userResponse;
	Addition addProblem(num1, num2);
	system("cls");
	cout << num1 << " + " << num2 << " = ?" << endl;
	cin >> userResponse;

	addProblem.checkUserResponse(userResponse);
	addProblem.updateStats(userResponse);
	addProblem.displayStats();

}
void displaySubtractionProblem()
{
	int num1, num2, userResponse;
	Subtraction subtractionProblem(num1, num2);
	system("cls");
	cout << num1 + num2 << " - " << num2 << " = ?" << endl;
	cin >> userResponse;

	subtractionProblem.checkUserResponse(userResponse);
	subtractionProblem.updateStats(userResponse);
	subtractionProblem.displayStats();
}
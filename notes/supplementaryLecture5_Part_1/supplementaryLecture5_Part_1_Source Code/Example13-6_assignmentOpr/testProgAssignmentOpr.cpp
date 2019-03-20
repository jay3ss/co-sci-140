 
#include <iostream>

#include "classAssignmentOverload.h"

using namespace std;
 
int main()
{
    cAssignmentOprOverload intList1(10);             //Line 9
    cAssignmentOprOverload intList2;                 //Line 10
    cAssignmentOprOverload intList3;                 //Line 11

    int i;                                           //Line 12
    int number;                                      //Line 13

    cout << "Line 14: Enter 5 integers: ";           //Line 14

    for (i = 0; i < 5; i++)                          //Line 15
    {
        cin >> number;                               //Line 16
        intList1.insertEnd(number);                  //Line 17
    }

    cout << endl;                                    //Line 18
    cout << "Line 19: intList1: ";                   //Line 19
    intList1.print();                                //Line 20

    intList3 = intList2 = intList1;                  //Line 21 //the reason you may have consecutive 
														//statements as these using the = is because you return *this
						 								//otherwise you may execute only statements like intList2 = intList1;
														//and not intList3 = intList2 = intList1; 
	//intList2 = intList1;

	//intList3.operator=(intList2.operator=(intList1));//by definition

    cout << "Line 22: intList2: ";                   //Line 22
    intList2.print();                                //Line 23

    intList2.destroyList();                          //Line 24

    cout << endl;                                    //Line 25
    cout << "Line 26: intList2: ";                   //Line 26
    intList2.print();                                //Line 27

    cout << "Line 28: After destroying intList2, "
         << "intList1: ";                            //Line 28
    intList1.print();                                //Line 29

    cout << "Line 30: After destroying intList2, "
         << "intList3: ";                            //Line 30
    intList3.print();                                //Line 31
    cout << endl;                                    //Line 32
	system("pause");
    return 0;
}


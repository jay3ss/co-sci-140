#include <iostream>

using namespace std;

template<class T>
class MyClass
{
public:
    T myData;
};

template<class T>
class MyOtherClass
{
public:
    T myData[3];
};


int main()
{
    // An array of objects
    MyClass<int> myClass[] = {MyClass<int>(), MyClass<int>()};

    myClass[0].myData = 15;
    myClass[1].myData = 137;
    for (int i = 0; i < 2; i++)
        cout << myClass[i].myData << endl;

    // An object with an array of templated data
    MyOtherClass<double> myOtherClass;

    myOtherClass.myData[0] = 26.;
    myOtherClass.myData[1] = 3.14;
    myOtherClass.myData[2] = 15.5;

    for (int i = 3; i < 3; i++)
        cout << myOtherClass.myData[i] << endl;
}

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class MyClass
{
public:
    MyClass()
    { size = 4;
      unique_ptr<string[]> strPtr(new string[size]);
    }

    // ~MyClass()
    // { delete [] strPtr;
    //   strPtr = nullptr; }

    void setStringArr(string strArr[])
    {
        for (int i = 0; i < size; i++)
        {
            str[i] = strArr[i];
        }
    }
    void printStringArr()
    {
        for (int i = 0; i < size; i++)
        {
            cout << str[i] << " ";
        }
    }

    void setStrPtr(string *a)
    { strPtr = new string[size];
      strPtr = a; }

    string *getStringArr()
    { return str; }

    string *getStringPtr()
    { return strPtr; }
private:
    int size;
    string* strPtr;
    string str[4];
};

void setStringArray(string strArr[]);

int main()
{
    const int SIZE = 4;
    string str[] = {"This", "is", "a", "string."};

    MyClass myClass;
    myClass.setStringArr(str);
    myClass.printStringArr();

    string* strArrPtr = nullptr;

    strArrPtr = myClass.getStringArr();

    cout << "\nPrint using local pointer variable\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(strArrPtr + i) << " ";
    }

    cout << endl;

    myClass.setStrPtr(strArrPtr);

    cout << "Print using member pointer variable\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(myClass.getStringPtr() + i) << " ";
    }

    string *myPtr = nullptr;
    myPtr = new string[SIZE];

    cout << "\nCopying the array\n";
    for (int i = 0; i < SIZE; i++)
    {
        myPtr[i] = str[i];
    }

    cout << "\nPrint using dynamically allocated array\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << myPtr[i] << " ";
    }
    

    // char myChars[] = "abcd";
    // char *myPtr = new char[SIZE];

    // myPtr = myChars;

    // cout << "\nPrint using dynamically allocated array\n";
    // for (int i = 0; i < SIZE; i++)
    // {
    //     cout << myPtr[i] << " ";
    // }

    delete[] myPtr;
    myPtr = nullptr;

    return 0;
}

void setStringArray(string strArr[])
{
    strArr[0] = "This ";
    strArr[1] = "is ";
    strArr[2] = "a ";
    strArr[3] = "string.";
}
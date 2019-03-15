#include <iostream>
using namespace std;

// class MyClass
// {
//   private:
//     static int numObjects;

//   public:
//     MyClass()
//     {
//         numObjects++;
//     }

//     int getNumObjects() const
//     {
//         return numObjects;
//     }
// };

class MyClass
{
  private:
    static int numObjects;

  public:
    MyClass()
    {
        numObjects++;
    }

    static int getNumObjects()
    {
        return numObjects;
    }
};

int MyClass::numObjects = 0;

int main()
{
    MyClass myClass1;
    MyClass myClass2;
    MyClass myClass3;
    cout << "Number of objects of type MyClass: " << MyClass::getNumObjects();

    return 0;
}
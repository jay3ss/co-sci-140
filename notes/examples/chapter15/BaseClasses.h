#ifndef _BASE_CLASSES_H
#define _BASE_CLASSES_H

#include <iostream>

using namespace std;

class BaseClassA
{
public:
    BaseClassA() { cout << "BaseClassA constructor\n"; }
    ~BaseClassA() { cout << "BaseClassA destructor\n"; }
};

class BaseClassB
{
public:
    BaseClassB() { cout << "BaseClassB constructor\n"; }
    ~BaseClassB() { cout << "BaseClassB destructor\n"; }
};

class DerivedClassA : public BaseClassA, public BaseClassB
{
public:
    DerivedClassA() { cout << "DerivedClassA constructor\n"; }
    ~DerivedClassA() { cout << "DerivedClassA destructor\n"; }
};

class DerivedClassB : public BaseClassB, public BaseClassA
{
public:
    DerivedClassB(): BaseClassB(), BaseClassA()
    { cout << "DerivedClassB constructor\n"; }
    ~DerivedClassB() { cout << "DerivedClassB destructor\n"; }
};

#endif // _BASE_CLASSES_H
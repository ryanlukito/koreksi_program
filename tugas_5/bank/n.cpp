#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    void print() { cout << "hello" << endl; }
};

class B : public A
{
};
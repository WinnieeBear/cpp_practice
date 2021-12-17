#include <iostream>

using namespace std;

class X {
    // will have 1 byte, will be insert one char
    // by the compiler, which will make two objects of the class
    // have the different address
};

class Y : public virtual X {
};

class Z : public virtual X {
};

class A : public Y, public Z {
};

int main()
{
    cout << "sizoef X:" << sizeof(X) << " sizeof Y:" << sizeof(Y) << " sizeof Z:" << sizeof(Z)
         << " sizeof A:" << sizeof(A) << endl;
    // size is 1, 8, 8, 16
    // if the virtural base class don't have any member, only the interface, it will not have any size
    // any more include the 1 byte char
    // so the sizeof(Y), sizeof(Z) and sizeof(A) is 8, 8, 16
    return 0;
}
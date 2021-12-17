/*
 * when must use the initialization list:
 * 1. initialization when the class contain the reference member
 * 2. initialization when the class contain the const member
 * 3. when calling the base class constructor, which have a set of parameter (I think the set of
 * parameter means the constutor initialization list parameter)
 * 4. when calllng the member class construtor, which have a set of parameter
 */

#include <cstdlib>

class String {
    int n;
    char* p;

public:
    String()
    {
        n = 0;
        p = nullptr;
    }
    String(int sz)
    {
        n = sz;
        p = (char*)malloc(sizeof(char) * n);
    }
    String& operator=(const String& rhs)
    {
        if (this != &rhs) {
            n = rhs.n;
            p = (char*)malloc(sizeof(char) * n);
            free(rhs.p);
        }
        return *this;
    }
    // c++11 have the rval ref and we can use it to call swap() for opertator=
};

class Word {
    String _name;
    int _cnt;

public:
    Word()
    {
        _name = 0;
        _cnt  = 0;
    }
};

// above constructor will be expanded as below, but it is not efficent
Word::Word()
{
    // call the defualt construtor
    _name.String::String();
    // then produce the tmp object
    String tmp = String(0);
    // memberwise copy
    _name.String::operator=(tmp);
    // destory the tmp object
    tmp.String::~String();
    // set _cnt
    _cnt = 0;
};

// this will be more effient than above
Word::Word() : _name(0)
{
    _cnt = 0;
}
// bacause it will be expaned by the compiler as
Word::Word()
{
    _name.String::String(0);
    _cnt = 0;
}

// attention the template code
template <class T>
class foo {
    T _t;

public:
    foo(T t)
    {
        // based on the type of t, it's a good a bad idea
        // like if the T is int, it's fully OK, but how the T is the String()?
        _t(t);
    }
};

// so what's doing in the initialization list for compiler?
// it adds the code before user's code!

// initialzation order
class X {
    int i;
    int j;

public:
    // bug! initialization order is based on the declaretion order
    X(int val) : j(val), i(j)
    {
    }
};

class X {
    int i;
    int j;
    int xfoo(int val);

public:
    // remove the above bug
    // but the initialization order will be kept or not? i.e. i is before j
    // will be broken? the answer is, the oder will be kept
    // answer is the initializaiton list will be put before the user's code
    X(int val) : j(val)
    {
        i = j;
    }
};

// can we use the member fucntion to set the member value?
// since the calliing the intializaiton list, the object is not fully constructed already
// so you need to pay attention to the member funciton which may use the not fully constructed
// member in initialzaiton list, otherwise, it's safe.
X::X(int val) : i(xfoo(val)), j(val)
{
}
// above will be expanded by the compiler as
X::X(int val)
{
    // this will be constructed well, but xfoo can't change the member
    i = this->xfoo(val);
    j = i;
}

class FooBar : public X {
    int _fval;

public:
    int fVal()
    {
        return _fval;
    }
    // bug! the X will be initialza firstly, X is not constuctored, so the fval() will not be ready?
    // notice, the later chapter will give more details the order of the class constructor in
    // inheritance
    FooBar(int val) : _fval(val), X(fVal())
    {
    }
};
/*
 * 2.3.1 Argument Initialization
 */

/*
 * 2.3.2 Return Value Initialization
 */

class X {
public:
    X(int val);
    void memfunc();
};

X bar()
{
    X xx;
    // change and deal with xx
    return xx;
}

/*
 * compiler will change above code to below:
 */

void bar(X& __result) // 1. the compiler will add an external paramter
{
    X xx;
    // call the defalut.constructor
    xx.X::X();

    // change tan deal with xx

    // 2. call the copy constructor
    __resutl.X::X(xx);
}

// example1:
X xx = bar();
// will be converted to:
X xx;
bar(xx);

// example2:
bar().memfunc();
// will be converted to:
X __tmp0;
// notice the comma expression, first change the __tmp0, then use it
(bar(__tmp0), __tmp0).memfunc();

// example3: function pointer
X (*pf)();
pf = bar;
// will be changed to:
void (*pf)(X&);
pf = bar;

/*
 * 2.3.3 Optimization at User Level
 */
X bar(const T& x, const T& y)
{
    X xx;
    // use x and y to change xx;
    return xx;
}
// some user define some code like this:
X bar(const T& x, const T& y)
{
    return X(x, y);
}
// becasue he has the construtor like: X::X(const T&, const T&);
void bar(X& __result, const T& x, const T& y)
{
    __result::X(x, y);
}
// this is not the best, because this will have to define a construtor and is not flexible

/*
 * 2.3.4 Optimization at Compiler Level(NRV)
 */
X bar()
{
    X xx;
    // ...change xx;
    return xx;
}
// will be optimized like
void bar(X& __result)
{
    __result.X::X();
    // change at __result directly
    return;
}

#include <memory.h>
class test {
    friend test foo(int val);

public:
    test()
    {
        memcpy(array, 0, sizeof(double) * 100);
    }

private:
    double array[100];
};

test foo(int val)
{
    test local;
    local.array[0]  = val;
    local.array[99] = val;
}

int main()
{
    for (int i = 0; i < 10000000; ++i) {
        // notice here can't be optimized by NRV, we need to explicilty set copy constructor
        test t = foo(double(i));
    }
    return 0;
}

// need to be explicilty set when NRV
inline test::test(const test& t)
{
    memcpy(this, &t, sizeof(test));
}

X xx0(1024);
X xx1 = X(1024);
X xx2 = (X)1024;

// xx0 will be directly constructed, xx1 and xx2 will be complex, compiler will do like below:
X __temp0;
__temp0.X::X(1024);
xx1.X::X(__temp0);
__temp0.X::~X();

/*
 * 2.3.5 copy constructor need or should be not need?
 */
class Point3d {
public:
    Point3d(float x, float y, float z);
    Point3d operator+(const Point3d&);
    Point3d operator-(const Point3d&);
    Point3d operator*(int);

private:
    float _x, _y, _z;
};
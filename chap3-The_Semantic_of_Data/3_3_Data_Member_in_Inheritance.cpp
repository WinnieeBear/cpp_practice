class Point2d {
public:
    // constructors
    // operations
    // access functions
private:
    float x, y;
};

class Point3d {
public:
    // constructors
    // operations
    // access functions
private:
    float x, y, z;
};

/*
 * inheritance without polymophism
 */
class Point2d {
public:
    Point2d(float x = 0.0, float y = 0.0) : _x(x), _y(y)
    {
    }
    float x()
    {
        return _x;
    }
    float y()
    {
        return _y;
    }
    void x(float newx)
    {
        _x = newx;
    }
    void y(float newx)
    {
        _y = newx;
    }
    Point2d& operator+=(const Point2d& rhs)
    {
        _x += rhs._x;
        _y += rhs._y;
        return *this;
    }

protected:
    float _x, _y;
};
// inheritance from concrete class
class Point3d : public Point2d {
public:
    float z()
    {
        return _z;
    }
    void z(float newz)
    {
        _z = newz;
    }
    Point3d& operator+=(const Point3d& rhs)
    {
        Point2d::operator+=(rhs);
        _z += rhs._z;
        return *this;
    }

protected:
    float _z;
};

#include <iostream>
using namespace std;

class Concrete {
public:
    // ...
private:
    int val;
    char c1;
    char c2;
    char c33;
};

class Concrete1 {
public:
    // ...
private:
    int val;
    char bit1;
};

class Concrete2 : public Concrete1 {
public:
    // ...
private:
    char bit2;
};

class Concrete3 : public Concrete2 {
public:
    // ...
private:
    char bit3;
};

int main()
{
    // attention the alignment of the inheritance
    // 8
    cout << sizeof(Concrete) << endl;
    // 8
    cout << sizeof(Concrete1) << endl;
    // 12
    cout << sizeof(Concrete2) << endl;
    // 16
    cout << sizeof(Concrete3) << endl;
}

/*
 * adding polymorphism
 */
class Point2d {
public:
    Point2d(float x = 0.0, float y = 0.0) : _x(x), _y(y)
    {
    }
    Point2d& operator+=(const Point2d& rhs)
    {
        _x += rhs._x;
        _y += rhs._y;
        return *this;
    }
    virtual float z()
    {
        return 0;
    }
    void z(float newz)
    {
    }

protected:
    float _x, _y;
};
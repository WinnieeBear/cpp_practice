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
    virtual Point2d& operator+=(const Point2d& rhs)
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

class Point3d : public Point2d {
public:
    Point3d(float x = 0.0, float y = 0.0, float z = 0.0) : Point2d(x, y), _z(z)
    {
    }
    virtual float z()
    {
        return _z;
    }
    void z(float newz)
    {
        _z = newz;
    }
    virtual Point3d& operator+=(/*const*/ Point2d& rhs)
    {
        Point2d::operator+=(rhs);
        // blow is not right, since the parameter is const, but z() is not const
        // so either remove const parameter or add const for z()
        // _z += rhs.z();
        _z += rhs.z();
    }

protected:
    float _z;
};

/*
 * multiple inheritance
 */

class Point2d {
public:
    // ... has virtual function
protected:
    float _x, _y;
};

class Point3d : public Point2d {
public:
protected:
    float _z;
};

class Vertex {
public:
    // ... has virtual function
protected:
    Vertex* next;
};

class Vertex3d : public Point3d, public Vertex {
public:
    // ...
protected:
    float mumble;
};

// memory layout please refer md
Vertex3d v3d;
Vertex* pv;
Point2d* p2d;
Point3d* p3d;

pv = &v3d;
// will be converted to
pv = (Vertex*)((char*)&v3d + sizeof(Point3d));
// below will directly copy the address
p2d = &v3d;
p3d = &v3d;

Vertex3d* pv3d;
Vertex* pv;
pv = pv3d;
// will be conveted to below(need judge the pointer)
pv = pv3d ? (Vertex*)((char*)pv3d + sizeof(Point3d)) : 0;

/*
 * vitrual inheritance
 */

class Point2d {
public:
    // ...
protected:
    float _x, _y;
};

class Vertex : public virtual Point2d {
public:
    // ...
protected:
    Vertex* next;
};

class Point3d : public virtual Point2d {
public:
    // ...
protected:
    float _z;
};

class Vertex3d : public Vertex, public Point3d {
public:
    // ...
protected:
    float mumble;
};
// please refer to the .md to check layout of memory

/*
 * pointers to data member
 */
class Point3d {
public:
    virtual ~Point3d();

protected:
    static Point3d origin;
    float x, y, z;
};

// what's the meaning of below?
&Point3d::z;
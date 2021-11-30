#include <iostream>

using namespace std;

template <class type>
class Point3d {
public:
    Point3d(type x = 0.0, type y = 0.0, type z = 0.0) : _x(x), _y(y), _z(z)
    {
    }
    type x() const
    {
        return _x;
    }
    void x(type xval)
    {
        _x = xval;
    }
    void y(type yval)
    {
        _y = yval;
    }
    void z(type zval)
    {
        _z = zval;
    }
    type y() const
    {
        return _y;
    }
    type z() const
    {
        return _z;
    }

private:
    type _x;
    type _y;
    type _z;
};

template <class type, int dim>
class Point {
public:
    Point();
    Point(type coords[dim])
    {
        for (int i = 0; i < dim; ++i) {
            _coords[i] = coords[i];
        }
    }
    type& operator[](int index)
    {
        assert(index >= 0 && index < dim);
        return _coords[index];
    }
    type& operator[](int index) const
    {
        assert(index >= 0 && index < dim);
        return _coords[index];
    }

private:
    type _coords[dim];
};

inline
template <class type, int dim>
ostream& operator<<(ostream& os, const Point<type, dim>& pt) {
    os << "(";
    for (int i = 0; i < dim - 1; ++i) {
        os << pt[i]  << ", ";
    }
    os << pt[dim - 1];
    so << " )";
}
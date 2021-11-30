class Point {
public:
    Point(float x = 0.0) : _x(x)
    {
    }
    float x() const
    {
        return _x;
    }
    void x(float x)
    {
        _x = x;
    }

protected:
    float _x;
};

class Point2d : public Point {
public:
    Point2d(float x = 0.0, float y = 0.0) : Point(x), _y(y)
    {
    }
    float y() const
    {
        return _y;
    }
    void y(float y)
    {
        _y = y;
    }

protected:
    float _y;
};

class Point3d : public Point2d {
public:
    Point3d(float x = 0.0, float y = 0.0, float z = 0.0) : Point2d(x, y)
    {
    }
    float z() const
    {
        return _z;
    }
    void z(float z)
    {
        _z = z;
    }

protected:
    float _z;
};

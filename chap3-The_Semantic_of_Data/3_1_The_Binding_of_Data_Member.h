extern float x;

class Point3d {
public:
    Point3d(float x, float y, float z) : x(x), y(y), z(z)
    {
    }
    float X() const
    {
        return x;
    }
    void X(float new_x)
    {
        // will be the global x
        x = new_x;
    }

private:
    float x, y, z;
};
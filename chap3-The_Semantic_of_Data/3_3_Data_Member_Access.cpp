/*
 * static member stored in data segment
 * so the access will be directly, not have
 * the difference
 */

/*
 * non-static member stored in data segment
 */

class Point3d {
public:
    // ...
public:
    // the object will contain x, y, z will not influenced by static
    float _x;
    float _y;
    static const int chunkSize = 250;
    float _z;
};

int main()
{
    Point3d origin;
    origin._y = 0.0;
    // will be transformed to, the below is pointer to member
    // about pointer to member pleade refer
    // https://stackoverflow.com/questions/670734/pointer-to-class-data-member
    &origin + (&Point3d::_y - 1);

    Point3d* p;
    p->_y = 0.0;
    // what's the diff between . and ->
    // when the p is a virtual base class, then we can say . is more efficent than ->
}
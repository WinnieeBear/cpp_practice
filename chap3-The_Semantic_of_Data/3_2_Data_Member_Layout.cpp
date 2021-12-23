template <typename T>
class List {
};

class Point3d {
public:
    // ...
public:
    // the object will contain x, y, z will not influenced by static
    float x;
    static List<Point3d*>* freeList;
    float y;
    static const int chunkSize = 250;
    float z;
};

template <class class_type, class data_type1, class data_type2>
// !!data member pointer!! wchich can determin which data occurss first
char* access_order(data_type1 class_type::*mem1, data_type2 class_type::*mem2)
{
    assert(mem1 != mem2);
    return mem1 < mem2 ? "mem1 occurs first" : "mem2 occurs first";
}

int main()
{
    access_order(&Point3d::z, &Point3d::x);
}
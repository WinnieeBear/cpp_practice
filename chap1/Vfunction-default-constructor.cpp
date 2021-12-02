class Widget {
public:
    virtual void flip();
};

void flip(Widget& widget)
{
    widget.flip();
}

class Bell : public Widget {
};

class Whistle : public Widget {
};

void foo()
{
    Bell b;
    Whistle w;

    flip(b);
    flip(w);
}
/*
 * 对于Bell和Whistle的default constructor会被扩张
 * 1. 一个虚函数表 vtbl 会被编译器产生出来，内部存放 class的
 * virtual function
 * 2. 每一个class object 中，一个vptr 会被编译器合成出来，内部
 * 含有相关的vtbl的地址
 */
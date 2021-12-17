class X {
public:
    int i;
};

class A : public virtual X {
public:
    int j;
};

class B : public virtual X {
public:
    double d;
};

class C : public A, public B {
public:
    int k;
};


// 无法在编译期间决定出 pa->X::i 的位置
void foo(A* pa)
{
    pa->i = 1024;
}

int main()
{
    foo(new A);
    foo(new C);
}

// 通过在virtual base class中来安插一个指针来确定具体位置，下面是具体实现策略
void foo(A* pa)
{
    // __vbcX 表示编译器所产生的指针，指向 virtual base class X
    pa->__vbcX->i = 1024;
}

// 所以在构造的时候必须要明确，如果没有default constructor，那么编译器必须要合成一个，用来在运行期确定virtual base class
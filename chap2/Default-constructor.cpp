// 如果一个class没有任何constructor，但它内含有member object，后者由default constructor，
// 那么这个class的implict default constructor就是non-trival的，编译器要为该class合成一个
// defualt constructor

class Foo {
public:
    Foo();
	Foo(int);
};

class Bar {
public:
	Foo foo;
	char* str;
};

void foo_bar()
{
	Bar bar;
	char* str = bar.str;
	if (str) {

	}
}

// bar 的defualt constructor可能被这样合成
// 并不会对str做任何操作，这不是编译器的责任
// 这是程序员的责任
inline Bar::Bar()
{
	foo.Foo::Foo();
}

// 如果程序员写了str的初始化操作，那么编译器会扩张原有的
// defualt construtor

Bar::Bar()
{
	foo.Foo.Foo();
	// 程序员的成员初始化, 编译器在上面安插的代码
	str = 0;
}

class Dopey {
public:
	Dopey();
};

class Sneezy {
public:
	Sneezy();
	Sneezy(int);
};

class Bashful {
public:
	Bashful();
};

class Snow_White {
public:
	Dopey dopey;
	Sneezy sneezy;
	Bashful bashful;

private:
	int mumble;
};

// 程序员所写的 default constructor
Snow_White::Snow_White() : sneezy(1024)
{
	mumble = 2048;
}

// 被编译器扩张后的结果为
Snow_White::Snow_White() : sneezy(1024)
{
	// 插入member class object
	dopey.Dopey::Dopey();
	sneezy.Sneezy::Sneezy(1024);
	bashful.Bashful::Bashful();

	// explict user code
	mumble = 2048;
}

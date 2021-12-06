# FAQ
is it ok to return the local std::vector object?
https://stackoverflow.com/questions/22655059/why-is-it-ok-to-return-a-vector-from-a-function/22655120

# 1. default constructor
## 1.1 含有member class object 的类会被编译器合成 
## 1.2. 带有defalut constructor的base class
继承的 derived class 会被编译器合成一个default constructor
## 1.3 带有虚函数的class
编译器会为class合成相应的vtbl，以及对class object合成相应的vptr来内含相对应的vtbl
## 1.4 带有virtual base class 的 class
 
## 1.5 两种误解
任何class如果没有default construtor就会被合称一个 (只有上述四种情况)
编译器合成出来的default constructor会显示设定class内每一个data member的初始值(只合成只有成员对象，基类，其他所有的non-static data member 不会被合成)
# 2. copy constructor
显示的调用，参数传递，返回值返回都会调用copy constructor
## 2.1 default memberwise initialization
copy data member, 对于 member class object 则是递归调用copy constructor


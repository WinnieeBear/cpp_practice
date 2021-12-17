class X {
public:
	virtual void foo();
	~X();
	X(const X&);
};

X foobar()
{
	X xx;
	X* px = new X;
	
	// foo is a virtural function;
	xx.foo();
	px->foo();

	delete px;
	return xx;
}

// compiler will do the follwoing accordingly.
void foobar(X& _result)
{
	// construct _result, substitute the local xx
	_result.X::X();

	// X* px = new X;
	px = _new(sizeof(X));
	if (px != 0) {
		px->X::X();
	}

	// non-virtual function xx.foo();
	foo(&_result);

	// virtual fucntion px->foo();
	(*px->vtbl[2])(px);

	// virtual destructor function
	if (px != 0) {
		(*px->vtbl[1])(px);
		_delete(px);
	}

	// will not destruct local xx
	return;
}
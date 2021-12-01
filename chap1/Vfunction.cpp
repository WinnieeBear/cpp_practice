class X {
public:
	virtual void rotate() const;
};
class Z : public X {
public:
	virtual void rotate() const;
};

void rotate(X datum, const X* pointer, const X& reference)
{
	// (*pointer) will be the real type, 
	(*pointer).rotate();
	reference.rotate();

	datum.rotate();
}

int main()
{
	Z z;
	rotate(z, &z, z);
	// will call z's rotate(), z's rotate() and final the x's rotate
	return 0;
}
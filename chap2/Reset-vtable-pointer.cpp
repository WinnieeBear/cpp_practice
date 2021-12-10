class ZooAnimal {
public:
    ZooAnimal();
    virtual ~ZooAnimal();

    virtual void animate();
    virtual void draw();

private:
    // ...
};

class Bear : public ZooAnimal {
public:
    Bear();
    void animate();
    void draw();
    virtual void dance();

private:
    // ...
};

// it's OK
Bear yogi;
Bear winnie = yogi;

// will be sliced
ZooAnimal franny = yogi;

void draw(ZooAnimal& zoey)
{
    zoey.draw();
}

void foo()
{
    // franny' vptr point to ZooAnimal' vitrual table not Bear's vitual table
    // so the copy construct will not copy the vptr directly from Bear, it's explicilty set
    // to the ZooAnimal's vptr
    ZooAnimal franny = yogi;
    draw(yogi);
    draw(franny);
}


// vitrual base class suboject will break the bitwise copy sematics
class Raccoon : public virtual ZooAnimal {
public:
    Raccoon();
    Raccoon(int val);
private:
    // ...
};

class RedPanda : public Raccoon {
public:
    RedPanda();
    RedPanda(int val);
private:
    // ...
};

// bitwise is enough
Raccoon rocky;
Raccoon little_critter = rocky;

// simple bitwise is not enough
// need explicitly set the virtual base class pointer/offset
RedPanda little_red;
Raccoon little_critter = little_red;

// we can't know ptr point to where, Raccoon or ZooAnimail?
// so bitwise copy is not enough
Raccoon* ptr;
Raccoon little_critter = *ptr;
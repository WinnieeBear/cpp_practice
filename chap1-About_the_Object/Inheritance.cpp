// single inheritance
class Libray_materials { ... };
class Book : public Libray_materials { ... };
class Rental_book : public Book { ... };

// multi inheritance
class iostream : public istream, pulbic ostream { ... };

// virtual inheritance
class istream : virtual public ios { ... };
class ostream : virtual public ios { ... };

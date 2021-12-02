class String {
public:
    // non-explict copy constructor
private:
    char* str;
    int len;
};

String noun("book");
String verb = noun;

// defalut copy constructor will worked like:
verb.str = noun.str;
verb.len = noun.len;

class Word {
public:
    // non-explict copy constructor
private:
    int _occurs;
    // Word 的defalut copy construtor会递归调用 String的copy constructor
    String _word;
};

/*
 * 是否能够合成一个copy constructor的关键是判断class是否是bitwise copy的
 */

// 以下声明显示bitwise copy
class Word {
public:
    Word(const char*);
    ~Word();

private:
    int cnt;
    char* str;
};

Word noun("book");

void foo()
{
    Word verb = noun;
}

// 以下声明未展现bitwise copy
class String {
public:
    String(const char*);
    String(const String& s);
    ~String();

private:
    char* str;
    int cnt;
};

class Word {
public:
    Word(String&);
    ~Word();

private:
    String str;
    int cnt;
};

// 这个时候编译器必须要合成一个
inline Word::Word(const Word& word)
{
    str.String::String(word);
    cnt = word.cnt;
}

// 同样的什么时候class不展现出来bitwise copy呢
// 1. 含有 member objcet，并且后者有个copy construcotr
// 2. 继承一个 base class， 含有一个 copy constructor
// 3. 含有虚函数
// 4. 有 virtual base class
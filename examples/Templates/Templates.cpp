// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
using namespace std;

// a simple class template named Pair
template <class T1, class T2>
class Pair {
public:
    Pair(T1 firstValue, T2 secondValue) : f(firstValue), s(secondValue) {}
    T1 first() const { return f; }
    T2 second() const { return s; }
private:
    T1 f;
    T2 s;
};

struct Foo {
    int x, y;
};

template <typename T>
concept comparable = requires (T a, T b) {
    { a > b } -> same_as<bool>;
};


// a simple function template named max
auto Max(comparable auto a, comparable auto b) {
    return a > b ? a : b;
}
auto Max(const Foo& a, const Foo& b) {
    return a.x + a.y > b.x + b.y ? a : b;
}

int main()
{
    int i = 1;
    auto s = "hello"s;
    Pair p(i, s);

    auto r1 = Max (1, 2);
    auto r2 = Max ("hello"s, "world"s);
    Foo f1{ 1, 2 };
    Foo f2{ 3, 4 };
    auto f = Max(f1, f2);

}




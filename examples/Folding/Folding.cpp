// Folding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template<typename... Args>
auto sum(Args... args)
{
    return (args + ...);
}



int main()
{
    cout << sum(1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u) << endl;
}

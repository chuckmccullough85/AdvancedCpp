// DIP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <list>
#include <numeric>

using namespace std;

//create a circle class with area calculation
class Circle
{
public:
    Circle(float radius) : radius_(radius) {}
    float area() const { return radius_ * radius_ * 3.1415926f; }
private:
    float radius_;
};

void print(const Circle& c)
{
    cout << c.area() << endl;
}
float area(float total, const Circle& c)
{
    return total + c.area();
}   

int main()
{
    std::list<Circle> circles = { Circle(1.0f), Circle(2.0f), Circle(3.0f), Circle(5.0f)};
    
    for_each(circles.begin(), circles.end(), print);
    float total = accumulate(circles.begin(), circles.end(), 0.0f, area);

    cout << "total area: " << total << endl;
}


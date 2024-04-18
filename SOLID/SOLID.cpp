// SOLID.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class Ellipse
{
private:
    double xr;
    double yr;

public:
    double getArea()
    {
        return 3.14 * xr * yr;
    }
    virtual void setXr(double xr)
    {
        this->xr = xr;
    }
    virtual void setYr(double yr)
    {
        this->yr = yr;
    }
    double getXr()
    {
        return xr;
    }
    double getYr()
    {
        return yr;
    }
};

class Circle : public Ellipse
{
public:
    void setXr(double xr) override
    {
        Ellipse::setXr(xr);
        Ellipse::setYr(xr);
    }
    void setYr(double yr) override
    {
        Ellipse::setYr(yr);
        Ellipse::setXr(yr);
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

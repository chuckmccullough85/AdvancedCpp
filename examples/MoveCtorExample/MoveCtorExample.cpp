// MoveCtorExample.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;


class Moveable2
{
    char* data;
};

class Moveable
{
    char* data;
public:
	Moveable()
	{
        data = new char[100];
		cout << "Default constructor called." << endl;
	}
    Moveable(const Moveable2& m)
    {
        data = new char[100];
        cout << "Copy constructor called." << endl;
    }

	Moveable(const Moveable& m)
	{
        data = new char[100];
        memcpy(data, m.data, 100);
        cout << "Copy constructor called." << endl;
    }
	Moveable(Moveable&& m) noexcept
	{
        data = m.data;
        m.data = nullptr;
        cout << "Move constructor called." << endl;
    }
	Moveable& operator=(const Moveable& m)
	{
        cout << "Assignment operator called." << endl;
        return *this;
    }
	Moveable& operator=(Moveable&& m) noexcept
	{
        cout << "Move assignment operator called." << endl;
        return *this;
    }
	~Moveable() noexcept
	{
        if (data != nullptr)
            delete[] data;
        cout << "Destructor called." << endl;
    }
};


Moveable2 GetTemp()
{
    Moveable2 tmp;
    cout << "Resource from " << __func__ << " is at " << &tmp << endl;
    return tmp;
}
void ShowTemp(Moveable obj)
{
    cout << "Resource from " << __func__ << " is at " << &obj << endl;
}

int main()
{
    auto obj(GetTemp());

    cout << "Resource from " << __func__ << " is at " << &obj << endl;
    ShowTemp(obj);

    obj = GetTemp();

    ShowTemp(GetTemp());

    ShowTemp(obj);

    return 0;
}

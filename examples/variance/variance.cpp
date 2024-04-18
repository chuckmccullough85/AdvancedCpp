// variance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <memory>
#include <functional>

using namespace std;

class Animal
{};
class Dog : public Animal
{};
class Cat : public Animal
{};

void func(list<Animal*> animals)
{
    animals.push_back(new Cat());
}

void cfunc(const Cat* cat)
{}
void afunc(const Animal* animal)
{}

int main()
{
    list<Dog*> dogs;
    list<Animal*> animals;
    dogs.push_back(new Dog());
    animals.push_back(new Dog());
    //func(dogs);
    func(animals);

    function<void(const Cat*)> f;
    f = afunc;
    f = cfunc;
    function<void(Animal*)> g;
    g = afunc;
    //g = cfunc;

    unique_ptr<Animal> a(new Dog());
}


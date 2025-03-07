// ObjectFactory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Factory.h"
using namespace std;
using namespace factory;

class Animal
{
    public:
        Animal() { cout << "default ctor\n"; }
        Animal(string name) : name(name) { cout << name << " ctor\n"; }  
        virtual ~Animal() = default;
        virtual void Speak() { cout << "I am " << name << endl; }
        string name;
};
class Dog : public Animal
{
    public:
        using Animal::Animal;
};
class Cat : public Animal
{};


int demo()
{
    
    auto& factory = ObjectFactory<shared_ptr<Animal>>::Instance();
    bool r = factory.Register ("dog"s, 
        [](const string& name) { return make_shared<Dog>(name); });

    auto dog = factory.Create("dog"s);
    dog->Speak();

    return 0;
}


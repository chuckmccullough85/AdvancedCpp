#pragma once
#include <string>
#include <list>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Payable.h"


namespace payroll {

    class Organization : public Payable
    {
    public:
        Organization() = default;
        Organization(std::string name) : name(name) {}

        void setName(std::string name) { this->name = name; }
        std::string getName() const { return name; }
        void addEmployee(Payable* employee) { employees.push_back(employee); }
        std::list<Payable*> getEmployees() const { return employees; }

        double pay() override
        {
            //return std::accumulate(employees.begin(), employees.end(), 0.0, 
            //    [](double t, Payable* p) {return t + p->pay(); });
            double total = 0.0;
            for_each(employees.begin(), employees.end(), [&total](Payable* p) {
                total += p->pay();
                });
            return total;
        }
    private:
        std::string name;
        std::list<Payable*> employees;
    };
}


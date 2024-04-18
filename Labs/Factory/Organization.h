#pragma once
#include <string>
#include <list>
#include <numeric>
#include "Payable.h"


namespace payroll {
    class Organization
    {
    public:
        Organization() = default;
        Organization(std::string name) : name(name) {}

        void setName(std::string name) { this->name = name; }
        std::string getName() const { return name; }
        void addEmployee(Payable* employee) { employees.push_back(employee); }
        std::list<Payable*> getEmployees() const { return employees; }

        double pay() const
        {
            return std::accumulate(employees.begin(), employees.end(), 0.0, 
                [](double t, Payable* p) {return t + p->pay(); });
        }
    private:
        std::string name;
        std::list<Payable*> employees;
    };
}


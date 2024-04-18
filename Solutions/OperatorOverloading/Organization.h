#pragma once
#include <string>
#include <list>
#include <numeric>
#include <iostream>
#include <iomanip>
#include "Payable.h"


namespace payroll {

    class RunningAverage
    {
    public:
        double operator()(double amount, Payable* p)
        {
            auto net = p->pay();
            total += net;
            count++;
            std::cout << std::setw(10) << std::fixed << std::setprecision(2) 
                << "$" << net << "\t$" << total << "\t$" << total / count << std::endl;
            return amount + net;
        }
    private:
        double total = 0;
        int count = 0;
    };

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
            RunningAverage averager;
            return std::accumulate(employees.begin(), employees.end(), 0.0, 
                averager);
        }
    private:
        std::string name;
        std::list<Payable*> employees;
    };
}


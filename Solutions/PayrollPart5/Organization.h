#pragma once
#include <string>
#include <list>
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
            double totalPay = 0;
            for (auto employee : employees)
            {
                totalPay += employee->pay();
            }
            return totalPay;
        }
    private:

        std::string name;
        std::list<Payable*> employees;
    };        
    
 }


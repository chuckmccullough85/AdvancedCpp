#pragma once
#include <string>
#include <list>
#include "HumanResource.h"


namespace payroll {
    class Organization
    {
    public:
        Organization() = default;
        Organization(std::string name) : name(name) {}

        void setName(std::string name) { this->name = name; }
        std::string getName() const { return name; }
        void addEmployee(HumanResource* employee) { employees.push_back(employee); }
        std::list<HumanResource*> getEmployees() const { return employees; }

        double pay() const
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
        std::list<HumanResource*> employees;
    };
}


#pragma once
#include <string>
#include <list>
#include "Employee.h"
#include "PayrollCalculator.h"

namespace payroll {
    class Organization
    {
    public:
        Organization() = default;
        Organization(std::string name) : name(name) {}

        void setName(std::string name) { this->name = name; }
        std::string getName() const { return name; }
        void addEmployee(Employee* employee) { employees.push_back(employee); }
        std::list<Employee*> getEmployees() const { return employees; }

        double pay() const
        {
            double totalPay = 0;
            for (auto employee : employees)
            {
                totalPay += PayrollCalculator::calculatePay(employee);
            }
            return totalPay;
        }
    private:
        std::string name;
        std::list<Employee*> employees;
    };
}


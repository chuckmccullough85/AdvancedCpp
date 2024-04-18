#pragma once
#include <string>
#include <list>
#include "Employee.h"

namespace payroll {
    class Organization
    {
    public:
        Organization() = default;
        Organization(std::string name) : name(name) {}

        void setName(std::string name) { this->name = name; }
        [[nodiscard]]
        std::string getName() const { return name; }
        void addEmployee(Employee* employee) { employees.push_back(employee); }
        [[nodiscard]]
       std::list<Employee*> getEmployees() const { return employees; }

        double pay() const
        {
            double totalPay = 0;
            for (auto employee : employees)
            {
                double p = 0;
                double taxes = 0;
                switch (employee->getId()[0])
                {
                case 'S':
                    p = employee->getPayRate();
                    taxes = p * 0.3;
                    break;
                case 'C':
                    p = employee->getPayRate() * 40;
                    taxes = 0;
                    break;
                case 'H':
                    p = employee->getPayRate() * 40;
                    taxes = p * 0.3;
                    break;

                }
                totalPay += p - taxes;
                employee->setYtdDeductions(taxes + employee->getYtdDeductions());
                employee->setYtdPay(p + employee->getYtdPay());
            }
            return totalPay;
        }
    private:
        std::string name;
        std::list<Employee*> employees;
    };
}


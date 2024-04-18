#pragma once
#include <string>
#include <list>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <memory>
#include "Payable.h"


namespace payroll {
    using PayableSptr = std::shared_ptr<Payable>;
    using PayableWptr = std::weak_ptr<Payable>;
    class Organization : public Payable
    {
    public:
        Organization() = default;
        Organization(std::string name) : name(name) {}

        void setName(std::string name) { this->name = name; }
        std::string getName() const { return name; }
        void addPayable(PayableWptr employee) { employees.push_back(employee); }
        const auto& getPayables() const { return employees; }

        double pay() override
        {
            //return std::accumulate(employees.begin(), employees.end(), 0.0, 
            //    [](double t, auto p) {return t + p->pay(); });
            double total = 0.0;
            for_each(employees.begin(), employees.end(), [&](auto p) {
                if (auto sp = p.lock())
                    total += sp->pay();
                // else remove from list
                });
            return total;
        }
    private:
        std::string name;
        std::list<PayableWptr> employees;
    };
}


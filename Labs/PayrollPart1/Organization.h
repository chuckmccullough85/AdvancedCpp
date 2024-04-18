#pragma once
#include <string>
#include <list>
#include "Employee.h"

namespace payroll {
    class Organization
    {
    public:
    private:
        std::string name;
        std::list<Employee*> employees;
    };
}


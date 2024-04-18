#pragma once
#include <string>

namespace payroll
{
    class Employee
    {
    public:

    private:
        std::string name;
        std::string id;
        double payRate;
        double ytdPay=0;
        double ytdDeductions=0;
    };
}
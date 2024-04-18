#pragma once
#include <string>

namespace payroll
{
    class Employee
    {
    public:
        Employee() = default;
        Employee(std::string name, std::string id, double payRate)
            : name(name), id(id), payRate(payRate)
        {}

        void setName(std::string name) { this->name = name; }
        std::string getName() const { return name; }
        void setId(std::string id) { this->id = id; }
        std::string getId() const { return id; }
        void setPayRate(double payRate) { this->payRate = payRate; }
        double getPayRate() const { return payRate; }
        void setYtdPay(double p) { this->ytdPay = p; }
        double getYtdPay() const { return ytdPay; }
        void setYtdDeductions(double d) { this->ytdDeductions = d; }
        double getYtdDeductions() const { return ytdDeductions; }

    private:
        std::string name;
        std::string id;
        double payRate;
        double ytdPay=0;
        double ytdDeductions=0;
    };
}
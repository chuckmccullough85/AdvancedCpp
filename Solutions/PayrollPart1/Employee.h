#pragma once
#include <string>

namespace payroll
{
    class Employee
    {
    public:
        Employee() = default;
        Employee(const std::string& name, const std::string& id, double payRate)
            : name(name), id(id), payRate(payRate)
        {}

        void setName(const std::string& name) { this->name = name; }
        [[nodiscard]]
        std::string getName() const { return name; }
        void setId(std::string id) { this->id = id; }
        [[nodiscard]]
        std::string getId() const { return id; }
        void setPayRate(double payRate) { this->payRate = payRate; }
        [[nodiscard]]
        double getPayRate() const { return payRate; }
        void setYtdPay(double p) { this->ytdPay = p; }
        [[nodiscard]]
        double getYtdPay() const { return ytdPay; }
        void setYtdDeductions(double d) { this->ytdDeductions = d; }
        [[nodiscard]]
        double getYtdDeductions() const { return ytdDeductions; }

    private:
        std::string name;
        std::string id;
        double payRate;
        double ytdPay=0;
        double ytdDeductions=0;
    };
}
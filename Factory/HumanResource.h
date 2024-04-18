#pragma once

#include <string>
#include "Payable.h"

namespace payroll
{
    class HumanResource : public Payable
    {
    public:
        HumanResource() = default;
        HumanResource(std::string id, std::string name="", double payRate=0)
            :  id(id), name(name), payRate(payRate)
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

        virtual double pay() = 0;

    private:
        std::string name;
        std::string id;
        double payRate;
        double ytdPay=0;
        double ytdDeductions=0;
    };

    template <typename T, typename B>
    B* makeResource(const std::string& id)
    {
        return new T(id);
    }
}
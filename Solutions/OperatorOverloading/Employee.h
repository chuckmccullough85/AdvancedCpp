#pragma once
#include <string>
#include "HumanResource.h"
#include "Factory.h"

namespace payroll
{
    class Employee : public HumanResource
    {
    public:
        using HumanResource::HumanResource;

        double pay() override
        {
            auto pay = getPayRate();
            auto taxes = pay * 0.3;
            setYtdDeductions(taxes + getYtdDeductions());
            setYtdPay(pay + getYtdPay());
            return pay - taxes;
        }

    private:
        static bool m_Registered;
    };
 
}
#pragma once
#include "HumanResource.h"

namespace payroll
{
    class HourlyEmployee : public HumanResource
    {
    public:
        using HumanResource::HumanResource;
        double pay() override
        {
            auto pay = getPayRate() * 40;
            auto taxes = pay * 0.3;
            setYtdDeductions(taxes + getYtdDeductions());
            setYtdPay(pay + getYtdPay());
            return pay - taxes;
        }
    private:
        static bool m_Registered;
    };
}
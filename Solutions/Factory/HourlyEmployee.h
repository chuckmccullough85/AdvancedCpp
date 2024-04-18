#pragma once
#include <string>
#include "HumanResource.h"
#include "Factory.h"

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
        static bool m_registered;
    };

    inline bool HourlyEmployee::m_registered = factory::ObjectFactory<HumanResource*>::Instance()
        .Register("H", [](const std::string& id) { return new HourlyEmployee(id); });
}
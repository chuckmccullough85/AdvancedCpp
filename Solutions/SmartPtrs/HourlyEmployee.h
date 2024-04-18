#pragma once
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
        static bool m_Registered;
    };
    inline bool HourlyEmployee::m_Registered = factory::ObjectFactory<HumanResourceSPtr>::Instance()
        .Register("H", [](const std::string& id) { return HumanResourceSPtr(new HourlyEmployee(id)); });
}
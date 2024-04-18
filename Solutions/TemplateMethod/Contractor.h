#pragma once

#include "HumanResource.h"
#include "Factory.h"

namespace payroll
{
    class Contractor : public HumanResource
    {
    public:
        using HumanResource::HumanResource;

        double pay() override
        {
            auto pay = getPayRate() * 40;
            setYtdPay(pay + getYtdPay());
            return pay;
        }

    private:
        static bool m_Registered;
    };
    inline bool Contractor::m_Registered = factory::ObjectFactory<HumanResourceSPtr>::Instance()
        .Register("C", [](const std::string& id) { return HumanResourceSPtr(new Contractor(id)); });

}
#pragma once
#include <string>
#include <stdexcept>
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
    protected:
        void validate() const override
        {
            if (getId().empty())
                throw std::invalid_argument("Employee id cannot be empty");
            if (getName().empty())
                throw std::invalid_argument("Employee name cannot be empty");
        }
    private:
        static bool m_Registered;
    };

    inline bool Employee::m_Registered = factory::ObjectFactory<HumanResourceSPtr>::Instance()
        .Register("E", [](const std::string& id) { return HumanResourceSPtr(new Employee(id)); });

}
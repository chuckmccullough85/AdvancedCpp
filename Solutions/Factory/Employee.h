#pragma once
#include <string>
#include "HumanResource.h"
#include "Factory.h"

namespace payroll
{
   
    using namespace std;

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
        static bool m_registered;
    };
 
    inline bool Employee::m_registered = factory::ObjectFactory<HumanResource*>::Instance()
        .Register("E", [](const std::string& id) { return new Employee(id); });

}
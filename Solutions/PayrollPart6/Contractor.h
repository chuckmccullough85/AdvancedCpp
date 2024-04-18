#pragma once

#include "HumanResource.h"

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
    };
}
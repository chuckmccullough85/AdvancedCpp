#pragma once

#include "HumanResource.h"

namespace payroll
{
    class Vendor : public HumanResource
    {
    public:
        using HumanResource::HumanResource;

        double pay() override
        {
            return 1000;
        }

    private:
    };
}
#pragma once

#include "Payable.h"

namespace payroll
{
    class Vendor : public Payable
    {
    public:

        double pay() override
        {
            return 1000;
        }

    private:
    };
}
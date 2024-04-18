#pragma once

namespace payroll
{
    class Payable
    {
    public:
        virtual ~Payable() = default;
        virtual double pay() = 0;
    };
}
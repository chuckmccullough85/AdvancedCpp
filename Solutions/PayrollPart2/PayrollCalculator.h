#pragma once

#include "Employee.h"

namespace payroll
{
    class PayrollCalculator
    {
    public:

        static double calculatePay(Employee* employee)
        {
            double pay = 0;
            double taxes = 0;
            switch (employee->getId()[0])
            {
            case 'S':
                pay = employee->getPayRate();
                taxes = pay * 0.3;
                break;
            case 'C':
                pay = employee->getPayRate() * 40;
                taxes = 0;
                break;
            case 'H':
                pay = employee->getPayRate() * 40;
                taxes = pay * 0.3;
                break;
            }
            employee->setYtdDeductions(taxes + employee->getYtdDeductions());
            employee->setYtdPay(pay + employee->getYtdPay());
            return pay - taxes;
        }
    };
}
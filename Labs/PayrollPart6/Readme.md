## Overview
Use DIP to calculate payroll for an organization.

| | |
| --------- | --------------------------- |
| Exercise Folder | PayrollPart6 |
| Builds On | PayrollPart5 |
| Time to complete | 20 minutes

Get rid of the loop in *Organization pay*.

### Steps
1. Add an include for `<numeric>` to *Organization.h*
1. Add a private member function to *Organization* to return the result of paying 1 payable `double payone(double total, Payable* p);`
1. Change *pay* to use `std::accumulate` to calculate the total payable amount


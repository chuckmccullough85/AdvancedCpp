## Overview
Apply ISP to the Payroll application.

| | |
| --------- | --------------------------- |
| Exercise Folder | PayrollPart5 |
| Builds On | PayrollPart4 |
| Time to complete | 30 minutes

Let's clean up the fat interface used by *Organization*.

### Steps
1. Create a new class named *Payable* in the *Payroll* namespace. 
   1. Add a single method named `virtual double pay() = 0;`
1. Update *HumanResource* to inherit from *Payable*.
1. Update *Vendor* to inherit from *Payable*.
1. Update *Organization* to use *Payable* instead of *HumanResource*.

The new design is much cleaner. *Organization* is no longer coupled to *HumanResource* and *Vendor* is not human!

We will also use this approach to implement even more features later!


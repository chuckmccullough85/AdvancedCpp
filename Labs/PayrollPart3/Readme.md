## Overview
*PayrollCalculator* will never be **closed** for modification.  It will always need to be modified when a new employee type is added.  This is a violation of the Open/Closed Principle.

| | |
| --------- | --------------------------- |
| Exercise Folder | PayrollPart3 |
| Builds On | PayrollPart2 |
| Time to complete | 30 minutes


### Steps
1. Create a new class named *HumanResource*.
1. Copy the methods and fields from *Employee* to *HumanResource*.
1. Add an additional method to *HumanResource* `virtual double pay() = 0;`.
1. Change the *Employee* class to inherit from *HumanResource*.
    1. override the `pay()` method and calculate pay for salaried employees. Increment the ytd fields.
1. Create a new class named *HourlyEmployee* that inherits from *HumanResource*.
    1. override the `pay()` method and calculate pay for the hourly employee. Increment the ytd fields.
1. Create a new class named *Contractor* that inherits from *HumanResource*.
    1. override the `pay()` method and calculate pay for the contractor. Increment the ytd fields.
1. Modify *Organization* by replacing all *Employee* references with *HumanResource*.  Change the `pay()` method to iterate over the *HumanResource* collection and call the `pay()` method on each *HumanResource*.
1. Delete the *PayrollCalculator* class.




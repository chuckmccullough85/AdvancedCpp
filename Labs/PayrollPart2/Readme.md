## Overview
Can we fix the SRP problems?

| | |
| --------- | --------------------------- |
| Exercise Folder | PayrollPart2 |
| Builds On | PayrollPart1 |
| Time to complete | 30 minutes


*Organizaton* has 2 distinct responsibilities:
* Calculate the pay for the employees
* Hire/Fire employees

Let's create a separate class to calculate the pay for the employees.

### Steps
1. Create a new class called `PayrollCalculator`
1. Move the `pay` method from `Organization` to `PayrollCalculator` and rename it to `calculatePay`
1. Update the `Organization` class to use the `PayrollCalculator` class


Did we fix the SRP problems?  At what cost?
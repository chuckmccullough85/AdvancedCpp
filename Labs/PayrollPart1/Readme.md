## Overview
Let's get started with simple classes to calculate payroll.

| | |
| --------- | --------------------------- |
| Exercise Folder | PayrollPart1 |
| Builds On |  |
| Time to complete | 30 minutes

A client requests that we design and build a payroll application.  To get started, we will create an *Employee* class that represents simple employee information.

Next, we will create an *Organization* class that represents the company or agency that employs the employees.  The *Organization* class will contain a collection of *Employee* objects.

The employee's ID indicates the employment classification.  The ID is a string of numbers and characters.  If the first character is a 'S', the employee is a salaried employee.  If the first character is an 'H', the employee is an hourly employee.  If the first character is a 'C', the employee is a contractor.  The remaining characters are the employee's ID number.

> Note: This solution contains several design flaws!  We will address these flaws in the next exercises.

These classes should be in `namespace payroll`.

### Steps
1. Create a new project named PayrollPart1.
1. Create a new class named `Employee`.
1. Add the following properties to the Employee class:
    * Name
    * ID
    * PayRate
    * YtdPay
    * YtdDeductions
1. Add a constructor that accepts the employee's name, ID, and salary.
1. Add getters and setters for the properties.
1. Create a new class named `Organization`.
1. The Organization class should have a name and a collection of employees.
1. Add a constructor that accepts the organization's name.
1. Add a method named `AddEmployee` that accepts an employee pointer and adds it to the collection.
1. Add another method named *pay*.  This method should iterate through the collection of employees and pay them.  
1. Use a switch-case statement to determine the employee's type and calculate the pay accordingly.
    1. For salaried employees, the tax deduction is 30% of the pay.
    1. For hourly employees, the pay rate is hourly.  The total pay is 40 hours times the pay rate. The tax deduction is 30% of the pay.
    1. For contractors, the tax deduction is 0% of the pay. The rate is an hourly rate.  The total pay is 40 hours times the pay rate.
1. Increment the employee's YtdPay & YtdDeductions properties.
1. Return the net total of all employee's pay.
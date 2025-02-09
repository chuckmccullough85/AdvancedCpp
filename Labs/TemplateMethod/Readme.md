## Overview
Add validation to *HumanResource*

| | |
| --------- | --------------------------- |
| Exercise Folder | TemplateMethod |
| Builds On | SmartPtrs |
| Time to complete | 20 minutes

This is a simple lab to demonstrate *template method*.  The actual validation rules are not important.  The important thing is to see how the template method pattern can be used.

### Steps
1. Add a new protected method to *HumanResource* called *validate*. Implement a do-nothing version of the method so that we don't have to implement it everywhere.
```cpp
virtual void validate() const {}
```
2. Change the setters in *HumanResource* to call *validate*, *after* setting the value.
3. Override *validate* in *Employee* to implement the validation rules.  Keep it simple.  Throw an exception if the validation fails.
1. In main, create an employee and set one of the properties to an invalid value.  Run the program and verify that the exception is thrown.

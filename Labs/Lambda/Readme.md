## Overview
Use lambda expressions to simplify the code.

| | |
| --------- | --------------------------- |
| Exercise Folder | Lambda |
| Builds On | OperatorOverloading |
| Time to complete | 20 minutes

Let's change our code to use lambda expressions.

### Organization

1. The customer changed their minds about the running averages.
1. Replace the functor in *Organization pay* with a lambda expression.
    1. Challenge: instead of *accumulate*, use *for_each*.
    1. This will require a local variable to hold the total and a capture to update it in the lambda.


### Employee, Contractor, and HourlyEmployee

Update the registrations for *Employee*, *Contractor* , and *HourlyEmployee* to use a lambda instead of the common template.



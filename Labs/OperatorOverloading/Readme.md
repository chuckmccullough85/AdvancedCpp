## Overview
Utlize a functor and explore operators.

| | |
| --------- | --------------------------- |
| Exercise Folder | OperatorOverload |
| Builds On | Factory |
| Time to complete | 30 minutes


First, let's creat a functor that can be used to calculate a running average.  You might be wondering why we would want that.  Well, it's not my place to question the customer and that's what they want.  So, let's do it.

The customer wants to see output on the console showing the current net pay to a payable along with the running total and average.  The current function could handle each pay net and the running total, but it doesn't have a good play to store the running average.  So, let's create a functor that can be used to calculate the running average.

### Functor
1. Create a new class called `RunningAverage` (you can put it in the same header as `Organization` if you want).
1. Add a private member variable called `total` of type `double`.
1. Add a private member variable called `count` of type `int`.
1. Add a public member function called `operator()` that takes a `double` and `payable*` and returns a `double`
1. Use the instance variables to keep up with the total and count.
1. Use `cout` to output the current net pay, running total, and running average.

### Conversion Operators

Because `HumanResource` has a constructor that *can* take a single argument (the id the of the person), it can be used as a conversion operator.  To demonstrate, create a simple function prior to main that accepts an `Employee` and outputs the id of the person.

From main(), call the function passing in just a string containing the id.  The compiler will convert the string to an `Employee` and then call the function.

```cpp




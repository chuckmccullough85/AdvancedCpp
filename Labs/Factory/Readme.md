## Overview
Create a simple factory to create Human Resources objects.

| | |
| --------- | --------------------------- |
| Exercise Folder | Factory |
| Builds On | PayrollPart6 |
| Time to complete | 60 minutes

In this lab, we will demonstrate a couple of design patterns:
  * Singleton
  * Factory

While this lab picks up where the previous lab left off, start with the code in this folder to get a head start.

### Overview:

*Factory.h* contains a class that creates Human Resource objects based on the first letter in the ID.

### Steps
The factory does not assume anything about HumanResource objects except that the create methods accept an Id as a parameter. The factory uses the first letter of the Id to determine which type of object to create.

This could be the case for many different types of objects. For example, if you were creating inventory products, you might have a factory that creates different types of products based on the first letter of the product id.  The factory can easily be generalized to create any type of object.

1. Open the solution in Visual Studio.
1. Open *Factory.h* and review the code.
1. Rename *HrFactory* to *ObjectFactory*.
1. Change the class to a template.  The template parameter will be the base class of the objects that the factory creates.
1. *Lift* the class from *HumanResource* to a template type
1. Modify *Create* to use an **init-if** statement instead of the separate iterator init statement and if statement.

Next, let's make the class a *Singleton*. This will ensure that there is only one instance of the class.
1. Make the default constructor private.
1. Create a static method that returns a reference to a single instance of the class.
1. Declare a static local variable of type HrFactory in the static method and return that object.

### The concrete classes
Employee, Contractor, and HourlyEmployee have been changed just a bit since the last lab.  The constructors have default values for name and pay rate.  This allows the factory to create objects without having to pass in those values.

In *Payroll.cpp*, prior to main, there are 3 make functions to create the objects.  These functions are registered with the factory.  The factory uses these functions to create the objects.

All three of these functions are nearly identical.  They differ only in the type of object that they create.  This is a good candidate for a template function.

1. Choose one of the make functions and make it a template function. Put it in *HumanResource.h* and delete the others.
1. Modify the register functions to use the template function.

### Self Registration

Having to explicitly register the concrete classes with the factory still requires us to maintain code that registers the classes. This will be an **Open/Closed Principle** violation if we add new types to the project.  We can use a technique called *Self Registration* to eliminate the need to maintain code that registers the classes.

1. Add a static bool named m_registered to each of the concrete classes.
1. In the cpp file for each class, add a static initializer that registers the class maker with the factory.
1. Remove the register functions from *Payroll.cpp*.

This can be problematic in that the classes have the extra resposibility of registering themselves (SRP violation). There might also be issues with the initialization order. In some scenarios, this technique is a good solution, while in other scenarios it is not.


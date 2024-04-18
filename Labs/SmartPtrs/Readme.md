## Overview
Change out application to utilize smart pointers.

| | |
| --------- | --------------------------- |
| Exercise Folder | SmartPtrs |
| Builds On | Composite |
| Time to complete | 60 minutes

### Design Considerations

The critical design question is who is ultimately responsible for creating and deleting the objects.  Since the payables are data-driven, we will need to allocate them dynamically (**new**, heap).  Payables will get hired by zero or more organizations.  Organzations will come and go as well.  A payable should be **delete**d when it is no longer employed by any organization.  

### Options

The most *similar to the real-world* options is to have a new abstraction that is the master list of payables.  When payables are added to our system, they go into this list, and when they leave the system, they are removed from the list and deleted.  In the real-world, people enter and leave the workforce.  While in the workforce, they can work for multiple organizations.  When they leave the workforce, they are no longer employed by any organization.  

* option 1 - have a master list of payables as **unique_ptrs**.  When a payable is hired, we will provide the Organization a raw pointer - same as we currently do.  This is a reasonable approach as there is no problem with having a pointer if the module has no responsibility for it.  However, if a payable leaves the workforce, we will need to remove it from all the organizations as well.  We don't have that information now, so we would need to add more complexity to track all the organizations that a payable is employed by.
* option 2 - Just hire **shared_ptrs** with no master list.  Last one out turns off the lights.  This is simple enough, but no good way to support a payable leaving the workforce.
* option 3 - have a master list of payables as **shared_ptrs**.  Organizations will hire **weak_ptrs**.  The organization, when paying, will need to check if the payable still exists and remove it from its list if it doesn't.  With this approach, the code that manages the workforce doesn't need to worry about the organizations.  This approach seems less coupled (better SRP).  Let's go with this one.

### Implementation
1. Define a type alias for HumanResource Shared pointers for convenience.  I like to do these in the header file for the class that owns the type. A the end of *HumanResource.h*, add the following:
```cpp
using HumanResourceSPtr = std::shared_ptr<HumanResource>;
```
You will need to add the appropriate include for **shared_ptr**.

2. In *Payroll.cpp* (main), change the type of the factory from *HumanResource* to *HumanResourceSPtr*.
```cpp
auto& factory = ObjectFactory<HumanResourceSPtr>::Instance();
```

3. *Organization*s hold payables, and the factory is creating *HumanResource* shared pointers.  Smart pointers are **Covariant**, so a HumanResource pointer is substituable for a payable smart pointer.  Define a type alias for payable weak pointers at the top of *Organization.h* (or at the end of *Payable.h*), your choice.
1. Change the *Payable\** to *PayableWPtr* in the *Organization* class. 
1. Let's take this opportunity to adjust the design a bit to reflect the new requirements.  Use refactoring to change the name of *addEmployee* to *addPayable*.  Change *getEmployees* to *getPayables* and update the return type to a const reference.
```cpp
const auto& getPayables() const { return employees; }
```
6. In *pay*, you will need to **lock** the weak pointer before calling pay.  Don't worry about removing the dead payables from the list.  That can be a future task.
1. Lastly, update the creators that register the payable concrete classes.  For instance, employee:
```cpp
inline bool Employee::m_Registered = factory::ObjectFactory<HumanResourceSPtr>::Instance()
    .Register("E", [](const std::string& id) { return HumanResourceSPtr(new Employee(id)); });
```

### Challenge
In *main*, create a nested scope that encloses some of the payables.  Pay our top organization after the nested scope.  You should see a reduction in pay as some of the payables have left the workforce.
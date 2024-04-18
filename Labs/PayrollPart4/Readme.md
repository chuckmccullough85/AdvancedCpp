## Overview
Now, a new requirement!  That inheritance is going to pay off!

| | |
| --------- | --------------------------- |
| Exercise Folder | PayrollPart4 |
| Builds On | PayrollPart3 |
| Time to complete | 30 minutes


### New Requirement!
Let's check out our design change with a new requirement:

> The customer requests that we also process payments for vendors.  The vendor will have a name and Id, but no other information.  The vendor will be paid a flat fee of $1000 per pay cycle.

The easiest way to implement this is to create a new class named *Vendor* that inherits from *HumanResource*.  Override the `pay()` method and calculate the pay for the vendor.

---


Is a *Vendor* really human?  A vendor could be a company with many employees.  The *Vendor* inherits properties from *HumanResource* that don't make sense for a *Vendor*.  For example, a *Vendor* has a name, but not a first name or last name.  A *Vendor* has an Id, but not the format used by the organization.  It also doesn't report YTD values nor use them.

Is it substitutable?  Technically yes, but not really.  Algorithms that expect the vendor's id to be in a certain format will fail.  Algorithms that expect the vendor to have a first and last name will fail.  Algorithms that expect the vendor to have YTD values will fail.


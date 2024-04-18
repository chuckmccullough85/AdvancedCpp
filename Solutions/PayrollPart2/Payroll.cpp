#include <iostream>
#include "Organization.h"
#include "Employee.h"

using namespace std;
using namespace payroll;

int main()
{
    Organization org("Acme");
    Employee emp1("John Doe", "S123", 100);
    Employee emp2("Jane Doe", "C123", 10);
    Employee emp3("Jack Doe", "H123", 10);

    org.addEmployee(&emp1);
    org.addEmployee(&emp2);
    org.addEmployee(&emp3);
    
    org.pay();

    cout << "Total pay: " << org.pay() << endl;
    cout << "Employee 1 YTD Pay: " << emp1.getYtdPay() << endl;
    cout << "Employee 1 YTD Deductions: " << emp1.getYtdDeductions() << endl;
    cout << "Employee 2 YTD Pay: " << emp2.getYtdPay() << endl;
    cout << "Employee 2 YTD Deductions: " << emp2.getYtdDeductions() << endl;
    cout << "Employee 3 YTD Pay: " << emp3.getYtdPay() << endl;
    cout << "Employee 3 YTD Deductions: " << emp3.getYtdDeductions() << endl;


}


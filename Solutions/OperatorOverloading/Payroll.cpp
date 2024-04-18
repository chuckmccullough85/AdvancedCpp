#include <iostream>

#include "Organization.h"
#include "HumanResource.h"
#include "Employee.h"
#include "Factory.h"

using namespace std;
using namespace payroll;
using namespace factory;

void ShowEmployee(Employee emp)
{
    cout << "Employee: " << emp.getId() << "\t" <<emp.getName() << endl;
}


int main()
{
    ShowEmployee("E101"s);

    auto factory = ObjectFactory<HumanResource*>::Instance();

    Organization org("Acme");
    string id = "E101"s;
    auto emp1 = factory.Create(id);
    emp1->setName("Hank Hill");
    emp1->setPayRate(1000);

    org.addEmployee(emp1);

    id = "C102"s;
    auto emp2 = factory.Create(id);
    emp2->setName("Peggy Hill");
    emp2->setPayRate(100);
    org.addEmployee(emp2);

    id = "H103"s;
    auto emp3 = factory.Create(id);
    emp3->setName("Luann Platter");
    emp3->setPayRate(100);
    org.addEmployee(emp3);


    org.pay();

    cout << "Total pay: " << org.pay() << endl;
    cout << "Employee 1 YTD Pay: " << emp1->getYtdPay() << endl;
    cout << "Employee 1 YTD Deductions: " << emp1->getYtdDeductions() << endl;
    cout << "Employee 2 YTD Pay: " << emp2->getYtdPay() << endl;
    cout << "Employee 2 YTD Deductions: " << emp2->getYtdDeductions() << endl;
    cout << "Employee 3 YTD Pay: " << emp3->getYtdPay() << endl;
    cout << "Employee 3 YTD Deductions: " << emp3->getYtdDeductions() << endl;

    delete emp1;
    delete emp2;
    delete emp3;
}


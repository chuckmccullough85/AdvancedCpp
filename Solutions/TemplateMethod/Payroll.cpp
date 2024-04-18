#include <iostream>
#include <memory>
#include "Organization.h"
#include "HumanResource.h"
#include "Employee.h"
#include "Factory.h"

using namespace std;
using namespace payroll;
using namespace factory;


int main()
{
    Employee bad("E101");
    bad.setName("");


    auto& factory = ObjectFactory<HumanResourceSPtr>::Instance();

    auto org = make_unique<Organization>("Acme");
    string id = "E101"s;
    auto emp1 = factory.Create(id);
    emp1->setName("Hank Hill");
    emp1->setPayRate(1000);

    org->addPayable(emp1);

    id = "C102"s;
    auto emp2 = factory.Create(id);
    emp2->setName("Peggy Hill");
    emp2->setPayRate(100);
    org->addPayable(emp2);

    id = "H103"s;
    auto emp3 = factory.Create(id);
    emp3->setName("Luann Platter");
    emp3->setPayRate(100);
    org->addPayable(emp3);

    {
        auto sub = make_shared<Organization>("Acme Subsidiary");
        id = "E104"s;
        auto emp4 = factory.Create(id);
        emp4->setName("Bobby Hill");
        emp4->setPayRate(10);
        sub->addPayable(emp4);
        sub->addPayable(emp2);

        org->addPayable(sub);

        org->pay();

        cout << "Total pay: " << org->pay() << endl;
        cout << "Employee 1 YTD Pay: " << emp1->getYtdPay() << endl;
        cout << "Employee 1 YTD Deductions: " << emp1->getYtdDeductions() << endl;
        cout << "Employee 2 YTD Pay: " << emp2->getYtdPay() << endl;
        cout << "Employee 2 YTD Deductions: " << emp2->getYtdDeductions() << endl;
        cout << "Employee 3 YTD Pay: " << emp3->getYtdPay() << endl;
        cout << "Employee 3 YTD Deductions: " << emp3->getYtdDeductions() << endl;
    }

    // sub and emp4 are gone.  Let's pay again!

    cout << "Total pay: " << org->pay() << endl;

}


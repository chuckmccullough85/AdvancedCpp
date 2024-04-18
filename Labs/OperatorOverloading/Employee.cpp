#include <string>
#include "Employee.h"
#include "Factory.h"

namespace payroll {

    HumanResource* makeEmployee(const std::string& id)
    {
        return new Employee(id);
    }

    bool Employee::m_Registered =
        factory::ObjectFactory<HumanResource*>::Instance()
            .Register<Employee>("E", makeEmployee);

}
#include <string>
#include "HourlyEmployee.h"
#include "Factory.h"

namespace payroll {

    HumanResource* makeHourlyEmployee(const std::string& id)
    {
        return new HourlyEmployee(id);
    }

    bool HourlyEmployee::m_Registered =
        factory::ObjectFactory<HumanResource*>::Instance()
            .Register<HourlyEmployee>("H", makeHourlyEmployee);

}
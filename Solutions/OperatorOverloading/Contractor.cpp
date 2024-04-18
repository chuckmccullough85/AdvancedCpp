#include <string>
#include "Contractor.h"
#include "Factory.h"

namespace payroll {

    HumanResource* makeContractor(const std::string& id)
    {
        return new Contractor(id);
    }

    bool Contractor::m_Registered =
        factory::ObjectFactory<HumanResource*>::Instance()
            .Register<Contractor>("C", makeContractor);

}
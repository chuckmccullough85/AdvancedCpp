#include <string>
#include "Contractor.h"
#include "Factory.h"
using namespace std;

namespace payroll {
    bool Contractor::m_registered = factory::ObjectFactory<HumanResource*>::Instance()
        .Register("C"s, makeResource<Contractor, HumanResource>);
}
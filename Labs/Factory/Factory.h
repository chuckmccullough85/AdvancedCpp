#pragma once
#include <memory>
#include <map>
#include <string>
#include <functional>
#include <stdexcept>
#include "HumanResource.h"

namespace factory {
    using namespace std;
        
    class HrFactory
    {
    public:

        bool Register(const string& key, function<payroll::HumanResource*(const string&)> createFunc)
        {
            m_FactoryMap[key] = createFunc;
            return true;
        }

        payroll::HumanResource* Create(const string& id)
        {
            auto it =m_FactoryMap.find(id.substr(0,1));
            if (it != m_FactoryMap.end())
            {
                return it->second(id);
            }
            throw runtime_error("Unknown object type");
        }

    private:
        typedef map<string, function<payroll::HumanResource*(const string&)>> FactoryMap;
        FactoryMap m_FactoryMap;
    };


}

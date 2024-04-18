#pragma once
#include <memory>
#include <map>
#include <string>
#include <functional>
#include <stdexcept>
#include "HumanResource.h"

namespace factory {
    using namespace std;
        
    template <typename Base>
    class ObjectFactory
    {
    public:
        static ObjectFactory& Instance()
        {
            static ObjectFactory instance;
            return instance;
        }

        bool Register(const string& key, function<Base(const string&)> createFunc)
        {
            m_FactoryMap[key] = createFunc;
            return true;
        }

        Base Create(const string& id)
        {
            if (auto it =m_FactoryMap.find(id.substr(0,1)); it != m_FactoryMap.end())
            {
                return it->second(id);
            }
            throw runtime_error("Unknown object type");
        }

    private:
        ObjectFactory()=default;
        ObjectFactory(const ObjectFactory&)=delete;
        using FactoryMap = map<string, function<Base(const string&)>>;
        FactoryMap m_FactoryMap;
    };


}

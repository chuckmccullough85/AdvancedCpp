#pragma once
#include <memory>
#include <map>
#include <string>
#include <functional>
#include <stdexcept>

namespace factory {
    using namespace std;
        
    template <typename B>
    class ObjectFactory
    {
    public:
        static ObjectFactory<B>& Instance()
        {
            static ObjectFactory<B> instance;
            return instance;
        }

        template <typename T>
        bool Register(const string& key, function<B(const string&)> createFunc)
        {
            m_FactoryMap[key] = createFunc;
            return true;
        }

        B Create(const string& id)
        {
            if (auto it =m_FactoryMap.find(id.substr(0,1)); it != m_FactoryMap.end())
            {
                return it->second(id);
            }
            throw runtime_error("Unknown object type");
        }

    private:
        ObjectFactory() = default;
        typedef map<string, function<B(const string&)>> FactoryMap;
        FactoryMap m_FactoryMap;
    };


}

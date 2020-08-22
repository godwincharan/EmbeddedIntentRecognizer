#include "state_machine_factory.h"

namespace state_machine
{
StateMachineFactory& StateMachineFactory::Get()
{
    static StateMachineFactory state_machine_factory;
    return state_machine_factory;
}

const std::string StateMachineFactory::GetExtension(const std::string &file_name)
{
    std::string extension{""};
    auto pos = file_name.find_last_of(".");
    if(std::string::npos != pos)
    {
        extension = file_name.substr(pos);
    }
    return extension;
}

StateManager::Ptr StateMachineFactory::CreateStateManagerFor(const std::string& file_name)
{
    const std::string &extension{GetExtension(file_name)};
    if(std::string(".csv") == extension)
    {
        return std::make_shared<StateManager>();
    }
    return nullptr;
}
} // state_machine

#include "state_machine_factory.h"
#include "csv_state_machine_reader.h"
#include "xml_state_machine_reader.h"
#include "json_state_machine_reader.h"

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

IReader::Ptr StateMachineFactory::CreateReaderFor(const std::string& file_name)
{
    IReader::Ptr reader{nullptr};
    const std::string &extension{GetExtension(file_name)};
    if(std::string(".csv") == extension)
    {
        reader = std::make_shared<CsvStateMachineReader>();
    }
    else if(std::string(".xml") == extension )
    {
        reader = std::make_shared<XmlStateMachineReader>();
    }
    else if(std::string(".json") == extension )
    {
        reader = std::make_shared<JsonStateMachineReader>();
    }

    if ( reader && reader->OpenFile(file_name))
    {
        return reader;
    }
    return nullptr;
}

std::vector<StateManager::Ptr> StateMachineFactory::CreateStateManagersFor(const std::string& file_name)
{
    IReader::Ptr reader{CreateReaderFor(file_name)};
    if ( reader)
    {
        return reader->GetStateManagers();
    }
    return std::vector<StateManager::Ptr>{};
}
} // state_machine

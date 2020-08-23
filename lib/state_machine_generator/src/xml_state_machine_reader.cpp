#include "xml_state_machine_reader.h"

namespace state_machine
{
XmlStateMachineReader::XmlStateMachineReader() noexcept
{
}

XmlStateMachineReader::~XmlStateMachineReader()
{
}

bool XmlStateMachineReader::OpenFile(const std::string& file_name) noexcept
{
    if(!file_name.empty())
    {
    }
    return false;
}

std::vector<StateManager::Ptr> XmlStateMachineReader::GetStateManagers() const noexcept
{
    return std::vector<StateManager::Ptr>{};
}
} // state_machine

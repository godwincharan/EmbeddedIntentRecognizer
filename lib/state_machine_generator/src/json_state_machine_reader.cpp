#include "json_state_machine_reader.h"

namespace state_machine
{
JsonStateMachineReader::JsonStateMachineReader() noexcept
{
}

JsonStateMachineReader::~JsonStateMachineReader()
{
}

bool JsonStateMachineReader::OpenFile(const std::string& file_name) noexcept
{
    if(!file_name.empty())
    {
    }
    return false;
}

std::vector<StateManager::Ptr> JsonStateMachineReader::GetStateManagers() const noexcept
{
    return std::vector<StateManager::Ptr>{};
}
} // state_machine

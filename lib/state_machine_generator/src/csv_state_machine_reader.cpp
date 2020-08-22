#include "csv_state_machine_reader.h"

namespace state_machine
{
CsvStateMachineReader::CsvStateMachineReader() noexcept
{
}

CsvStateMachineReader::~CsvStateMachineReader()
{
}

bool CsvStateMachineReader::OpenFile(const std::string& file_name) noexcept
{
    if(!file_name.empty())
    {
    }
    return false;
}

StateManager::Ptr CsvStateMachineReader::GetStateManager() noexcept
{
    return nullptr;
}
} // state_machine

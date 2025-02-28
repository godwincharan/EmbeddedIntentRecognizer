#ifndef STATE_MACHINE_FACTORY_H
#define STATE_MACHINE_FACTORY_H

#include <state_manager.h>
#include "i_reader.h"

namespace state_machine
{
class StateMachineFactory final
{
private:
    explicit StateMachineFactory() noexcept = default;
    ~StateMachineFactory() = default;

    static const std::string GetExtension(const std::string &file_name);
    IReader::Ptr CreateReaderFor(const std::string& file_name);

public:
    static StateMachineFactory& Get();
    
    std::vector<StateManager::Ptr> CreateStateManagersFor(const std::string& file_name);
};
} // state_machine
#endif //STATE_MACHINE_FACTORY_H

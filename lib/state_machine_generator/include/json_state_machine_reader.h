#ifndef JSON_STATE_MACHINE_READER_H
#define JSON_STATE_MACHINE_READER_H

#include "i_reader.h"

namespace state_machine
{
class JsonStateMachineReader final : public IReader
{
public:
    using Ptr = std::shared_ptr<JsonStateMachineReader>;
    explicit JsonStateMachineReader() noexcept;
    ~JsonStateMachineReader();

    bool OpenFile(const std::string& file_name) noexcept override;
    std::vector<StateManager::Ptr> GetStateManagers() const noexcept override;
};
} // state_machine
#endif //JSON_STATE_MACHINE_READER_H

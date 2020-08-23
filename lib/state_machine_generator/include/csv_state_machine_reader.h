#ifndef CSV_STATE_MACHINE_READER_H
#define CSV_STATE_MACHINE_READER_H

#include "i_reader.h"

namespace state_machine
{
class CsvStateMachineReader final : public IReader
{
public:
    using Ptr = std::shared_ptr<CsvStateMachineReader>;
    explicit CsvStateMachineReader() noexcept;
    ~CsvStateMachineReader();

    bool OpenFile(const std::string& file_name) noexcept override;
    StateManager::Ptr GetStateManager() const noexcept override;
private:
    StateManager::Ptr state_manager_{nullptr};
};
} // state_machine
#endif //CSV_STATE_MACHINE_READER_H

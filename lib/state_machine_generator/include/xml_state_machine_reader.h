#ifndef XML_STATE_MACHINE_READER_H
#define XML_STATE_MACHINE_READER_H

#include "i_reader.h"

namespace state_machine
{
class XmlStateMachineReader final : public IReader
{
public:
    using Ptr = std::shared_ptr<XmlStateMachineReader>;
    explicit XmlStateMachineReader() noexcept;
    ~XmlStateMachineReader();

    bool OpenFile(const std::string& file_name) noexcept override;
    StateManager::Ptr GetStateManager() const noexcept override;
};
} // state_machine
#endif //XML_STATE_MACHINE_READER_H

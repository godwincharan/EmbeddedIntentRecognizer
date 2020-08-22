#ifndef I_READER_H
#define I_READER_H

#include <memory>
#include <string>
#include <state_manager.h>

namespace state_machine
{
class IReader
{
public:
    using Ptr = std::shared_ptr<IReader>;
    explicit IReader() noexcept {}
    virtual ~IReader(){}

    virtual bool OpenFile(const std::string &file_name) noexcept = 0;
    virtual StateManager::Ptr GetStateManager() const noexcept = 0;
};
} // state_machine
#endif //I_READER_H


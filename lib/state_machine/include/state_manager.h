#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <memory>

namespace state_machine
{
class StateManager
{
public:
    using Ptr = std::shared_ptr<StateManager>;
    explicit StateManager() noexcept;
    ~StateManager();
};
} // state_machine
#endif //STATE_MANAGER_H

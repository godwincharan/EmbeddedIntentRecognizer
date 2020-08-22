#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <memory>
#include "state.h"

namespace state_machine
{
class StateManager final
{
public:
    using Ptr = std::shared_ptr<StateManager>;
    explicit StateManager() noexcept;
    ~StateManager();

    const std::shared_ptr<State> GetCurrentState()const noexcept; 
private:
    std::shared_ptr<State> current_state_{std::make_shared<InitialState>()};
};
} // state_machine
#endif //STATE_MANAGER_H

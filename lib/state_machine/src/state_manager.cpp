#include "state_manager.h"

namespace state_machine
{
StateManager::StateManager() noexcept
{
}

StateManager::~StateManager()
{
}

const std::shared_ptr<State> StateManager::GetCurrentState()const noexcept
{
    return current_state_;
}
} // state_machine

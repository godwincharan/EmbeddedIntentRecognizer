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

bool StateManager::HasState(const State::SPtr state) const noexcept
{
    return all_states_.find(state) != all_states_.end();
}

bool StateManager::AddState(const std::string& state_str) noexcept
{
    auto new_state{std::make_shared<State>(state_str)};
    if ( HasState(new_state) )
    {
        return false;
    }
        
    all_states_.emplace(new_state);
    return true;
}
    
} // state_machine

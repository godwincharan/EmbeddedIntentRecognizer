#include "state_manager.h"

namespace state_machine
{
StateManager::StateManager() noexcept
{
}

StateManager::~StateManager()
{
}

void StateManager::Reset()
{
    current_state_ = initial_state_;
}

const std::shared_ptr<State> StateManager::GetCurrentState()const noexcept
{
    return current_state_;
}

State::SPtr StateManager::ProcessState(const std::string& state_str) noexcept
{
    if ( current_state_ )
    {
        if ( current_state_->IsValid() && HasState(state_str) )
        {
            current_state_ =  ( current_state_ == initial_state_) ? GetBeginState(state_str) :    current_state_->GetNextState(state_str);
        }
        else
        {
            current_state_ = nullptr;
        }
    }
    return current_state_;
}

bool StateManager::HasState(const State::SPtr state) const noexcept
{
    return all_states_.find(state) != all_states_.end();
}

bool StateManager::HasState(const std::string& state_str) const noexcept
{
    return all_states_.find(state_str) != all_states_.end();
}

State::SPtr StateManager::GetState(const std::string& state_str) const noexcept
{
    auto it{all_states_.find(state_str)};
    if ( it != all_states_.end())
    {
        return *it;
    }
    return nullptr;    
}

State::SPtr StateManager::GetState(const State::SPtr state) const noexcept
{
    auto it{all_states_.find(state)};
    if ( it != all_states_.end())
    {
       return *it;
    }
    return nullptr;   
}

State::SPtr StateManager::GetBeginState(const std::string& state_str) const noexcept
{
    auto it{all_states_.find(state_str)};
    if ( it != all_states_.end() && std::dynamic_pointer_cast<BeginState>(*it) != nullptr )
    {
       return *it;
    }
    return nullptr; 
}

bool StateManager::AddState(const State::SPtr state) noexcept
{
    if ( !state->IsValid() || HasState(state) )
    {
        return false;
    }

    all_states_.emplace(state);
    return true;
}
    
} // state_machine

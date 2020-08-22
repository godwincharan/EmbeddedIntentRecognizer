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

bool StateManager::ProcessState(const std::string& state_str) noexcept
{
    if ( current_state_ && current_state_->IsValid() && HasState(state_str) )
    {
        current_state_ =  ( current_state_ == initial_state_) ? GetState(state_str) :    current_state_->GetNextState(state_str);
    }
    return false;
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

bool StateManager::AddState(const std::string& state_str, bool is_final /* = false */) noexcept
{
    if ( state_str.empty())
    {
        return false;
    }

    State::SPtr new_state{nullptr};
    if (is_final)
    {
        new_state = std::make_shared<FinalState>(state_str);
    }
    else
    {
        new_state = std::make_shared<State>(state_str);
    }
    if ( HasState(new_state) )
    {
        return false;
    }

    all_states_.emplace(new_state);
    return true;
}
    
} // state_machine

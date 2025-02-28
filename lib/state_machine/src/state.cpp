#include "state.h"

namespace state_machine
{
State::State(const std::string& state_str) noexcept:
state_str_{state_str}
{
}

State::~State()
{
    next_states_.clear();
}

const std::string& State::GetState() const noexcept
{
    return state_str_;
}

void State::AddNextState(const State::SPtr state) noexcept
{
    next_states_.emplace(state);
}

State::SPtr State::GetNextState(const std::string& state_str) const noexcept
{
    auto it{next_states_.find(state_str)};
    if ( it != next_states_.end())
    {
        return *it;
    }
    return nullptr;    
}

State::SPtr State::GetNextState(const State::SPtr state) const noexcept
{
    auto it{next_states_.find(state)};
    if ( it != next_states_.end())
    {
       return *it;
    }
    return nullptr;   
}

bool State::operator< (const State &state) const noexcept
{
    return state_str_ < state.state_str_;
}

bool State::IsValid() const noexcept
{
    return (state_str_.empty() == false);
}

InitialState::InitialState() noexcept:
State("")
{
}

bool InitialState::IsValid() const noexcept
{
    return true;
}

BeginState::BeginState(const std::string& state_str) noexcept:
State(state_str)
{

}

FinalState::FinalState(const std::string& state_str) noexcept:
State(state_str)
{
}

void FinalState::SetFinalIntent(const std::string& final_intent) noexcept
{
    final_intent_ = final_intent;
}

const std::string FinalState::GetFinalIntent() const noexcept
{
    return final_intent_;
}
} // state_machine

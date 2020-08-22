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

void State::AddNextState(const State& state) noexcept
{
    next_states_.emplace(state);
}

bool State::HasNextState(const State& state) const noexcept
{
    return next_states_.find(state) != next_states_.end();
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

FinalState::FinalState(const std::string& intent) noexcept:
State(intent)
{
}
} // state_machine

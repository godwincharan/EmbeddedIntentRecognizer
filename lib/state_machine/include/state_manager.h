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

    bool ProcessState(const std::string& state_str) noexcept;

    bool HasState(const State::SPtr state) const noexcept;
    bool HasState(const std::string& state_str) const noexcept;

    State::SPtr GetState(const std::string& state_str) const noexcept;
    State::SPtr GetState(const State::SPtr state) const noexcept;

    bool AddState(const std::string& state_str, bool is_final = false) noexcept;
private:
    const std::shared_ptr<State> initial_state_{std::make_shared<InitialState>()};
    std::shared_ptr<State> current_state_{initial_state_};
    std::set<State::SPtr, State::StateCompare> all_states_{};
};
} // state_machine
#endif //STATE_MANAGER_H

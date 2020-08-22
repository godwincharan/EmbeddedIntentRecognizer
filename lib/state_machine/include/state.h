#ifndef STATE_H
#define STATE_H

#include <set>
#include <string>

namespace state_machine
{
class State
{
public:
    explicit State(const std::string& state_str) noexcept;
    virtual ~State();

    const std::string& GetState() const noexcept;
    void AddNextState(const State& state) noexcept;
    bool HasNextState(const State& state) const noexcept;

    bool operator< (const State &state) const noexcept;

    virtual bool IsValid() const noexcept;
private:
    std::string state_str_;
    std::set<State> next_states_;
};

class InitialState final : public State
{
public: 
    InitialState() noexcept;
    bool IsValid() const noexcept override;
};

class FinalState final : public State
{
public: 
    FinalState(const std::string& intent) noexcept;
};
} // state_machine
#endif //STATE_H

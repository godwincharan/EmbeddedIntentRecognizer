#ifndef STATE_H
#define STATE_H

#include <set>
#include <string>

namespace state_machine
{
class State
{
public:
    using SPtr = std::shared_ptr<State>;
    struct StateCompare
    {
        using is_transparent = void;
        bool operator() (const State::SPtr& lhs, const State::SPtr& rhs) const
        {
            return *lhs < *rhs;
        }
        
        bool operator() (const State::SPtr& lhs, std::string rhs) const
        {
            return lhs->GetState() < rhs;
        }

        bool operator() (std::string lhs, const State::SPtr& rhs) const
        {
            return lhs < rhs->GetState();
        }
    };

    explicit State(const std::string& state_str) noexcept;
    virtual ~State();

    const std::string& GetState() const noexcept;
    void AddNextState(const State::SPtr state) noexcept;
    
    State::SPtr GetNextState(const std::string& state_str) const noexcept;
    State::SPtr GetNextState(const State::SPtr state) const noexcept;

    bool operator< (const State &state) const noexcept;

    virtual bool IsValid() const noexcept;
private:
    std::string state_str_;
    std::set<State::SPtr, StateCompare> next_states_;
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
    FinalState(const std::string& state_str) noexcept;
    void SetFinalIntent(const std::string& final_intent);
private:
    std::string final_intent_;
};
} // state_machine
#endif //STATE_H

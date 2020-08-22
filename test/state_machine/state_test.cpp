#include <gtest/gtest.h>
#include <state.h>

TEST(StateTest, CreateState)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Initial State")};
    EXPECT_NE(state, nullptr);
}

TEST(StateTest, TestState)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Initial State")};
    EXPECT_NE(state, nullptr);
    EXPECT_EQ(state->GetState(), "Initial State");
}

TEST(StateTest, NextState)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Initial State")};
    EXPECT_NE(state, nullptr);

    State next_state{"Next State"};
    state->AddNextState(next_state);

    EXPECT_TRUE(state->HasNextState(next_state));
    EXPECT_FALSE(state->HasNextState(State{"Invalid State"}));
}

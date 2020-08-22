#include <gtest/gtest.h>
#include <state.h>

TEST(StateTest, CreateState)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Some State")};
    EXPECT_NE(state, nullptr);
}

TEST(StateTest, InitialState)
{
    using namespace state_machine;
    auto state{std::make_unique<InitialState>()};
    EXPECT_NE(state, nullptr);
    EXPECT_TRUE(state->IsValid());
}

TEST(StateTest, FinalState)
{
    using namespace state_machine;
    auto state{std::make_unique<FinalState>("Final State")};
    EXPECT_NE(state, nullptr);
    EXPECT_TRUE(state->IsValid());
}

TEST(StateTest, TestState)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Some State")};
    EXPECT_NE(state, nullptr);
    EXPECT_EQ(state->GetState(), "Some State");
}

TEST(StateTest, TestStateValid)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Some State")};
    EXPECT_NE(state, nullptr);
    EXPECT_EQ(state->GetState(), "Some State");
    EXPECT_TRUE(state->IsValid());
}

TEST(StateTest, NextState)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Some State")};
    EXPECT_NE(state, nullptr);

    auto next_state{std::make_shared<State>("Next State")};
    state->AddNextState(next_state);
    EXPECT_TRUE(state->HasNextState(next_state));

    auto next_state_new_ptr{std::make_shared<State>("Next State")};
    EXPECT_TRUE(state->HasNextState(next_state_new_ptr));

    auto not_available_next_state{std::make_shared<State>("No Next State")};
    EXPECT_FALSE(state->HasNextState(not_available_next_state));
}

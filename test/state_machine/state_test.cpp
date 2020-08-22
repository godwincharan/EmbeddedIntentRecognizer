#include <gtest/gtest.h>
#include <state.h>


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

TEST(StateTest, CreateState)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Some State")};
    EXPECT_NE(state, nullptr);
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
    EXPECT_TRUE(state->IsValid());
}

TEST(StateTest, AddState)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Some State")};

    auto next_state{std::make_shared<State>("Next State")};
    state->AddNextState(next_state);
    EXPECT_TRUE(state->GetNextState(next_state) != nullptr);

    auto next_state_new_ptr{std::make_shared<State>("Next State")};
    EXPECT_TRUE(state->GetNextState(next_state_new_ptr) != nullptr);
}

TEST(StateTest, NotAddedState)
{
    using namespace state_machine;
    auto state{std::make_unique<State>("Some State")};

    auto not_available_next_state{std::make_shared<State>("No Next State")};
    EXPECT_TRUE(state->GetNextState(not_available_next_state) == nullptr);
}

TEST(StateTest, CheckLessThan)
{
    using namespace state_machine;
    auto a_state{std::make_unique<State>("a")};
    auto b_state{std::make_unique<State>("b")};

    EXPECT_TRUE(*(a_state.get()) < *(b_state.get()));
}

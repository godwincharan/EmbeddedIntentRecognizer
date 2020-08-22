#include <gtest/gtest.h>
#include <state_manager.h>

TEST(StateManagerTest, CreateStateManager)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    EXPECT_NE(state_manager, nullptr);
}

TEST(StateManagerTest, CheckInitialState)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    EXPECT_NE(state_manager, nullptr);

    EXPECT_TRUE(state_manager->GetCurrentState()->IsValid());
}

TEST(StateManagerTest, CreateState)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    EXPECT_NE(state_manager, nullptr);

    EXPECT_TRUE(state_manager->AddState("State"));
    EXPECT_FALSE(state_manager->AddState("State"));

    auto state{std::make_shared<State>("State")};
    EXPECT_TRUE(state_manager->HasState(state));

    auto no_state{std::make_shared<State>("No State")};
    EXPECT_FALSE(state_manager->HasState(no_state));
}

#include <gtest/gtest.h>
#include <state_manager.h>

TEST(StateManagerTest, CreateStateManager)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    EXPECT_NE(state_manager, nullptr);
}

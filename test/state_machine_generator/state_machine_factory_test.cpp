#include <gtest/gtest.h>
#include <state_machine_factory.h>

TEST(StateManagerTest, CreateStateMachineFactory)
{
    using namespace state_machine;
    EXPECT_NE(StateMachineFactory::Get().CreateStateManagerFor(".csv"), nullptr);
}

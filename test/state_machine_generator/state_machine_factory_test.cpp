#include <gtest/gtest.h>
#include <state_machine_factory.h>

TEST(StateManagerTest, CheckStateManagerForCSV)
{
    using namespace state_machine;
    EXPECT_EQ(StateMachineFactory::Get().CreateStateManagerFor(".csv"), nullptr);
}

TEST(StateManagerTest, CheckStateManagerForXML)
{
    using namespace state_machine;
    EXPECT_EQ(StateMachineFactory::Get().CreateStateManagerFor(".xml"), nullptr);
}

TEST(StateManagerTest, CheckStateManagerForJson)
{
    using namespace state_machine;
    EXPECT_EQ(StateMachineFactory::Get().CreateStateManagerFor(".json"), nullptr);
}

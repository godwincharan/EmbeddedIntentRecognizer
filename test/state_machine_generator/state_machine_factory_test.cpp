#include <gtest/gtest.h>
#include <state_machine_factory.h>

TEST(StateManagerTest, CheckStateManagerForCSV)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    EXPECT_NE(StateMachineFactory::Get().CreateStateManagerFor(csv_file_name), nullptr);
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

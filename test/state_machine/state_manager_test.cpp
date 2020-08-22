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
    EXPECT_TRUE(state_manager->GetCurrentState()->IsValid());
}

TEST(StateManagerTest, AddStateStateEmpty)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    EXPECT_FALSE(state_manager->AddState(""));
}

TEST(StateManagerTest, AddStateState)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    EXPECT_TRUE(state_manager->AddState("State"));
}

TEST(StateManagerTest, AddStateSame)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    EXPECT_TRUE(state_manager->AddState("State"));
    EXPECT_FALSE(state_manager->AddState("State"));
}

TEST(StateManagerTest, CheckAddStateString)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    EXPECT_TRUE(state_manager->AddState("State"));
    EXPECT_TRUE(state_manager->HasState(std::string("State")));
}

TEST(StateManagerTest, CheckAddStatePointer)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    EXPECT_TRUE(state_manager->AddState("State"));
    auto state{std::make_shared<State>("State")};
    EXPECT_TRUE(state_manager->HasState(state));
}

TEST(StateManagerTest, CheckNoAddedStateString)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};

    EXPECT_FALSE(state_manager->HasState(std::string("No State")));
}

TEST(StateManagerTest, CheckNoAddedStatePointer)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};

    auto no_state{std::make_shared<State>("No State")};
    EXPECT_FALSE(state_manager->HasState(no_state));
}

TEST(StateManagerTest, GetAddedStateString)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    EXPECT_TRUE(state_manager->AddState("State"));

    EXPECT_TRUE(state_manager->GetState(std::string("State")) != nullptr);
}

TEST(StateManagerTest, GetAddedStatePointer)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    EXPECT_TRUE(state_manager->AddState("State"));

    auto state{std::make_shared<State>("State")};
    EXPECT_TRUE(state_manager->GetState(state) != nullptr);
}

TEST(StateManagerTest, GetNoAddedStateString)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};

    EXPECT_TRUE(state_manager->GetState(std::string("No State")) == nullptr);
}

TEST(StateManagerTest, GetNoAddedStatePointer)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};

    auto no_state{std::make_shared<State>("No State")};
    EXPECT_TRUE(state_manager->GetState(no_state) == nullptr);
}

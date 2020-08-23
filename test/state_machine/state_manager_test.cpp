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

TEST(StateManagerTest, AddStateEmpty)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    State::SPtr state = std::make_shared<State>("");
    EXPECT_FALSE(state_manager->AddState(state));
}

TEST(StateManagerTest, AddStateValid)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    State::SPtr state = std::make_shared<State>("State");
    EXPECT_TRUE(state_manager->AddState(state));
}

TEST(StateManagerTest, AddStateSame)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    State::SPtr state1 = std::make_shared<State>("State");
    EXPECT_TRUE(state_manager->AddState(state1));
    State::SPtr state2 = std::make_shared<State>("State");
    EXPECT_FALSE(state_manager->AddState(state2));
}

TEST(StateManagerTest, CheckAddStateString)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    State::SPtr state = std::make_shared<State>("State");
    EXPECT_TRUE(state_manager->AddState(state));
    EXPECT_TRUE(state_manager->HasState(std::string("State")));
}

TEST(StateManagerTest, CheckAddStatePointer)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    
    State::SPtr state = std::make_shared<State>("State");
    EXPECT_TRUE(state_manager->AddState(state));

    auto check_state{std::make_shared<State>("State")};
    EXPECT_TRUE(state_manager->HasState(check_state));
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
    State::SPtr state = std::make_shared<State>("State");
    EXPECT_TRUE(state_manager->AddState(state));

    EXPECT_TRUE(state_manager->GetState(std::string("State")) != nullptr);
}

TEST(StateManagerTest, GetAddedStatePointer)
{
    using namespace state_machine;
    auto state_manager{std::make_unique<StateManager>()};
    auto state{std::make_shared<State>("State")};
    EXPECT_TRUE(state_manager->AddState(state));

    auto check_state{std::make_shared<State>("State")};
    EXPECT_TRUE(state_manager->GetState(check_state) != nullptr);
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

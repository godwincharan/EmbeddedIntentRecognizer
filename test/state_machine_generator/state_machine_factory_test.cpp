#include <gtest/gtest.h>
#include <state_machine_factory.h>
#include <string_utils.h>

TEST(StateMachineGeneratorTest, CheckStateManagerForCSV)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    EXPECT_NE(StateMachineFactory::Get().CreateStateManagersFor(csv_file_name).size(), 0);
}

TEST(StateMachineGeneratorTest, CheckStateManagerForXML)
{
    using namespace state_machine;
    EXPECT_EQ(StateMachineFactory::Get().CreateStateManagersFor(".xml").size(), 0);
}

TEST(StateMachineGeneratorTest, CheckStateManagerForJson)
{
    using namespace state_machine;
    EXPECT_EQ(StateMachineFactory::Get().CreateStateManagersFor(".json").size(), 0);
}

TEST(StateMachineGeneratorTest, CheckWrongSentence)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_managers = StateMachineFactory::Get().CreateStateManagersFor(csv_file_name);
    
    auto run_lambda=[](const StateManager::Ptr& state_manager, const std::string& sentence ){
        auto current_state =  state_manager->GetCurrentState();
        auto tokens = utils::GetTokens(sentence, ' ');
        for(auto token: tokens)
        {
            current_state =  state_manager->ProcessState(token);
            if ( current_state == nullptr)
            {
                break;
            }
        }
        return current_state;
    };

    std::string sentence{"what is your name"};
    State::SPtr result_state{nullptr};
    for(auto& state_manager: state_managers)
    {
        result_state = run_lambda(state_manager, sentence);
        if ( result_state)
        {
            break;
        }
    }
    EXPECT_EQ(result_state, nullptr);
}

TEST(StateMachineGeneratorTest, IncompleteSentence_Begin)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_managers = StateMachineFactory::Get().CreateStateManagersFor(csv_file_name);
    
    auto run_lambda=[](const StateManager::Ptr& state_manager, const std::string& sentence ){
        auto current_state =  state_manager->GetCurrentState();
        auto tokens = utils::GetTokens(sentence, ' ');
        for(auto token: tokens)
        {
            current_state =  state_manager->ProcessState(token);
            if ( current_state == nullptr)
            {
                break;
            }
        }
        return current_state;
    };

    std::string sentence{"weather like in Paris today"};
    State::SPtr result_state{nullptr};
    for(auto& state_manager: state_managers)
    {
        result_state = run_lambda(state_manager, sentence);
        if ( result_state)
        {
            break;
        }
    }
    EXPECT_EQ(result_state, nullptr);

}

TEST(StateMachineGeneratorTest, IncompleteSentence_End)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_managers = StateMachineFactory::Get().CreateStateManagersFor(csv_file_name);
    
    auto run_lambda=[](const StateManager::Ptr& state_manager, const std::string& sentence ){
        auto current_state =  state_manager->GetCurrentState();
        auto tokens = utils::GetTokens(sentence, ' ');
        for(auto token: tokens)
        {
            current_state =  state_manager->ProcessState(token);
            if ( current_state == nullptr)
            {
                break;
            }
        }
        return current_state;
    };

    std::string sentence{"what is the weather like in "};
    FinalState::SPtr final_state{nullptr};
    for(auto& state_manager: state_managers)
    {
        auto result_state = run_lambda(state_manager, sentence);
        if ( result_state)
        {
            final_state = std::dynamic_pointer_cast<FinalState>(result_state);
            if ( final_state)
            {
                break;

            }
        }
    }
    EXPECT_EQ(final_state, nullptr);
}

TEST(StateMachineGeneratorTest, IncompleteSentence_JustFinalWord)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_managers = StateMachineFactory::Get().CreateStateManagersFor(csv_file_name);
    
    auto run_lambda=[](const StateManager::Ptr& state_manager, const std::string& sentence ){
        auto current_state =  state_manager->GetCurrentState();
        auto tokens = utils::GetTokens(sentence, ' ');
        for(auto token: tokens)
        {
            current_state =  state_manager->ProcessState(token);
            if ( current_state == nullptr)
            {
                break;
            }
        }
        return current_state;
    };

    std::string sentence{"today"};
    State::SPtr result_state{nullptr};
    for(auto& state_manager: state_managers)
    {
        result_state = run_lambda(state_manager, sentence);
        if ( result_state)
        {
            break;
        }
    }
    EXPECT_EQ(result_state, nullptr);
}

TEST(StateMachineGeneratorTest, CompleteSentence_1)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_managers = StateMachineFactory::Get().CreateStateManagersFor(csv_file_name);
    
    auto run_lambda=[](const StateManager::Ptr& state_manager, const std::string& sentence ){
        auto current_state =  state_manager->GetCurrentState();
        auto tokens = utils::GetTokens(sentence, ' ');
        for(auto token: tokens)
        {
            current_state =  state_manager->ProcessState(token);
            if ( current_state == nullptr)
            {
                break;
            }
        }
        return current_state;
    };

    std::string sentence{"what is the weather like today"};
    FinalState::SPtr final_state{nullptr};
    for(auto& state_manager: state_managers)
    {
        auto result_state = run_lambda(state_manager, sentence);
        if ( result_state)
        {
            final_state = std::dynamic_pointer_cast<FinalState>(result_state);
            if ( final_state != nullptr)
            {
                break;
            }
        }
    }
    EXPECT_NE(final_state, nullptr);
    EXPECT_EQ(final_state->GetFinalIntent(), "Intent: Get Weather");
}

TEST(StateMachineGeneratorTest, CompleteSentence_2)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_managers = StateMachineFactory::Get().CreateStateManagersFor(csv_file_name);
    
    auto run_lambda=[](const StateManager::Ptr& state_manager,const std::string& sentence ){
        auto current_state =  state_manager->GetCurrentState();
        auto tokens = utils::GetTokens(sentence, ' ');
        for(auto token: tokens)
        {
            current_state =  state_manager->ProcessState(token);
            if ( current_state == nullptr)
            {
                break;
            }
        }
        return current_state;
    };

    std::string sentence{"what is the weather like in Paris today"};
    FinalState::SPtr final_state{nullptr};
    for(auto& state_manager: state_managers)
    {
        auto result_state = run_lambda(state_manager, sentence);
        if ( result_state)
        {
            final_state = std::dynamic_pointer_cast<FinalState>(result_state);
            if ( final_state != nullptr)
            {
                break;
            }
        }
    }
    EXPECT_NE(final_state, nullptr);
    EXPECT_EQ(final_state->GetFinalIntent(), "Intent: Get Weather");
}

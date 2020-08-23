#include <gtest/gtest.h>
#include <state_machine_factory.h>
#include <iostream>
#include <string_utils.h>

TEST(StateMachineGeneratorTest, CheckStateManagerForCSV)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    EXPECT_NE(StateMachineFactory::Get().CreateStateManagerFor(csv_file_name), nullptr);
}

TEST(StateMachineGeneratorTest, CheckStateManagerForXML)
{
    using namespace state_machine;
    EXPECT_EQ(StateMachineFactory::Get().CreateStateManagerFor(".xml"), nullptr);
}

TEST(StateMachineGeneratorTest, CheckStateManagerForJson)
{
    using namespace state_machine;
    EXPECT_EQ(StateMachineFactory::Get().CreateStateManagerFor(".json"), nullptr);
}

TEST(StateMachineGeneratorTest, CheckWrongSentence)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_manager = StateMachineFactory::Get().CreateStateManagerFor(csv_file_name);
    
    auto run_lambda=[&state_manager](const std::string& sentence ){
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
    auto result_state = run_lambda(sentence);
    EXPECT_EQ(result_state, nullptr);
}

TEST(StateMachineGeneratorTest, IncompleteSentence_Begin)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_manager = StateMachineFactory::Get().CreateStateManagerFor(csv_file_name);
    
    auto run_lambda=[&state_manager](const std::string& sentence ){
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
    auto result_state = run_lambda(sentence);
    EXPECT_EQ(result_state, nullptr);
}

TEST(StateMachineGeneratorTest, IncompleteSentence_End)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_manager = StateMachineFactory::Get().CreateStateManagerFor(csv_file_name);
    
    auto run_lambda=[&state_manager](const std::string& sentence ){
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
    auto result_state = run_lambda(sentence);
    EXPECT_NE(result_state, nullptr);
    auto final_state = std::dynamic_pointer_cast<FinalState>(result_state);
    EXPECT_EQ(final_state, nullptr);
}

TEST(StateMachineGeneratorTest, IncompleteSentence_JustFinalWord)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_manager = StateMachineFactory::Get().CreateStateManagerFor(csv_file_name);
    
    auto run_lambda=[&state_manager](const std::string& sentence ){
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
    auto result_state = run_lambda(sentence);
    EXPECT_EQ(result_state, nullptr);
}

TEST(StateMachineGeneratorTest, CompleteSentence_1)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_manager = StateMachineFactory::Get().CreateStateManagerFor(csv_file_name);
    
    auto run_lambda=[&state_manager](const std::string& sentence ){
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
    auto result_state = run_lambda(sentence);
    EXPECT_NE(result_state, nullptr);
    auto final_state = std::dynamic_pointer_cast<FinalState>(result_state);
    EXPECT_NE(final_state, nullptr);
    EXPECT_EQ(final_state->GetFinalIntent(), "Intent: Get Weather");
}

TEST(StateMachineGeneratorTest, CompleteSentence_2)
{
    using namespace state_machine;
    std::string csv_file_name{"data/weather_intent_data.csv"};
    auto state_manager = StateMachineFactory::Get().CreateStateManagerFor(csv_file_name);
    
    auto run_lambda=[&state_manager](const std::string& sentence ){
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
    auto result_state = run_lambda(sentence);
    EXPECT_NE(result_state, nullptr);
    auto final_state = std::dynamic_pointer_cast<FinalState>(result_state);
    EXPECT_NE(final_state, nullptr);
    EXPECT_EQ(final_state->GetFinalIntent(), "Intent: Get Weather");
}

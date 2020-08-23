#include <gtest/gtest.h>
#include <state_machine_factory.h>
#include <string_utils.h>

TEST(Report, CheckWrongSentence)
{
    using namespace state_machine;
    std::string csv_file_name{"/Users/Charan/Documents/MyDev/EmbeddedIntentRecognizer/data/weather_intent_data.csv"};
    auto state_managers = StateMachineFactory::Get().CreateStateManagersFor(csv_file_name);
    
    auto find_in_state_managers = [&state_managers](const std::string& sentence)
    {
        auto get_final_state = [](const StateManager::Ptr& state_manager, const std::string& sentence ){
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

        for(auto& state_manager: state_managers)
        {
            state_manager->Reset();
            auto result_state = get_final_state(state_manager, sentence);
            if ( result_state)
            {
                FinalState::SPtr final_state = std::dynamic_pointer_cast<FinalState>(result_state);
                if ( final_state != nullptr)
                {
                    return final_state->GetFinalIntent();
                }
            }
        }
        return std::string("");
    };

    std::string sentence1{"what is your name"};
    EXPECT_EQ(find_in_state_managers(sentence1), "");

    std::string sentence2{"weather like in Paris today"};
    EXPECT_EQ(find_in_state_managers(sentence2), "");

    std::string sentence3{"what is the weather like in "};
    EXPECT_EQ(find_in_state_managers(sentence3), "");

    std::string sentence4{"today"};
    EXPECT_EQ(find_in_state_managers(sentence4), "");

    std::string sentence5{"what is the weather like today"};
    EXPECT_EQ(find_in_state_managers(sentence5), "Intent: Get Weather");

    std::string sentence6{"what is the weather like in Paris today"};
    EXPECT_EQ(find_in_state_managers(sentence6), "Intent: Get Weather");

    std::string sentence7{"what is the weather like in New York today"};
    EXPECT_EQ(find_in_state_managers(sentence7), "Intent: Get Weather");

    std::string sentence8{"am I free at 13:00 PM tomorrow"};
    EXPECT_EQ(find_in_state_managers(sentence8), "Intent: Check calendar");

    std::string sentence9{"tell me an interesting fact"};
    EXPECT_EQ(find_in_state_managers(sentence9), "Intent: Get Fact");

    std::string sentence10{"do I have an appointment at 13:00 PM tomorrow"};
    EXPECT_EQ(find_in_state_managers(sentence10), "Intent: Check calendar");
}

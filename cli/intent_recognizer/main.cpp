
#include <state_machine_factory.h>
#include <string_utils.h>
#include <string>
#include <iostream>

constexpr uint32_t max_threads_in_pool{10};
void show_usage(std::string applicaton_name)
{
    std::cerr << "\t -------------------------------------------------------------------------------------------" << std::endl
              << "\t| Usage:                                                                                    |" << std::endl
              << "\t|     " << applicaton_name << " <description_file> <sentence>                                      |" << std::endl
              << "\t| Options:                                                                                  |" << std::endl
              << "\t|     <description_file>     Path to input decription file used for creating state machine. |" << std::endl
			  << "\t|     <sentence>             Sentence to interpret.                                         |" << std::endl
              << "\t -------------------------------------------------------------------------------------------" << std::endl
              << std::endl;
}

int main(int argc, char **argv)
{
    std::string input_description_path{""};
    std::string input_sentence{""};
    if (argc  == 3)
    {
        input_sentence = argv[argc - 1];
		argc--;
		input_description_path = argv[argc - 1];
    }
    else
    {
        std::cerr << "\tInvalid arguments passed." << std::endl;
        show_usage(argv[0]);
        return 1;
    }

    using namespace state_machine;
    auto state_managers = StateMachineFactory::Get().CreateStateManagersFor(input_description_path);
    
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

    State::SPtr result_state{nullptr};
    FinalState::SPtr final_state{nullptr};
    for(auto& state_manager: state_managers)
    {
        result_state = get_final_state(state_manager, input_sentence);
        if ( result_state)
        {
            final_state = std::dynamic_pointer_cast<FinalState>(result_state);
            if ( final_state != nullptr)
            {
                break;
            }
        }
    }

	if ( result_state == nullptr)
	{
		std::cout << "Could not find the Intent for the sentence." <<std::endl;
		return 1;
	}

	if ( final_state == nullptr)
	{
		std::cout << "Could not find the Intent. Probably the sentense is incomplete." <<std::endl;
		return 1;
	}

	std::cout << final_state->GetFinalIntent() <<std::endl;
	return 0;
}

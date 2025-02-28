#include "csv_state_machine_reader.h"
#include <fstream>
#include <map>
#include <string_utils.h>

namespace state_machine
{
CsvStateMachineReader::CsvStateMachineReader() noexcept
{
}

CsvStateMachineReader::~CsvStateMachineReader()
{
}

bool CsvStateMachineReader::OpenFile(const std::string& file_name) noexcept
{
    if(file_name.empty())
    {
        return false;
    }
    using StateMap = std::map<std::string,std::vector<std::string>>;
    auto create_next_states = [](StateManager::Ptr state_manager, const StateMap& intermediate_state_map, const StateMap& final_state_map){
        for(const auto& value_pair: intermediate_state_map)
        {
            auto main_state_ptr = state_manager->GetState(value_pair.first);
            if (main_state_ptr)
            {
                for(const auto& state: value_pair.second )
                {
                    auto state_ptr = state_manager->GetState(state);
                    if (state_ptr)
                    {
                        main_state_ptr->AddNextState(state_ptr);
                    }
                }
            }
        }

        for(const auto& value_pair: final_state_map)
        {
            if ( value_pair.second.size() == 1 )
            {
                auto state_ptr = state_manager->GetState(value_pair.first);
                if (state_ptr)
                {
                    auto final_state_ptr = std::dynamic_pointer_cast<FinalState>(state_ptr);
                    if ( final_state_ptr)
                    {
                        final_state_ptr->SetFinalIntent(value_pair.second[0]);
                    }
                }
            }
        }
    };

    StateMap intermediate_state_map;
    StateMap final_state_map;
    auto state_manager{std::make_shared<StateManager>()};
    std::ifstream csv_state_file{file_name};
    std::string state_line;
    while( std::getline( csv_state_file, state_line) )
    {
        utils::trim(state_line);
        if ( state_line.size())
        {
            if ( state_line == "-")
            {
                create_next_states(state_manager, intermediate_state_map, final_state_map);
                state_managers_.push_back(state_manager);
                intermediate_state_map.clear();
                final_state_map.clear();
                state_manager = std::make_shared<StateManager>();
            }
            else if ( state_line.find(">") != std::string::npos)
            {
                auto tokens = utils::GetTokens(state_line, '>');
                if ( tokens.size())
                {
                    auto main_state{tokens[0]};
                    auto new_state = std::make_shared<FinalState>(main_state);
                    state_manager->AddState(new_state);
                    tokens.erase(tokens.begin());
                    final_state_map[main_state] = tokens;
                } 
            }
            else if ( state_line.find("*") != std::string::npos)
            {
                auto tokens = utils::GetTokens(state_line.substr(state_line.find("*")+1), ',');
                if ( tokens.size())
                {
                    auto main_state{tokens[0]};
                    auto new_state = std::make_shared<BeginState>(main_state);
                    state_manager->AddState(new_state);
                    tokens.erase(tokens.begin());
                    intermediate_state_map[main_state] = tokens;
                } 
            }
            else
            {
                auto tokens = utils::GetTokens(state_line, ',');
                if ( tokens.size())
                {
                    auto main_state{tokens[0]};
                    tokens.erase(tokens.begin());
                    auto& token_vector = intermediate_state_map[main_state];;
                    auto new_state = std::make_shared<State>(main_state);
                    state_manager->AddState(new_state);
                    token_vector.insert(token_vector.begin(), tokens.begin(), tokens.end());
                } 
            }
        }
    }

    csv_state_file.close();
    return true;
}

std::vector<StateManager::Ptr> CsvStateMachineReader::GetStateManagers() const noexcept
{
    return state_managers_;
}
} // state_machine
